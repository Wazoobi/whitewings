﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class CustomControl1 : Control
    {
        public CustomControl1()
        {
            InitializeComponent();
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            base.OnPaint(pe);
        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {
            DoubleBuffered = true;
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {
            DoubleBuffered = true;
        }

    }
}
