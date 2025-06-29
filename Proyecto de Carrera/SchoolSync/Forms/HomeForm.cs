using Google.Apis.Auth.OAuth2;
using Google.Apis.Calendar.v3;
using Google.Apis.Calendar.v3.Data;
using ScholarSync.Forms;
using SchoolSync.Forms;

namespace SchoolSync
{
    public partial class HomeForm : Form
    {
        private SettingsData? settingsData;
        public int? FromDate { get; set; }
        public int? UntilDate { get; set; }

        public static bool? notAllowedApp { get; set; }
        public static string? notAllowedAppName { get; set; }


        private UserCredential? userCredential;
        private CalendarService? service;

        public const int MAX_DAYS = 999;
        public const String SETTINGS_FORM = "SettingsForm";
        public const String BLOCKED_APPS_FORM = "BlockedAppsForm";
        public const String GOOGLE_ACCOUNT_FORM = "GoogleAccountForm";

        private Events events;

        bool sidebarMenuExpanded = false;

        BlockedAppsForm? blockedAppsForm;
        SettingsForm? settingsForm;
        GoogleAccountForm? googleAccountForm;


        public HomeForm()
        {
            InitializeComponent();
            sidebarMenu.Width = sidebarMenu.MinimumSize.Width;
            InitializeGoogleAPI();
            LoadSettings();
            UpdateDaysCountLabels();
            Utils.InitWatcher();
        }

        private async void InitializeGoogleAPI()
        {
            userCredential = await GoogleAPI.GoogleAuth();
            CalendarService auxService = GoogleAPI.CreateCalendarService(userCredential);
            service = auxService;
        }

        private void LoadSettings()
        {
            settingsData = Utils.LoadSettings();
            FromDate = settingsData.FromDate;
            UntilDate = settingsData.UntilDate;
        }

        private void SaveSettings()
        {
            SettingsData dataToSave = new()
            {
                FromDate = FromDate,
                UntilDate = UntilDate,
            };
            Utils.SaveSettings(dataToSave);
        }

        private void SidebarMenuTimer_Tick(object sender, EventArgs e)
        {
            if (sidebarMenuExpanded == false)
            {
                sidebarMenu.Width += 10;
                if (sidebarMenu.Width >= sidebarMenu.MaximumSize.Width)
                {
                    sidebarMenuExpanded = true;
                    sidebarMenuTimer.Stop();
                }
            }
            else
            {
                sidebarMenu.Width -= 10;
                if (sidebarMenu.Width <= sidebarMenu.MinimumSize.Width)
                {
                    sidebarMenuExpanded = false;
                    sidebarMenuTimer.Stop();
                }
            }
            homePanel.Location = new Point(sidebarMenu.Width, homePanel.Location.Y);
        }

        private void MenuControl_Clicked(object sender, EventArgs e)
        {
            sidebarMenuTimer.Start();
        }

        private void NoAllowedAppsControl_Clicked(object sender, EventArgs e)
        {
            homePanel.Controls.Clear();
            blockedAppsForm = new BlockedAppsForm()
            {
                TopLevel = false,
                FormBorderStyle = FormBorderStyle.None,
                Dock = DockStyle.Fill,
            };
            homePanel.Controls.Add(blockedAppsForm);
            ShrinkSidebarMenu();
            blockedAppsForm.Show();
            ReturnControl.Show();
        }

        private void SettingsControl_Clicked(object sender, EventArgs e)
        {
            homePanel.Controls.Clear();
            settingsForm = new SettingsForm()
            {
                TopLevel = false,
                FormBorderStyle = FormBorderStyle.None,
                Dock = DockStyle.Fill,
            };
            homePanel.Controls.Add(settingsForm);
            ShrinkSidebarMenu();
            settingsForm.ReceiveData(FromDate, UntilDate);
            LabelFromDate.Hide();
            LabelUntilDate.Hide();
            LabelUntilDateDescription.Hide();
            LabelFromDateDescription.Hide();
            settingsForm.Show();
            ReturnControl.Show();
        }

