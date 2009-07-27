namespace WindowsFormsApplication1
{
    partial class ImportDialog
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
            this.TileRadio = new System.Windows.Forms.RadioButton();
            this.ItemRadio = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.BackgroundRadio = new System.Windows.Forms.RadioButton();
            this.SuspendLayout();
            // 
            // TileRadio
            // 
            this.TileRadio.AutoSize = true;
            this.TileRadio.Location = new System.Drawing.Point(12, 25);
            this.TileRadio.Name = "TileRadio";
            this.TileRadio.Size = new System.Drawing.Size(61, 17);
            this.TileRadio.TabIndex = 0;
            this.TileRadio.TabStop = true;
            this.TileRadio.Text = "Tile Set";
            this.TileRadio.UseVisualStyleBackColor = true;
            // 
            // ItemRadio
            // 
            this.ItemRadio.AutoSize = true;
            this.ItemRadio.Location = new System.Drawing.Point(12, 48);
            this.ItemRadio.Name = "ItemRadio";
            this.ItemRadio.Size = new System.Drawing.Size(45, 17);
            this.ItemRadio.TabIndex = 0;
            this.ItemRadio.TabStop = true;
            this.ItemRadio.Text = "Item";
            this.ItemRadio.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Image Type";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(94, 42);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 2;
            this.button1.Text = "Confirm";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // BackgroundRadio
            // 
            this.BackgroundRadio.AutoSize = true;
            this.BackgroundRadio.Location = new System.Drawing.Point(12, 72);
            this.BackgroundRadio.Name = "BackgroundRadio";
            this.BackgroundRadio.Size = new System.Drawing.Size(115, 17);
            this.BackgroundRadio.TabIndex = 3;
            this.BackgroundRadio.TabStop = true;
            this.BackgroundRadio.Text = "Background Image";
            this.BackgroundRadio.UseVisualStyleBackColor = true;
            // 
            // ImportDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(181, 106);
            this.Controls.Add(this.BackgroundRadio);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ItemRadio);
            this.Controls.Add(this.TileRadio);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ImportDialog";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Import";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton TileRadio;
        private System.Windows.Forms.RadioButton ItemRadio;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RadioButton BackgroundRadio;
    }
}