using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Animation_Editor
{
    public struct Trigger
    {
        public Point Loc;
        public string Event;
    }
    public struct Frame
    {
        public Rectangle ImageRect, CollisionRect, AttackRect;
        public Point Anchor, Weapon;
        public Trigger[] Triggers;
        public float Duration;
    }
    public struct Animation
    {

        public Frame[] Frames;
        public bool isLooping;
        public string AnimName;
    }
    public struct Sheet
    {
        public int ImageID;
        public Animation[] Animations;
        public string FilePath;
    }
}