        private void GoogleAccountControl_Clicked(object? sender, EventArgs e)
        {
            homePanel.Controls.Clear();
            googleAccountForm = new GoogleAccountForm()
            {
                TopLevel = false,
                MdiParent = this,
                Dock = DockStyle.Fill,
            };
            homePanel.Controls.Add(googleAccountForm);
            googleAccountForm.SendCredential(userCredential);
            ShrinkSidebarMenu();
            googleAccountForm.Show();
            ReturnControl.Show();
        }

        private void ReturnControl_Clicked(object? sender, EventArgs e)
        {

            switch (GetFormIncontrol())
            {
                case SETTINGS_FORM:
                    int[] dataArray = settingsForm.GetFormData();
                    FromDate = dataArray[0];
                    UntilDate = dataArray[1];
                    break;
                case BLOCKED_APPS_FORM:
                    break;
                case GOOGLE_ACCOUNT_FORM:
                    userCredential = googleAccountForm.GetCredential();
                    break;
                default:
                    break;
            }
            LabelFromDate.Show();
            LabelUntilDate.Show();
            LabelUntilDateDescription.Show();
            LabelFromDateDescription.Show();


            homePanel.Controls.Clear();
            calendarWebView = new Microsoft.Web.WebView2.WinForms.WebView2()
            {
                Dock = DockStyle.Fill,
                Source = new Uri("https://calendar.google.com/calendar/u/0/r"),
            };
            homePanel.Controls.Add(calendarWebView);
            ReturnControl.Hide();
            calendarWebView.Show();
            ShrinkSidebarMenu();
            UpdateDaysCountLabels();
        }

        private void UpdateDaysCountLabels()
        {
            if (FromDate != null && UntilDate != null)
            {
                LabelUntilDate.Text = UntilDate.ToString();
                LabelUntilDate.ForeColor = Color.Black;
                LabelFromDate.Text = FromDate.ToString();
                LabelFromDate.ForeColor = Color.Black;
            }
            else
            {
                LabelUntilDate.Text = SettingsForm.MINIMUM_DAY_DIFFERENCE.ToString();
                LabelUntilDate.ForeColor = Color.Red;
                LabelFromDate.Text = SettingsForm.MINIMUM_DAY_DIFFERENCE.ToString();
                LabelFromDate.ForeColor = Color.Red;
            }
        }

        private void ShrinkSidebarMenu()
        {
            if (sidebarMenuExpanded == true)
            {
                sidebarMenuTimer.Start();
            }
        }

        private void HomeForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            SaveSettings();
        }

        private void HomeForm_SizeChanged(object? sender, EventArgs e)
        {
            homePanel.Size = new Size(Width - sidebarMenu.Width, Height);
            switch (GetFormIncontrol())
            {
                case "GoogleAccount":
                    settingsForm.ReceiveData(FromDate, UntilDate);
                    break;
                default:
                    break;
            }

        }

        private String GetFormIncontrol()
        {
            Control control = homePanel.Controls[0];
            Type? currentFormType;
            if (control is Form form)
            {
                currentFormType = form.GetType();
                return currentFormType.Name;
            }
            return "";
        }

        private void displayNotification()
        {
            Events events = GoogleAPI.GetEvents(service, 10, 10);
            NotificationForm notification = new NotificationForm(events);
            notification.Show();
        }

        private void displayNotification(string noAllowedApp)
        {
            Events events = GoogleAPI.GetEvents(service, 10, 10);
            NotificationForm notification = new NotificationForm(events, noAllowedApp);
            notification.Show();
        }

        private void notificationTimer_Tick(object sender, EventArgs e)
        {
            if (File.Exists("token\\Google.Apis.Auth.OAuth2.Responses.TokenResponse-user"))
            {
                displayNotification();
                notificationTimer.Stop();
            }
            
        }

        private void appChekcer_Tick(object sender, EventArgs e)
        {
            if (notAllowedApp ?? false)
            { 
                displayNotification(notAllowedAppName);
                notAllowedApp = false;
            }
        }
    }
}