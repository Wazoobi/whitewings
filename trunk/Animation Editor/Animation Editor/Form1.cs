using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Linq;
using System.IO;

using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;

using SGD;

namespace Animation_Editor
{
   
    public partial class Form1 : Form
    {
        // A sheet for the animations, filepath, and Image ID
        Sheet theSheet;
        
        // Boolean to handle looping
        public bool Looping;

        // Points to make rects from drag'n'drop with mouse
        Point a, b;

        float SheetZoom;

        // Boolean set to whether the mouse is pressed down or not
        bool MDown;
        // Width and Height to put into the Rectangle's Size
        int RectWidth, RectHeight;

        int XOffSet, YOffSet;

        // Size to make rects based on the two previous points
        Size RectSize;
        
        // D3D wrapper obj
        ManagedDirect3D D3D = ManagedDirect3D.Instance;

        // D3D wrapper for Preview
        ManagedDirect3D D3DPrev = ManagedDirect3D.Instance;

        // Texture Manager obj
        ManagedTextureManager TM = ManagedTextureManager.Instance;

        // TM for Preview
        ManagedTextureManager TMPrev = ManagedTextureManager.Instance;

        // Short to use to tell which type of rect is being drawn by the mouse.
        // 0 - Image, 1 - Collision, 2 - Attack
        short RectType;

        short PointType;

        // Rectangle for mouse drag and drop to make the image, collision, and attack rects
        Rectangle MouseRect, ImageRect, CollisionRect, AttackRect;
        
        Point MousePoint;

        Size scrollSize;

        new Point Anchor;
        Point Trigger, Weapon;

        Trigger[] Triggers;
        short CurTrigger, MAX_TRIGGERS;

        Frame[] Frames;
        short CurFrame, PreviewFrame, MAX_FRAMES;

        //Animation[] Anims;
        short CurAnim, PreviewAnim, MAX_ANIMS;

        bool isLooping;

        bool isPlaying;
        int playCounter;

        float FrameDuration;

        int SheetImageID;

        public Form1()
        {
            InitializeComponent();
            
            // Set looping to true cause we want don't want the window to instantly go 'poof'
            Looping = true;

            isPlaying = false;

            // Make a zero point and set our points to it so they are not full of trash
            Point zero = new Point(0, 0);
            a = b = zero;

            SheetZoom = 1;

            // Set the RectType to 0 for drawing the Image Rect by default
            RectType = -1;

            PointType = -1;

            theSheet = new Sheet();
            scrollSize.Width = 0;
            scrollSize.Height = 0;

            CurTrigger = 0;
            MAX_TRIGGERS = 10;

            CurFrame = 0;
            PreviewFrame = 0;            
            MAX_FRAMES = 30;

            CurAnim = 0;
            PreviewAnim = 0;
            MAX_ANIMS = 50;

            isLooping = false;

            XOffSet = 0;
            YOffSet = 0;

        }

