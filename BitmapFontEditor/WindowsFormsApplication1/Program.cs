using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new BitmapFontEditor());

            //BitmapFontEditor theform = new BitmapFontEditor();

            //theform.Show();

            //while(theform.Looping)
            //{
            //    theform.Update();

            //    theform.Render();

            //    Application.DoEvents();
            //}
        }
    }
}
