using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;


namespace WindowsFormsApplication1
{
    public class CharRect
    {
        private char character;

        public char Character
        {
            get { return character; }
            set { character = value; }
        }
        private Rectangle bounding;

        public Rectangle Bounding
        {
            get { return bounding; }
            set { bounding = value; }
        }

        public CharRect()
        {
        }

        public CharRect(char character, Rectangle bounding, int offset)
        {
        }
        public override string ToString()
        {
            return character.ToString() + '\t' + bounding.X.ToString() + '\t' + bounding.Y.ToString() + '\t' + bounding.Width.ToString() + '\t' + bounding.Height.ToString();
        }

        private int offset;

        public int Offset
        {
            get { return offset; }
            set { offset = value; }
        }
    }
}