        public void Render()
        {
            // Draw Sheet
            D3D.ChangeDisplayParam(SpriteSheetPanel, false);
            // begin the device and sprite, draw shtuff, end the sprite and device.
            D3D.Clear(0, 0, 0);
            D3D.DeviceBegin();
            D3D.SpriteBegin();
 
            if(SheetImageID != -1)
                TM.Draw(SheetImageID, 0 - XOffSet, 0 - YOffSet, SheetZoom, SheetZoom, Rectangle.Empty, 0, 0, 0, Color.White.ToArgb());
         
            D3D.SpriteEnd();
           
            // Draw Image Rectangle
            D3D.DrawLine((ImageRect.X - XOffSet), (ImageRect.Y - YOffSet), ((ImageRect.X + ImageRect.Width) - XOffSet), (ImageRect.Y - YOffSet), 0, 0, 255);
            D3D.DrawLine(ImageRect.X - XOffSet, ImageRect.Y - YOffSet, ImageRect.X - XOffSet, (ImageRect.Y + ImageRect.Height) - YOffSet, 0, 0, 255);
            D3D.DrawLine(ImageRect.X - XOffSet, (ImageRect.Y + ImageRect.Height) - YOffSet, (ImageRect.X + ImageRect.Width) - XOffSet, (ImageRect.Y + ImageRect.Height) - YOffSet, 0, 0, 255);
            D3D.DrawLine((ImageRect.X + ImageRect.Width) - XOffSet, ImageRect.Y - YOffSet, (ImageRect.X + ImageRect.Width) - XOffSet, (ImageRect.Y + ImageRect.Height) - YOffSet, 0, 0, 255);
            
            // Draw Collision Rectangle
            D3D.DrawLine(CollisionRect.X - XOffSet, CollisionRect.Y - YOffSet, (CollisionRect.X + CollisionRect.Width) - XOffSet, CollisionRect.Y - YOffSet, 0, 255, 0);
            D3D.DrawLine(CollisionRect.X - XOffSet, CollisionRect.Y - YOffSet, CollisionRect.X - XOffSet, (CollisionRect.Y + CollisionRect.Height) - YOffSet, 0, 255, 0);
            D3D.DrawLine(CollisionRect.X - XOffSet, (CollisionRect.Y + CollisionRect.Height) - YOffSet, (CollisionRect.X + CollisionRect.Width) - XOffSet, (CollisionRect.Y + CollisionRect.Height) - YOffSet, 0, 255, 0);
            D3D.DrawLine((CollisionRect.X + CollisionRect.Width) - XOffSet, CollisionRect.Y - YOffSet, (CollisionRect.X + CollisionRect.Width) - XOffSet, (CollisionRect.Y + CollisionRect.Height) - YOffSet, 0, 255, 0);
            
            // Draw Attack Rectangle
            D3D.DrawLine(AttackRect.X - XOffSet, AttackRect.Y - YOffSet, (AttackRect.X + AttackRect.Width) - XOffSet, AttackRect.Y - YOffSet, 255, 0, 0);
            D3D.DrawLine(AttackRect.X - XOffSet, AttackRect.Y - YOffSet, AttackRect.X - XOffSet, (AttackRect.Y + AttackRect.Height) - YOffSet, 255, 0, 0);
            D3D.DrawLine(AttackRect.X - XOffSet, (AttackRect.Y + AttackRect.Height) - YOffSet, (AttackRect.X + AttackRect.Width) - XOffSet, (AttackRect.Y + AttackRect.Height) - YOffSet, 255, 0, 0);
            D3D.DrawLine((AttackRect.X + AttackRect.Width) - XOffSet, AttackRect.Y - YOffSet, (AttackRect.X + AttackRect.Width) - XOffSet, (AttackRect.Y + AttackRect.Height) - YOffSet, 255, 0, 0);

            // Draw Anchor Point
            D3D.DrawLine((Anchor.X - 2) - XOffSet, (Anchor.Y - 2) - YOffSet, (Anchor.X + 2) - XOffSet, (Anchor.Y + 2) - YOffSet, 0, 255, 0);
            D3D.DrawLine((Anchor.X + 2) - XOffSet, (Anchor.Y - 2) - YOffSet, (Anchor.X - 2) - XOffSet, (Anchor.Y + 2) - YOffSet, 0, 255, 0);

            // Draw Weapon Point
            D3D.DrawLine((Weapon.X - 2) - XOffSet, (Weapon.Y - 2) - YOffSet, (Weapon.X + 2) - XOffSet, (Weapon.Y + 2) - YOffSet, 255, 0, 0);
            D3D.DrawLine((Weapon.X + 2) - XOffSet, (Weapon.Y - 2) - YOffSet, (Weapon.X - 2) - XOffSet, (Weapon.Y + 2) - YOffSet, 255, 0, 0);

            // Draw Trigger
            D3D.DrawLine((Trigger.X - 2) - XOffSet, (Trigger.Y - 2) - YOffSet, (Trigger.X + 2) - XOffSet, (Trigger.Y + 2) - YOffSet, 0, 0, 255);
            D3D.DrawLine((Trigger.X + 2) - XOffSet, (Trigger.Y - 2) - YOffSet, (Trigger.X - 2) - XOffSet, (Trigger.Y + 2) - YOffSet, 0, 0, 255);

            

            D3D.DeviceEnd();
            D3D.Present();

            // Draw Preview
            D3D.ChangeDisplayParam(PreviewAnimPanel, false);
            D3D.Clear(0, 0, 0);
            D3D.DeviceBegin();
            D3D.SpriteBegin();
            if (theSheet.ImageID != -1)
            {
                //theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.X = (int)((float)theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.X * SheetZoom);
                //theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Y = (int)((float)theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Y * SheetZoom);
                //theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Width = (int)((float)theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Width * SheetZoom);
                //theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Height = (int)((float)theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect.Height * SheetZoom);

                TM.Draw(theSheet.ImageID, 5, 5, 1, 1, theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect, 0, 0, 0, Color.White.ToArgb());
            }
            D3D.SpriteEnd();
            D3D.DeviceEnd();
            D3D.Present();

            
        }

