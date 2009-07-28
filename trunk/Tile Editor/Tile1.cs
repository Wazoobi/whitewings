using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Tile1
    {
        Point toDrawFrom;

        public Point ToDrawFrom
        {
            get { return toDrawFrom; }
            set { toDrawFrom = value; }
        }
        bool isCollideable;

        public bool IsCollideable
        {
            get { return isCollideable; }
            set { isCollideable = value; }
        }
        Trigger trigger;

        public Trigger pTrigger
        {
            get { return trigger; }
            set { trigger = value; }
        }

        bool isDrawn = false;

        public bool IsDrawn
        {
            get { return isDrawn; }
            set { isDrawn = value; }
        }

    }
}
