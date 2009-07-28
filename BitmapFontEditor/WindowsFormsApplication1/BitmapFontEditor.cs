using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using SGD;
using System.Xml.Linq;
using System.IO;



namespace WindowsFormsApplication1
{
    /// <summary>
    /// .167 s
    /// </summary>

    public partial class BitmapFontEditor : Form
    {
        ManagedDirect3D D3D = ManagedDirect3D.Instance;
        ManagedTextureManager TM = ManagedTextureManager.Instance;
        int imageid = -1;
        int alphaimageid = -1;
        bool mousedown = false;
        int startx = 0;
        int starty = 0;
        string preview = "";
        Random rand = new Random();
        string filename;

        Color backgroundclr = Color.White;
        Color transparencyclr = Color.Black;
        Color rectangleclr = Color.Green;
        Color displayclr = Color.White;

        public BitmapFontEditor()
        {
            InitializeComponent();
        }

        private void PreviewButton_Click(object sender, EventArgs e)
        {
            if (PreviewPanel.Visible)
            {
                PreviewPanel.Visible = false;
                FontPagePanel.Height = 450;
            }
            else
            {
                PreviewPanel.Visible = true;
                FontPagePanel.Height = 250;
            }
        }

        private void RemoveButton_Click(object sender, EventArgs e)
        {
            CharList.Items.RemoveAt(CharList.SelectedIndex);

            CharTxt.Clear();
            CharTxt.Enabled = true;
            AddButton.Enabled = true;
            CharList.SelectedIndex = -1;

            XNum.Value = 0;
            YNum.Value = 0;
            WidthNum.Value = 0;
            HeightNum.Value = 0;
            OffsetNum.Value = 0;
        }


        private void BitmapFontEditor_Load(object sender, EventArgs e)
        {
            RemoveButton.Enabled = false;
            UpdateButton.Enabled = false;

            PreviewPanel.Visible = false;
            FontPagePanel.Height = 450;
            AddButton.Enabled = false;
            D3D.InitManagedDirect3D(FontPagePanel, false);
            TM.InitManagedTextureManager(D3D.Device, D3D.Sprite);
            imageid = TM.LoadTexture("../../Resources/RiC_Font.PNG", Color.White.ToArgb());
            alphaimageid = TM.LoadTexture("../../Resources/RiC_Font.PNG", Color.Black.ToArgb());
            filename = "../../Resources/RiC_Font.PNG";
            //FontPagePanel.AutoScrollMinSize = new Size(TM.GetTextureWidth(imageid),TM.GetTextureHeight(imageid));
            if (TM.GetTextureWidth(imageid) > FontPagePanel.Width)
            {
                FontPanelHScroll.Visible = true;
                FontPanelHScroll.Maximum = (TM.GetTextureWidth(imageid) - FontPagePanel.Width);
            }
            else
                FontPanelHScroll.Visible = false;
            if (TM.GetTextureHeight(imageid) > FontPagePanel.Height)
            {
                FontPanelVScroll.Visible = true;
                FontPanelVScroll.Maximum = (TM.GetTextureHeight(imageid) - FontPagePanel.Height);
            }
            else
                FontPanelVScroll.Visible = false;

        }



        private void importToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "All Picture Files |*.gif;*.jpg;*.jpeg;*.jpe;*.jfif;*.png;*.bmp;*.dib;*.wmf;*.art;*.ico|All Files (*.*)|*.*";

            if (DialogResult.OK == dlg.ShowDialog())
            {
                imageid = TM.LoadTexture(dlg.FileName, backgroundclr.ToArgb());
                alphaimageid = TM.LoadTexture(dlg.FileName, transparencyclr.ToArgb());
                filename = dlg.FileName;
            }

