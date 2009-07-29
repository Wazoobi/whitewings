namespace Animation_Editor
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
            this.FrameBox = new System.Windows.Forms.ListBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.openXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadSpriteSheetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.collisionRectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.renderRectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.anchorPointToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.weaponPointToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.triggersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guideToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.AnchorX = new System.Windows.Forms.NumericUpDown();
            this.AnchorY = new System.Windows.Forms.NumericUpDown();
            this.WeaponX = new System.Windows.Forms.NumericUpDown();
            this.WeaponY = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.Play = new System.Windows.Forms.Button();
            this.Stop = new System.Windows.Forms.Button();
            this.NextFrame = new System.Windows.Forms.Button();
            this.PrevFrame = new System.Windows.Forms.Button();
            this.AddFrame = new System.Windows.Forms.Button();
            this.DelFrame = new System.Windows.Forms.Button();
            this.Reset = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SpriteSheetPanel = new System.Windows.Forms.Panel();
            this.hSpriteBar = new System.Windows.Forms.HScrollBar();
            this.vSpriteBar = new System.Windows.Forms.VScrollBar();
            this.ImageButton = new System.Windows.Forms.Button();
            this.CollisionButton = new System.Windows.Forms.Button();
            this.AttackButton = new System.Windows.Forms.Button();
            this.WeaponButton = new System.Windows.Forms.Button();
            this.AnchorButton = new System.Windows.Forms.Button();
            this.TriggerName = new System.Windows.Forms.TextBox();
            this.TriggerButton = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.TriggerX = new System.Windows.Forms.NumericUpDown();
            this.TriggerY = new System.Windows.Forms.NumericUpDown();
            this.TriggerBox = new System.Windows.Forms.ListBox();
            this.label8 = new System.Windows.Forms.Label();
            this.DelAnim = new System.Windows.Forms.Button();
            this.AddAnim = new System.Windows.Forms.Button();
            this.AnimBox = new System.Windows.Forms.ListBox();
            this.AnimName = new System.Windows.Forms.TextBox();
            this.AddTrigger = new System.Windows.Forms.Button();
            this.Duration = new System.Windows.Forms.NumericUpDown();
            this.label11 = new System.Windows.Forms.Label();
            this.DelTrigger = new System.Windows.Forms.Button();
            this.isLoopingCheck = new System.Windows.Forms.CheckBox();
            this.ZoomIn = new System.Windows.Forms.Button();
            this.ZoomOut = new System.Windows.Forms.Button();
            this.PreviewAnimPanel = new System.Windows.Forms.Panel();
            this.UpdateButton = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AnchorX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.AnchorY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.WeaponX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.WeaponY)).BeginInit();
            this.SpriteSheetPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TriggerX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TriggerY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Duration)).BeginInit();
            this.SuspendLayout();
            // 
            // FrameBox
            // 
            this.FrameBox.FormattingEnabled = true;
            this.FrameBox.Location = new System.Drawing.Point(269, 406);
            this.FrameBox.Name = "FrameBox";
            this.FrameBox.Size = new System.Drawing.Size(154, 56);
            this.FrameBox.TabIndex = 1;
            this.FrameBox.SelectedIndexChanged += new System.EventHandler(this.FrameBox_SelectedIndexChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(784, 24);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.toolStripSeparator3,
            this.saveToolStripMenuItem,
            this.toolStripSeparator2,
            this.openXMLToolStripMenuItem,
            this.saveXMLToolStripMenuItem,
            this.toolStripSeparator1,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(149, 6);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.saveToolStripMenuItem.Text = "Save Binary";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(149, 6);
            // 
            // openXMLToolStripMenuItem
            // 
            this.openXMLToolStripMenuItem.Name = "openXMLToolStripMenuItem";
            this.openXMLToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.openXMLToolStripMenuItem.Text = "Open XML";
            this.openXMLToolStripMenuItem.Click += new System.EventHandler(this.openXMLToolStripMenuItem_Click);
            // 
            // saveXMLToolStripMenuItem
            // 
            this.saveXMLToolStripMenuItem.Name = "saveXMLToolStripMenuItem";
            this.saveXMLToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.saveXMLToolStripMenuItem.Text = "Save XML";
            this.saveXMLToolStripMenuItem.Click += new System.EventHandler(this.saveXMLToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.loadSpriteSheetToolStripMenuItem,
            this.toolStripSeparator4,
            this.collisionRectToolStripMenuItem,
            this.renderRectToolStripMenuItem,
            this.toolStripSeparator5,
            this.anchorPointToolStripMenuItem,
            this.weaponPointToolStripMenuItem,
            this.triggersToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.toolsToolStripMenuItem.Text = "&Tools";
            // 
            // loadSpriteSheetToolStripMenuItem
            // 
            this.loadSpriteSheetToolStripMenuItem.Name = "loadSpriteSheetToolStripMenuItem";
            this.loadSpriteSheetToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.loadSpriteSheetToolStripMenuItem.Text = "Load Sprite Sheet";
            this.loadSpriteSheetToolStripMenuItem.Click += new System.EventHandler(this.loadSpriteSheetToolStripMenuItem_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(162, 6);
            // 
            // collisionRectToolStripMenuItem
            // 
            this.collisionRectToolStripMenuItem.Name = "collisionRectToolStripMenuItem";
            this.collisionRectToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.collisionRectToolStripMenuItem.Text = "Collision Rects";
            this.collisionRectToolStripMenuItem.Click += new System.EventHandler(this.collisionRectToolStripMenuItem_Click);
            // 
            // renderRectToolStripMenuItem
            // 
            this.renderRectToolStripMenuItem.Name = "renderRectToolStripMenuItem";
            this.renderRectToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.renderRectToolStripMenuItem.Text = "Render Rect";
            this.renderRectToolStripMenuItem.Click += new System.EventHandler(this.renderRectToolStripMenuItem_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(162, 6);
            // 
            // anchorPointToolStripMenuItem
            // 
            this.anchorPointToolStripMenuItem.Name = "anchorPointToolStripMenuItem";
            this.anchorPointToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.anchorPointToolStripMenuItem.Text = "Anchor Point";
            this.anchorPointToolStripMenuItem.Click += new System.EventHandler(this.anchorPointToolStripMenuItem_Click);
            // 
            // weaponPointToolStripMenuItem
            // 
            this.weaponPointToolStripMenuItem.Name = "weaponPointToolStripMenuItem";
            this.weaponPointToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.weaponPointToolStripMenuItem.Text = "Weapon Point";
            this.weaponPointToolStripMenuItem.Click += new System.EventHandler(this.weaponPointToolStripMenuItem_Click);
            // 
            // triggersToolStripMenuItem
            // 
            this.triggersToolStripMenuItem.Name = "triggersToolStripMenuItem";
            this.triggersToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.triggersToolStripMenuItem.Text = "Trigger";
            this.triggersToolStripMenuItem.Click += new System.EventHandler(this.triggersToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.guideToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // guideToolStripMenuItem
            // 
            this.guideToolStripMenuItem.Name = "guideToolStripMenuItem";
            this.guideToolStripMenuItem.Size = new System.Drawing.Size(105, 22);
            this.guideToolStripMenuItem.Text = "Guide";
            // 
            // AnchorX
            // 
            this.AnchorX.Location = new System.Drawing.Point(12, 51);
            this.AnchorX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.AnchorX.Name = "AnchorX";
            this.AnchorX.Size = new System.Drawing.Size(40, 20);
            this.AnchorX.TabIndex = 3;
            this.AnchorX.ValueChanged += new System.EventHandler(this.AnchorX_ValueChanged);
            // 
            // AnchorY
            // 
            this.AnchorY.Location = new System.Drawing.Point(12, 77);
            this.AnchorY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.AnchorY.Name = "AnchorY";
            this.AnchorY.Size = new System.Drawing.Size(40, 20);
            this.AnchorY.TabIndex = 4;
            this.AnchorY.ValueChanged += new System.EventHandler(this.AnchorY_ValueChanged);
            // 
            // WeaponX
            // 
            this.WeaponX.Location = new System.Drawing.Point(82, 51);
            this.WeaponX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.WeaponX.Name = "WeaponX";
            this.WeaponX.Size = new System.Drawing.Size(40, 20);
            this.WeaponX.TabIndex = 5;
            // 
            // WeaponY
            // 
            this.WeaponY.Location = new System.Drawing.Point(82, 77);
            this.WeaponY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.WeaponY.Name = "WeaponY";
            this.WeaponY.Size = new System.Drawing.Size(40, 20);
            this.WeaponY.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Anchor";
            // 
            // Play
            // 
            this.Play.Location = new System.Drawing.Point(269, 498);
            this.Play.Name = "Play";
            this.Play.Size = new System.Drawing.Size(75, 23);
            this.Play.TabIndex = 8;
            this.Play.Text = "Play";
            this.Play.UseVisualStyleBackColor = true;
            this.Play.Click += new System.EventHandler(this.Play_Click);
            // 
            // Stop
            // 
            this.Stop.Location = new System.Drawing.Point(350, 498);
            this.Stop.Name = "Stop";
            this.Stop.Size = new System.Drawing.Size(75, 23);
            this.Stop.TabIndex = 9;
            this.Stop.Text = "Stop";
            this.Stop.UseVisualStyleBackColor = true;
            this.Stop.Click += new System.EventHandler(this.Stop_Click);
            // 
            // NextFrame
            // 
            this.NextFrame.Location = new System.Drawing.Point(350, 469);
            this.NextFrame.Name = "NextFrame";
            this.NextFrame.Size = new System.Drawing.Size(75, 23);
            this.NextFrame.TabIndex = 10;
            this.NextFrame.Text = "Next Frame";
            this.NextFrame.UseVisualStyleBackColor = true;
            this.NextFrame.Click += new System.EventHandler(this.NextFrame_Click);
            // 
            // PrevFrame
            // 
            this.PrevFrame.Location = new System.Drawing.Point(269, 469);
            this.PrevFrame.Name = "PrevFrame";
            this.PrevFrame.Size = new System.Drawing.Size(75, 23);
            this.PrevFrame.TabIndex = 11;
            this.PrevFrame.Text = "Prev. Frame";
            this.PrevFrame.UseVisualStyleBackColor = true;
            this.PrevFrame.Click += new System.EventHandler(this.PrevFrame_Click);
            // 
            // AddFrame
            // 
            this.AddFrame.Location = new System.Drawing.Point(269, 377);
            this.AddFrame.Name = "AddFrame";
            this.AddFrame.Size = new System.Drawing.Size(75, 23);
            this.AddFrame.TabIndex = 12;
            this.AddFrame.Text = "Add Frame";
            this.AddFrame.UseVisualStyleBackColor = true;
            this.AddFrame.Click += new System.EventHandler(this.AddFrame_Click);
            // 
            // DelFrame
            // 
            this.DelFrame.Location = new System.Drawing.Point(350, 377);
            this.DelFrame.Name = "DelFrame";
            this.DelFrame.Size = new System.Drawing.Size(75, 23);
            this.DelFrame.TabIndex = 13;
            this.DelFrame.Text = "Del Frame";
            this.DelFrame.UseVisualStyleBackColor = true;
            this.DelFrame.Click += new System.EventHandler(this.DelFrame_Click);
            // 
            // Reset
            // 
            this.Reset.Location = new System.Drawing.Point(312, 527);
            this.Reset.Name = "Reset";
            this.Reset.Size = new System.Drawing.Size(69, 23);
            this.Reset.TabIndex = 14;
            this.Reset.Text = "Reset";
            this.Reset.UseVisualStyleBackColor = true;
            this.Reset.Click += new System.EventHandler(this.Reset_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(58, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 13);
            this.label2.TabIndex = 15;
            this.label2.Text = "X";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(58, 79);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(14, 13);
            this.label3.TabIndex = 16;
            this.label3.Text = "Y";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(58, 126);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(14, 13);
            this.label4.TabIndex = 17;
            this.label4.Text = "X";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(58, 152);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(14, 13);
            this.label5.TabIndex = 18;
            this.label5.Text = "Y";
            // 
            // SpriteSheetPanel
            // 
            this.SpriteSheetPanel.AutoScroll = true;
            this.SpriteSheetPanel.BackColor = System.Drawing.SystemColors.Menu;
            this.SpriteSheetPanel.Controls.Add(this.hSpriteBar);
            this.SpriteSheetPanel.Controls.Add(this.vSpriteBar);
            this.SpriteSheetPanel.Location = new System.Drawing.Point(217, 71);
            this.SpriteSheetPanel.Name = "SpriteSheetPanel";
            this.SpriteSheetPanel.Size = new System.Drawing.Size(555, 286);
            this.SpriteSheetPanel.TabIndex = 19;
            this.SpriteSheetPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.SpriteSheetPanel_MouseMove);
            this.SpriteSheetPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.SpriteSheetPanel_MouseDown);
            this.SpriteSheetPanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.SpriteSheetPanel_MouseUp);
            // 
            // hSpriteBar
            // 
            this.hSpriteBar.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.hSpriteBar.Location = new System.Drawing.Point(0, 269);
            this.hSpriteBar.Name = "hSpriteBar";
            this.hSpriteBar.Size = new System.Drawing.Size(538, 17);
            this.hSpriteBar.TabIndex = 1;
            this.hSpriteBar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hSpriteBar_Scroll);
            // 
            // vSpriteBar
            // 
            this.vSpriteBar.Dock = System.Windows.Forms.DockStyle.Right;
            this.vSpriteBar.Location = new System.Drawing.Point(538, 0);
            this.vSpriteBar.Name = "vSpriteBar";
            this.vSpriteBar.Size = new System.Drawing.Size(17, 286);
            this.vSpriteBar.TabIndex = 0;
            this.vSpriteBar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vSpriteBar_Scroll);
            // 
            // ImageButton
            // 
            this.ImageButton.Location = new System.Drawing.Point(136, 48);
            this.ImageButton.Name = "ImageButton";
            this.ImageButton.Size = new System.Drawing.Size(75, 23);
            this.ImageButton.TabIndex = 20;
            this.ImageButton.Text = "Image";
            this.ImageButton.UseVisualStyleBackColor = true;
            this.ImageButton.Click += new System.EventHandler(this.ImageButton_Click);
            // 
            // CollisionButton
            // 
            this.CollisionButton.Location = new System.Drawing.Point(136, 79);
            this.CollisionButton.Name = "CollisionButton";
            this.CollisionButton.Size = new System.Drawing.Size(75, 23);
            this.CollisionButton.TabIndex = 21;
            this.CollisionButton.Text = "Collision";
            this.CollisionButton.UseVisualStyleBackColor = true;
            this.CollisionButton.Click += new System.EventHandler(this.CollisionButton_Click);
            // 
            // AttackButton
            // 
            this.AttackButton.Location = new System.Drawing.Point(136, 108);
            this.AttackButton.Name = "AttackButton";
            this.AttackButton.Size = new System.Drawing.Size(75, 23);
            this.AttackButton.TabIndex = 22;
            this.AttackButton.Text = "Attack";
            this.AttackButton.UseVisualStyleBackColor = true;
            this.AttackButton.Click += new System.EventHandler(this.AttackButton_Click);
            // 
            // WeaponButton
            // 
            this.WeaponButton.Location = new System.Drawing.Point(136, 155);
            this.WeaponButton.Name = "WeaponButton";
            this.WeaponButton.Size = new System.Drawing.Size(75, 23);
            this.WeaponButton.TabIndex = 23;
            this.WeaponButton.Text = "Weapon";
            this.WeaponButton.UseVisualStyleBackColor = true;
            this.WeaponButton.Click += new System.EventHandler(this.WeaponButton_Click);
            // 
            // AnchorButton
            // 
            this.AnchorButton.Location = new System.Drawing.Point(136, 184);
            this.AnchorButton.Name = "AnchorButton";
            this.AnchorButton.Size = new System.Drawing.Size(75, 23);
            this.AnchorButton.TabIndex = 24;
            this.AnchorButton.Text = "Anchor";
            this.AnchorButton.UseVisualStyleBackColor = true;
            this.AnchorButton.Click += new System.EventHandler(this.AnchorButton_Click);
            // 
            // TriggerName
            // 
            this.TriggerName.Location = new System.Drawing.Point(135, 215);
            this.TriggerName.Name = "TriggerName";
            this.TriggerName.Size = new System.Drawing.Size(75, 20);
            this.TriggerName.TabIndex = 25;
            // 
            // TriggerButton
            // 
            this.TriggerButton.Location = new System.Drawing.Point(135, 241);
            this.TriggerButton.Name = "TriggerButton";
            this.TriggerButton.Size = new System.Drawing.Size(75, 23);
            this.TriggerButton.TabIndex = 26;
            this.TriggerButton.Text = "Trigger";
            this.TriggerButton.UseVisualStyleBackColor = true;
            this.TriggerButton.Click += new System.EventHandler(this.TriggerButton_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(154, 35);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 13);
            this.label6.TabIndex = 27;
            this.label6.Text = "Rects";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(153, 139);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 13);
            this.label7.TabIndex = 28;
            this.label7.Text = "Points";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(82, 35);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(48, 13);
            this.label9.TabIndex = 30;
            this.label9.Text = "Weapon";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(12, 108);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(40, 13);
            this.label10.TabIndex = 31;
            this.label10.Text = "Trigger";
            // 
            // TriggerX
            // 
            this.TriggerX.Location = new System.Drawing.Point(12, 124);
            this.TriggerX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.TriggerX.Name = "TriggerX";
            this.TriggerX.Size = new System.Drawing.Size(40, 20);
            this.TriggerX.TabIndex = 32;
            // 
            // TriggerY
            // 
            this.TriggerY.Location = new System.Drawing.Point(11, 150);
            this.TriggerY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.TriggerY.Name = "TriggerY";
            this.TriggerY.Size = new System.Drawing.Size(41, 20);
            this.TriggerY.TabIndex = 33;
            // 
            // TriggerBox
            // 
            this.TriggerBox.FormattingEnabled = true;
            this.TriggerBox.Location = new System.Drawing.Point(11, 241);
            this.TriggerBox.Name = "TriggerBox";
            this.TriggerBox.Size = new System.Drawing.Size(111, 95);
            this.TriggerBox.TabIndex = 34;
            this.TriggerBox.SelectedIndexChanged += new System.EventHandler(this.TriggerBox_SelectedIndexChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(39, 184);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(45, 13);
            this.label8.TabIndex = 35;
            this.label8.Text = "Triggers";
            // 
            // DelAnim
            // 
            this.DelAnim.Location = new System.Drawing.Point(27, 400);
            this.DelAnim.Name = "DelAnim";
            this.DelAnim.Size = new System.Drawing.Size(75, 23);
            this.DelAnim.TabIndex = 38;
            this.DelAnim.Text = "Del Anim";
            this.DelAnim.UseVisualStyleBackColor = true;
            this.DelAnim.Click += new System.EventHandler(this.DelAnim_Click);
            // 
            // AddAnim
            // 
            this.AddAnim.Location = new System.Drawing.Point(27, 371);
            this.AddAnim.Name = "AddAnim";
            this.AddAnim.Size = new System.Drawing.Size(75, 23);
            this.AddAnim.TabIndex = 37;
            this.AddAnim.Text = "Add Anim";
            this.AddAnim.UseVisualStyleBackColor = true;
            this.AddAnim.Click += new System.EventHandler(this.AddAnim_Click);
            // 
            // AnimBox
            // 
            this.AnimBox.FormattingEnabled = true;
            this.AnimBox.Location = new System.Drawing.Point(12, 429);
            this.AnimBox.Name = "AnimBox";
            this.AnimBox.Size = new System.Drawing.Size(107, 121);
            this.AnimBox.TabIndex = 36;
            this.AnimBox.SelectedIndexChanged += new System.EventHandler(this.AnimBox_SelectedIndexChanged);
            // 
            // AnimName
            // 
            this.AnimName.Location = new System.Drawing.Point(27, 345);
            this.AnimName.Name = "AnimName";
            this.AnimName.Size = new System.Drawing.Size(75, 20);
            this.AnimName.TabIndex = 40;
            // 
            // AddTrigger
            // 
            this.AddTrigger.Location = new System.Drawing.Point(12, 213);
            this.AddTrigger.Name = "AddTrigger";
            this.AddTrigger.Size = new System.Drawing.Size(45, 23);
            this.AddTrigger.TabIndex = 41;
            this.AddTrigger.Text = "Add Trigger";
            this.AddTrigger.UseVisualStyleBackColor = true;
            this.AddTrigger.Click += new System.EventHandler(this.AddTrigger_Click);
            // 
            // Duration
            // 
            this.Duration.Location = new System.Drawing.Point(136, 295);
            this.Duration.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.Duration.Name = "Duration";
            this.Duration.Size = new System.Drawing.Size(74, 20);
            this.Duration.TabIndex = 42;
            this.Duration.ValueChanged += new System.EventHandler(this.Duration_ValueChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(148, 279);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(47, 13);
            this.label11.TabIndex = 43;
            this.label11.Text = "Duration";
            // 
            // DelTrigger
            // 
            this.DelTrigger.Location = new System.Drawing.Point(75, 212);
            this.DelTrigger.Name = "DelTrigger";
            this.DelTrigger.Size = new System.Drawing.Size(44, 23);
            this.DelTrigger.TabIndex = 44;
            this.DelTrigger.Text = "Del Trigger";
            this.DelTrigger.UseVisualStyleBackColor = true;
            this.DelTrigger.Click += new System.EventHandler(this.DelTrigger_Click);
            // 
            // isLoopingCheck
            // 
            this.isLoopingCheck.AutoSize = true;
            this.isLoopingCheck.Location = new System.Drawing.Point(109, 347);
            this.isLoopingCheck.Name = "isLoopingCheck";
            this.isLoopingCheck.Size = new System.Drawing.Size(70, 17);
            this.isLoopingCheck.TabIndex = 45;
            this.isLoopingCheck.Text = "Looping?";
            this.isLoopingCheck.UseVisualStyleBackColor = true;
            this.isLoopingCheck.CheckedChanged += new System.EventHandler(this.isLoopingCheck_CheckedChanged);
            // 
            // ZoomIn
            // 
            this.ZoomIn.Location = new System.Drawing.Point(242, 48);
            this.ZoomIn.Name = "ZoomIn";
            this.ZoomIn.Size = new System.Drawing.Size(75, 23);
            this.ZoomIn.TabIndex = 46;
            this.ZoomIn.Text = "Zoom In";
            this.ZoomIn.UseVisualStyleBackColor = true;
            this.ZoomIn.Click += new System.EventHandler(this.ZoomIn_Click);
            // 
            // ZoomOut
            // 
            this.ZoomOut.Location = new System.Drawing.Point(323, 48);
            this.ZoomOut.Name = "ZoomOut";
            this.ZoomOut.Size = new System.Drawing.Size(75, 23);
            this.ZoomOut.TabIndex = 47;
            this.ZoomOut.Text = "Zoom Out";
            this.ZoomOut.UseVisualStyleBackColor = true;
            this.ZoomOut.Click += new System.EventHandler(this.ZoomOut_Click);
            // 
            // PreviewAnimPanel
            // 
            this.PreviewAnimPanel.Location = new System.Drawing.Point(462, 377);
            this.PreviewAnimPanel.Name = "PreviewAnimPanel";
            this.PreviewAnimPanel.Size = new System.Drawing.Size(310, 173);
            this.PreviewAnimPanel.TabIndex = 0;
            // 
            // UpdateButton
            // 
            this.UpdateButton.Location = new System.Drawing.Point(166, 419);
            this.UpdateButton.Name = "UpdateButton";
            this.UpdateButton.Size = new System.Drawing.Size(84, 23);
            this.UpdateButton.TabIndex = 48;
            this.UpdateButton.Text = "Update Frame";
            this.UpdateButton.UseVisualStyleBackColor = true;
            this.UpdateButton.Click += new System.EventHandler(this.UpdateButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 562);
            this.Controls.Add(this.UpdateButton);
            this.Controls.Add(this.PreviewAnimPanel);
            this.Controls.Add(this.ZoomOut);
            this.Controls.Add(this.ZoomIn);
            this.Controls.Add(this.isLoopingCheck);
            this.Controls.Add(this.DelTrigger);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.Duration);
            this.Controls.Add(this.AddTrigger);
            this.Controls.Add(this.AnimName);
            this.Controls.Add(this.DelAnim);
            this.Controls.Add(this.AddAnim);
            this.Controls.Add(this.AnimBox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.TriggerBox);
            this.Controls.Add(this.TriggerY);
            this.Controls.Add(this.TriggerX);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.PrevFrame);
            this.Controls.Add(this.Play);
            this.Controls.Add(this.Stop);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.NextFrame);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.Reset);
            this.Controls.Add(this.TriggerButton);
            this.Controls.Add(this.TriggerName);
            this.Controls.Add(this.AnchorButton);
            this.Controls.Add(this.WeaponButton);
            this.Controls.Add(this.AttackButton);
            this.Controls.Add(this.CollisionButton);
            this.Controls.Add(this.ImageButton);
            this.Controls.Add(this.SpriteSheetPanel);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.DelFrame);
            this.Controls.Add(this.AddFrame);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.WeaponY);
            this.Controls.Add(this.WeaponX);
            this.Controls.Add(this.AnchorY);
            this.Controls.Add(this.AnchorX);
            this.Controls.Add(this.FrameBox);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Animation Editor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AnchorX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.AnchorY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.WeaponX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.WeaponY)).EndInit();
            this.SpriteSheetPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.TriggerX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TriggerY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Duration)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel PreviewPanel;
        private System.Windows.Forms.ListBox FrameBox;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem collisionRectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem renderRectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem anchorPointToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem triggersToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem guideToolStripMenuItem;
        private System.Windows.Forms.NumericUpDown AnchorX;
        private System.Windows.Forms.NumericUpDown AnchorY;
        private System.Windows.Forms.NumericUpDown WeaponX;
        private System.Windows.Forms.NumericUpDown WeaponY;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Play;
        private System.Windows.Forms.Button Stop;
        private System.Windows.Forms.Button NextFrame;
        private System.Windows.Forms.Button PrevFrame;
        private System.Windows.Forms.Button AddFrame;
        private System.Windows.Forms.Button DelFrame;
        private System.Windows.Forms.Button Reset;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button ImageButton;
        private System.Windows.Forms.Button CollisionButton;
        private System.Windows.Forms.Button AttackButton;
        private System.Windows.Forms.Button WeaponButton;
        private System.Windows.Forms.Button AnchorButton;
        private System.Windows.Forms.TextBox TriggerName;
        private System.Windows.Forms.Button TriggerButton;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.NumericUpDown TriggerX;
        private System.Windows.Forms.NumericUpDown TriggerY;
        private System.Windows.Forms.ListBox TriggerBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button DelAnim;
        private System.Windows.Forms.Button AddAnim;
        private System.Windows.Forms.ListBox AnimBox;
        private System.Windows.Forms.ToolStripMenuItem openXMLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadSpriteSheetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveXMLToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem weaponPointToolStripMenuItem;
        private System.Windows.Forms.TextBox AnimName;
        private System.Windows.Forms.Panel SpriteSheetPanel;
        private System.Windows.Forms.Button AddTrigger;
        private System.Windows.Forms.NumericUpDown Duration;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button DelTrigger;
        private System.Windows.Forms.CheckBox isLoopingCheck;
        private System.Windows.Forms.Button ZoomIn;
        private System.Windows.Forms.Button ZoomOut;
        private System.Windows.Forms.Panel PreviewAnimPanel;
        private System.Windows.Forms.VScrollBar vSpriteBar;
        private System.Windows.Forms.HScrollBar hSpriteBar;
        private System.Windows.Forms.Button UpdateButton;
    }
}

