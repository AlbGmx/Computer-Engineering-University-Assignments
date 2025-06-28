namespace SchoolSync
{
    partial class BlockedAppsForm
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
            button1 = new Button();
            listView1 = new ListView();
            button2 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(12, 20);
            label1.Name = "label1";
            label1.Size = new Size(280, 45);
            label1.TabIndex = 0;
            label1.Text = "Not Allowed Apps";
            // 
            // button1
            // 
            button1.Location = new Point(791, 30);
            button1.Name = "button1";
            button1.Size = new Size(139, 43);
            button1.TabIndex = 1;
            button1.Text = "Add App";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // listView1
            // 
            listView1.Location = new Point(12, 79);
            listView1.Name = "listView1";
            listView1.Size = new Size(1063, 628);
            listView1.TabIndex = 2;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.View = View.Details;
            // 
            // button2
            // 
            button2.Location = new Point(936, 30);
            button2.Name = "button2";
            button2.Size = new Size(139, 43);
            button2.TabIndex = 3;
            button2.Text = "Remove App";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // BlockedAppsForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1096, 800);
            Controls.Add(button2);
            Controls.Add(listView1);
            Controls.Add(button1);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.None;
            MinimumSize = new Size(1096, 800);
            Name = "BlockedAppsForm";
            Text = "Form2";
            Load += BlockedAppsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button button1;
        private ListView listView1;
        private Button button2;
    }
}