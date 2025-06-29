using Newtonsoft.Json;
using SchoolSync.Forms;
using System.Management;
using System.Timers;

namespace SchoolSync
{
    public class SettingsData
    {
        public int? FromDate { get; set; }
        public int? UntilDate { get; set; }
    }

    internal class Utils
    {
        //private static List<string> applicationList = new();
        private static Dictionary<string, int> appList = new();
        private const string wmiQuery = "SELECT * FROM Win32_ProcessStartTrace";
        private const string filePath = "applicationsList.bin";
        private const string settingsPath = "../../../settings.bin";

        public event EventHandler appInList;
        private static System.Timers.Timer timer;


        public static void InitWatcher()
        {
            appList = LoadApplicationList(filePath);
            ProcessWatcher();
            AppTimer();
        }

        public static void ProcessWatcher()
        {
            ManagementEventWatcher watcher = new (wmiQuery);
            watcher.EventArrived += new EventArrivedEventHandler(ProcessStarted);
            watcher.Start();
        }

        static void ProcessStarted(object sender, EventArrivedEventArgs e)
        {
            string processName = e.NewEvent.Properties["ProcessName"].Value.ToString();
            uint processId = (uint)e.NewEvent.Properties["ProcessId"].Value;
            ProcessChecker(processName);
        }

        static void ProcessChecker(string processName)
        {
            processName = processName.ToLower();
            if (appList.ContainsKey(processName) && appList[processName] == 0)
            {
                HomeForm.notAllowedApp = true;
                HomeForm.notAllowedAppName = processName;
                appList[processName] = 2;
            }
        }

        private static void AppTimer()
        {
            timer = new(3600000);
            timer.Elapsed += OnTimedEvent;
            timer.AutoReset = true;
            timer.Start();
        }

        public static double GetAppTimer()
        {
            return timer.Interval;
        }

        public static void SetAppTimer(int time)
        {
            timer.Interval = time;
        }

        private static void OnTimedEvent(Object source, ElapsedEventArgs e)
        {
            foreach (KeyValuePair<string, int> kvp in appList)
            {
                if (kvp.Value > 0) 
                {
                    appList[kvp.Key]--;
                }
            }

        }

        public static void AddApplicationList()
        {
            using (OpenFileDialog ofd = new ())
            {
                ofd.Filter = "Executable Files (*.exe)|*.exe|All Files (*.*)|*.*";
                ofd.Title = "Select an Application";
                ofd.InitialDirectory = @"C:\Program Files";

                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    string appName = Path.GetFileName(ofd.FileName).ToLower();
                    if (!appList.ContainsKey(appName))
                    {
                        appList.Add(appName, 0);
                        SaveApplicationList(appList, filePath);
                    }
                }
            }
        }

        public static void SaveApplicationList(Dictionary<string, int> appList, string filePath)
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (var kvp in appList)
                {
                    writer.WriteLine($"{kvp.Key},{kvp.Value}");
                }
            }
        }

        public static void SaveApplicationList()
        {
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (var kvp in appList)
                {
                    writer.WriteLine($"{kvp.Key},{kvp.Value}");
                }
            }
        }

        public static Dictionary<string, int> getDictiorany()
        {
            return appList;
        }

        public static void RemoveAppFromList(string key)
        {
            appList.Remove(key); 
        }

        public static Dictionary<string, int> LoadApplicationList(string filePath)
        {
            Dictionary<string, int> appList = new();

            if (File.Exists(filePath))
            {
                using (StreamReader reader = new StreamReader(filePath))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        var parts = line.Split(',');
                        string key = parts[0];
                        int value = int.Parse(parts[1]);
                        appList[key] = value;
                    }
                }
            }
            return appList;
        }

        public static void SaveSettings(SettingsData data)
        {
            string json = JsonConvert.SerializeObject(data);
            File.WriteAllText(settingsPath, json);
        }

        public static SettingsData LoadSettings()
        {
            const int defaultDayDifference = SettingsForm.MINIMUM_DAY_DIFFERENCE;
            SettingsData defaultData = new()
            {
                FromDate = defaultDayDifference,
                UntilDate = defaultDayDifference,
            };

            if (!File.Exists(settingsPath))
            {
                MessageBox.Show("Settings file not found. Default settings will be used.", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return defaultData;
            }

            string json = File.ReadAllText(settingsPath);
            SettingsData data = JsonConvert.DeserializeObject<SettingsData>(json) ?? defaultData;

            if (data == defaultData)
            {
                MessageBox.Show("Settings file is invalid. Default settings will be used.", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

            return data;
        }
    }
}
