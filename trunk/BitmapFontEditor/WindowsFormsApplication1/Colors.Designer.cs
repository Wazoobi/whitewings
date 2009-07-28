namespace WindowsFormsApplication1
{
    partial class Colors
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
            this.BackgroundColorButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.TransparencyColorButton = new System.Windows.Forms.Button();
            this.RectangleColorButton = new System.Windows.Forms.Button();
            this.OKButton = new System.Windows.Forms.Button();
            this.Cancel = new System.Windows.Forms.Button();
            this.DisplayColorButton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BackgroundColorButton
            // 
            this.BackgroundColorButton.BackColor = System.Drawing.Color.White;
            this.BackgroundColorButton.Location = new System.Drawing.Point(90, 12);
            this.BackgroundColorButton.Name = "BackgroundColorButton";
            this.BackgroundColorButton.Size = new System.Drawing.Size(75, 23);
            this.BackgroundColorButton.TabIndex = 0;
            this.BackgroundColorButton.Text = " ";
            this.BackgroundColorButton.UseVisualStyleBackColor = false;
            this.BackgroundColorButton.Click += new System.EventHandler(this.BackgroundColorButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Background";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Transparency";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 75);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "Rectangle";
            // 
            // TransparencyColorButton
            // 
            this.TransparencyColorButton.BackColor = System.Drawing.Color.Black;
            this.TransparencyColorButton.Location = new System.Drawing.Point(90, 41);
            this.TransparencyColorButton.Name = "TransparencyColorButton";
            this.TransparencyColorButton.Size = new System.Drawing.Size(75, 23);
            this.TransparencyColorButton.TabIndex = 4;
            this.TransparencyColorButton.Text = " ";
            this.TransparencyColorButton.UseVisualStyleBackColor = false;
            this.TransparencyColorButton.Click += new System.EventHandler(this.TransparencyColorButton_Click);
            // 
            // RectangleColorButton
            // 
            this.RectangleColorButton.BackColor = System.Drawing.Color.Green;
            this.RectangleColorButton.Location = new System.Drawing.Point(90, 70);
            this.RectangleColorButton.Name = "RectangleColorButton";
            this.RectangleColorButton.Size = new System.Drawing.Size(75, 23);
            this.RectangleColorButton.TabIndex = 5;
            this.RectangleColorButton.Text = " ";
            this.RectangleColorButton.UseVisualStyleBackColor = false;
            this.RectangleColorButton.Click += new System.EventHandler(this.RectangleColorButton_Click);
            // 
            // OKButton
            // 
            this.OKButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.OKButton.Location = new System.Drawing.Point(15, 128);
            this.OKButton.Name = "OKButton";
            this.OKButton.Size = new System.Drawing.Size(150, 23);
            this.OKButton.TabIndex = 6;
            this.OKButton.Text = "OK";
            this.OKButton.UseVisualStyleBackColor = true;
            // 
            // Cancel
            // 
            this.Cancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.Cancel.Location = new System.Drawing.Point(15, 157);
            this.Cancel.Name = "Cancel";
            this.Cancel.Size = new System.Drawing.Size(150, 23);
            this.Cancel.TabIndex = 7;
            this.Cancel.Text = "Cancel";
            this.Cancel.UseVisualStyleBackColor = true;
            // 
            // DisplayColorButton
            // 
            this.DisplayColorButton.BackColor = System.Drawing.Color.White;
            this.DisplayColorButton.Location = new System.Drawing.Point(90, 99);
            this.DisplayColorButton.Name = "DisplayColorButton";
            this.DisplayColorButton.Size = new System.Drawing.Size(75, 23);
            this.DisplayColorButton.TabIndex = 9;
            this.DisplayColorButton.Text = " ";
            this.DisplayColorButton.UseVisualStyleBackColor = false;
            this.DisplayColorButton.Click += new System.EventHandler(this.DisplayColorButton_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 104);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Display";
            // 
            // Colors
            // 
            this.AcceptButton = this.OKButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.Cancel;
            this.ClientSize = new System.Drawing.Size(182, 189);
            this.Controls.Add(this.DisplayColorButton);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Cancel);
            this.Controls.Add(this.OKButton);
            this.Controls.Add(this.RectangleColorButton);
            this.Controls.Add(this.TransparencyColorButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.BackgroundColorButton);
            this.Name = "Colors";
            this.Text = "Colors";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BackgroundColorButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button TransparencyColorButton;
        private System.Windows.Forms.Button RectangleColorButton;
        private System.Windows.Forms.Button OKButton;
        private System.Windows.Forms.Button Cancel;
        private System.Windows.Forms.Button DisplayColorButton;
        private System.Windows.Forms.Label label4;
    }
}