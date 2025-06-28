using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScholarSync.Forms
{
    public partial class NotificationForm : Form
    {
        int notificacionX;
        int notificacionY;
        int finalNotificationY;
        int offsetX = 10;
        int offsetY = 20;

        private static Form currentForm;

        public NotificationForm()
        {
            InitializeComponent();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        public static void setSnoozeTime(int time)
        {
            //snoozeTimer.Interval = time * 60000;
        }

        public static int GetSnoozeTime()
        {
            //return snoozeTimer.Interval;
            return 0;
        }


        private void Position()
        {
            int ScreenWidth = Screen.PrimaryScreen.WorkingArea.Width;
            int ScreenHeight = Screen.PrimaryScreen.WorkingArea.Height;

            notificacionX = ScreenWidth - this.Width - offsetX;
            notificacionY = ScreenHeight - this.Height + 200;
            finalNotificationY = ScreenHeight - this.Height - offsetY;

            this.Location = new Point(notificacionX, notificacionY);
        }

        private void NotificationForm_Load(object sender, EventArgs e)
        {
            if (currentForm != null)
            {
                currentForm.Close();
            }

            currentForm = this;
            currentForm.FormClosed += (sender, e) => currentForm = null;
            Position();
        }

        private void dismissLabel_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void snoozeTimer_Tick(object sender, EventArgs e)
        {
            Position();
            showTimer.Start();
            this.Show();
            snoozeTimer.Stop();
        }

        private void snoozeLabel_Click(object sender, EventArgs e)
        {
            this.Hide();
            snoozeTimer.Start();
        }

        private void showTimer_Tick(object sender, EventArgs e)
        {
            notificacionY -= 10;
            this.Location = new Point(notificacionX, notificacionY);
            if (notificacionY <= finalNotificationY)
            {
                showTimer.Stop();
            }
        }
    }
}