        new public void Update()
        {
            if (SheetImageID != -1 && TM.GetTextureWidth(SheetImageID) * SheetZoom > SpriteSheetPanel.Width)
            {
                hSpriteBar.Visible = true;
                hSpriteBar.Maximum = (int)((float)TM.GetTextureWidth(SheetImageID) * SheetZoom);
            }
            if (SheetImageID != -1 && TM.GetTextureHeight(SheetImageID) * SheetZoom > SpriteSheetPanel.Height)
            {
                vSpriteBar.Visible = true;
                vSpriteBar.Maximum = (int)((float)TM.GetTextureHeight(SheetImageID) * SheetZoom);
            }

            XOffSet = hSpriteBar.Value;
            YOffSet = vSpriteBar.Value;
            // Set the width and height up for the RectSize, and set the Mouse Rect up to be drawn in the Render
            //a.X = XOffSet;
            //b.X = XOffSet;
            //a.Y = YOffSet;
            //b.Y = YOffSet;
            //MousePoint.X += XOffSet;
            //MousePoint.Y += YOffSet;
            if (b.X > a.X)
                RectWidth = b.X - a.X;
            else
                RectWidth = a.X - b.X;
            if (b.Y > a.Y)
                RectHeight = b.Y - a.Y;
            else
                RectHeight = a.Y - b.Y;
            RectSize = new Size(RectWidth, RectHeight);
            if (a.X < b.X)
            {
                if (a.Y < b.Y)
                    MouseRect = new Rectangle(a.X, a.Y, RectSize.Width, RectSize.Height);
                else
                    MouseRect = new Rectangle(a.X, b.Y, RectSize.Width, RectSize.Height);
            }
            if (b.X < a.X)
            {
                if (b.Y < a.Y)
                    MouseRect = new Rectangle(b.X, b.Y, RectSize.Width, RectSize.Height);
                else
                    MouseRect = new Rectangle(b.X, a.Y, RectSize.Width, RectSize.Height);
            }

            // Set up the color based on what type of rect it is
            switch (RectType)
            {
                case 0:
                    ImageRect = MouseRect;
                    break;
                case 1:
                    CollisionRect = MouseRect;
                    break;
                case 2:
                    AttackRect = MouseRect;
                    break;
            }
            
            switch (PointType)
            {
                case 0:
                    Anchor = MousePoint;
                    AnchorX.Value = Anchor.X;
                    AnchorY.Value = Anchor.Y;
                    break;
                case 1:
                    Weapon = MousePoint;
                    WeaponX.Value = Weapon.X;
                    WeaponY.Value = Weapon.Y;
                    break;
                case 2:
                    Trigger = MousePoint;
                    TriggerX.Value = Trigger.X;
                    TriggerY.Value = Trigger.Y;
                    break;
            }
            if (isPlaying == true)
            {
                if (playCounter > Frames[PreviewFrame].Duration)
                {
                    if (Frames[PreviewFrame + 1].Anchor.X != 0 && Frames[PreviewFrame + 1].Anchor.Y != 0)
                        PreviewFrame++;
                    else
                        PreviewFrame = 0;
                    playCounter = 0;
                }
                else
                    playCounter++;

            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Initialize the wrapper objs
            D3D.InitManagedDirect3D(SpriteSheetPanel, false);
            TM.InitManagedTextureManager(D3D.Device, D3D.Sprite);
            

            // Load in the sprite sheet (for now a default for debugging purpose
            theSheet.ImageID = -1;
            SheetImageID = -1;
            //theSheet.ImageID = TM.LoadTexture("C:\\Users\\Dr. Snow\\Documents\\School\\SGP\\Animation Editor\\Animation Editor\\Resources\\Sprites\\SpriteSheet.png", Color.FromArgb(0, 0, 0, 0).ToArgb());

            //SheetImageID = TM.LoadTexture("C:\\Users\\Dr. Snow\\Documents\\School\\SGP\\Animation Editor\\Animation Editor\\Resources\\Sprites\\SpriteSheet.png", Color.FromArgb(0, 0, 0, 0).ToArgb());

            theSheet.Animations = new Animation[MAX_ANIMS];
            
            Triggers = new Trigger[MAX_TRIGGERS];
            Frames = new Frame[MAX_FRAMES];
            for( int i = 0; i < theSheet.Animations.Length; i++)
            {
                theSheet.Animations[i].Frames = new Frame[MAX_FRAMES];
                for (int j = 0; j < theSheet.Animations[i].Frames.Length; j++)
                {
                    theSheet.Animations[i].Frames[j].Triggers = new Trigger[MAX_TRIGGERS];
                }
            }

        }
        private void ResetValues()
        {
            ImageRect = new Rectangle();
            CollisionRect = new Rectangle();
            AttackRect = new Rectangle();
            Anchor = new Point();
            Weapon = new Point();
            Trigger = new Point();
            TriggerName.Text = "";
            TriggerBox.Items.Clear();
            FrameBox.Items.Clear();
            Triggers = new Trigger[MAX_TRIGGERS];
            Frames = new Frame[MAX_FRAMES];
            Duration.Value = (decimal)0;
        }
        private void UpdateValues()
        {
            ImageRect = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].ImageRect;
            CollisionRect = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].CollisionRect;
            AttackRect = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].AttackRect;
            Anchor = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].Anchor;
            AnchorX.Value = Anchor.X;
            AnchorY.Value = Anchor.Y;
            Weapon = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].Weapon;
            WeaponX.Value = Weapon.X;
            WeaponY.Value = Weapon.Y;
            Triggers = theSheet.Animations[PreviewAnim].Frames[PreviewFrame].Triggers;
            Frames = theSheet.Animations[PreviewAnim].Frames;
            Duration.Value = (decimal)theSheet.Animations[PreviewAnim].Frames[PreviewFrame].Duration;
            for (int i = 0; i < theSheet.Animations.Length; i++)
            {
                if(theSheet.Animations[i].AnimName != null)
                    AnimBox.Items.Add(theSheet.Animations[i].AnimName);
            }
            for (int j = 0; j < theSheet.Animations[0].Frames.Length; j++)
            {
                if (theSheet.Animations[0].Frames[j].Anchor.X != 0 && theSheet.Animations[0].Frames[j].Anchor.Y != 0)
                FrameBox.Items.Add("Frame" + j);
            }
            for (int k = 0; k < theSheet.Animations[0].Frames[0].Triggers.Length; k++)
            {
                if (theSheet.Animations[0].Frames[0].Triggers[k].Event != null)
                TriggerBox.Items.Add(theSheet.Animations[0].Frames[0].Triggers[k].Event);
            }
            TriggerX.Value = theSheet.Animations[0].Frames[0].Triggers[0].Loc.X;
            TriggerY.Value = theSheet.Animations[0].Frames[0].Triggers[0].Loc.Y;
        }


        private void loadSpriteSheetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Open the Open File Dialog box when the user clicks "Load Sprite Sheet"
            OpenFileDialog OpenSprite = new OpenFileDialog();
            OpenSprite.Filter = "Picture Files (*.bmp, *.png)|*.png;*.bmp| All Files (*.*)|*.*";
            OpenSprite.ShowDialog();

            theSheet.FilePath = OpenSprite.FileName;
            // Release the ImageID so we can re-load the selected file as the sprite sheet.
            
            theSheet.ImageID = TM.LoadTexture(theSheet.FilePath, Color.FromArgb(0,0,0,0).ToArgb());
            SheetImageID = TM.LoadTexture(theSheet.FilePath, Color.White.ToArgb());

        }

        private void ImageButton_Click(object sender, EventArgs e)
        {
            Point zero = new Point();
            a = zero;
            b = zero;
            MouseRect = new Rectangle(); 
            RectType = 0;
            PointType = -1;
            
        }

        private void CollisionButton_Click(object sender, EventArgs e)
        {
            Point zero = new Point(0, 0);
            a = zero;
            b = zero;
            MouseRect = new Rectangle(0, 0, 0, 0);
            RectType = 1;
            PointType = -1;
                      
        }

        private void AttackButton_Click(object sender, EventArgs e)
        {
            Point zero = new Point(0, 0);
            a = zero;
            b = zero;
            MouseRect = new Rectangle(0, 0, 0, 0);
            RectType = 2;
            PointType = -1;
                        
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Looping = false;
        }

        private void SpriteSheetPanel_MouseDown(object sender, MouseEventArgs e)
        {
            a.X = e.Location.X + XOffSet;
            a.Y = e.Location.Y + YOffSet;
            b.X = e.Location.X + XOffSet;
            b.Y = e.Location.Y + YOffSet;
            MousePoint = b;
            MDown = true;
        }

        private void SpriteSheetPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X >= 0 && e.Y >= 0 && MDown == true)
            {
                b.X = e.Location.X + XOffSet;
                b.Y = e.Location.Y + YOffSet;
                MousePoint = b;
            }
        }

        private void SpriteSheetPanel_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.X >= 0 && e.Y >= 0)
            {
                b.X = e.Location.X + XOffSet;
                b.Y = e.Location.Y + YOffSet;
            }
            MDown = false;
            MousePoint = b;
        }

        private void AddTrigger_Click(object sender, EventArgs e)
        {
            Triggers[CurTrigger].Loc = Trigger;
            Triggers[CurTrigger].Event = TriggerName.Text;
            TriggerBox.Items.Add(TriggerName.Text);
            Trigger = new Point(-1, -1);
            TriggerName.Text = "";
            CurTrigger++;
        }

        private void DelTrigger_Click(object sender, EventArgs e)
        {
            bool foundIt = false;
            for (int i = 0; i < MAX_TRIGGERS; i++)
            {
                if (i == TriggerBox.SelectedIndex)
                {
                    foundIt = true;
                }
                if (foundIt == true)
                {
                    if (i < MAX_TRIGGERS - 1)
                    {
                        Triggers[i] = Triggers[i + 1];
                    }
                    else
                    {
                        Triggers[i] = new Trigger();
                    }
                    if (i < TriggerBox.Items.Count - 1)
                    {
                        TriggerBox.Items[i] = TriggerBox.Items[i + 1];
                    }
                    else if (i == TriggerBox.Items.Count - 1)
                    {
                        TriggerBox.Items.RemoveAt(i);
                    }
                }
            }
            if (CurTrigger > 0)
                CurTrigger--;
        }

        private void AddFrame_Click(object sender, EventArgs e)
        {
            Frames[CurFrame].ImageRect = ImageRect;
            Frames[CurFrame].CollisionRect = CollisionRect;
            Frames[CurFrame].AttackRect = AttackRect;
            Frames[CurFrame].Anchor = Anchor;
            Frames[CurFrame].Triggers = Triggers;
            Frames[CurFrame].Duration = (float)Duration.Value;
            Frames[CurFrame].Weapon = Weapon;

            FrameBox.Items.Add("Frame" + CurFrame);

            ImageRect = new Rectangle();
            CollisionRect = new Rectangle();
            AttackRect = new Rectangle();
            Anchor = new Point();
            Triggers = new Trigger[10];
            Duration.Value = (decimal)0.0;
            Weapon = new Point();

            CurFrame++;
            Frames[CurFrame] = new Frame();
        }

        private void DelFrame_Click(object sender, EventArgs e)
        {
            bool foundIt = false;
            for (int i = 0; i < MAX_FRAMES; i++)
            {
                if (i == FrameBox.SelectedIndex)
                {
                    foundIt = true;
                }
                if (foundIt == true)
                {
                    if (i < MAX_TRIGGERS - 1)
                    {
                        Frames[i] = Frames[i + 1];
                    }
                    else
                    {
                        Frames[i] = new Frame();
                    }
                    if (i < FrameBox.Items.Count - 1)
                    {
                        FrameBox.Items[i] = FrameBox.Items[i + 1];
                    }
                    else if (i == FrameBox.Items.Count - 1)
                    {
                        FrameBox.Items.RemoveAt(i);
                    }
                }
            }
            if(CurFrame > 0)
                CurFrame--;
        }
        private void AddAnim_Click(object sender, EventArgs e)
        {
            theSheet.Animations[CurAnim].AnimName = AnimName.Text;
            theSheet.Animations[CurAnim].Frames = Frames;
            theSheet.Animations[CurAnim].isLooping = isLooping;

            Frames = new Frame[MAX_FRAMES];
            CurAnim++;
            CurFrame = 0;
            PreviewFrame = 0;
            PreviewAnim = 0;
            theSheet.Animations[CurAnim] = new Animation();
            theSheet.Animations[CurAnim].Frames = new Frame[MAX_FRAMES];
            theSheet.Animations[CurAnim].Frames[CurFrame] = new Frame();

            AnimBox.Items.Add(AnimName.Text);
            AnimName.Text = "";

            FrameBox.Items.Clear();                                
            
        }

        private void DelAnim_Click(object sender, EventArgs e)
        {
            bool foundIt = false;
            for (int i = 0; i < MAX_ANIMS; i++)
            {
                foundIt = true;
                if (foundIt == true)
                {
                    if (i < MAX_ANIMS - 1)
                    {
                        theSheet.Animations[i] = theSheet.Animations[i + 1];
                    }
                    else
                    {
                        theSheet.Animations[i] = new Animation();
                    }
                    if (i < AnimBox.Items.Count - 1)
                    {
                        AnimBox.Items[i] = AnimBox.Items[i + 1];
                    }
                    else if (i == AnimBox.Items.Count - 1)
                    {
                        AnimBox.Items.RemoveAt(i);
                    }
                }
            }
            CurAnim--;
            

        }
        private void WeaponButton_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 1;
            RectType = -1;
        }

        private void AnchorButton_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 0;
            RectType = -1;
        }

        private void TriggerButton_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 2;
            RectType = -1;
        }

        private void AnchorX_ValueChanged(object sender, EventArgs e)
        {
            MousePoint.X = (int)AnchorX.Value;
        }

        private void AnchorY_ValueChanged(object sender, EventArgs e)
        {
            MousePoint.Y = (int)AnchorY.Value;
        }

        private void Duration_ValueChanged(object sender, EventArgs e)
        {
            FrameDuration = (float)Duration.Value;
        }
        
        private void PrevFrame_Click(object sender, EventArgs e)
        {
            if (FrameBox.SelectedIndex - 1 > -1)
            {
                FrameBox.SelectedIndex--;
                PreviewFrame = (short)FrameBox.SelectedIndex;
            }
        }

        private void NextFrame_Click(object sender, EventArgs e)
        {
            if (FrameBox.SelectedIndex + 1 < FrameBox.Items.Count)
            {
                FrameBox.SelectedIndex++;
                PreviewFrame = (short)FrameBox.SelectedIndex;
            }
        }

        private void Play_Click(object sender, EventArgs e)
        {
            isPlaying = true;
        }

        private void Stop_Click(object sender, EventArgs e)
        {
            isPlaying = false;
        }

        private void Reset_Click(object sender, EventArgs e)
        {
            FrameBox.SelectedIndex = 0;
        }

        private void isLoopingCheck_CheckedChanged(object sender, EventArgs e)
        {
            isLooping = isLoopingCheck.Checked;
        }

        private void ZoomIn_Click(object sender, EventArgs e)
        {
            SheetZoom *= 2;
        }

        private void ZoomOut_Click(object sender, EventArgs e)
        {
            SheetZoom /= 2;
        }

        private void FrameBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (FrameBox.SelectedIndex > -1)
            {
                PreviewFrame = (short)FrameBox.SelectedIndex;
                Frames[PreviewFrame] = theSheet.Animations[PreviewAnim].Frames[PreviewFrame];
            }
        }

        private void AnimBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (AnimBox.SelectedIndex > -1)
            {
                Rectangle zero = new Rectangle(0,0,0,0);
                PreviewAnim = (short)AnimBox.SelectedIndex;
                FrameBox.Items.Clear();
                for (int i = 0; theSheet.Animations[PreviewAnim].Frames[i].ImageRect != zero; i++)
                {
                    Frames[i] = theSheet.Animations[PreviewAnim].Frames[i];
                    FrameBox.Items.Add("Frame" + i);                    
                }
            }
        }

        private void TriggerBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (TriggerBox.SelectedIndex > -1)
                Trigger = Triggers[TriggerBox.SelectedIndex].Loc;
        }

        private void saveXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XDocument xmlDoc = new XDocument();

            XDeclaration xmlDecl = new XDeclaration("1.0", "utf-8", "yes");
            xmlDoc.Declaration = xmlDecl;
            XName xmlName;

            xmlName = "Sheet";

            XElement root = new XElement(xmlName);

            xmlDoc.Add(root);

            xmlName = "SheetImage"; 
            XElement path = new XElement(xmlName);

            xmlName = "FilePath";
            XAttribute filepath = new XAttribute(xmlName, theSheet.FilePath);
           
            path.Add(filepath);

            root.Add(path);

            xmlName = "ImageID";
            XElement image = new XElement(xmlName);

            xmlName = "ID";
            XAttribute ID = new XAttribute(xmlName, theSheet.ImageID);
            image.Add(ID);
            root.Add(image);

            xmlName = "Animations";
            XElement Animations = new XElement(xmlName);

            foreach (Animation anim in theSheet.Animations)
            {
                if (anim.AnimName != null)
                {
                    xmlName = "Animation";
                    XElement Animation = new XElement(xmlName);

                    xmlName = "Name";
                    XAttribute Name = new XAttribute(xmlName, anim.AnimName);

                    Animation.Add(Name);

                    xmlName = "Looping";
                    XAttribute Looping = new XAttribute(xmlName, anim.isLooping);

                    Animation.Add(Looping);

                    xmlName = "Frames";
                    XElement Frames = new XElement(xmlName);
                    foreach (Frame frame in anim.Frames)
                    {
                        if (frame.Anchor.X != 0 && frame.Anchor.Y != 0)
                        {
                            xmlName = "Frame";
                            XElement Frame = new XElement(xmlName);

                            xmlName = "Duration";
                            XElement Duration = new XElement(xmlName);

                            xmlName = "Time";
                            XAttribute Time = new XAttribute(xmlName, frame.Duration);

                            Duration.Add(Time);

                            Frame.Add(Duration);
                            
                            xmlName = "Image";
                            XElement Image = new XElement(xmlName);

                            xmlName = "X";
                            XAttribute ImageX = new XAttribute(xmlName, frame.ImageRect.X);

                            Image.Add(ImageX);

                            xmlName = "Y";
                            XAttribute ImageY = new XAttribute(xmlName, frame.ImageRect.Y);

                            Image.Add(ImageY);

                            xmlName = "Width";
                            XAttribute ImageWidth = new XAttribute(xmlName, frame.ImageRect.Width);

                            Image.Add(ImageWidth);

                            xmlName = "Height";
                            XAttribute ImageHeight = new XAttribute(xmlName, frame.ImageRect.Height);

                            Image.Add(ImageHeight);

                            Frame.Add(Image);

                            xmlName = "Collision";
                            XElement Collision = new XElement(xmlName);

                            xmlName = "X";
                            XAttribute CollisionX = new XAttribute(xmlName, frame.CollisionRect.X);

                            Collision.Add(CollisionX);

                            xmlName = "Y";
                            XAttribute CollisionY = new XAttribute(xmlName, frame.CollisionRect.Y);

                            Collision.Add(CollisionY);

                            xmlName = "Width";
                            XAttribute CollisionWidth = new XAttribute(xmlName, frame.CollisionRect.Width);

                            Collision.Add(CollisionWidth);

                            xmlName = "Height";
                            XAttribute CollisionHeight = new XAttribute(xmlName, frame.CollisionRect.Height);

                            Collision.Add(CollisionHeight);

                            Frame.Add(Collision);

                            xmlName = "Attack";
                            XElement Attack = new XElement(xmlName);

                            xmlName = "X";
                            XAttribute AttackX = new XAttribute(xmlName, frame.AttackRect.X);

                            Attack.Add(AttackX);

                            xmlName = "Y";
                            XAttribute AttackY = new XAttribute(xmlName, frame.AttackRect.Y);

                            Attack.Add(AttackY);

                            xmlName = "Width";
                            XAttribute AttackWidth = new XAttribute(xmlName, frame.AttackRect.Width);

                            Attack.Add(AttackWidth);

                            xmlName = "Height";
                            XAttribute AttackHeight = new XAttribute(xmlName, frame.AttackRect.Height);

                            Attack.Add(AttackHeight);

                            Frame.Add(Attack);

                            xmlName = "Anchor";
                            XElement Anchor = new XElement(xmlName);

                            xmlName = "AnchorX";
                            XAttribute AnchorX = new XAttribute(xmlName, frame.Anchor.X);
                            Anchor.Add(AnchorX);

                            xmlName = "AnchorY";
                            XAttribute AnchorY = new XAttribute(xmlName, frame.Anchor.Y);
                            Anchor.Add(AnchorY);

                            Frame.Add(Anchor);

                            xmlName = "Weapon";
                            XElement Weapon = new XElement(xmlName);

                            xmlName = "WeaponX";
                            XAttribute WeaponX = new XAttribute(xmlName, frame.Weapon.X);
                            Weapon.Add(WeaponX);

                            xmlName = "WeaponY";
                            XAttribute WeaponY = new XAttribute(xmlName, frame.Weapon.Y);
                            Weapon.Add(WeaponY);

                            Frame.Add(Weapon);

                            xmlName = "Triggers";
                            XElement Triggers = new XElement(xmlName);
                            foreach (Trigger trigger in frame.Triggers)
                            {
                                if (trigger.Event != null)
                                {
                                    xmlName = "Trigger";
                                    XElement Trigger = new XElement(xmlName);

                                    xmlName = "Event";
                                    XAttribute Event = new XAttribute(xmlName, trigger.Event);

                                    Trigger.Add(Event);
                                    xmlName = "LocX";
                                    XAttribute LocX = new XAttribute(xmlName, trigger.Loc.X);

                                    Trigger.Add(LocX);
                                    xmlName = "LocY";
                                    XAttribute LocY = new XAttribute(xmlName, trigger.Loc.Y);
                                    Trigger.Add(LocY);

                                    Triggers.Add(Trigger);
                                }
                            }
                            Frame.Add(Triggers);
                            Frames.Add(Frame);


                        }
                    }
                    Animation.Add(Frames);
                    Animations.Add(Animation);
                    root.Add(Animations);
                }

            }

            SaveFileDialog dlg = new SaveFileDialog();
            dlg.Filter = "XML Files (*.xml)|*.xml|All Files (*.*)|*.*";
            dlg.ShowDialog();

            xmlDoc.Save(dlg.FileName);



        }

        private void openXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XDocument xmlDoc = new XDocument();
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "XML Files (*.xml)|*.xml|All Files (*.*)|*.*";
            dlg.ShowDialog();

            xmlDoc = XDocument.Load(dlg.FileName);

            theSheet.FilePath = xmlDoc.Root.Element("SheetImage").Attribute("FilePath").Value;
            theSheet.ImageID = Convert.ToInt32(xmlDoc.Root.Element("ImageID").Attribute("ID").Value);

            IEnumerable<XElement> Animations = xmlDoc.Root.Element("Animations").Descendants("Animation");
            int animCounter = 0, frameCounter = 0, triggerCounter = 0;
            foreach (XElement animation in Animations)
            {
                theSheet.Animations[animCounter].AnimName = animation.Attribute("Name").Value;
                theSheet.Animations[animCounter].isLooping = Convert.ToBoolean(animation.Attribute("Looping").Value);

                IEnumerable<XElement> Frames = animation.Element("Frames").Descendants("Frame");
                frameCounter = 0;
                foreach (XElement frame in Frames)
                {
                    theSheet.Animations[animCounter].Frames[frameCounter].Duration = (float)Convert.ToDecimal(frame.Element("Duration").Attribute("Time").Value);

                    theSheet.Animations[animCounter].Frames[frameCounter].ImageRect.X = Convert.ToInt32(frame.Element("Image").Attribute("X").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].ImageRect.Y = Convert.ToInt32(frame.Element("Image").Attribute("Y").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].ImageRect.Width = Convert.ToInt32(frame.Element("Image").Attribute("Width").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].ImageRect.Height = Convert.ToInt32(frame.Element("Image").Attribute("Height").Value);

                    theSheet.Animations[animCounter].Frames[frameCounter].CollisionRect.X = Convert.ToInt32(frame.Element("Collision").Attribute("X").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].CollisionRect.Y = Convert.ToInt32(frame.Element("Collision").Attribute("Y").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].CollisionRect.Width = Convert.ToInt32(frame.Element("Collision").Attribute("Width").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].CollisionRect.Height = Convert.ToInt32(frame.Element("Collision").Attribute("Height").Value);
                
                    theSheet.Animations[animCounter].Frames[frameCounter].AttackRect.X = Convert.ToInt32(frame.Element("Attack").Attribute("X").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].AttackRect.Y = Convert.ToInt32(frame.Element("Attack").Attribute("Y").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].AttackRect.Width = Convert.ToInt32(frame.Element("Attack").Attribute("Width").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].AttackRect.Height = Convert.ToInt32(frame.Element("Attack").Attribute("Height").Value);

                    theSheet.Animations[animCounter].Frames[frameCounter].Anchor.X = Convert.ToInt32(frame.Element("Anchor").Attribute("AnchorX").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].Anchor.Y = Convert.ToInt32(frame.Element("Anchor").Attribute("AnchorY").Value);

                    theSheet.Animations[animCounter].Frames[frameCounter].Weapon.X = Convert.ToInt32(frame.Element("Weapon").Attribute("WeaponX").Value);
                    theSheet.Animations[animCounter].Frames[frameCounter].Weapon.Y = Convert.ToInt32(frame.Element("Weapon").Attribute("WeaponY").Value);

                    IEnumerable<XElement> Triggers = frame.Element("Triggers").Descendants("Trigger");
                    triggerCounter = 0;
                    foreach (XElement trigger in Triggers)
                    {
                        theSheet.Animations[animCounter].Frames[frameCounter].Triggers[triggerCounter].Event = trigger.Attribute("Event").Value;
                        theSheet.Animations[animCounter].Frames[frameCounter].Triggers[triggerCounter].Loc.X = Convert.ToInt32(trigger.Attribute("LocX").Value);
                        theSheet.Animations[animCounter].Frames[frameCounter].Triggers[triggerCounter].Loc.Y = Convert.ToInt32(trigger.Attribute("LocY").Value);
                        triggerCounter++;
                    }
                    frameCounter++;
                }
                animCounter++;
            }

            theSheet.ImageID = TM.LoadTexture(theSheet.FilePath, Color.FromArgb(0, 0, 0, 0).ToArgb());
            SheetImageID = TM.LoadTexture(theSheet.FilePath, Color.White.ToArgb());

            UpdateValues();

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Point zero = new Point(0, 0);

            SaveFileDialog saveDlg = new SaveFileDialog();
            saveDlg.ShowDialog();

            FileStream stream = new FileStream(saveDlg.FileName, FileMode.Create);
            BinaryWriter binWrite = new BinaryWriter(stream);

            if (theSheet.FilePath != null)
            {
               
                binWrite.Write(theSheet.FilePath);
            }
            else
            {
                
                binWrite.Write("NULL PATH");
            }
            
            binWrite.Write(theSheet.ImageID);
            int i;
            for (i = 0; i < MAX_ANIMS; i++)
            {
                if (theSheet.Animations[i].AnimName == null)
                {
                    break;
                }
            }
            binWrite.Write(i);

            for (; i > 0; i--)
            {
                if (theSheet.Animations[i-1].AnimName != null)
                {
                    
                    binWrite.Write(theSheet.Animations[i-1].AnimName);
                }
                else
                {
                    
                    binWrite.Write("NULL ANIMATION");
                }

                binWrite.Write(theSheet.Animations[i].isLooping);

                int j;
                for (j = 0; j < MAX_FRAMES; j++)
                {
                    if (theSheet.Animations[i-1].Frames[j].Anchor.X == 0 && theSheet.Animations[i-1].Frames[j].Anchor.Y == 0)
                    {
                        break;
                    }
                }
                binWrite.Write(j);
                for (; j > 0; j--)
                {

                    binWrite.Write(theSheet.Animations[i-1].Frames[j-1].Duration);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].Anchor.X);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].Anchor.Y);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].Weapon.X);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].Weapon.Y);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].ImageRect.X);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].ImageRect.Y);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].ImageRect.Width);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].ImageRect.Height);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].CollisionRect.X);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].CollisionRect.Y);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].CollisionRect.Width);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].CollisionRect.Height);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].AttackRect.X);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].AttackRect.Y);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].AttackRect.Width);
                    binWrite.Write(theSheet.Animations[i - 1].Frames[j - 1].AttackRect.Height);

                    if (theSheet.Animations[i-1].Frames[j-1].Triggers != null)
                    {
                        if (theSheet.Animations[i-1].Frames[j-1].Triggers.Length > 0)
                        {
                            int k;
                            for (k = 0; k < MAX_TRIGGERS; k++)
                            {
                                if (theSheet.Animations[i-1].Frames[j-1].Triggers[k].Event == null)
                                {
                                    break;
                                }
                            }
                            binWrite.Write(k);

                            for (; k > 0; k--)
                            {
                                if (theSheet.Animations[i-1].Frames[j-1].Triggers[k-1].Event != null)
                                {
                                    
                                    binWrite.Write(theSheet.Animations[i-1].Frames[j-1].Triggers[k-1].Event);
                                }
                                else
                                {
                                   
                                    binWrite.Write("NULL TRIGGER");
                                }

                                binWrite.Write(theSheet.Animations[i-1].Frames[j-1].Triggers[k-1].Loc.X);
                                binWrite.Write(theSheet.Animations[i-1].Frames[j-1].Triggers[k-1].Loc.Y);


                            }
                        }
                    }
                    else
                        binWrite.Write(0);
                }
            }
        }
    



        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            InitializeComponent();

            // Set looping to true cause we want don't want the window to instantly go 'poof'
            Looping = true;

            isPlaying = false;

            // Make a zero point and set our points to it so they are not full of trash
            Point zero = new Point(0, 0);
            a = b = zero;

            SheetZoom = 1;

            // Set the RectType to 0 for drawing the Image Rect by default
            RectType = -1;

            PointType = -1;

            theSheet = new Sheet();
            scrollSize.Width = 0;
            scrollSize.Height = 0;

            CurTrigger = 0;
            MAX_TRIGGERS = 10;

            CurFrame = 0;
            PreviewFrame = 0;
            MAX_FRAMES = 30;

            CurAnim = 0;
            PreviewAnim = 0;
            MAX_ANIMS = 50;

            isLooping = false;

            XOffSet = 0;
            YOffSet = 0;

            D3D.InitManagedDirect3D(SpriteSheetPanel, false);
            TM.InitManagedTextureManager(D3D.Device, D3D.Sprite);


            // Load in the sprite sheet (for now a default for debugging purposes)
            //theSheet.ImageID = TM.LoadTexture("C:\\Users\\Dr. Snow\\Documents\\School\\SGP\\Animation Editor\\Animation Editor\\Resources\\Sprites\\SpriteSheet.png", Color.FromArgb(0, 0, 0, 0).ToArgb());

            //SheetImageID = TM.LoadTexture("C:\\Users\\Dr. Snow\\Documents\\School\\SGP\\Animation Editor\\Animation Editor\\Resources\\Sprites\\SpriteSheet.png", Color.FromArgb(0, 0, 0, 0).ToArgb());

            theSheet.Animations = new Animation[MAX_ANIMS];

            Triggers = new Trigger[MAX_TRIGGERS];
            Frames = new Frame[MAX_FRAMES];
            for (int i = 0; i < theSheet.Animations.Length; i++)
            {
                theSheet.Animations[i].Frames = new Frame[MAX_FRAMES];
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void collisionRectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Point zero = new Point(0, 0);
            a = zero;
            b = zero;
            MouseRect = new Rectangle(0, 0, 0, 0);
            RectType = 1;
            PointType = -1;
        }

        private void renderRectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Point zero = new Point();
            a = zero;
            b = zero;
            MouseRect = new Rectangle();
            RectType = 0;
            PointType = -1;
        }

        private void anchorPointToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 0;
            RectType = -1;
        }

        private void weaponPointToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 1;
            RectType = -1;
        }

        private void triggersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MousePoint = new Point(0, 0);
            PointType = 2;
            RectType = -1;
        }

        private void vSpriteBar_Scroll(object sender, ScrollEventArgs e)
        {
            Update();
            Render();
        }

        private void hSpriteBar_Scroll(object sender, ScrollEventArgs e)
        {
            Update();
            Render();
        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            UpdateValues();
            
        }

    }
}
