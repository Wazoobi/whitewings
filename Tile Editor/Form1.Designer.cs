namespace WindowsFormsApplication1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.grpBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btndelall = new System.Windows.Forms.Button();
            this.btndellayer = new System.Windows.Forms.Button();
            this.lblLayers = new System.Windows.Forms.Label();
            this.lblDrawOpts = new System.Windows.Forms.Label();
            this.btnLayerDown = new System.Windows.Forms.Button();
            this.btnLayerUp = new System.Windows.Forms.Button();
            this.btnTile = new System.Windows.Forms.Button();
            this.btnFill = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabSelection = new System.Windows.Forms.TabControl();
            this.tabTiles = new System.Windows.Forms.TabPage();
            this.vScrollBar2 = new System.Windows.Forms.VScrollBar();
            this.hScrollBar2 = new System.Windows.Forms.HScrollBar();
            this.tabItems = new System.Windows.Forms.TabPage();
            this.Image_Timer = new System.Windows.Forms.Timer(this.components);
            this.Tiles_Timer = new System.Windows.Forms.Timer(this.components);
            this.ImageViewPort = new System.Windows.Forms.Panel();
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.hScrollBar1 = new System.Windows.Forms.HScrollBar();
            this.RCImagePort = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.TriggerOption = new System.Windows.Forms.ToolStripMenuItem();
            this.collideableTileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.rNone = new System.Windows.Forms.RadioButton();
            this.rCollision = new System.Windows.Forms.RadioButton();
            this.rTrigger = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.numericUpDown3 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown4 = new System.Windows.Forms.NumericUpDown();
            this.grpBox1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.tabSelection.SuspendLayout();
            this.tabTiles.SuspendLayout();
            this.ImageViewPort.SuspendLayout();
            this.RCImagePort.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown4)).BeginInit();
            this.SuspendLayout();
            // 
            // grpBox1
            // 
            this.grpBox1.Controls.Add(this.label1);
            this.grpBox1.Controls.Add(this.btndelall);
            this.grpBox1.Controls.Add(this.btndellayer);
            this.grpBox1.Controls.Add(this.lblLayers);
            this.grpBox1.Controls.Add(this.lblDrawOpts);
            this.grpBox1.Controls.Add(this.btnLayerDown);
            this.grpBox1.Controls.Add(this.btnLayerUp);
            this.grpBox1.Controls.Add(this.btnTile);
            this.grpBox1.Controls.Add(this.btnFill);
            this.grpBox1.Location = new System.Drawing.Point(935, 34);
            this.grpBox1.Name = "grpBox1";
            this.grpBox1.Size = new System.Drawing.Size(334, 126);
            this.grpBox1.TabIndex = 1;
            this.grpBox1.TabStop = false;
            this.grpBox1.Text = "Options";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(249, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Clear";
            // 
            // btndelall
            // 
            this.btndelall.Location = new System.Drawing.Point(234, 86);
            this.btndelall.Name = "btndelall";
            this.btndelall.Size = new System.Drawing.Size(75, 23);
            this.btndelall.TabIndex = 6;
            this.btndelall.Text = "Delete All";
            this.btndelall.UseVisualStyleBackColor = true;
            this.btndelall.Click += new System.EventHandler(this.btndelall_Click);
            // 
            // btndellayer
            // 
            this.btndellayer.Location = new System.Drawing.Point(234, 48);
            this.btndellayer.Name = "btndellayer";
            this.btndellayer.Size = new System.Drawing.Size(75, 23);
            this.btndellayer.TabIndex = 5;
            this.btndellayer.Text = "Delete Layer";
            this.btndellayer.UseVisualStyleBackColor = true;
            this.btndellayer.Click += new System.EventHandler(this.btndellayer_Click);
            // 
            // lblLayers
            // 
            this.lblLayers.AutoSize = true;
            this.lblLayers.Location = new System.Drawing.Point(136, 22);
            this.lblLayers.Name = "lblLayers";
            this.lblLayers.Size = new System.Drawing.Size(47, 13);
            this.lblLayers.TabIndex = 4;
            this.lblLayers.Text = "Layering";
            // 
            // lblDrawOpts
            // 
            this.lblDrawOpts.AutoSize = true;
            this.lblDrawOpts.Location = new System.Drawing.Point(19, 22);
            this.lblDrawOpts.Name = "lblDrawOpts";
            this.lblDrawOpts.Size = new System.Drawing.Size(71, 13);
            this.lblDrawOpts.TabIndex = 4;
            this.lblDrawOpts.Text = "Draw Options";
            // 
            // btnLayerDown
            // 
            this.btnLayerDown.Location = new System.Drawing.Point(124, 86);
            this.btnLayerDown.Name = "btnLayerDown";
            this.btnLayerDown.Size = new System.Drawing.Size(75, 23);
            this.btnLayerDown.TabIndex = 3;
            this.btnLayerDown.Text = "Layer Down";
            this.btnLayerDown.UseVisualStyleBackColor = true;
            this.btnLayerDown.Click += new System.EventHandler(this.btnLayerDown_Click);
            // 
            // btnLayerUp
            // 
            this.btnLayerUp.Location = new System.Drawing.Point(124, 48);
            this.btnLayerUp.Name = "btnLayerUp";
            this.btnLayerUp.Size = new System.Drawing.Size(75, 23);
            this.btnLayerUp.TabIndex = 2;
            this.btnLayerUp.Text = "Layer Up";
            this.btnLayerUp.UseVisualStyleBackColor = true;
            this.btnLayerUp.Click += new System.EventHandler(this.btnLayerUp_Click);
            // 
            // btnTile
            // 
            this.btnTile.Location = new System.Drawing.Point(15, 48);
            this.btnTile.Name = "btnTile";
            this.btnTile.Size = new System.Drawing.Size(75, 23);
            this.btnTile.TabIndex = 1;
            this.btnTile.Text = "Tile";
            this.btnTile.UseVisualStyleBackColor = true;
            this.btnTile.Click += new System.EventHandler(this.btnTile_Click);
            // 
            // btnFill
            // 
            this.btnFill.Location = new System.Drawing.Point(15, 86);
            this.btnFill.Name = "btnFill";
            this.btnFill.Size = new System.Drawing.Size(75, 23);
            this.btnFill.TabIndex = 0;
            this.btnFill.Text = "Fill";
            this.btnFill.UseVisualStyleBackColor = true;
            this.btnFill.Click += new System.EventHandler(this.btnFill_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1300, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.importToolStripMenuItem,
            this.exportToolStripMenuItem,
            this.toolStripSeparator,
            this.saveToolStripMenuItem,
            this.toolStripSeparator1,
            this.toolStripSeparator2,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("newToolStripMenuItem.Image")));
            this.newToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.newToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.newToolStripMenuItem.Text = "&New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
            this.openToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.openToolStripMenuItem.Text = "&Open";
            // 
            // importToolStripMenuItem
            // 
            this.importToolStripMenuItem.Name = "importToolStripMenuItem";
            this.importToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.importToolStripMenuItem.Text = "Import Image";
            this.importToolStripMenuItem.Click += new System.EventHandler(this.importToolStripMenuItem_Click);
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exportToolStripMenuItem.Text = "Export Image";
            this.exportToolStripMenuItem.Click += new System.EventHandler(this.exportToolStripMenuItem_Click);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(149, 6);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripMenuItem.Image")));
            this.saveToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(149, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // tabSelection
            // 
            this.tabSelection.Controls.Add(this.tabTiles);
            this.tabSelection.Controls.Add(this.tabItems);
            this.tabSelection.Location = new System.Drawing.Point(935, 259);
            this.tabSelection.Name = "tabSelection";
            this.tabSelection.SelectedIndex = 0;
            this.tabSelection.Size = new System.Drawing.Size(328, 346);
            this.tabSelection.TabIndex = 5;
            // 
            // tabTiles
            // 
            this.tabTiles.Controls.Add(this.vScrollBar2);
            this.tabTiles.Controls.Add(this.hScrollBar2);
            this.tabTiles.Location = new System.Drawing.Point(4, 22);
            this.tabTiles.Name = "tabTiles";
            this.tabTiles.Padding = new System.Windows.Forms.Padding(3);
            this.tabTiles.Size = new System.Drawing.Size(320, 320);
            this.tabTiles.TabIndex = 0;
            this.tabTiles.Text = "Tile Set";
            this.tabTiles.UseVisualStyleBackColor = true;
            this.tabTiles.MouseClick += new System.Windows.Forms.MouseEventHandler(this.tabTiles_MouseClick);
            // 
            // vScrollBar2
            // 
            this.vScrollBar2.Location = new System.Drawing.Point(303, 0);
            this.vScrollBar2.Name = "vScrollBar2";
            this.vScrollBar2.Size = new System.Drawing.Size(17, 307);
            this.vScrollBar2.TabIndex = 1;
            // 
            // hScrollBar2
            // 
            this.hScrollBar2.Location = new System.Drawing.Point(-4, 307);
            this.hScrollBar2.Name = "hScrollBar2";
            this.hScrollBar2.Size = new System.Drawing.Size(324, 17);
            this.hScrollBar2.TabIndex = 0;
            // 
            // tabItems
            // 
            this.tabItems.Location = new System.Drawing.Point(4, 22);
            this.tabItems.Name = "tabItems";
            this.tabItems.Padding = new System.Windows.Forms.Padding(3);
            this.tabItems.Size = new System.Drawing.Size(320, 320);
            this.tabItems.TabIndex = 1;
            this.tabItems.Text = "Items";
            this.tabItems.UseVisualStyleBackColor = true;
            // 
            // Image_Timer
            // 
            this.Image_Timer.Interval = 50;
            this.Image_Timer.Tick += new System.EventHandler(this.Image_Timer_Tick);
            // 
            // Tiles_Timer
            // 
            this.Tiles_Timer.Interval = 16;
            this.Tiles_Timer.Tick += new System.EventHandler(this.Tiles_Timer_Tick);
            // 
            // ImageViewPort
            // 
            this.ImageViewPort.AutoScroll = true;
            this.ImageViewPort.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ImageViewPort.Controls.Add(this.vScrollBar1);
            this.ImageViewPort.Controls.Add(this.hScrollBar1);
            this.ImageViewPort.Location = new System.Drawing.Point(39, 56);
            this.ImageViewPort.Name = "ImageViewPort";
            this.ImageViewPort.Size = new System.Drawing.Size(800, 600);
            this.ImageViewPort.TabIndex = 7;
            this.ImageViewPort.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ImageViewPort_MouseMove);
            this.ImageViewPort.MouseClick += new System.Windows.Forms.MouseEventHandler(this.ImageViewPort_MouseClick);
            this.ImageViewPort.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ImageViewPort_MouseDown);
            this.ImageViewPort.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ImageViewPort_MouseUp);
            // 
            // vScrollBar1
            // 
            this.vScrollBar1.LargeChange = 1000;
            this.vScrollBar1.Location = new System.Drawing.Point(782, 0);
            this.vScrollBar1.Maximum = 32768;
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Size = new System.Drawing.Size(18, 583);
            this.vScrollBar1.SmallChange = 1000;
            this.vScrollBar1.TabIndex = 1;
            // 
            // hScrollBar1
            // 
            this.hScrollBar1.LargeChange = 1000;
            this.hScrollBar1.Location = new System.Drawing.Point(0, 583);
            this.hScrollBar1.Maximum = 32768;
            this.hScrollBar1.Name = "hScrollBar1";
            this.hScrollBar1.Size = new System.Drawing.Size(800, 17);
            this.hScrollBar1.TabIndex = 0;
            // 
            // RCImagePort
            // 
            this.RCImagePort.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.TriggerOption,
            this.collideableTileToolStripMenuItem});
            this.RCImagePort.Name = "RCImagePort";
            this.RCImagePort.Size = new System.Drawing.Size(149, 48);
            this.RCImagePort.Opening += new System.ComponentModel.CancelEventHandler(this.RCImagePort_Opening);
            // 
            // TriggerOption
            // 
            this.TriggerOption.Name = "TriggerOption";
            this.TriggerOption.Size = new System.Drawing.Size(148, 22);
            this.TriggerOption.Text = "Trigger";
            this.TriggerOption.Click += new System.EventHandler(this.TriggerOption_Click);
            // 
            // collideableTileToolStripMenuItem
            // 
            this.collideableTileToolStripMenuItem.Name = "collideableTileToolStripMenuItem";
            this.collideableTileToolStripMenuItem.Size = new System.Drawing.Size(148, 22);
            this.collideableTileToolStripMenuItem.Text = "Collide-able Tile";
            this.collideableTileToolStripMenuItem.Click += new System.EventHandler(this.collideableTileToolStripMenuItem_Click);
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(1147, 181);
            this.numericUpDown1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(49, 20);
            this.numericUpDown1.TabIndex = 8;
            this.numericUpDown1.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Location = new System.Drawing.Point(1220, 181);
            this.numericUpDown2.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(49, 20);
            this.numericUpDown2.TabIndex = 8;
            this.numericUpDown2.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.numericUpDown2.ValueChanged += new System.EventHandler(this.numericUpDown2_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1175, 163);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Tile Size";
            // 
            // rNone
            // 
            this.rNone.AutoSize = true;
            this.rNone.Checked = true;
            this.rNone.Location = new System.Drawing.Point(950, 181);
            this.rNone.Name = "rNone";
            this.rNone.Size = new System.Drawing.Size(51, 17);
            this.rNone.TabIndex = 10;
            this.rNone.TabStop = true;
            this.rNone.Text = "None";
            this.rNone.UseVisualStyleBackColor = true;
            // 
            // rCollision
            // 
            this.rCollision.AutoSize = true;
            this.rCollision.Location = new System.Drawing.Point(950, 204);
            this.rCollision.Name = "rCollision";
            this.rCollision.Size = new System.Drawing.Size(63, 17);
            this.rCollision.TabIndex = 10;
            this.rCollision.Text = "Collision";
            this.rCollision.UseVisualStyleBackColor = true;
            // 
            // rTrigger
            // 
            this.rTrigger.AutoSize = true;
            this.rTrigger.Location = new System.Drawing.Point(950, 227);
            this.rTrigger.Name = "rTrigger";
            this.rTrigger.Size = new System.Drawing.Size(58, 17);
            this.rTrigger.TabIndex = 10;
            this.rTrigger.Text = "Trigger";
            this.rTrigger.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(1019, 210);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(88, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "Current Layer = 1";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(1175, 210);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 13);
            this.label4.TabIndex = 12;
            this.label4.Text = "Level Size";
            // 
            // numericUpDown3
            // 
            this.numericUpDown3.Increment = new decimal(new int[] {
            128,
            0,
            0,
            0});
            this.numericUpDown3.Location = new System.Drawing.Point(1110, 233);
            this.numericUpDown3.Maximum = new decimal(new int[] {
            32768,
            0,
            0,
            0});
            this.numericUpDown3.Name = "numericUpDown3";
            this.numericUpDown3.Size = new System.Drawing.Size(86, 20);
            this.numericUpDown3.TabIndex = 13;
            this.numericUpDown3.Value = new decimal(new int[] {
            25000,
            0,
            0,
            0});
            this.numericUpDown3.ValueChanged += new System.EventHandler(this.numericUpDown3_ValueChanged);
            // 
            // numericUpDown4
            // 
            this.numericUpDown4.Increment = new decimal(new int[] {
            128,
            0,
            0,
            0});
            this.numericUpDown4.Location = new System.Drawing.Point(1210, 233);
            this.numericUpDown4.Maximum = new decimal(new int[] {
            32768,
            0,
            0,
            0});
            this.numericUpDown4.Name = "numericUpDown4";
            this.numericUpDown4.Size = new System.Drawing.Size(78, 20);
            this.numericUpDown4.TabIndex = 14;
            this.numericUpDown4.Value = new decimal(new int[] {
            25000,
            0,
            0,
            0});
            this.numericUpDown4.ValueChanged += new System.EventHandler(this.numericUpDown4_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(1300, 680);
            this.Controls.Add(this.numericUpDown4);
            this.Controls.Add(this.numericUpDown3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.rNone);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.rCollision);
            this.Controls.Add(this.rTrigger);
            this.Controls.Add(this.ImageViewPort);
            this.Controls.Add(this.tabSelection);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.grpBox1);
            this.Controls.Add(this.numericUpDown2);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.numericUpDown1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "White Wings Tile Editor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grpBox1.ResumeLayout(false);
            this.grpBox1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabSelection.ResumeLayout(false);
            this.tabTiles.ResumeLayout(false);
            this.ImageViewPort.ResumeLayout(false);
            this.RCImagePort.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown4)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox grpBox1;
        private System.Windows.Forms.Button btnTile;
        private System.Windows.Forms.Button btnFill;
        private System.Windows.Forms.Button btnLayerUp;
        private System.Windows.Forms.Label lblDrawOpts;
        private System.Windows.Forms.Button btnLayerDown;
        private System.Windows.Forms.Label lblLayers;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btndelall;
        private System.Windows.Forms.Button btndellayer;
        private System.Windows.Forms.TabControl tabSelection;
        private System.Windows.Forms.TabPage tabTiles;
        private System.Windows.Forms.TabPage tabItems;
        private System.Windows.Forms.Timer Image_Timer;
        private System.Windows.Forms.Timer Tiles_Timer;
        private System.Windows.Forms.ToolStripMenuItem importToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.Panel ImageViewPort;
        private System.Windows.Forms.ContextMenuStrip RCImagePort;
        private System.Windows.Forms.ToolStripMenuItem TriggerOption;
        private System.Windows.Forms.ToolStripMenuItem collideableTileToolStripMenuItem;
        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.HScrollBar hScrollBar1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.VScrollBar vScrollBar2;
        private System.Windows.Forms.HScrollBar hScrollBar2;
        private System.Windows.Forms.RadioButton rNone;
        private System.Windows.Forms.RadioButton rCollision;
        private System.Windows.Forms.RadioButton rTrigger;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDown3;
        private System.Windows.Forms.NumericUpDown numericUpDown4;
    }
}

