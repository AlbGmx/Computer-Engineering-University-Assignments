using Google.Apis.Calendar.v3.Data;
using System;

namespace ScholarSync.Forms
{
    partial class NotificationForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            snoozeLabel = new Button();
            dismissLabel = new Button();
            snoozeTimer = new System.Windows.Forms.Timer(components);
            showTimer = new System.Windows.Forms.Timer(components);
            SuspendLayout();
            // 
            // snoozeLabel
            // 
            snoozeLabel.Location = new Point(132, 90);
            snoozeLabel.Name = "snoozeLabel";
            snoozeLabel.Size = new Size(75, 23);
            snoozeLabel.TabIndex = 0;
            snoozeLabel.Text = "Snooze";
            snoozeLabel.UseVisualStyleBackColor = true;
            snoozeLabel.Click += snoozeLabel_Click;
            // 
            // dismissLabel
            // 
            dismissLabel.Location = new Point(213, 90);
            dismissLabel.Name = "dismissLabel";
            dismissLabel.Size = new Size(75, 23);
            dismissLabel.TabIndex = 1;
            dismissLabel.Text = "Dismiss";
            dismissLabel.UseVisualStyleBackColor = true;
            dismissLabel.Click += dismissLabel_Click;
            // 
            // snoozeTimer
            // 
            snoozeTimer.Interval = 60000;
            snoozeTimer.Tick += snoozeTimer_Tick;
            // 
            // showTimer
            // 
            showTimer.Enabled = true;
            showTimer.Interval = 5;
            showTimer.Tick += showTimer_Tick;
            // 
            // NotificationForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(77, 134, 156);
            ClientSize = new Size(300, 120);
            Controls.Add(dismissLabel);
            Controls.Add(snoozeLabel);
            FormBorderStyle = FormBorderStyle.None;
            Name = "NotificationForm";
            ShowInTaskbar = false;
            Text = "NotificationForm";
            Load += NotificationForm_Load;
            ResumeLayout(false);
        }

        #endregion

        private Button snoozeLabel;
        private Button dismissLabel;
        private System.Windows.Forms.Timer showTimer;

        private int panelHeight = 80;
        private int panelWidth = 300;
        private int warningPanel = 0;
        private int spacing = 5;

        private Events events;
        private string noAllowedApp;

        public NotificationForm(Events events)
        {
            this.events = events;
            InitializeComponent();
            AddNotificationPanel(events);
            this.TopMost = true;
        }

        public NotificationForm(Events events, string noAllowedApp)
        {
            warningPanel = 105;
            this.events = events;
            this.noAllowedApp = noAllowedApp;
            InitializeComponent();
            AddNotAllowedPanel(noAllowedApp);
            AddNotificationPanel(events);
            this.TopMost = true;
            
        }

        private void AddNotAllowedPanel(string noAllowedApp)
        {
            Panel eventPanel = new Panel()
            {
                BackColor = Color.FromArgb(205, 232, 229),
                Size = new Size(panelWidth, panelHeight + 20),
                Name = "warningPanel",
                Location = new Point(0, 0),
            };

            Label warningLabel = new Label()
            {
                AutoSize = true,
                MaximumSize = new Size(240, 0),
                Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point, 0),
                Location = new Point(53, 5),
                Name = "warningLabel",
                Text = "Aun tienes tareas pendientes!",
            };

            Label infoLabel = new Label()
            {
                AutoSize = true,
                MaximumSize = new Size(240, 0),
                Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 0),
                Location = new Point(53, 5),
                Name = "infoLabel",
                Text = "\nHas abierto una aplicacion que tienes en tu lista, piensa.\n" + noAllowedApp,
            };

            PictureBox pictureBox = new PictureBox()
            {
                Image = Properties.Resources.warning,
                Location = new Point(7, 7),
                Size = new Size(40, 40),
                Name = "warningPicture",
                SizeMode = PictureBoxSizeMode.StretchImage,
            };

            eventPanel.Controls.Add(warningLabel);
            eventPanel.Controls.Add(infoLabel);
            eventPanel.Controls.Add(pictureBox);

            Controls.Add(eventPanel);
        }

        private void AddNotificationPanel(Events events)
        {
            for (int i = 0; i < events.Items.Count; i++)
            {
                Panel eventPanel = new Panel()
                {
                    BackColor = Color.FromArgb(205, 232, 229),
                    Size = new Size(panelWidth, panelHeight),
                    Location = new Point(0, ((panelHeight + spacing) * i) + warningPanel),
                    Name = "panel" + i,
                };

                Label assignmentLabel = new Label()
                {
                    AutoSize = true,
                    Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point, 0),
                    Location = new Point(53, 5),
                    Name = "assigmentLabel" + i,
                    Text = events.Items[i].Summary,
                };

                Label courseLabel = new Label()
                {
                    AutoSize = true,
                    Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 0),
                    Location = new Point(53, 26),
                    Name = "courseLabel" + i,
                    Text = events.Items[i].Summary,
                };

                DateTime dateTime = (events.Items[i].Start.DateTime.HasValue) ? (events.Items[i].Start.DateTime.Value) : (DateTime.Parse(events.Items[i].Start.Date));

                Label dueToLabel = new Label()
                {
                    AutoSize = true,
                    Font = new Font("Segoe UI", 10F, FontStyle.Regular, GraphicsUnit.Point, 0),
                    Location = new Point(53, 55),
                    Name = "dueToLabel" + i,
                    Text = "Due to " + dateTime.ToString("MMMM dd"),
                };

                TimeSpan timeLeft = dateTime - DateTime.Today;

                Label timeLeftLabel = new Label()
                {
                    AutoSize = true,
                    Font = new Font("Segoe UI", 10F, FontStyle.Regular, GraphicsUnit.Point, 0),
                    Location = new Point(175, 55),
                    Name = "timeLeftLabel" + i,
                    Text = "Time Left: " + timeLeft.Days + " Days",
                };

                PictureBox pictureBox = new PictureBox()
                {
                    Image = Properties.Resources.assignment,
                    Location = new Point(7, 7),
                    Name = "pictureBox" + i,
                    Size = new Size(40, 40),
                    SizeMode = PictureBoxSizeMode.StretchImage,
                };

                eventPanel.Controls.Add(assignmentLabel);
                eventPanel.Controls.Add(courseLabel);
                eventPanel.Controls.Add(dueToLabel);
                eventPanel.Controls.Add(timeLeftLabel);
                eventPanel.Controls.Add(pictureBox);

                Controls.Add(eventPanel);
            }

            this.ClientSize = new Size(300, (panelHeight * events.Items.Count) + (spacing * (events.Items.Count - 1)) + 40 + warningPanel);
            snoozeLabel.Location = new Point(132, (panelHeight * events.Items.Count) + (spacing * (events.Items.Count - 1)) + 10 + warningPanel);
            dismissLabel.Location = new Point(213, (panelHeight * events.Items.Count) + (spacing * (events.Items.Count - 1)) + 10 + warningPanel);
        }

        private System.Windows.Forms.Timer snoozeTimer;
    }
}
