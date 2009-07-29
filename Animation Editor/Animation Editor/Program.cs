using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using Microsoft.DirectX;

namespace Animation_Editor
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
            //Application.Run(new Form1());

            // Make a form to make our own game loop.
            Form1 theForm = new Form1();

            // Show the form we made
            theForm.Show();

            // Make our game loop
            while (theForm.Looping)
            {
                // Update the form
                theForm.Update();

                // Render it
                theForm.Render();

                // Do events
                Application.DoEvents();
            }
            
        }
    }
}