            if (TM.GetTextureWidth(imageid) > FontPagePanel.Width)
            {
                FontPanelHScroll.Visible = true;
                FontPanelHScroll.Maximum = (TM.GetTextureWidth(imageid) - FontPagePanel.Width);
            }
            else
                FontPanelHScroll.Visible = false;
            if (TM.GetTextureHeight(imageid) > FontPagePanel.Height)
            {
                FontPanelVScroll.Visible = true;
                FontPanelVScroll.Maximum = (TM.GetTextureHeight(imageid) - FontPagePanel.Height);
            }
            else
                FontPanelVScroll.Visible = false;

        }

        private void FontPagePanel_MouseDown(object sender, MouseEventArgs e)
        {
            ClearButtton_Click(sender, e);
            Point p = Point.Empty;


            p.X += FontPanelHScroll.Value;
            p.Y += FontPanelVScroll.Value;

            XNum.Value = e.X + p.X;
            YNum.Value = e.Y + p.Y;
            startx = e.X + p.X;
            starty = e.Y + p.Y;
            WidthNum.Value = e.X + p.X - XNum.Value;
            HeightNum.Value = e.Y + p.Y - YNum.Value;
            OffsetNum.Value = 0;

            mousedown = true;
        }

        private void FontPagePanel_MouseUp(object sender, MouseEventArgs e)
        {
            Point p = Point.Empty;


            p.X += FontPanelHScroll.Value;
            p.Y += FontPanelVScroll.Value;

            if (e.X + p.X >= 0 && e.Y + p.Y >= 0)
            {
                if (e.X + p.X < startx)
                {
                    WidthNum.Value = startx - XNum.Value;
                    XNum.Value = e.X + p.X;
                }
                else
                {
                    WidthNum.Value = e.X + p.X - XNum.Value;
                }

                if (e.Y + p.Y < starty)
                {
                    HeightNum.Value = starty - YNum.Value;
                    YNum.Value = e.Y + p.Y;
                }
                else
                {
                    HeightNum.Value = e.Y + p.Y - YNum.Value;
                }
            }

            mousedown = false;
        }

        private void CharTxt_TextChanged(object sender, EventArgs e)
        {
            if (UpperCheckBox.Checked)
                CharTxt.Text = CharTxt.Text.ToUpper();
            if (CharTxt.Text.Length == 0)
                AddButton.Enabled = false;
            else if (CharList.SelectedIndex == -1)
                AddButton.Enabled = true;

        }

        private void FontPagePanel_MouseMove(object sender, MouseEventArgs e)
        {
            Point p = Point.Empty;


            p.X += FontPanelHScroll.Value;
            p.Y += FontPanelVScroll.Value;
            if (mousedown && e.X + p.X >= 0 && e.Y + p.Y >= 0)
            {
                if (e.X + p.X < startx)
                {
                    XNum.Value = e.X + p.X;
                    WidthNum.Value = startx - XNum.Value;
                }
                else
                {
                    WidthNum.Value = e.X + p.X - XNum.Value;
                }

                if (e.Y + p.Y < starty)
                {
                    YNum.Value = e.Y + p.Y;
                    HeightNum.Value = starty - YNum.Value;
                }
                else
                {
                    HeightNum.Value = e.Y + p.Y - YNum.Value;
                }

            }
            Statuslbl.Text = startx + " " + starty;
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            Rectangle temprect = new Rectangle();
            temprect.X = (int)XNum.Value;
            temprect.Y = (int)YNum.Value;
            temprect.Width = (int)WidthNum.Value;
            temprect.Height = (int)HeightNum.Value;
            CharRect temp = new CharRect();
            temp.Character = CharTxt.Text[0];
            temp.Bounding = temprect;
            temp.Offset = (int)OffsetNum.Value;

            foreach (CharRect item in CharList.Items)
            {

                if (CharTxt.Text[0] == item.Character)
                {
                    //item.Bounding = temprect;
                    return;
                }

            }

            CharList.Items.Add(temp);
            CharList.SelectedIndex = -1;

            CharTxt.Clear();
            XNum.Value = 0;
            YNum.Value = 0;
            WidthNum.Value = 0;
            HeightNum.Value = 0;


        }

