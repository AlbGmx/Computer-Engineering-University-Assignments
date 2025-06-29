namespace SchoolSync
{
    partial class HomeForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(HomeForm));
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            menuButton = new PictureBox();
            sidebarMenu = new FlowLayoutPanel();
            NoAllowedAppsControl = new Button();
            SettingsControl = new Button();
            GoogleAccountControl = new Button();
            ReturnControl = new Button();
            sidebarMenuTimer = new System.Windows.Forms.Timer(components);
            homePanel = new Panel();
            calendarWebView = new Microsoft.Web.WebView2.WinForms.WebView2();
            DaysShownPanel = new TableLayoutPanel();
            LabelFromDateDescription = new Label();
            LabelFromDate = new Label();
            LabelUntilDateDescription = new Label();
            LabelUntilDate = new Label();
            notificationTimer = new System.Windows.Forms.Timer(components);
            appChekcer = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)menuButton).BeginInit();
            sidebarMenu.SuspendLayout();
            homePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)calendarWebView).BeginInit();
            DaysShownPanel.SuspendLayout();
            SuspendLayout();
            // 
            // menuButton
            // 
            menuButton.Image = (Image)resources.GetObject("menuButton.Image");
            menuButton.Location = new Point(5, 3);
            menuButton.Margin = new Padding(5, 3, 3, 3);
            menuButton.Name = "menuButton";
            menuButton.Size = new Size(40, 40);
            menuButton.SizeMode = PictureBoxSizeMode.StretchImage;
            menuButton.TabIndex = 2;
            menuButton.TabStop = false;
            menuButton.Click += MenuControl_Clicked;
            // 
            // sidebarMenu
            // 
            sidebarMenu.BackColor = Color.FromArgb(77, 134, 156);
            sidebarMenu.Controls.Add(menuButton);
            sidebarMenu.Controls.Add(NoAllowedAppsControl);
            sidebarMenu.Controls.Add(SettingsControl);
            sidebarMenu.Controls.Add(GoogleAccountControl);
            sidebarMenu.Controls.Add(ReturnControl);
            sidebarMenu.Dock = DockStyle.Left;
            sidebarMenu.Location = new Point(0, 0);
            sidebarMenu.MaximumSize = new Size(250, 0);
            sidebarMenu.MinimumSize = new Size(50, 0);
            sidebarMenu.Name = "sidebarMenu";
            sidebarMenu.Size = new Size(250, 820);
            sidebarMenu.TabIndex = 5;
            // 
            // NoAllowedAppsControl
            // 
            NoAllowedAppsControl.BackColor = Color.FromArgb(205, 232, 229);
            NoAllowedAppsControl.Location = new Point(3, 49);
            NoAllowedAppsControl.Name = "NoAllowedAppsControl";
            NoAllowedAppsControl.Size = new Size(245, 70);
            NoAllowedAppsControl.TabIndex = 4;
            NoAllowedAppsControl.Text = "No Allowed Apps";
            NoAllowedAppsControl.UseVisualStyleBackColor = false;
            NoAllowedAppsControl.Click += NoAllowedAppsControl_Clicked;
            // 
            // SettingsControl
            // 
            SettingsControl.BackColor = Color.FromArgb(205, 232, 229);
            SettingsControl.Location = new Point(3, 125);
            SettingsControl.Name = "SettingsControl";
            SettingsControl.Size = new Size(245, 70);
            SettingsControl.TabIndex = 4;
            SettingsControl.Text = "Settings";
            SettingsControl.UseVisualStyleBackColor = false;
            SettingsControl.Click += SettingsControl_Clicked;
            // 
            // GoogleAccountControl
            // 
            GoogleAccountControl.BackColor = Color.FromArgb(205, 232, 229);
            GoogleAccountControl.Location = new Point(3, 201);
            GoogleAccountControl.Name = "GoogleAccountControl";
            GoogleAccountControl.Size = new Size(245, 70);
            GoogleAccountControl.TabIndex = 5;
            GoogleAccountControl.Text = "Google Account";
            GoogleAccountControl.UseVisualStyleBackColor = false;
            GoogleAccountControl.Click += GoogleAccountControl_Clicked;
            // 
            // ReturnControl
            // 
            ReturnControl.BackColor = Color.FromArgb(205, 232, 229);
            ReturnControl.Location = new Point(3, 277);
            ReturnControl.Name = "ReturnControl";
            ReturnControl.Size = new Size(245, 70);
            ReturnControl.TabIndex = 6;
            ReturnControl.Text = "Return";
            ReturnControl.UseVisualStyleBackColor = false;
            ReturnControl.Visible = false;
            ReturnControl.Click += ReturnControl_Clicked;
            // 
            // sidebarMenuTimer
            // 
            sidebarMenuTimer.Interval = 5;
            sidebarMenuTimer.Tick += SidebarMenuTimer_Tick;
            // 
            // homePanel
            // 
            homePanel.BackColor = Color.White;
            homePanel.Controls.Add(calendarWebView);
            homePanel.Location = new Point(50, 50);
            homePanel.Name = "homePanel";
            homePanel.Size = new Size(1092, 770);
            homePanel.TabIndex = 0;
            // 
            // calendarWebView
            // 
            calendarWebView.AllowExternalDrop = true;
            calendarWebView.BackColor = Color.Gainsboro;
            calendarWebView.CreationProperties = null;
            calendarWebView.DefaultBackgroundColor = Color.Transparent;
            calendarWebView.Dock = DockStyle.Fill;
            calendarWebView.Location = new Point(0, 0);
            calendarWebView.Margin = new Padding(10);
            calendarWebView.MinimumSize = new Size(800, 600);
            calendarWebView.Name = "calendarWebView";
            calendarWebView.Padding = new Padding(10);
            calendarWebView.Size = new Size(1092, 770);
            calendarWebView.Source = new Uri("https://calendar.google.com/calendar/u/0/r", UriKind.Absolute);
            calendarWebView.TabIndex = 0;
            calendarWebView.ZoomFactor = 1D;
            // 
            // DaysShownPanel
            // 
            DaysShownPanel.BackColor = Color.FromArgb(77, 134, 156);
            DaysShownPanel.ColumnCount = 4;
            DaysShownPanel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            DaysShownPanel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            DaysShownPanel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            DaysShownPanel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            DaysShownPanel.Controls.Add(LabelFromDateDescription, 0, 0);
            DaysShownPanel.Controls.Add(LabelFromDate, 1, 0);
            DaysShownPanel.Controls.Add(LabelUntilDateDescription, 2, 0);
            DaysShownPanel.Controls.Add(LabelUntilDate, 3, 0);
            DaysShownPanel.Dock = DockStyle.Top;
            DaysShownPanel.Location = new Point(250, 0);
            DaysShownPanel.Name = "DaysShownPanel";
            DaysShownPanel.RowCount = 1;
            DaysShownPanel.RowStyles.Add(new RowStyle(SizeType.Percent, 100F));
            DaysShownPanel.Size = new Size(890, 50);
            DaysShownPanel.TabIndex = 4;
            // 
            // LabelFromDateDescription
            // 
            LabelFromDateDescription.AutoSize = true;
            LabelFromDateDescription.Dock = DockStyle.Fill;
            LabelFromDateDescription.Location = new Point(3, 0);
            LabelFromDateDescription.Name = "LabelFromDateDescription";
            LabelFromDateDescription.Size = new Size(216, 50);
            LabelFromDateDescription.TabIndex = 0;
            LabelFromDateDescription.Text = "Days to Count Backwards";
            LabelFromDateDescription.TextAlign = ContentAlignment.MiddleRight;
            // 
            // LabelFromDate
            // 
            LabelFromDate.AutoSize = true;
            LabelFromDate.Dock = DockStyle.Fill;
            LabelFromDate.Location = new Point(225, 0);
            LabelFromDate.Name = "LabelFromDate";
            LabelFromDate.Size = new Size(216, 50);
            LabelFromDate.TabIndex = 1;
            LabelFromDate.Text = "0";
            LabelFromDate.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // LabelUntilDateDescription
            // 
            LabelUntilDateDescription.AutoSize = true;
            LabelUntilDateDescription.Dock = DockStyle.Fill;
            LabelUntilDateDescription.Location = new Point(447, 0);
            LabelUntilDateDescription.Name = "LabelUntilDateDescription";
            LabelUntilDateDescription.Size = new Size(216, 50);
            LabelUntilDateDescription.TabIndex = 2;
            LabelUntilDateDescription.Text = "Days to Count Forward";
            LabelUntilDateDescription.TextAlign = ContentAlignment.MiddleRight;
            // 
            // LabelUntilDate
            // 
            LabelUntilDate.AutoSize = true;
            LabelUntilDate.Dock = DockStyle.Fill;
            LabelUntilDate.Location = new Point(669, 0);
            LabelUntilDate.Name = "LabelUntilDate";
            LabelUntilDate.Size = new Size(218, 50);
            LabelUntilDate.TabIndex = 3;
            LabelUntilDate.Text = "0";
            LabelUntilDate.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // notificationTimer
            // 
            notificationTimer.Enabled = true;
            notificationTimer.Interval = 600;
            notificationTimer.Tick += notificationTimer_Tick;
            // 
            // appChekcer
            // 
            appChekcer.Enabled = true;
            appChekcer.Interval = 600;
            appChekcer.Tick += appChekcer_Tick;
            // 
            // HomeForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.Control;
            ClientSize = new Size(1140, 820);
            Controls.Add(DaysShownPanel);
            Controls.Add(sidebarMenu);
            Controls.Add(homePanel);
            IsMdiContainer = true;
            MinimumSize = new Size(800, 600);
            Name = "HomeForm";
            SizeGripStyle = SizeGripStyle.Show;
            FormClosing += HomeForm_FormClosing;
            SizeChanged += HomeForm_SizeChanged;
            ((System.ComponentModel.ISupportInitialize)menuButton).EndInit();
            sidebarMenu.ResumeLayout(false);
            homePanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)calendarWebView).EndInit();
            DaysShownPanel.ResumeLayout(false);
            DaysShownPanel.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private PictureBox menuButton;
        private FlowLayoutPanel sidebarMenu;
        private Button NoAllowedAppsControl;
        private Panel panel3;
        private Button GoogleAccountControl;
        private Button SettingsControl;
        private System.Windows.Forms.Timer sidebarMenuTimer;
        private Panel homePanel;
        private Microsoft.Web.WebView2.WinForms.WebView2 calendarWebView;
        private TableLayoutPanel DaysShownPanel;
        private Label LabelFromDateDescription;
        private Label LabelFromDate;
        private Label LabelUntilDateDescription;
        private Label LabelUntilDate;
        private Button ReturnControl;
        private System.Windows.Forms.Timer notificationTimer;
        private System.Windows.Forms.Timer appChekcer;
    }
}
