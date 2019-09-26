namespace Interface_PLS_PCRegistry
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.ComOpen = new System.Windows.Forms.Button();
            this.ComClose = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // ComOpen
            // 
            this.ComOpen.Location = new System.Drawing.Point(12, 12);
            this.ComOpen.Name = "ComOpen";
            this.ComOpen.Size = new System.Drawing.Size(113, 51);
            this.ComOpen.TabIndex = 0;
            this.ComOpen.Text = "Connect";
            this.ComOpen.UseVisualStyleBackColor = true;
            this.ComOpen.Click += new System.EventHandler(this.ComOpen_Click);
            // 
            // ComClose
            // 
            this.ComClose.Enabled = false;
            this.ComClose.Location = new System.Drawing.Point(140, 12);
            this.ComClose.Name = "ComClose";
            this.ComClose.Size = new System.Drawing.Size(113, 51);
            this.ComClose.TabIndex = 1;
            this.ComClose.Text = "Disconnect";
            this.ComClose.UseVisualStyleBackColor = true;
            this.ComClose.Click += new System.EventHandler(this.ComClose_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(265, 81);
            this.Controls.Add(this.ComClose);
            this.Controls.Add(this.ComOpen);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "PLC Registry Control";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button ComOpen;
        private System.Windows.Forms.Button ComClose;
        private System.Windows.Forms.Timer timer1;
    }
}