        private void ClearListButton_Click(object sender, EventArgs e)
        {
            CharList.Items.Clear();
            RemoveButton.Enabled = false;

            CharTxt.Clear();
            CharTxt.Enabled = true;
            AddButton.Enabled = true;
            CharList.SelectedIndex = -1;

            XNum.Value = 0;
            YNum.Value = 0;
            WidthNum.Value = 0;
            HeightNum.Value = 0;
            OffsetNum.Value = 0;

        }

        private void UpdateFontPage_Tick(object sender, EventArgs e)
        {
            Point p = Point.Empty;


            p.X -= FontPanelHScroll.Value;
            p.Y -= FontPanelVScroll.Value;

            D3D.ChangeDisplayParam(FontPagePanel, false);
            D3D.Clear(backgroundclr.R, backgroundclr.G, backgroundclr.B);
            D3D.DeviceBegin();
            D3D.SpriteBegin();




            Rectangle box = new Rectangle();

            box.X = (int)XNum.Value;
            box.Y = (int)YNum.Value;
            box.Width = (int)WidthNum.Value;
            box.Height = (int)HeightNum.Value;

            TM.Draw(imageid, p.X, p.Y, 1, 1, Rectangle.Empty, 0, 0, 0, Color.White.ToArgb());

            D3D.SpriteEnd();

            //D3D.DrawRect(((Rectangle)box),255,0,0);

            D3D.DrawLine(box.X + p.X, box.Y + p.Y, box.X + box.Width + p.X, box.Y + p.Y, rectangleclr.R, rectangleclr.G, rectangleclr.B);
            D3D.DrawLine(box.X + p.X, box.Y + p.Y, box.X + p.X, box.Y + box.Height + p.Y, rectangleclr.R, rectangleclr.G, rectangleclr.B);
            D3D.DrawLine(box.X + box.Width + p.X, box.Y + p.Y, box.X + box.Width + p.X, box.Y + box.Height + p.Y, rectangleclr.R, rectangleclr.G, rectangleclr.B);
            D3D.DrawLine(box.X + p.X, box.Y + box.Height + p.Y, box.X + box.Width + p.X, box.Y + box.Height + p.Y, rectangleclr.R, rectangleclr.G, rectangleclr.B);

            if (OffsetNum.Value > 0)
                D3D.DrawLine(p.X, box.Y - (int)OffsetNum.Value + p.Y, FontPagePanel.Width + p.X, box.Y - (int)OffsetNum.Value + p.Y, 0, 0, 255);


            D3D.DeviceEnd();
            D3D.Present();



        }

        private void UpdatePreview_Tick(object sender, EventArgs e)
        {
            Point p = Point.Empty;

            p.X -= PreviewPanelHScroll.Value;
            p.Y -= PreviewPanelVScroll.Value;
            D3D.ChangeDisplayParam(PreviewDisplayPanel, false);

            D3D.Clear(backgroundclr.R, backgroundclr.G, backgroundclr.B);
            D3D.DeviceBegin();
            D3D.SpriteBegin();
            int netwidth = 0;
            int maxheight = 0;


            for (int i = 0; i < preview.Length; i++)
            {
                foreach (CharRect item in CharList.Items)
                {
                    if (item.Character == preview[i])
                    {
                        TM.Draw(alphaimageid, p.X + netwidth, p.Y + item.Offset, 1, 1, item.Bounding, 0, 0, 0, displayclr.ToArgb());
                        netwidth += item.Bounding.Width + 2;

                        //D3D.SpriteEnd();
                        //D3D.DrawLine(item.Bounding.Width + netwidth, 0, item.Bounding.Width + netwidth, maxheight, 255, 0, 0);
                        //D3D.SpriteBegin();

                        if (item.Bounding.Height > maxheight)
                            maxheight = item.Bounding.Height;
                    }
                }
            }

            if (netwidth > PreviewPanel.Width)
            {
                PreviewPanelHScroll.Visible = true;
                PreviewPanelHScroll.Maximum = netwidth - PreviewPanel.Width;
            }
            else
                PreviewPanelHScroll.Visible = false;

            if (maxheight > PreviewPanel.Height)
            {
                PreviewPanelVScroll.Visible = true;
                PreviewPanelVScroll.Maximum = maxheight - PreviewPanel.Height;
            }
            else
                PreviewPanelVScroll.Visible = false;


            D3D.SpriteEnd();

            if (GridCheckBox.Checked)
            {
                D3D.DrawLine(0, 0, netwidth, 0, rectangleclr.R, rectangleclr.G, rectangleclr.B);
                D3D.DrawLine(0, maxheight, netwidth, maxheight, rectangleclr.R, rectangleclr.G, rectangleclr.B);
            }
            if (MidlineCheckBox.Checked)
            {
                D3D.DrawLine(0, maxheight / 2, netwidth, maxheight / 2, 255, 0, 0);
            }

            D3D.DeviceEnd();
            D3D.Present();

        }

