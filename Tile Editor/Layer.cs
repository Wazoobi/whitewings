using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Layer
    {
        Point[] tilePoints;
        public Point[] TilePoints
        {
            get { return tilePoints; }
            set { tilePoints = value; }
        }

        short totalTilePoints = 0;

        public short TotalTilePoints
        {
            get { return totalTilePoints; }
            set { totalTilePoints = value; }
        }

        short layerNum;
        public short LayerNum
        {
            get { return layerNum; }
            set { layerNum = value; }
        }

        Point[] pointsClicked;
        public Point[] PointsClicked
        {
            get { return pointsClicked; }
            set { pointsClicked = value; }
        }

        short totalPointsClicked = 0;
        public short TotalPointsClicked
        {
            get { return totalPointsClicked; }
            set { totalPointsClicked = value; }
        }

        Point[] pointsCollideable;

        public Point[] PointsCollideable
        {
            get { return pointsCollideable; }
            set { pointsCollideable = value; }
        }

        short totalCollideableTiles;

        public short TotalCollideableTiles
        {
            get { return totalCollideableTiles; }
            set { totalCollideableTiles = value; }
        }

        Trigger[] triggers;

        public Trigger[] Triggers
        {
            get { return triggers; }
            set { triggers = value; }
        }

        short totalTriggers = 0;

        public short TotalTriggers
        {
            get { return totalTriggers; }
            set { totalTriggers = value; }
        }

    }
}
