using ScholarSync.Forms;

namespace SchoolSync.Forms
{
    public partial class SettingsForm : Form
    {
        public int? FromDate { get; set; }
        public int? UntilDate { get; set; }
        public const int MINIMUM_DAY_DIFFERENCE = 2;
        public const int MAXIMUM_DAY_DIFFERENCE = 999;

        public SettingsForm()
        {
            InitializeComponent();
            //Initialize ranges
            dtpFromDate.MinDate = DateTime.Today.AddDays(-MAXIMUM_DAY_DIFFERENCE);
            dtpFromDate.MaxDate = DateTime.Today.AddDays(-MINIMUM_DAY_DIFFERENCE);
            dtpUntilDate.MinDate = DateTime.Today.AddDays(MINIMUM_DAY_DIFFERENCE);
            dtpUntilDate.MaxDate = DateTime.Today.AddDays(MAXIMUM_DAY_DIFFERENCE);

        }

        private void UpdateDaysTextboxes()
        {
            tBoxFromDate.Text = FromDate.ToString();
            tBoxUntilDate.Text = UntilDate.ToString();
        }

        public void ReceiveData(int? fromDate, int? untilDate)
        {
            // if not initialized, set to minimum
            FromDate = fromDate ?? MINIMUM_DAY_DIFFERENCE;
            UntilDate = untilDate ?? MINIMUM_DAY_DIFFERENCE;
            UpdateDaysTextboxes();
        }

        public int[] GetFormData()
        {
            int[] data = new int[] { FromDate ?? MINIMUM_DAY_DIFFERENCE, UntilDate ?? MINIMUM_DAY_DIFFERENCE };
            return data;
        }

        private void SettingsForm_Load(object? sender, EventArgs e)
        {
            ControlBox = false;
            //dismissTime.Text = (NotificationForm.GetSnoozeTime()/60000).ToString();
            //notAllowAppTime.Text = (Utils.GetAppTimer() / 60000).ToString();
        }

        private void TextBox_KeyPress(object? sender, KeyPressEventArgs e)
        {
            TextBox textBox = sender as TextBox;

            if (char.IsControl(e.KeyChar))
            {
                return;
            }

            if (!char.IsDigit(e.KeyChar) || textBox.Text.Length >= 3)
            {
                e.Handled = true;
            }
        }

        private void DateTimePickerFromDate_ValueChanged(object? sender, EventArgs e)
        {
            tBoxFromDate.Text = GetDifferenceInDays(dtpFromDate.Value, DateTime.Today).ToString();
        }

        private void DateTimePickerUntilDate_ValueChanged(object? sender, EventArgs e)
        {
            tBoxUntilDate.Text = GetDifferenceInDays(DateTime.Today, dtpUntilDate.Value).ToString();
        }

        private static int GetDifferenceInDays(DateTime? fromDate, DateTime? untilDate)
        {
            if (fromDate == null || untilDate == null || fromDate == untilDate)
            {
                return 0;
            }

            return (untilDate.Value - fromDate.Value).Days;
        }

        private void TextBoxFromDate_TextChanged(object? sender, EventArgs e)
        {
            if (int.TryParse(tBoxFromDate.Text, out int daysDifference))
            {
                if (daysDifference < MINIMUM_DAY_DIFFERENCE)
                {
                    daysDifference = MINIMUM_DAY_DIFFERENCE;
                    dtpFromDate.Value = DateTime.Today.AddDays(-daysDifference);
                }
            }
        }

        private void TextBoxUntilDate_TextChanged(object? sender, EventArgs e)
        {
            if (int.TryParse(tBoxUntilDate.Text, out int daysDifference))
            {
                dtpUntilDate.Value = DateTime.Today.AddDays(daysDifference);
            }
        }

        private void SetControl_Click(object sender, EventArgs e)
        {
            FromDate = int.TryParse(tBoxFromDate.Text, out int fromDate) ? fromDate : MINIMUM_DAY_DIFFERENCE;
            UntilDate = int.TryParse(tBoxUntilDate.Text, out int untilDate) ? untilDate : MINIMUM_DAY_DIFFERENCE;
        }
    }
}
