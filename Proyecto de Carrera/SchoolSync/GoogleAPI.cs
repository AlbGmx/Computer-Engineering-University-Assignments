using Google.Apis.Auth.OAuth2;
using Google.Apis.Auth.OAuth2.Flows;
using Google.Apis.Auth.OAuth2.Responses;
using Google.Apis.Calendar.v3;
using Google.Apis.Calendar.v3.Data;
using Google.Apis.Services;
using Google.Apis.Util.Store;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SchoolSync
{
    internal class TokenRevocationClient
    {
        private static readonly HttpClient _httpClient = new HttpClient();

        public async Task RevokeTokenAsync(string token)
        {
            var content = new FormUrlEncodedContent(new[]
            {
                new KeyValuePair<string, string>("token", token)
            });

            var response = await _httpClient.PostAsync("https://accounts.google.com/o/oauth2/revoke", content);
            response.EnsureSuccessStatusCode();
        }
    }

    internal class GoogleAPI
    {
        static readonly string[] Scopes = { CalendarService.Scope.CalendarReadonly };
        private const string CREDENTIALS_PATH = "../../../../credentials.json";
        private const string TOKEN_DIRECTORY = "../../../../token";  // Directory for storing tokens
        private const string APP_NAME = "ScholarSync - API";

        public static async Task<UserCredential> GoogleAuth()
        {
            UserCredential credential = null;
            bool needsLogin = false;

            if (File.Exists(CREDENTIALS_PATH))
            {
                using (var stream = new FileStream(CREDENTIALS_PATH, FileMode.Open, FileAccess.Read))
                {
                    var secrets = GoogleClientSecrets.FromStream(stream).Secrets;
                    var initializer = new GoogleAuthorizationCodeFlow.Initializer
                    {
                        ClientSecrets = secrets,
                        Scopes = Scopes,
                        DataStore = new FileDataStore(TOKEN_DIRECTORY, true)
                    };

                    var flow = new GoogleAuthorizationCodeFlow(initializer);

                    var token = await flow.LoadTokenAsync("user", CancellationToken.None);
                    if (token != null && !token.IsExpired(flow.Clock))
                    {
                        credential = new UserCredential(flow, "user", token);
                    }
                    else
                    {
                        needsLogin = true;
                    }
                }
            }
            else
            {
                needsLogin = true;
            }

            if (needsLogin)
            {
                using (var stream = new FileStream(CREDENTIALS_PATH, FileMode.Open, FileAccess.Read))
                {
                    credential = await GoogleWebAuthorizationBroker.AuthorizeAsync(
                        GoogleClientSecrets.FromStream(stream).Secrets,
                        Scopes,
                        "user",
                        CancellationToken.None,
                        new FileDataStore(TOKEN_DIRECTORY, true));
                }

                if (credential == null)
                {
                    MessageBox.Show("Unable to log in. Please try again.", "Authentication Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }

            return credential;
        }

        public static Events GetEvents(CalendarService service, int goingBackDays, int goingForwardDays)
        {
            EventsResource.ListRequest request = service.Events.List("primary");
            request.TimeMin = DateTime.Now.AddDays(goingBackDays * -1);
            request.TimeMax = DateTime.Now.AddDays(goingForwardDays);
            request.ShowDeleted = false;
            request.SingleEvents = true;
            request.MaxResults = 10;
            request.OrderBy = EventsResource.ListRequest.OrderByEnum.StartTime;

            Events events = request.Execute();
            return events;
        }

        public static CalendarService CreateCalendarService(UserCredential credential)
        {
            CalendarService service = new CalendarService(new BaseClientService.Initializer()
            {
                HttpClientInitializer = credential,
                ApplicationName = APP_NAME,
            });

            return service;
        }

        public static async Task RevokeCredentials(UserCredential credential)
        {
            try
            {
                var token = await credential.GetAccessTokenForRequestAsync();
                await new TokenRevocationClient().RevokeTokenAsync(token);

                if (Directory.Exists(TOKEN_DIRECTORY))
                {
                    Directory.Delete(TOKEN_DIRECTORY, true);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred while revoking credentials: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
