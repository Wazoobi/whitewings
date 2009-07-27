using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Trigger
    {
        private string eventString;

        public string EventString
        {
            get { return eventString; }
            set { eventString = value; }
        }

        private Point triggerPosition;

        public Point TriggerPosition
        {
            get { return triggerPosition; }
            set { triggerPosition = value; }
        }
        

    }
}
