namespace SchoolSync.Forms
{
    partial class SettingsForm
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
            dtpFromDate = new DateTimePicker();
            dtpUntilDate = new DateTimePicker();
            lblDateRangeDescription = new Label();
            tBoxUntilDate = new TextBox();
            tBoxFromDate = new TextBox();
            SetControl = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            dismissTime = new TextBox();
            snoozeTime = new TextBox();
            notAllowAppTime = new TextBox();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            SuspendLayout();
            // 
            // dtpFromDate
            // 
            dtpFromDate.Location = new Point(41, 88);
            dtpFromDate.MaxDate = new DateTime(2024, 5, 25, 0, 0, 0, 0);
            dtpFromDate.MinDate = new DateTime(2021, 8, 29, 23, 11, 22, 629);
            dtpFromDate.Name = "dtpFromDate";
            dtpFromDate.Size = new Size(200, 23);
            dtpFromDate.TabIndex = 0;
            dtpFromDate.Value = new DateTime(2024, 5, 25, 0, 0, 0, 0);
            dtpFromDate.ValueChanged += DateTimePickerFromDate_ValueChanged;
            // 
            // dtpUntilDate
            // 
            dtpUntilDate.Location = new Point(320, 88);
            dtpUntilDate.MaxDate = new DateTime(2027, 2, 18, 23, 11, 22, 631);
            dtpUntilDate.MinDate = new DateTime(2024, 5, 25, 0, 0, 0, 0);
            dtpUntilDate.Name = "dtpUntilDate";
            dtpUntilDate.Size = new Size(200, 23);
            dtpUntilDate.TabIndex = 1;
            dtpUntilDate.ValueChanged += DateTimePickerUntilDate_ValueChanged;
            // 
            // lblDateRangeDescription
            // 
            lblDateRangeDescription.AutoSize = true;
            lblDateRangeDescription.Font = new Font("Segoe UI", 26.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblDateRangeDescription.Location = new Point(12, 26);
            lblDateRangeDescription.Name = "lblDateRangeDescription";
            lblDateRangeDescription.Size = new Size(397, 47);
            lblDateRangeDescription.TabIndex = 2;
            lblDateRangeDescription.Text = "Ajuste de Rango de dias";
            // 
            // tBoxUntilDate
            // 
            tBoxUntilDate.Location = new Point(526, 88);
            tBoxUntilDate.Name = "tBoxUntilDate";
            tBoxUntilDate.PlaceholderText = "000";
            tBoxUntilDate.Size = new Size(28, 23);
            tBoxUntilDate.TabIndex = 4;
            tBoxUntilDate.TextAlign = HorizontalAlignment.Center;
            tBoxUntilDate.TextChanged += TextBoxUntilDate_TextChanged;
            tBoxUntilDate.KeyPress += TextBox_KeyPress;
            // 
            // tBoxFromDate
            // 
            tBoxFromDate.Location = new Point(247, 88);
            tBoxFromDate.Name = "tBoxFromDate";
            tBoxFromDate.PlaceholderText = "000";
            tBoxFromDate.Size = new Size(28, 23);
            tBoxFromDate.TabIndex = 5;
            tBoxFromDate.TextAlign = HorizontalAlignment.Center;
            tBoxFromDate.TextChanged += TextBoxFromDate_TextChanged;
            tBoxFromDate.KeyPress += TextBox_KeyPress;
            // 
            // SetControl
            // 
            SetControl.AutoSize = true;
            SetControl.Location = new Point(861, 611);
            SetControl.Name = "SetControl";
            SetControl.Size = new Size(137, 40);
            SetControl.TabIndex = 6;
            SetControl.Text = "Establecer Valores";
            SetControl.UseVisualStyleBackColor = true;
            SetControl.Click += SetControl_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(82, 114);
            label1.Name = "label1";
            label1.Size = new Size(92, 17);
            label1.TabIndex = 7;
            label1.Text = "Rango Inferior";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label2.Location = new Point(369, 114);
            label2.Name = "label2";
            label2.Size = new Size(100, 17);
            label2.TabIndex = 8;
            label2.Text = "Rango Superior";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 26.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label3.Location = new Point(12, 181);
            label3.Name = "label3";
            label3.Size = new Size(151, 47);
            label3.TabIndex = 9;
            label3.Text = "Tiempos";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label4.Location = new Point(48, 286);
            label4.Name = "label4";
            label4.Size = new Size(143, 25);
            label4.TabIndex = 10;
            label4.Text = "Tiempo Dismiss";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label5.Location = new Point(48, 240);
            label5.Name = "label5";
            label5.Size = new Size(142, 25);
            label5.TabIndex = 11;
            label5.Text = "Tiempo Snooze";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label6.Location = new Point(48, 331);
            label6.Name = "label6";
            label6.Size = new Size(227, 25);
            label6.TabIndex = 12;
            label6.Text = "Tiempo App no permitida";
            // 
            // dismissTime
            // 
            dismissTime.Location = new Point(320, 242);
            dismissTime.Name = "dismissTime";
            dismissTime.PlaceholderText = "000";
            dismissTime.Size = new Size(28, 23);
            dismissTime.TabIndex = 13;
            dismissTime.TextAlign = HorizontalAlignment.Center;
            // 
            // snoozeTime
            // 
            snoozeTime.Location = new Point(320, 286);
            snoozeTime.Name = "snoozeTime";
            snoozeTime.PlaceholderText = "000";
            snoozeTime.Size = new Size(28, 23);
            snoozeTime.TabIndex = 14;
            snoozeTime.TextAlign = HorizontalAlignment.Center;
            // 
            // notAllowAppTime
            // 
            notAllowAppTime.Location = new Point(320, 331);
            notAllowAppTime.Name = "notAllowAppTime";
            notAllowAppTime.PlaceholderText = "000";
            notAllowAppTime.Size = new Size(28, 23);
            notAllowAppTime.TabIndex = 15;
            notAllowAppTime.TextAlign = HorizontalAlignment.Center;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label7.Location = new Point(354, 248);
            label7.Name = "label7";
            label7.Size = new Size(54, 17);
            label7.TabIndex = 16;
            label7.Text = "Minutes";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label8.Location = new Point(354, 292);
            label8.Name = "label8";
            label8.Size = new Size(54, 17);
            label8.TabIndex = 17;
            label8.Text = "Minutes";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label9.Location = new Point(354, 339);
            label9.Name = "label9";
            label9.Size = new Size(54, 17);
            label9.TabIndex = 18;
            label9.Text = "Minutes";
            // 
            // SettingsForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1096, 800);
            Controls.Add(label9);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(notAllowAppTime);
            Controls.Add(snoozeTime);
            Controls.Add(dismissTime);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(SetControl);
            Controls.Add(tBoxFromDate);
            Controls.Add(tBoxUntilDate);
            Controls.Add(lblDateRangeDescription);
            Controls.Add(dtpUntilDate);
            Controls.Add(dtpFromDate);
            FormBorderStyle = FormBorderStyle.None;
            MinimumSize = new Size(1096, 800);
            Name = "SettingsForm";
            Text = "SettingsForm";
            Load += SettingsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DateTimePicker dtpFromDate;
        private DateTimePicker dtpUntilDate;
        private Label lblDateRangeDescription;
        private TextBox tBoxUntilDate;
        private TextBox tBoxFromDate;
        private Button SetControl;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private TextBox dismissTime;
        private TextBox snoozeTime;
        private TextBox notAllowAppTime;
        private Label label7;
        private Label label8;
        private Label label9;
    }
}