        private void ClearButtton_Click(object sender, EventArgs e)
        {
            CharTxt.Clear();
            CharTxt.Enabled = true;
            AddButton.Enabled = true;
            CharList.SelectedIndex = -1;

            XNum.Value = 0;
            YNum.Value = 0;
            WidthNum.Value = 0;
            HeightNum.Value = 0;
            OffsetNum.Value = 0;

            AddButton.Enabled = false;
            UpdateButton.Enabled = false;
        }

        private void CharList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (CharList.SelectedIndex != -1)   //Something selected
            {
                RemoveButton.Enabled = true;
                UpdateButton.Enabled = true;
                AddButton.Enabled = false;
                CharTxt.Text = ((CharRect)(CharList.SelectedItem)).Character.ToString();
                CharTxt.Enabled = false;
                XNum.Value = ((CharRect)(CharList.SelectedItem)).Bounding.X;
                YNum.Value = ((CharRect)(CharList.SelectedItem)).Bounding.Y;
                WidthNum.Value = ((CharRect)(CharList.SelectedItem)).Bounding.Width;
                HeightNum.Value = ((CharRect)(CharList.SelectedItem)).Bounding.Height;
                OffsetNum.Value = ((CharRect)(CharList.SelectedItem)).Offset;

            }
            else                    //Nothing Selected
            {
                RemoveButton.Enabled = false;
                UpdateButton.Enabled = false;
            }

        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            Rectangle temprect = new Rectangle();
            temprect.X = (int)XNum.Value;
            temprect.Y = (int)YNum.Value;
            temprect.Width = (int)WidthNum.Value;
            temprect.Height = (int)HeightNum.Value;
            CharRect temp = new CharRect();
            temp.Character = CharTxt.Text[0];
            temp.Bounding = temprect;
            temp.Offset = (int)OffsetNum.Value;
            CharList.Items.Insert(CharList.SelectedIndex, temp);
            CharList.Items.RemoveAt(CharList.SelectedIndex);
            CharList.SelectedIndex = CharList.Items.IndexOf(temp);


        }

        private void DisplayButton_Click(object sender, EventArgs e)
        {
            preview = PreviewTxt.Text;
            if (UpperCheckBox.Checked)
                preview = preview.ToUpper();

        }

        private void ClearPreviewButton_Click(object sender, EventArgs e)
        {
            preview = "";
        }

        private void ListButton_Click(object sender, EventArgs e)
        {
            preview = "";
            foreach (CharRect item in CharList.Items)
            {
                preview += item.Character.ToString();
            }

        }

        private void RandomButton_Click(object sender, EventArgs e)
        {
            preview = "";
            for (int i = 0; i < 5; i++)
            {
                preview += (char)(rand.Next('a', 'z'));
            }
            if (UpperCheckBox.Checked)
                preview = preview.ToUpper();

        }

        private void exportXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XDocument xmldoc = new XDocument();
            xmldoc.Declaration = new XDeclaration("1.0", "utf-8", "yes");


            XName xmlname;
            xmlname = "charrects";

            XElement root = new XElement(xmlname);
            xmldoc.Add(root);

            xmlname = "filename";

            XElement xelement = new XElement(xmlname);
            root.Add(xelement);

            xmlname = "name";

            XAttribute xattr = new XAttribute(xmlname, filename);
            xelement.Add(xattr);



            foreach (CharRect item in CharList.Items)
            {
                xmlname = "charrect";

                xelement = new XElement(xmlname);
                root.Add(xelement);

                xmlname = "char";

                xattr = new XAttribute(xmlname, item.Character.ToString());
                xelement.Add(xattr);

                xmlname = "x";

                xattr = new XAttribute(xmlname, item.Bounding.X.ToString());
                xelement.Add(xattr);

                xmlname = "y";

                xattr = new XAttribute(xmlname, item.Bounding.Y.ToString());
                xelement.Add(xattr);


                xmlname = "width";

                xattr = new XAttribute(xmlname, item.Bounding.Width.ToString());
                xelement.Add(xattr);

                xmlname = "height";

                xattr = new XAttribute(xmlname, item.Bounding.Height.ToString());
                xelement.Add(xattr);

                xmlname = "offset";

                xattr = new XAttribute(xmlname, item.Offset.ToString());
                xelement.Add(xattr);
            }

            SaveFileDialog dlg = new SaveFileDialog();

            if (DialogResult.OK == dlg.ShowDialog())
            {
                xmldoc.Save(dlg.FileName);
            }

            
        }

        private void loadXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ClearListButton_Click(sender,e);
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "Text files (*.xml)|*.xml|All files (*.*)|*.*";

            if (DialogResult.OK == dlg.ShowDialog())
            {
                XDocument doc = XDocument.Load(dlg.FileName);
                XElement root = doc.Root;
                XElement xmlfilename = root.Element("filename");
                filename = xmlfilename.Attribute("name").Value;
                IEnumerable<XElement> Group = root.Descendants("charrect");
                foreach (XElement item in Group)
                {
                    CharRect temp = new CharRect();
                    Rectangle temprect = new Rectangle();
                    temp.Character = item.Attribute("char").Value[0];
                    temprect.X = Convert.ToInt32(item.Attribute("x").Value);
                    temprect.Y = Convert.ToInt32(item.Attribute("y").Value);
                    temprect.Width = Convert.ToInt32(item.Attribute("width").Value);
                    temprect.Height = Convert.ToInt32(item.Attribute("height").Value);
                    temp.Offset = Convert.ToInt32(item.Attribute("offset").Value);
                    temp.Bounding = temprect;
                    CharList.Items.Add(temp);
                    
                }
                imageid = TM.LoadTexture(filename,backgroundclr.ToArgb());
                alphaimageid = TM.LoadTexture(filename,transparencyclr.ToArgb());
            }

        }

        private void colorsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Colors dlg = new Colors();

            //dlg.Apply += new ApplyEventHandler(dlg_Apply);
            dlg.background = backgroundclr;
            dlg.transparency = transparencyclr;
            dlg.rectangle = rectangleclr;
            dlg.display = displayclr;

            if (DialogResult.OK == dlg.ShowDialog())
            {
                backgroundclr = dlg.background;
                transparencyclr = dlg.transparency;
                rectangleclr = dlg.rectangle;
                displayclr = dlg.display;
                imageid = TM.LoadTexture(filename, backgroundclr.ToArgb());
                alphaimageid = TM.LoadTexture(filename, transparencyclr.ToArgb());
            }

        }

        private void exportBianaryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string name;
            name = filename.Substring(filename.LastIndexOf('/') + 1);

            FileStream fs;
            fs = new FileStream( filename + ".bin", FileMode.Create);
            BinaryWriter bw = new BinaryWriter(fs);
            name += 0;

            //bw.Write(name.Length);
            //bw.Write(name);

            foreach (CharRect item in CharList.Items)
            {
                bw.Write(item.Character);
                bw.Write(item.Bounding.X);
                bw.Write(item.Bounding.Y);
                bw.Write(item.Bounding.Width);
                bw.Write(item.Bounding.Height);
                bw.Write(item.Offset);
            }
        }

    }
}
