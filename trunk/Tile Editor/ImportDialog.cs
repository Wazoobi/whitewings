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
    public partial class ImportDialog : Form
    {
        public Form1 parent;
        public ImportDialog()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (TileRadio.Checked == true || ItemRadio.Checked == true || BackgroundRadio.Checked == true && parent != null)
            {
                if (TileRadio.Checked == true)
                {
                    parent.TileAppend = true;
                    Close();
                }
                else if (ItemRadio.Checked == true)
                {
                    parent.ItemImage = true;
                    Close(); 
                }
                else
                {
                    parent.BackGroundImage = true;
                    Close();
                }
            }
        }
    }
}
