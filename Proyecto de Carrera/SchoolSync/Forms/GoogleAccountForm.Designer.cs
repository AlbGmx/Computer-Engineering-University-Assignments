namespace SchoolSync.Forms
{
    partial class GoogleAccountForm
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
            label1 = new Label();
            LoginControl = new Button();
            LabelLoginDescription = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(564, 217);
            label1.Name = "label1";
            label1.Size = new Size(185, 32);
            label1.TabIndex = 0;
            label1.Text = "Google Account";
            // 
            // LoginControl
            // 
            LoginControl.AutoSize = true;
            LoginControl.Location = new Point(609, 468);
            LoginControl.Name = "LoginControl";
            LoginControl.Size = new Size(86, 25);
            LoginControl.TabIndex = 1;
            LoginControl.Text = "Iniciar Sesión";
            LoginControl.UseVisualStyleBackColor = true;
            LoginControl.Click += LoginControl_Clicked;
            // 
            // LabelLoginDescription
            // 
            LabelLoginDescription.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            LabelLoginDescription.AutoEllipsis = true;
            LabelLoginDescription.AutoSize = true;
            LabelLoginDescription.Location = new Point(484, 378);
            LabelLoginDescription.Name = "LabelLoginDescription";
            LabelLoginDescription.Size = new Size(353, 15);
            LabelLoginDescription.TabIndex = 2;
            LabelLoginDescription.Text = "Inicia sesión con tu cuenta de Google para sincronizar tus eventos";
            LabelLoginDescription.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // GoogleAccountForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1296, 800);
            Controls.Add(LabelLoginDescription);
            Controls.Add(LoginControl);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.None;
            MinimumSize = new Size(1296, 800);
            Name = "GoogleAccountForm";
            Text = "GoogleAccountForm";
            Load += GoogleAccountForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button LoginControl;
        private Label LabelLoginDescription;
    }
}