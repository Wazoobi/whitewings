namespace WindowsFormsApplication1
{
    partial class BitmapFontEditor
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportBianaryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Status = new System.Windows.Forms.StatusStrip();
            this.Statuslbl = new System.Windows.Forms.ToolStripStatusLabel();
            this.InfoGroup = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.WidthNum = new System.Windows.Forms.NumericUpDown();
            this.OffsetNum = new System.Windows.Forms.NumericUpDown();
            this.HeightNum = new System.Windows.Forms.NumericUpDown();
            this.YNum = new System.Windows.Forms.NumericUpDown();
            this.XNum = new System.Windows.Forms.NumericUpDown();
            this.UpperCheckBox = new System.Windows.Forms.CheckBox();
            this.CharTxt = new System.Windows.Forms.TextBox();
            this.Character = new System.Windows.Forms.Label();
            this.AddButton = new System.Windows.Forms.Button();
            this.ClearButtton = new System.Windows.Forms.Button();
            this.UpdateButton = new System.Windows.Forms.Button();
            this.CharList = new System.Windows.Forms.ListBox();
            this.FontPagePanel = new System.Windows.Forms.Panel();
            this.FontPanelVScroll = new System.Windows.Forms.VScrollBar();
            this.FontPanelHScroll = new System.Windows.Forms.HScrollBar();
            this.PreviewPanel = new System.Windows.Forms.Panel();
            this.MidlineCheckBox = new System.Windows.Forms.CheckBox();
            this.GridCheckBox = new System.Windows.Forms.CheckBox();
            this.ListButton = new System.Windows.Forms.Button();
            this.RandomButton = new System.Windows.Forms.Button();
            this.ClearPreviewButton = new System.Windows.Forms.Button();
            this.DisplayButton = new System.Windows.Forms.Button();
            this.PreviewTxt = new System.Windows.Forms.TextBox();
            this.PreviewDisplayPanel = new System.Windows.Forms.Panel();
            this.PreviewPanelHScroll = new System.Windows.Forms.HScrollBar();
            this.PreviewPanelVScroll = new System.Windows.Forms.VScrollBar();
            this.ClearListButton = new System.Windows.Forms.Button();
            this.PreviewButton = new System.Windows.Forms.Button();
            this.RemoveButton = new System.Windows.Forms.Button();
            this.lblChar = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.UpdateFontPage = new System.Windows.Forms.Timer(this.components);
            this.UpdatePreview = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1.SuspendLayout();
            this.Status.SuspendLayout();
            this.InfoGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.WidthNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.OffsetNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.HeightNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.YNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.XNum)).BeginInit();
            this.FontPagePanel.SuspendLayout();
            this.PreviewPanel.SuspendLayout();
            this.PreviewDisplayPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(766, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exportXMLToolStripMenuItem,
            this.exportBianaryToolStripMenuItem,
            this.loadXMLToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exportXMLToolStripMenuItem
            // 
            this.exportXMLToolStripMenuItem.Name = "exportXMLToolStripMenuItem";
            this.exportXMLToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.exportXMLToolStripMenuItem.Text = "Export XML";
            this.exportXMLToolStripMenuItem.Click += new System.EventHandler(this.exportXMLToolStripMenuItem_Click);
            // 
            // exportBianaryToolStripMenuItem
            // 
            this.exportBianaryToolStripMenuItem.Name = "exportBianaryToolStripMenuItem";
            this.exportBianaryToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.exportBianaryToolStripMenuItem.Text = "Export Binary";
            this.exportBianaryToolStripMenuItem.Click += new System.EventHandler(this.exportBianaryToolStripMenuItem_Click);
            // 
            // loadXMLToolStripMenuItem
            // 
            this.loadXMLToolStripMenuItem.Name = "loadXMLToolStripMenuItem";
            this.loadXMLToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.loadXMLToolStripMenuItem.Text = "Load XML";
            this.loadXMLToolStripMenuItem.Click += new System.EventHandler(this.loadXMLToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importToolStripMenuItem,
            this.colorsToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // importToolStripMenuItem
            // 
            this.importToolStripMenuItem.Name = "importToolStripMenuItem";
            this.importToolStripMenuItem.Size = new System.Drawing.Size(106, 22);
            this.importToolStripMenuItem.Text = "Import";
            this.importToolStripMenuItem.Click += new System.EventHandler(this.importToolStripMenuItem_Click);
            // 
            // colorsToolStripMenuItem
            // 
            this.colorsToolStripMenuItem.Name = "colorsToolStripMenuItem";
            this.colorsToolStripMenuItem.Size = new System.Drawing.Size(106, 22);
            this.colorsToolStripMenuItem.Text = "Colors";
            this.colorsToolStripMenuItem.Click += new System.EventHandler(this.colorsToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // Status
            // 
            this.Status.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Statuslbl});
            this.Status.Location = new System.Drawing.Point(0, 499);
            this.Status.Name = "Status";
            this.Status.Size = new System.Drawing.Size(766, 22);
            this.Status.TabIndex = 1;
            this.Status.Text = "statusStrip1";
            // 
            // Statuslbl
            // 
            this.Statuslbl.Name = "Statuslbl";
            this.Statuslbl.Size = new System.Drawing.Size(0, 17);
            // 
            // InfoGroup
            // 
            this.InfoGroup.Controls.Add(this.label3);
            this.InfoGroup.Controls.Add(this.label9);
            this.InfoGroup.Controls.Add(this.label8);
            this.InfoGroup.Controls.Add(this.label7);
            this.InfoGroup.Controls.Add(this.label6);
            this.InfoGroup.Controls.Add(this.WidthNum);
            this.InfoGroup.Controls.Add(this.OffsetNum);
            this.InfoGroup.Controls.Add(this.HeightNum);
            this.InfoGroup.Controls.Add(this.YNum);
            this.InfoGroup.Controls.Add(this.XNum);
            this.InfoGroup.Controls.Add(this.UpperCheckBox);
            this.InfoGroup.Controls.Add(this.CharTxt);
            this.InfoGroup.Controls.Add(this.Character);
            this.InfoGroup.Location = new System.Drawing.Point(11, 30);
            this.InfoGroup.Name = "InfoGroup";
            this.InfoGroup.Size = new System.Drawing.Size(244, 117);
            this.InfoGroup.TabIndex = 2;
            this.InfoGroup.TabStop = false;
            this.InfoGroup.Text = "character Info";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(160, 40);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 13);
            this.label3.TabIndex = 13;
            this.label3.Text = "Y:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(29, 40);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(17, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "X:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(8, 65);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(38, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Width:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(139, 92);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 13);
            this.label7.TabIndex = 10;
            this.label7.Text = "Offset:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(136, 66);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(41, 13);
            this.label6.TabIndex = 9;
            this.label6.Text = "Height:";
            // 
            // WidthNum
            // 
            this.WidthNum.Location = new System.Drawing.Point(52, 63);
            this.WidthNum.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.WidthNum.Name = "WidthNum";
            this.WidthNum.Size = new System.Drawing.Size(55, 20);
            this.WidthNum.TabIndex = 5;
            // 
            // OffsetNum
            // 
            this.OffsetNum.Location = new System.Drawing.Point(183, 90);
            this.OffsetNum.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.OffsetNum.Name = "OffsetNum";
            this.OffsetNum.Size = new System.Drawing.Size(55, 20);
            this.OffsetNum.TabIndex = 7;
            // 
            // HeightNum
            // 
            this.HeightNum.Location = new System.Drawing.Point(183, 64);
            this.HeightNum.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.HeightNum.Name = "HeightNum";
            this.HeightNum.Size = new System.Drawing.Size(55, 20);
            this.HeightNum.TabIndex = 6;
            // 
            // YNum
            // 
            this.YNum.Location = new System.Drawing.Point(183, 38);
            this.YNum.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.YNum.Name = "YNum";
            this.YNum.Size = new System.Drawing.Size(55, 20);
            this.YNum.TabIndex = 4;
            // 
            // XNum
            // 
            this.XNum.Location = new System.Drawing.Point(52, 38);
            this.XNum.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.XNum.Name = "XNum";
            this.XNum.Size = new System.Drawing.Size(55, 20);
            this.XNum.TabIndex = 3;
            // 
            // UpperCheckBox
            // 
            this.UpperCheckBox.AutoSize = true;
            this.UpperCheckBox.Location = new System.Drawing.Point(130, 15);
            this.UpperCheckBox.Name = "UpperCheckBox";
            this.UpperCheckBox.Size = new System.Drawing.Size(108, 17);
            this.UpperCheckBox.TabIndex = 2;
            this.UpperCheckBox.Text = "Force Uppercase";
            this.UpperCheckBox.UseVisualStyleBackColor = true;
            // 
            // CharTxt
            // 
            this.CharTxt.Location = new System.Drawing.Point(76, 13);
            this.CharTxt.MaxLength = 1;
            this.CharTxt.Name = "CharTxt";
            this.CharTxt.Size = new System.Drawing.Size(21, 20);
            this.CharTxt.TabIndex = 1;
            this.CharTxt.TextChanged += new System.EventHandler(this.CharTxt_TextChanged);
            // 
            // Character
            // 
            this.Character.AutoSize = true;
            this.Character.Location = new System.Drawing.Point(18, 16);
            this.Character.Name = "Character";
            this.Character.Size = new System.Drawing.Size(55, 13);
            this.Character.TabIndex = 0;
            this.Character.Text = "character:";
            // 
            // AddButton
            // 
            this.AddButton.Location = new System.Drawing.Point(12, 153);
            this.AddButton.Name = "AddButton";
            this.AddButton.Size = new System.Drawing.Size(73, 26);
            this.AddButton.TabIndex = 8;
            this.AddButton.Text = "Add";
            this.AddButton.UseVisualStyleBackColor = true;
            this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
            // 
            // ClearButtton
            // 
            this.ClearButtton.Location = new System.Drawing.Point(186, 153);
            this.ClearButtton.Name = "ClearButtton";
            this.ClearButtton.Size = new System.Drawing.Size(73, 26);
            this.ClearButtton.TabIndex = 10;
            this.ClearButtton.Text = "Clear";
            this.ClearButtton.UseVisualStyleBackColor = true;
            this.ClearButtton.Click += new System.EventHandler(this.ClearButtton_Click);
            // 
            // UpdateButton
            // 
            this.UpdateButton.Location = new System.Drawing.Point(99, 153);
            this.UpdateButton.Name = "UpdateButton";
            this.UpdateButton.Size = new System.Drawing.Size(73, 26);
            this.UpdateButton.TabIndex = 9;
            this.UpdateButton.Text = "Update";
            this.UpdateButton.UseVisualStyleBackColor = true;
            this.UpdateButton.Click += new System.EventHandler(this.UpdateButton_Click);
            // 
            // CharList
            // 
            this.CharList.HorizontalScrollbar = true;
            this.CharList.Location = new System.Drawing.Point(11, 216);
            this.CharList.Name = "CharList";
            this.CharList.Size = new System.Drawing.Size(244, 238);
            this.CharList.TabIndex = 11;
            this.CharList.SelectedIndexChanged += new System.EventHandler(this.CharList_SelectedIndexChanged);
            // 
            // FontPagePanel
            // 
            this.FontPagePanel.BackColor = System.Drawing.Color.White;
            this.FontPagePanel.Controls.Add(this.FontPanelVScroll);
            this.FontPagePanel.Controls.Add(this.FontPanelHScroll);
            this.FontPagePanel.Location = new System.Drawing.Point(265, 30);
            this.FontPagePanel.Name = "FontPagePanel";
            this.FontPagePanel.Size = new System.Drawing.Size(492, 259);
            this.FontPagePanel.TabIndex = 7;
            this.FontPagePanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.FontPagePanel_MouseMove);
            this.FontPagePanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.FontPagePanel_MouseDown);
            this.FontPagePanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.FontPagePanel_MouseUp);
            // 
            // FontPanelVScroll
            // 
            this.FontPanelVScroll.Dock = System.Windows.Forms.DockStyle.Right;
            this.FontPanelVScroll.Location = new System.Drawing.Point(475, 0);
            this.FontPanelVScroll.Name = "FontPanelVScroll";
            this.FontPanelVScroll.Size = new System.Drawing.Size(17, 242);
            this.FontPanelVScroll.TabIndex = 1;
            this.FontPanelVScroll.Visible = false;
            // 
            // FontPanelHScroll
            // 
            this.FontPanelHScroll.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.FontPanelHScroll.Location = new System.Drawing.Point(0, 242);
            this.FontPanelHScroll.Name = "FontPanelHScroll";
            this.FontPanelHScroll.Size = new System.Drawing.Size(492, 17);
            this.FontPanelHScroll.TabIndex = 0;
            this.FontPanelHScroll.Visible = false;
            // 
            // PreviewPanel
            // 
            this.PreviewPanel.BackColor = System.Drawing.SystemColors.Control;
            this.PreviewPanel.Controls.Add(this.MidlineCheckBox);
            this.PreviewPanel.Controls.Add(this.GridCheckBox);
            this.PreviewPanel.Controls.Add(this.ListButton);
            this.PreviewPanel.Controls.Add(this.RandomButton);
            this.PreviewPanel.Controls.Add(this.ClearPreviewButton);
            this.PreviewPanel.Controls.Add(this.DisplayButton);
            this.PreviewPanel.Controls.Add(this.PreviewTxt);
            this.PreviewPanel.Controls.Add(this.PreviewDisplayPanel);
            this.PreviewPanel.Location = new System.Drawing.Point(265, 292);
            this.PreviewPanel.Name = "PreviewPanel";
            this.PreviewPanel.Size = new System.Drawing.Size(492, 192);
            this.PreviewPanel.TabIndex = 0;
            // 
            // MidlineCheckBox
            // 
            this.MidlineCheckBox.AutoSize = true;
            this.MidlineCheckBox.Location = new System.Drawing.Point(406, 169);
            this.MidlineCheckBox.Name = "MidlineCheckBox";
            this.MidlineCheckBox.Size = new System.Drawing.Size(62, 17);
            this.MidlineCheckBox.TabIndex = 19;
            this.MidlineCheckBox.Text = "Mid-line";
            this.MidlineCheckBox.UseVisualStyleBackColor = true;
            // 
            // GridCheckBox
            // 
            this.GridCheckBox.AutoSize = true;
            this.GridCheckBox.Location = new System.Drawing.Point(406, 138);
            this.GridCheckBox.Name = "GridCheckBox";
            this.GridCheckBox.Size = new System.Drawing.Size(45, 17);
            this.GridCheckBox.TabIndex = 18;
            this.GridCheckBox.Text = "Grid";
            this.GridCheckBox.UseVisualStyleBackColor = true;
            // 
            // ListButton
            // 
            this.ListButton.Location = new System.Drawing.Point(10, 163);
            this.ListButton.Name = "ListButton";
            this.ListButton.Size = new System.Drawing.Size(120, 26);
            this.ListButton.TabIndex = 15;
            this.ListButton.Text = "List";
            this.ListButton.UseVisualStyleBackColor = true;
            this.ListButton.Click += new System.EventHandler(this.ListButton_Click);
            // 
            // RandomButton
            // 
            this.RandomButton.Location = new System.Drawing.Point(137, 163);
            this.RandomButton.Name = "RandomButton";
            this.RandomButton.Size = new System.Drawing.Size(120, 26);
            this.RandomButton.TabIndex = 16;
            this.RandomButton.Text = "Random";
            this.RandomButton.UseVisualStyleBackColor = true;
            this.RandomButton.Click += new System.EventHandler(this.RandomButton_Click);
            // 
            // ClearPreviewButton
            // 
            this.ClearPreviewButton.Location = new System.Drawing.Point(264, 163);
            this.ClearPreviewButton.Name = "ClearPreviewButton";
            this.ClearPreviewButton.Size = new System.Drawing.Size(120, 26);
            this.ClearPreviewButton.TabIndex = 17;
            this.ClearPreviewButton.Text = "Clear";
            this.ClearPreviewButton.UseVisualStyleBackColor = true;
            this.ClearPreviewButton.Click += new System.EventHandler(this.ClearPreviewButton_Click);
            // 
            // DisplayButton
            // 
            this.DisplayButton.Location = new System.Drawing.Point(309, 129);
            this.DisplayButton.Name = "DisplayButton";
            this.DisplayButton.Size = new System.Drawing.Size(73, 26);
            this.DisplayButton.TabIndex = 14;
            this.DisplayButton.Text = "Display";
            this.DisplayButton.UseVisualStyleBackColor = true;
            this.DisplayButton.Click += new System.EventHandler(this.DisplayButton_Click);
            // 
            // PreviewTxt
            // 
            this.PreviewTxt.Location = new System.Drawing.Point(9, 133);
            this.PreviewTxt.Name = "PreviewTxt";
            this.PreviewTxt.Size = new System.Drawing.Size(285, 20);
            this.PreviewTxt.TabIndex = 13;
            // 
            // PreviewDisplayPanel
            // 
            this.PreviewDisplayPanel.BackColor = System.Drawing.Color.White;
            this.PreviewDisplayPanel.Controls.Add(this.PreviewPanelHScroll);
            this.PreviewDisplayPanel.Controls.Add(this.PreviewPanelVScroll);
            this.PreviewDisplayPanel.Location = new System.Drawing.Point(0, 9);
            this.PreviewDisplayPanel.Name = "PreviewDisplayPanel";
            this.PreviewDisplayPanel.Size = new System.Drawing.Size(492, 114);
            this.PreviewDisplayPanel.TabIndex = 0;
            // 
            // PreviewPanelHScroll
            // 
            this.PreviewPanelHScroll.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.PreviewPanelHScroll.Location = new System.Drawing.Point(0, 97);
            this.PreviewPanelHScroll.Name = "PreviewPanelHScroll";
            this.PreviewPanelHScroll.Size = new System.Drawing.Size(475, 17);
            this.PreviewPanelHScroll.TabIndex = 2;
            this.PreviewPanelHScroll.Visible = false;
            // 
            // PreviewPanelVScroll
            // 
            this.PreviewPanelVScroll.Dock = System.Windows.Forms.DockStyle.Right;
            this.PreviewPanelVScroll.Location = new System.Drawing.Point(475, 0);
            this.PreviewPanelVScroll.Name = "PreviewPanelVScroll";
            this.PreviewPanelVScroll.Size = new System.Drawing.Size(17, 114);
            this.PreviewPanelVScroll.TabIndex = 2;
            this.PreviewPanelVScroll.Visible = false;
            // 
            // ClearListButton
            // 
            this.ClearListButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.ClearListButton.Location = new System.Drawing.Point(99, 458);
            this.ClearListButton.Name = "ClearListButton";
            this.ClearListButton.Size = new System.Drawing.Size(73, 26);
            this.ClearListButton.TabIndex = 12;
            this.ClearListButton.Text = "Clear List";
            this.ClearListButton.UseVisualStyleBackColor = true;
            this.ClearListButton.Click += new System.EventHandler(this.ClearListButton_Click);
            // 
            // PreviewButton
            // 
            this.PreviewButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.PreviewButton.Location = new System.Drawing.Point(178, 458);
            this.PreviewButton.Name = "PreviewButton";
            this.PreviewButton.Size = new System.Drawing.Size(73, 26);
            this.PreviewButton.TabIndex = 13;
            this.PreviewButton.Text = "Preview";
            this.PreviewButton.UseVisualStyleBackColor = true;
            this.PreviewButton.Click += new System.EventHandler(this.PreviewButton_Click);
            // 
            // RemoveButton
            // 
            this.RemoveButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.RemoveButton.Location = new System.Drawing.Point(20, 458);
            this.RemoveButton.Name = "RemoveButton";
            this.RemoveButton.Size = new System.Drawing.Size(73, 26);
            this.RemoveButton.TabIndex = 11;
            this.RemoveButton.Text = "Remove";
            this.RemoveButton.UseVisualStyleBackColor = true;
            this.RemoveButton.Click += new System.EventHandler(this.RemoveButton_Click);
            // 
            // lblChar
            // 
            this.lblChar.AutoSize = true;
            this.lblChar.Location = new System.Drawing.Point(11, 200);
            this.lblChar.Name = "lblChar";
            this.lblChar.Size = new System.Drawing.Size(18, 13);
            this.lblChar.TabIndex = 11;
            this.lblChar.Text = "\'A\'";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(195, 200);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "Height";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(138, 200);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 13;
            this.label2.Text = "Width";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(107, 200);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(14, 13);
            this.label4.TabIndex = 12;
            this.label4.Text = "Y";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(61, 200);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(14, 13);
            this.label5.TabIndex = 13;
            this.label5.Text = "X";
            // 
            // UpdateFontPage
            // 
            this.UpdateFontPage.Enabled = true;
            this.UpdateFontPage.Interval = 16;
            this.UpdateFontPage.Tick += new System.EventHandler(this.UpdateFontPage_Tick);
            // 
            // UpdatePreview
            // 
            this.UpdatePreview.Enabled = true;
            this.UpdatePreview.Interval = 16;
            this.UpdatePreview.Tick += new System.EventHandler(this.UpdatePreview_Tick);
            // 
            // BitmapFontEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(766, 521);
            this.Controls.Add(this.PreviewPanel);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lblChar);
            this.Controls.Add(this.ClearListButton);
            this.Controls.Add(this.PreviewButton);
            this.Controls.Add(this.RemoveButton);
            this.Controls.Add(this.FontPagePanel);
            this.Controls.Add(this.CharList);
            this.Controls.Add(this.UpdateButton);
            this.Controls.Add(this.ClearButtton);
            this.Controls.Add(this.AddButton);
            this.Controls.Add(this.InfoGroup);
            this.Controls.Add(this.Status);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "BitmapFontEditor";
            this.Text = "White Wing Bitmap Font Editor";
            this.Load += new System.EventHandler(this.BitmapFontEditor_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.Status.ResumeLayout(false);
            this.Status.PerformLayout();
            this.InfoGroup.ResumeLayout(false);
            this.InfoGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.WidthNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.OffsetNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.HeightNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.YNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.XNum)).EndInit();
            this.FontPagePanel.ResumeLayout(false);
            this.PreviewPanel.ResumeLayout(false);
            this.PreviewPanel.PerformLayout();
            this.PreviewDisplayPanel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.StatusStrip Status;
        private System.Windows.Forms.GroupBox InfoGroup;
        private System.Windows.Forms.Button AddButton;
        private System.Windows.Forms.Button ClearButtton;
        private System.Windows.Forms.Button UpdateButton;
        private System.Windows.Forms.ListBox CharList;
        private System.Windows.Forms.Panel FontPagePanel;
        private System.Windows.Forms.Panel PreviewPanel;
        private System.Windows.Forms.Button ClearListButton;
        private System.Windows.Forms.Button PreviewButton;
        private System.Windows.Forms.Button RemoveButton;
        private System.Windows.Forms.Label lblChar;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel PreviewDisplayPanel;
        private System.Windows.Forms.NumericUpDown WidthNum;
        private System.Windows.Forms.NumericUpDown OffsetNum;
        private System.Windows.Forms.NumericUpDown HeightNum;
        private System.Windows.Forms.NumericUpDown YNum;
        private System.Windows.Forms.NumericUpDown XNum;
        private System.Windows.Forms.CheckBox UpperCheckBox;
        private System.Windows.Forms.TextBox CharTxt;
        private System.Windows.Forms.Label Character;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button DisplayButton;
        private System.Windows.Forms.TextBox PreviewTxt;
        private System.Windows.Forms.Button ListButton;
        private System.Windows.Forms.Button RandomButton;
        private System.Windows.Forms.Button ClearPreviewButton;
        private System.Windows.Forms.CheckBox MidlineCheckBox;
        private System.Windows.Forms.CheckBox GridCheckBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ToolStripMenuItem importToolStripMenuItem;
        private System.Windows.Forms.Timer UpdateFontPage;
        private System.Windows.Forms.Timer UpdatePreview;
        private System.Windows.Forms.ToolStripStatusLabel Statuslbl;
        private System.Windows.Forms.HScrollBar FontPanelHScroll;
        private System.Windows.Forms.VScrollBar FontPanelVScroll;
        private System.Windows.Forms.HScrollBar PreviewPanelHScroll;
        private System.Windows.Forms.VScrollBar PreviewPanelVScroll;
        private System.Windows.Forms.ToolStripMenuItem exportXMLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportBianaryToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadXMLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem colorsToolStripMenuItem;
    }
}

