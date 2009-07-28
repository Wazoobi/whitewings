using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Colors : Form
    {
        public Colors()
        {
            InitializeComponent();
        }

        public Color background
        {
            get
            {
                return BackgroundColorButton.BackColor;
            }
            set
            {
                BackgroundColorButton.BackColor = value;
            }
        }
        public Color rectangle
        {
            get
            {
                return RectangleColorButton.BackColor;
            }
            set
            {
                RectangleColorButton.BackColor = value;
            }
        }
        public Color transparency
        {
            get
            {
                return TransparencyColorButton.BackColor;
            }
            set
            {
                TransparencyColorButton.BackColor = value;
            }
        }

        public Color display
        {
            get
            {
                return DisplayColorButton.BackColor;
            }
            set
            {
                DisplayColorButton.BackColor = value;
            }
        }

        private void BackgroundColorButton_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();

            dlg.Color = BackgroundColorButton.BackColor;


            if (DialogResult.OK == dlg.ShowDialog())
            {
                BackgroundColorButton.BackColor = dlg.Color;
            }
        }

        private void TransparencyColorButton_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();

            dlg.Color = TransparencyColorButton.BackColor;


            if (DialogResult.OK == dlg.ShowDialog())
            {
                TransparencyColorButton.BackColor = dlg.Color;
            }
        }

        private void RectangleColorButton_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();

            dlg.Color = RectangleColorButton.BackColor;


            if (DialogResult.OK == dlg.ShowDialog())
            {
                RectangleColorButton.BackColor = dlg.Color;
            }

        }

        private void DisplayColorButton_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();

            dlg.Color = DisplayColorButton.BackColor;


            if (DialogResult.OK == dlg.ShowDialog())
            {
                DisplayColorButton.BackColor = dlg.Color;
            }
        }



    }
}
