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
    public partial class Tile_Set : Form
    {
        public Form1 parent;
        public Tile_Set()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (NewTileSet.Checked == true || AppendToTile.Checked == true)
            {
                if (parent != null)
                {
                    if (NewTileSet.Checked == true)
                    {
                        parent.TileNew = true;
                        Close();
                    }
                    else
                    {
                        parent.TileAppend = true;
                        Close();
                    }
                }
            }
        }

       

      
    }
}
