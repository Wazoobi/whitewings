


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using SGD;
using System.Collections;
using System.Xml.Linq;
using System.IO;

namespace WindowsFormsApplication1
{

    public partial class Form1 : Form
    {
        ManagedDirect3D D3D_Image = ManagedDirect3D.Instance;
        ManagedTextureManager TM_ImagePort = ManagedTextureManager.Instance;

        Layer[] TileLayers;
        short CurLayer = 1;
        int CURRENT_WIDTH = 3200;
        int CURRENT_HEIGHT = 3200;

        int TILE_WIDTH = 32;
        int TILE_HEIGHT = 32;

        


        // Import vars
        public bool ItemImage = false;
        public bool TileAppend = false;
        public bool TileNew = false;
        public bool BackGroundImage = false;
        public string ImageFileName;
        public string TriggerString;
        public Point TriggerPoint;
        public bool TriggerChange;

        //Tile Set Storage Variables
        public short[] TileIds = new short[50];
        public short TotalTileImages = 0;
        public Rectangle TileSelection;

        public Point[] PointsToBeDrawn;
        public short TotalPointsToBeDrawn = 0;
        public bool dragging = false;
        public bool rDragging = false;

        public Point RClickMenu = Point.Empty;

        public String toWrite;
        public String toWriteEvents;

        //Map Image Storage
        short BackGroundID = -1;

        bool DrawTile = true;
        bool DrawFill = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            D3D_Image.InitManagedDirect3D(ImageViewPort, false);
            TM_ImagePort.InitManagedTextureManager(D3D_Image.Device, D3D_Image.Sprite);
            


            //initialize the layers
            TileLayers = new Layer[5];
            for (int i = 0; i < 5; ++i)
            {
                TileLayers[i] = new Layer();
                TileLayers[i].LayerNum = (short)i;
            }

            


            // init the "Updates"
            Image_Timer.Enabled = true;
            Tiles_Timer.Enabled = true;


            btnTile.Enabled = false;

            numericUpDown3.Value = 32;
            numericUpDown4.Value = 32;


          
        }

        private void Image_Timer_Tick(object sender, EventArgs e)
        {
            D3D_Image.ChangeDisplayParam(ImageViewPort, false);
            D3D_Image.DeviceBegin();
            D3D_Image.SpriteBegin();

            D3D_Image.Clear(255, 255, 255);

            //////////////////////////////////////////////////////////////////////////
            // Update / Check for Background
            if (BackGroundImage == true)
            {
                BackGroundID = (short)TM_ImagePort.LoadTexture(ImageFileName, Color.White.ToArgb());
                BackGroundImage = false;
            }

            if (BackGroundID != -1)
            {
                TM_ImagePort.Draw(BackGroundID, -hScrollBar1.Value, -vScrollBar1.Value, 1, 1, Rectangle.Empty, 0, 0, 0, Color.White.ToArgb());
            }


            hScrollBar1.Maximum = CURRENT_WIDTH + hScrollBar1.Height;
            vScrollBar1.Maximum = CURRENT_HEIGHT + vScrollBar1.Width;

            //
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            // Accessing the Point Array
            //--------------------------------------------------------------------
            // Algorithm for accessing a 1D like a 2D array
            // Height (20) * the Y + the X



            for (int k = 0; k < CurLayer; ++k) //Now we draw back to front
            {
                if (TileLayers[k].TilePoints != null)
                {

                    for (int j = 0; j < TileLayers[k].TotalPointsClicked; ++j)
                    {
                        if (TileLayers[k].PointsClicked[j].X >= hScrollBar1.Value && TileLayers[k].PointsClicked[j].X <= hScrollBar1.Value + TILE_WIDTH * 26)
                        {
                            if (TileLayers[k].PointsClicked[j].Y >= vScrollBar1.Value && TileLayers[k].PointsClicked[j].Y <= vScrollBar1.Value + 20 * TILE_HEIGHT)
                            {

                                Point toDrawPoint = Point.Empty; //where in the IMAGE panel we a drawing to

                                Size toDrawSize = Size.Empty; //for simplicity's sake we store the size of the rect
                                toDrawSize.Width = TILE_WIDTH;
                                toDrawSize.Height = TILE_HEIGHT;

                                Rectangle toDrawAt = Rectangle.Empty; //the section of the bitmap in the TILE panel where we are drawing from


                                toDrawPoint = TileLayers[k].PointsClicked[j];
                                toDrawAt = new Rectangle(TileLayers[k].TilePoints[j], toDrawSize); //And what to draw?


                                if (TileLayers[k].TotalPointsClicked != 0) //if we are layered... sighz
                                    for (int l = 0; l < TileLayers[k].TotalPointsClicked; ++l) //Loop through the points clicked array
                                        if (TileLayers[k].PointsClicked[l].X == toDrawPoint.X &&
                                            TileLayers[k].PointsClicked[l].Y == toDrawPoint.Y) //if there is a point that has been clicked
                                            if (TileLayers[k].LayerNum == CurLayer - 1) //if its the current layer
                                            {
                                                for (int z = 0; z < TotalTileImages; ++z)
                                                {//Loop through to make sure we are at the proper image
                                                    if (TileLayers[k].TilePoints[j].X <= TM_ImagePort.GetTextureWidth(z))
                                                        TM_ImagePort.Draw(TileIds[z], toDrawPoint.X - hScrollBar1.Value, toDrawPoint.Y - vScrollBar1.Value, 1, 1, toDrawAt, 0, 0, 0, Color.White.ToArgb());
                                                }
                                            }
                                            else //otherwise it will be grayed out
                                                for (int z = 0; z < TotalTileImages; ++z) //So we loop... again
                                                    if (TileLayers[k].TilePoints[j].X <= TM_ImagePort.GetTextureWidth(z))
                                                        TM_ImagePort.Draw(TileIds[z], toDrawPoint.X - hScrollBar1.Value, toDrawPoint.Y - vScrollBar1.Value, 1, 1, toDrawAt, 0, 0, 0, Color.DarkGray.ToArgb());
                                                    else if (TileLayers[k].PointsClicked[l] != toDrawPoint && TileLayers[k].TotalPointsClicked == l) //Otherwise this current iteration is not a drawn tile
                                                        continue;
                            }
                        }
                    }

                }

            }


            // End Draw
            //////////////////////////////////////////////////////////////////////////

            D3D_Image.SpriteEnd();
         

            //////////////////////////////////////////////////////////////////////////
            // Line Drawing (ImagePort)
            int index = TILE_WIDTH - (hScrollBar1.Value % TILE_WIDTH);
            for (int i = 0; i < ImageViewPort.Width / TILE_WIDTH; ++i )
            {
                D3D_Image.DrawLine(index,
                                   0,
                                   index,
                                   ImageViewPort.Height,
                                   0, 0, 0);
                index += TILE_WIDTH;
            }


            index = TILE_HEIGHT - (vScrollBar1.Value % TILE_HEIGHT);
            for (int i = 0; i < ImageViewPort.Height / TILE_HEIGHT; ++i )
            {
                D3D_Image.DrawLine(0,
                                   index,
                                   ImageViewPort.Width,
                                   index,
                                   0,0,0);
                index += TILE_HEIGHT;
            }
            // End Line Drawing
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            // Collision Rects & Trigger Rects Drawing

            //(5) = total amount of layers
            Rectangle drawRect = Rectangle.Empty;
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < TileLayers[CurLayer - 1].TotalCollideableTiles; ++j)
                {
                    drawRect.Location = TileLayers[CurLayer - 1].PointsCollideable[j];
                    drawRect.Width = TILE_WIDTH;
                    drawRect.Height = TILE_HEIGHT;


                    D3D_Image.DrawLine(drawRect.X - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value,
                   255, 0, 0); //Top Left to Top Right
                    D3D_Image.DrawLine(drawRect.Left - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, drawRect.Left - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        255, 0, 0); //Top Left to Bottom Left
                    D3D_Image.DrawLine(drawRect.X - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        255, 0, 0); //Bottom Left to Bottom Right
                    D3D_Image.DrawLine((drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        255, 0, 0); //Top Right to Bottom Right
                }

                for (int j = 0; j < TileLayers[CurLayer - 1].TotalTriggers; ++j)
                {
                    drawRect.Location = TileLayers[CurLayer - 1].Triggers[j].TriggerPosition;
                    drawRect.Width = TILE_WIDTH;
                    drawRect.Height = TILE_HEIGHT;


                    D3D_Image.DrawLine(drawRect.X - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value,
                   0, 255, 0); //Top Left to Top Right
                    D3D_Image.DrawLine(drawRect.Left - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, drawRect.Left - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        0, 255, 0); //Top Left to Bottom Left
                    D3D_Image.DrawLine(drawRect.X - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        0, 255, 0); //Bottom Left to Bottom Right
                    D3D_Image.DrawLine((drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, drawRect.Y - (int)vScrollBar1.Value, (drawRect.X + TILE_WIDTH) - (int)hScrollBar1.Value, (drawRect.Y + TILE_HEIGHT) - (int)vScrollBar1.Value,
                        0, 255, 0); //Top Right to Bottom Right
                }
            }


            //
            //////////////////////////////////////////////////////////////////////////

            D3D_Image.DeviceEnd();
            D3D_Image.Present();

        }

        private void Tiles_Timer_Tick(object sender, EventArgs e)
        {

            D3D_Image.ChangeDisplayParam(tabTiles, false);
            D3D_Image.DeviceBegin();
            D3D_Image.SpriteBegin();
            D3D_Image.Clear(255, 255, 255);


            //////////////////////////////////////////////////////////////////////////
            // Update the image
            if (ItemImage == true) //If the new image is an Item
            {

                ItemImage = false;
            }
            else if (TileNew == true) //if they want this to be the new tile set.
            {

                //Clear and release any Images that were in the array
                for (int i = 0; i < 50; ++i)
                {
                    TM_ImagePort.ReleaseTexture(TileIds[i]);
                }

                //Forget about and other images
                TotalTileImages = 0;

                //Load in the new image
                //TileIds[0] = (short)TM_ImagePort.LoadTexture(ImageFileName, 0);

                //Flip the bool off
                TileNew = false;
            }
            else if (TileAppend == true) //if they have appended a new tile set
            {
                //Add a new Tile Image to the end of the Tile ID array
                TileIds[TotalTileImages] = (short)TM_ImagePort.LoadTexture(ImageFileName, 0);

                //Update the total images
                TotalTileImages++;

                //Really you're reading what this does and can't figure it out???
                TileAppend = false;
            }

            if (TriggerChange == true)
            {
                TileLayers[CurLayer - 1].Triggers[TileLayers[CurLayer - 1].TotalTriggers].EventString = TriggerString;
                TileLayers[CurLayer - 1].TotalTriggers++;
                TriggerChange = false;
            }

            // End Update
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            // Drawing The TileSets

            //Variables to determine the size of the image
            int TotalWidths = 0;
            int MaxHeight = 0;

            for (int i = 0; i < TotalTileImages; ++i)
            {
                //Update the size of the image
                TotalWidths += TM_ImagePort.GetTextureWidth(i);
                

                //Check to see if the image is any taller
                if (MaxHeight <= TM_ImagePort.GetTextureHeight(i))
                    MaxHeight = TM_ImagePort.GetTextureHeight(i);

                hScrollBar2.Maximum = TotalWidths;
                vScrollBar2.Maximum = MaxHeight;

                //Draw the image
                TM_ImagePort.Draw(TileIds[i], (i * TotalWidths) - hScrollBar2.Value, -vScrollBar2.Value, 1, 1, Rectangle.Empty, 0, 0, 0, Color.White.ToArgb());
            }


            // End Draw
            //////////////////////////////////////////////////////////////////////////

            //Finish Drawing Images
            D3D_Image.SpriteEnd();


            //////////////////////////////////////////////////////////////////////////
            // Line Drawing (Tile Port)
            for (int i = (hScrollBar2.Value / TILE_WIDTH); i < (hScrollBar2.Value / TILE_WIDTH) + tabTiles.Width; ++i)
            {
                D3D_Image.DrawLine((i * TILE_WIDTH) - hScrollBar2.Value, ((vScrollBar2.Value / TILE_HEIGHT) * TILE_HEIGHT), (i * TILE_WIDTH) - hScrollBar2.Value, tabTiles.Height - vScrollBar2.Value, 1, 1, 1);
            }
            for (int i = (vScrollBar2.Value / TILE_HEIGHT); i < (vScrollBar2.Value / TILE_HEIGHT) + tabTiles.Height; ++i)
            {
                D3D_Image.DrawLine(((hScrollBar2.Value / TILE_WIDTH) * TILE_WIDTH), (i * TILE_HEIGHT) - vScrollBar2.Value, tabTiles.Width - hScrollBar2.Value, (i * TILE_HEIGHT) - vScrollBar2.Value, 1, 1, 1);
            }
            // End Line Drawing
            //////////////////////////////////////////////////////////////////////////


            if (TileSelection != Rectangle.Empty)    // Tile Selection Drawing
            {
                D3D_Image.DrawLine(TileSelection.X - (int)hScrollBar2.Value, TileSelection.Y - (int)vScrollBar2.Value, (TileSelection.X + TILE_WIDTH) - (int)hScrollBar2.Value, TileSelection.Y - (int)vScrollBar2.Value,
                    255, 0, 0); //Top Left to Top Right
                D3D_Image.DrawLine(TileSelection.Left - (int)hScrollBar2.Value, TileSelection.Y - (int)vScrollBar2.Value, TileSelection.Left - (int)hScrollBar2.Value, (TileSelection.Y + TILE_HEIGHT) - (int)vScrollBar2.Value,
                    255, 0, 0); //Top Left to Bottom Left
                D3D_Image.DrawLine(TileSelection.X - (int)hScrollBar2.Value, (TileSelection.Y + TILE_HEIGHT) - (int)vScrollBar2.Value, (TileSelection.X + TILE_WIDTH) - (int)hScrollBar2.Value, (TileSelection.Y + TILE_HEIGHT) - (int)vScrollBar2.Value,
                    255, 0, 0); //Bottom Left to Bottom Right
                D3D_Image.DrawLine((TileSelection.X + TILE_WIDTH) - (int)hScrollBar2.Value, TileSelection.Y - (int)vScrollBar2.Value, (TileSelection.X + TILE_WIDTH) - (int)hScrollBar2.Value, (TileSelection.Y + TILE_HEIGHT) - (int)vScrollBar2.Value,
                    255, 0, 0); //Top Right to Bottom Right
            }

            //Draw everything
            D3D_Image.DeviceEnd();
            D3D_Image.Present();
        }

        private void importToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Create the dialog
            OpenFileDialog dlg = new OpenFileDialog();
            if (dlg.ShowDialog() == DialogResult.OK) //if they press OK
            {
                //Flip all of the update bools
                TileAppend = false;
                TileNew = false;
                ItemImage = false;

                //Publicly store the filepath
                ImageFileName = dlg.FileName;


                //Open the import dialog and set it up
                ImportDialog Idlg = new ImportDialog();
                Idlg.parent = this;
                Idlg.Show();


            }

        }

        private void tabTiles_MouseClick(object sender, MouseEventArgs e)
        {
            int MouseX = e.Location.X + hScrollBar2.Value;
            int MouseY = e.Location.Y + vScrollBar2.Value;

            MouseX /= TILE_WIDTH;
            MouseY /= TILE_HEIGHT;

            MouseX *= TILE_WIDTH;
            MouseY *= TILE_HEIGHT;

            
           
            TileSelection.X = MouseX;
            TileSelection.Y = MouseY;
            TileSelection.Width = TILE_WIDTH;
            TileSelection.Height = TILE_HEIGHT;

        }

        private void ImageViewPort_MouseClick(object sender, MouseEventArgs e)
        {

          
        }

       
        private void btnLayerDown_Click(object sender, EventArgs e)
        {
            if (CurLayer - 1 != 0)
            {
                CurLayer--;
                label3.Text = "Current Layer: " + CurLayer.ToString();
            }
            else
                MessageBox.Show("At the lowest layer");
        }

        private void collideableTileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
                    
                
            //else
            //{

            //}
        }

        private void btnLayerUp_Click(object sender, EventArgs e)
        {

            if (CurLayer >= 5)
            {
                MessageBox.Show("At the top layer");
            }
            else
            {
                CurLayer++;
                label3.Text = "Current Layer: " + CurLayer.ToString();
            }
        }

        private void btndellayer_Click(object sender, EventArgs e)
        {
            TileLayers[CurLayer - 1].PointsClicked = null;
            TileLayers[CurLayer - 1].TilePoints = null;
            TileLayers[CurLayer - 1].PointsCollideable = null;
            TileLayers[CurLayer - 1].TotalCollideableTiles = 0;
            TileLayers[CurLayer - 1].TotalPointsClicked = 0;
            TileLayers[CurLayer - 1].TotalTilePoints = 0;
        }

        private void btndelall_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 5; ++i)
            {
                TileLayers[i].PointsClicked = null;
                TileLayers[i].TilePoints = null;
                TileLayers[i].PointsCollideable = null;
                TileLayers[i].TotalCollideableTiles = 0;
                TileLayers[i].TotalPointsClicked = 0;
                TileLayers[i].TotalTilePoints = 0;
            }
        }

        private void btnFill_Click(object sender, EventArgs e)
        {
            DrawFill = true;
            DrawTile = false;

            btnTile.Enabled = true;
            btnFill.Enabled = false;
        }

        private void btnTile_Click(object sender, EventArgs e)
        {
            DrawTile = true;
            DrawFill = false;

            btnTile.Enabled = false;
            btnFill.Enabled = true;
        }

        private void ImageViewPort_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                if (dragging == false)
                    dragging = true;

                int MouseX = e.Location.X + hScrollBar1.Value;
                int MouseY = e.Location.Y + vScrollBar1.Value;

                MouseX /= TILE_WIDTH;
                MouseY /= TILE_HEIGHT;

                MouseX *= TILE_WIDTH;
                MouseY *= TILE_HEIGHT;
                if (DrawTile == true && rNone.Checked == true)
                {

                    //////////////////////////////////////////////////////////////////////////
                    // Gathering the Point Clicked

                    

                    if (DrawTile == true)
                    {
                        if (TileLayers[CurLayer - 1].PointsClicked != null) //if there are points already
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the array
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i) //Swap the array
                                temp[i] = TileLayers[CurLayer - 1].PointsClicked[i];
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the actual array
                            TileLayers[CurLayer - 1].PointsClicked = temp;
                        }
                        else
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1];


                        TileLayers[CurLayer - 1].PointsClicked[TileLayers[CurLayer - 1].TotalPointsClicked] = new Point(MouseX, MouseY); // add the point where clicked to the array
                        TileLayers[CurLayer - 1].TotalPointsClicked++; //increment the total points clicked

                        if (TileLayers[CurLayer - 1].TilePoints != null)
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalTilePoints + 1];
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                                temp[i] = TileLayers[CurLayer - 1].TilePoints[i];
                            TileLayers[CurLayer - 1].TilePoints = new Point[TileLayers[CurLayer - 1].TotalTilePoints];
                            TileLayers[CurLayer - 1].TilePoints = temp;

                        }
                        else
                            TileLayers[CurLayer - 1].TilePoints = new Point[1];

                        TileLayers[CurLayer - 1].TilePoints[TileLayers[CurLayer - 1].TotalTilePoints] = TileSelection.Location;
                        TileLayers[CurLayer - 1].TotalTilePoints++;
                    }
                    else if (dragging == false && PointsToBeDrawn != null)
                    {
                        PointsToBeDrawn = null;
                        TotalPointsToBeDrawn = 0;
                    }
                }
                else if (DrawFill == true && rNone.Checked == true)
                {

                    //////////////////////////////////////////////////////////////////////////
                    // Filling
                    // Oh GOD

                    //Things that we are going to check up against

                    

                    Point toFill = new Point(MouseX, MouseY);
                    Point toDrawFrom = new Point(TileSelection.X, TileSelection.Y);
                    Queue<Point> toBeFilled = new Queue<Point>();

                    //////////////////////////////////////////////////////////////////////////
                    // Variables to save the current state of the image in case we blow the hell up
                    Point[] tempPoints = TileLayers[CurLayer - 1].PointsClicked;
                    Point[] tempTiles = TileLayers[CurLayer - 1].TilePoints;
                    short tempTotalPoints = TileLayers[CurLayer - 1].TotalPointsClicked;
                    short tempTotalTiles = TileLayers[CurLayer - 1].TotalTilePoints;

                    //////////////////////////////////////////////////////////////////////////
                    // Have to begin with something
                    toBeFilled.Enqueue(toFill);
                    Point toCheck;

                    //////////////////////////////////////////////////////////////////////////
                    //------------------------------------------------------------------------

                    //The Algorithm. Well I'm a genius. In my own world. Haha this didn't turn out near as well as I thought...
                    //Basically you take the initial point and add it to a queue. Then you check the tile to its left, right, top, and bottom
                    //if any of them aren't the tile you're trying to color, add them to the queue. after you have checked them all, you color the
                    //the tile that you're on. Then it continues until the queue is empty. But I kinda have conflicting architecture. /sigh

                    //------------------------------------------------------------------------
                    //////////////////////////////////////////////////////////////////////////
                    while (toBeFilled.Count != 0)
                    {
                        if (toBeFilled.Count >= 4000)
                        {
                            TileLayers[CurLayer - 1].PointsClicked = tempPoints;
                            TileLayers[CurLayer - 1].TilePoints = tempTiles;
                            TileLayers[CurLayer - 1].TotalTilePoints = tempTotalTiles;
                            TileLayers[CurLayer - 1].TotalPointsClicked = tempTotalPoints;
                            MessageBox.Show("Exceeds fill limit");

                            return;
                        }

                        toFill = toBeFilled.Dequeue();
                        toCheck = new Point(toFill.X - TILE_WIDTH, toFill.Y);
                        if (toCheck.X >= 0 && toCheck.X <= 800 && toCheck.Y >= 0 && toCheck.Y <= 600)
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i)
                            {
                                if (TileLayers[CurLayer - 1].PointsClicked[i] == toCheck)
                                {
                                    if (TileLayers[CurLayer - 1].TilePoints[i] != toDrawFrom)
                                    {
                                        toBeFilled.Enqueue(toCheck);
                                    }
                                    else
                                        break;
                                }

                                if (i == TileLayers[CurLayer - 1].TotalPointsClicked - 1)
                                {
                                    toBeFilled.Enqueue(toCheck);

                                }
                            }

                        toCheck.X += TILE_WIDTH;


                        toCheck = new Point(toCheck.X + TILE_WIDTH, toCheck.Y);
                        if (toCheck.X >= 0 && toCheck.X <= 800 && toCheck.Y >= 0 && toCheck.Y <= 600)
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                            {
                                if (TileLayers[CurLayer - 1].PointsClicked[i] == toCheck)
                                {
                                    if (TileLayers[CurLayer - 1].TilePoints[i] != toDrawFrom)
                                    {
                                        toBeFilled.Enqueue(toCheck);

                                    }
                                    else
                                        break;
                                }

                                if (i == TileLayers[CurLayer - 1].TotalPointsClicked - 1)
                                {
                                    toBeFilled.Enqueue(toCheck);

                                }

                            }

                        toCheck.X -= TILE_WIDTH;


                        toCheck = new Point(toCheck.X, toCheck.Y - TILE_HEIGHT);
                        if (toCheck.X >= 0 && toCheck.X <= 800 && toCheck.Y >= 0 && toCheck.Y <= 800)
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                            {
                                if (TileLayers[CurLayer - 1].PointsClicked[i] == toCheck)
                                {
                                    if (TileLayers[CurLayer - 1].TilePoints[i] != toDrawFrom)
                                    {
                                        toBeFilled.Enqueue(toCheck);

                                    }
                                    else
                                        break;
                                }
                                if (i == TileLayers[CurLayer - 1].TotalPointsClicked - 1)
                                {
                                    toBeFilled.Enqueue(toCheck);

                                }

                            }


                        toCheck.Y += TILE_HEIGHT;

                        toCheck = new Point(toCheck.X, toCheck.Y + TILE_HEIGHT);
                        if (toCheck.X >= 0 && toCheck.X <= 800 && toCheck.Y >= 0 && toCheck.Y <= 800)
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                            {
                                if (TileLayers[CurLayer - 1].PointsClicked[i] == toCheck)
                                {
                                    if (TileLayers[CurLayer - 1].TilePoints[i] != toDrawFrom)
                                    {
                                        toBeFilled.Enqueue(toCheck);

                                    }
                                    else
                                        break;
                                }
                                if (i == TileLayers[CurLayer - 1].TotalPointsClicked - 1)
                                {
                                    toBeFilled.Enqueue(toCheck);

                                }

                            }


                        toCheck.Y -= TILE_HEIGHT;


                        if (TileLayers[CurLayer - 1].PointsClicked != null) //if there are points already
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the array
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i) //Swap the array
                                temp[i] = TileLayers[CurLayer - 1].PointsClicked[i];
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the actual array
                            TileLayers[CurLayer - 1].PointsClicked = temp;
                        }
                        else
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1];


                        TileLayers[CurLayer - 1].PointsClicked[TileLayers[CurLayer - 1].TotalPointsClicked] = new Point(toCheck.X, toCheck.Y); // add the point where clicked to the array
                        TileLayers[CurLayer - 1].TotalPointsClicked++; //increment the total points clicked

                        if (TileLayers[CurLayer - 1].TilePoints != null)
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalTilePoints + 1];
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                                temp[i] = TileLayers[CurLayer - 1].TilePoints[i];
                            TileLayers[CurLayer - 1].TilePoints = new Point[TileLayers[CurLayer - 1].TotalTilePoints];
                            TileLayers[CurLayer - 1].TilePoints = temp;

                        }
                        else
                            TileLayers[CurLayer - 1].TilePoints = new Point[1];

                        TileLayers[CurLayer - 1].TilePoints[TileLayers[CurLayer - 1].TotalTilePoints] = TileSelection.Location;
                        TileLayers[CurLayer - 1].TotalTilePoints++;


                    }
                }


                // End Point Gathering
                //////////////////////////////////////////////////////////////////////////

                else if (rCollision.Checked == true && DrawFill != true)
                {
                    Point tempPoint = Point.Empty;
                    tempPoint.X = MouseX;
                    tempPoint.Y = MouseY;
                    tempPoint.X += hScrollBar1.Value;
                    tempPoint.Y += vScrollBar1.Value;

                    tempPoint.X = ((tempPoint.X / 32) * 32);
                    tempPoint.Y = ((tempPoint.Y / 32) * 32);


                    if (TileLayers[CurLayer - 1].TotalCollideableTiles == 0)
                    {
                        TileLayers[CurLayer - 1].PointsCollideable = new Point[1];
                    }
                    else
                    {
                        Point[] temp = new Point[TileLayers[CurLayer - 1].TotalCollideableTiles + 1];
                        for (int j = 0; j < TileLayers[CurLayer - 1].TotalCollideableTiles; ++j)
                            temp[j] = TileLayers[CurLayer - 1].PointsCollideable[j];
                        TileLayers[CurLayer - 1].PointsCollideable = new Point[TileLayers[CurLayer - 1].TotalCollideableTiles];
                        TileLayers[CurLayer - 1].PointsCollideable = temp;
                    }
                    TileLayers[CurLayer - 1].PointsCollideable[TileLayers[CurLayer - 1].TotalCollideableTiles] = tempPoint;
                    TileLayers[CurLayer - 1].TotalCollideableTiles++;
                }
                else if (rTrigger.Checked == true && DrawFill != true)
                {
                    Event_String dlg = new Event_String();
                    dlg.parent = this;
                    dlg.Show();

                    Point tempPoint = new Point(MouseX, MouseY);
                    tempPoint.X += hScrollBar1.Value;
                    tempPoint.Y += vScrollBar1.Value;

                    tempPoint.X = ((tempPoint.X / 32) * 32);
                    tempPoint.Y = ((tempPoint.Y / 32) * 32);

                    if (TileLayers[CurLayer - 1].Triggers != null)
                    {

                        Trigger[] temp = new Trigger[TileLayers[CurLayer - 1].TotalTriggers + 1];
                        for (int i = 0; i < TileLayers[CurLayer - 1].TotalTriggers; ++i)
                            temp[i] = TileLayers[CurLayer - 1].Triggers[i];
                        TileLayers[CurLayer - 1].Triggers = new Trigger[TileLayers[CurLayer - 1].TotalTriggers + 1];
                        TileLayers[CurLayer - 1].Triggers = temp;
                    }
                    else
                        TileLayers[CurLayer - 1].Triggers = new Trigger[1];

                    TileLayers[CurLayer - 1].Triggers[TileLayers[CurLayer - 1].TotalTriggers] = new Trigger();
                    TileLayers[CurLayer - 1].Triggers[TileLayers[CurLayer - 1].TotalTriggers].TriggerPosition = tempPoint;
                }

            }
            else
                rDragging = true;
        
        }

        private void ImageViewPort_MouseUp(object sender, MouseEventArgs e)
        {
            if (dragging == true)
                dragging = false;

            if (rDragging == true)
                rDragging = false;


            
            List<Point> realPoints = new List<Point>();
            List<Point> tilePoints = new List<Point>();
            int currentIndex = 0;

            for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i)
            {
                if (realPoints.Contains(TileLayers[CurLayer - 1].PointsClicked[i]) == false)
                {
                    realPoints.Add(TileLayers[CurLayer - 1].PointsClicked[i]);
                    tilePoints.Add(TileLayers[CurLayer - 1].TilePoints[i]);

                    ++currentIndex;
                }
            }

            TileLayers[CurLayer - 1].PointsClicked = realPoints.ToArray();
            TileLayers[CurLayer - 1].TilePoints = tilePoints.ToArray();
            TileLayers[CurLayer - 1].TotalPointsClicked = (short)realPoints.Count;
            TileLayers[CurLayer - 1].TotalTilePoints = (short)realPoints.Count;

        }
          
        private void ImageViewPort_MouseMove(object sender, MouseEventArgs e)
        {
            if (dragging == true)
            {
                if (DrawTile == true && rNone.Checked == true)
                {
                    int MouseX = e.Location.X + hScrollBar1.Value;
                    int MouseY = e.Location.Y + vScrollBar1.Value;

                    MouseX /= TILE_WIDTH;
                    MouseY /= TILE_HEIGHT;

                    MouseX *= TILE_WIDTH;
                    MouseY *= TILE_HEIGHT;

                    if (TileLayers[CurLayer - 1].PointsClicked != null && TileLayers[CurLayer - 1].PointsClicked.Contains(new Point(MouseX, MouseY)) == false)
                    {


                        if (TileLayers[CurLayer - 1].PointsClicked != null) //if there are points already
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the array
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i) //Swap the array
                                temp[i] = TileLayers[CurLayer - 1].PointsClicked[i];
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1]; //increase the size of the actual array
                            TileLayers[CurLayer - 1].PointsClicked = temp;
                        }
                        else
                            TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked + 1];


                        TileLayers[CurLayer - 1].PointsClicked[TileLayers[CurLayer - 1].TotalPointsClicked] = new Point(MouseX, MouseY); // add the point where clicked to the array
                        TileLayers[CurLayer - 1].TotalPointsClicked++; //increment the total points clicked

                        if (TileLayers[CurLayer - 1].TilePoints != null)
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalTilePoints + 1];
                            for (int i = 0; i < TileLayers[CurLayer - 1].TotalTilePoints; ++i)
                                temp[i] = TileLayers[CurLayer - 1].TilePoints[i];
                            TileLayers[CurLayer - 1].TilePoints = new Point[TileLayers[CurLayer - 1].TotalTilePoints];
                            TileLayers[CurLayer - 1].TilePoints = temp;

                        }
                        else
                            TileLayers[CurLayer - 1].TilePoints = new Point[1];

                        TileLayers[CurLayer - 1].TilePoints[TileLayers[CurLayer - 1].TotalTilePoints] = TileSelection.Location;
                        TileLayers[CurLayer - 1].TotalTilePoints++;
                    }
                    else
                    {
                        for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i )
                        {
                            if (TileLayers[CurLayer - 1].PointsClicked[i] == new Point(MouseX, MouseY))
                            {
                                TileLayers[CurLayer - 1].TilePoints[i] = TileSelection.Location;
                            }
                        }
                    }
                }
                if (dragging == true && rCollision.Checked == true)
                {
                   int MouseX = e.Location.X + hScrollBar1.Value;
                   int MouseY = e.Location.Y + vScrollBar1.Value;

                    MouseX /= TILE_WIDTH;
                    MouseY /= TILE_HEIGHT;

                    MouseX *= TILE_WIDTH;
                    MouseY *= TILE_HEIGHT;

                    if (TileLayers[CurLayer - 1].PointsCollideable.Contains(new Point(MouseX, MouseY)) == false)
                    {
                        if (TileLayers[CurLayer - 1].TotalCollideableTiles == 0)
                        {
                            TileLayers[CurLayer - 1].PointsCollideable = new Point[1];
                        }
                        else
                        {
                            Point[] temp = new Point[TileLayers[CurLayer - 1].TotalCollideableTiles + 1];
                            for (int j = 0; j < TileLayers[CurLayer - 1].TotalCollideableTiles; ++j)
                                temp[j] = TileLayers[CurLayer - 1].PointsCollideable[j];
                            TileLayers[CurLayer - 1].PointsCollideable = new Point[TileLayers[CurLayer - 1].TotalCollideableTiles];
                            TileLayers[CurLayer - 1].PointsCollideable = temp;
                        }
                        TileLayers[CurLayer - 1].PointsCollideable[TileLayers[CurLayer - 1].TotalCollideableTiles] = new Point(MouseX, MouseY);
                        TileLayers[CurLayer - 1].TotalCollideableTiles++;
                    }
                }

            }
            else if (rDragging == true)
            {
                int MouseX = e.Location.X + hScrollBar1.Value;
                int MouseY = e.Location.Y + vScrollBar1.Value;

                MouseX /= TILE_WIDTH;
                MouseY /= TILE_HEIGHT;

                MouseX *= TILE_WIDTH;
                MouseY *= TILE_HEIGHT;

                for (int i = 0; i < TileLayers[CurLayer - 1].TotalPointsClicked; ++i )
                {
                    if (TileLayers[CurLayer - 1].PointsClicked[i] == new Point(MouseX, MouseY))
                    {
                        Point[] temp = new Point[TileLayers[CurLayer - 1].TotalPointsClicked];
                        Point badPoint = Point.Empty;
                        short badIndex = 0;


                        for(int j = 0; j < TileLayers[CurLayer - 1].TotalPointsClicked; ++j)
                        {
                            if (TileLayers[CurLayer - 1].PointsClicked[j] != new Point(MouseX, MouseY))
                            {
                                temp[j] = TileLayers[CurLayer - 1].PointsClicked[j];
                            }
                            else
                            {
                                badPoint = TileLayers[CurLayer - 1].PointsClicked[j];
                                badIndex = (short)j;

                            }
                            
                        }

                        TileLayers[CurLayer - 1].PointsClicked = new Point[TileLayers[CurLayer - 1].TotalPointsClicked - 1];
                        short index = 0;
                        for (int j = 0; index < TileLayers[CurLayer - 1].TotalPointsClicked; ++j)
                        {
                            if (index == badIndex && index + 1 == TileLayers[CurLayer - 1].TotalPointsClicked)
                                break;
                            else if (index == badIndex)
                                index++;
                                
                            TileLayers[CurLayer - 1].PointsClicked[j] = temp[index];
                            index++;
                              
                        }
                        TileLayers[CurLayer - 1].TotalPointsClicked--;

                        for (int j = 0; j < TileLayers[CurLayer - 1].TotalTilePoints; ++j)
                        {  
                            if( j != badIndex)
                                temp[j] = TileLayers[CurLayer - 1].TilePoints[j];

                        }

                        TileLayers[CurLayer - 1].TilePoints= new Point[TileLayers[CurLayer - 1].TotalTilePoints - 1];
                        index = 0;
                        for (int j = 0; index < TileLayers[CurLayer - 1].TotalTilePoints; ++j)
                        {
                            if (index == badIndex && index + 1 == TileLayers[CurLayer - 1].TotalTilePoints)
                                break;
                            
                            else if (index == badIndex)
                                index++;

                            TileLayers[CurLayer - 1].TilePoints[j] = temp[index];
                            index++;

                        }
                        TileLayers[CurLayer - 1].TotalTilePoints--;

                    
                        break;
                    }
                }
                for (int i = 0; i < TileLayers[CurLayer - 1].TotalCollideableTiles; ++i)
                {
                    if (TileLayers[CurLayer - 1].PointsCollideable[i] == new Point(MouseX, MouseY))
                    {

                        List<Point> tempList = new List<Point>();

                        for (int j = 0; j < TileLayers[CurLayer - 1].TotalCollideableTiles; ++j)
                        {
                            if (TileLayers[CurLayer - 1].PointsCollideable[j] != new Point(MouseX, MouseY))
                            {
                                tempList.Add(TileLayers[CurLayer - 1].PointsCollideable[j]);
                            }
                        }

                        TileLayers[CurLayer - 1].PointsCollideable = tempList.ToArray();
                        TileLayers[CurLayer - 1].TotalCollideableTiles = (short)tempList.Count;
                        break;
                    }

                }
            }

    
                
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            TILE_WIDTH = (int)numericUpDown1.Value;
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            TILE_HEIGHT = (int)numericUpDown2.Value;
        }

        private void TriggerOption_Click(object sender, EventArgs e)
        {
           

        }

        private void RCImagePort_Opening(object sender, CancelEventArgs e)
        {
            RClickMenu.X = MousePosition.X - ImageViewPort.Location.X;
            RClickMenu.Y = MousePosition.Y - ImageViewPort.Location.Y;
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            CURRENT_WIDTH = (int)numericUpDown3.Value * TILE_WIDTH;
        }

        private void numericUpDown4_ValueChanged(object sender, EventArgs e)
        {
            CURRENT_HEIGHT = (int)numericUpDown4.Value * TILE_HEIGHT;
        }

        private void exportToolStripMenuItem_Click(object sender, EventArgs e)
        {

            FileStream fileWriter = new FileStream("..\\level.bin", FileMode.Create);
            BinaryWriter writer = new BinaryWriter(fileWriter);

            List<Tile1[,]> mapArray = new List<Tile1[,]>();

            for (int z = 0; z < 5; ++z )
            {
                Tile1[,] map = new Tile1[CURRENT_WIDTH / TILE_WIDTH, CURRENT_HEIGHT / TILE_HEIGHT];
                mapArray.Add(map);
            }

            for (int z = 0; z < 5; ++z)
            {
                for (int i = 0; i < CURRENT_WIDTH / TILE_WIDTH; ++i )
                {
                    for (int j = 0; j < CURRENT_HEIGHT / TILE_HEIGHT; ++j )
                    {
                        mapArray[z][i, j] = new Tile1();
                        mapArray[z][i, j].ToDrawFrom = new Point(10000, 10000);
                        mapArray[z][i, j].pTrigger = new Trigger();
                    }
                }
            }

                for (int curLayer = 0; curLayer < 5; ++curLayer)
                {
                    for (int i = 0; i < TileLayers[curLayer].TotalPointsClicked; ++i)
                    {
                        // Index the map at the points array.X, points array.Y and set the tile to draw from at the tile points[i]
                        if (TileLayers[curLayer].PointsClicked == null)
                            break;
                        mapArray[curLayer][TileLayers[curLayer].PointsClicked[i].X / TILE_WIDTH, TileLayers[curLayer].PointsClicked[i].Y / TILE_HEIGHT].ToDrawFrom = TileLayers[curLayer].TilePoints[i];
                        mapArray[curLayer][TileLayers[curLayer].PointsClicked[i].X / TILE_WIDTH, TileLayers[curLayer].PointsClicked[i].Y / TILE_HEIGHT].IsDrawn = true;                        
                    }
                    for (int j = 0; j < TileLayers[curLayer].TotalCollideableTiles; ++j)
                    {
                        if (TileLayers[curLayer].PointsCollideable == null)
                            break;
                        mapArray[curLayer][TileLayers[curLayer].PointsCollideable[j].X / TILE_WIDTH, TileLayers[curLayer].PointsCollideable[j].Y / TILE_HEIGHT].IsCollideable = true;
                        mapArray[curLayer][TileLayers[curLayer].PointsCollideable[j].X / TILE_WIDTH, TileLayers[curLayer].PointsCollideable[j].Y / TILE_HEIGHT].IsDrawn = true;
                    }

                    for (int j = 0; j < TileLayers[curLayer].TotalTriggers; ++j)
                    {
                        if (TileLayers[curLayer].TotalTriggers == 0)
                            break;
                        mapArray[curLayer][TileLayers[curLayer].Triggers[j].TriggerPosition.X / TILE_WIDTH, TileLayers[curLayer].Triggers[j].TriggerPosition.Y / TILE_HEIGHT].pTrigger = TileLayers[curLayer].Triggers[j];
                        mapArray[curLayer][TileLayers[curLayer].Triggers[j].TriggerPosition.X / TILE_WIDTH, TileLayers[curLayer].Triggers[j].TriggerPosition.Y / TILE_HEIGHT].IsDrawn = true;
                    }
                }

            writer.Write(5);
            writer.Write(TILE_WIDTH);
            writer.Write(TILE_HEIGHT);
            writer.Write((CURRENT_WIDTH / TILE_WIDTH));
            writer.Write((CURRENT_HEIGHT / TILE_HEIGHT));


            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < CURRENT_WIDTH / TILE_WIDTH; ++j )
                {
                    

                    for (int k = 0; k < CURRENT_HEIGHT / TILE_HEIGHT; ++k )
                    {
                        if (mapArray[i][j,k].IsDrawn == true)
                        {
                            writer.Write(mapArray[i][j,k].ToDrawFrom.X);
                            writer.Write(mapArray[i][j, k].ToDrawFrom.Y);
                            writer.Write(mapArray[i][j, k].IsCollideable);
                            if (mapArray[i][j, k].pTrigger.EventString != null)
                            {
                                writer.Write(mapArray[i][j, k].pTrigger.TriggerPosition.X);
                                writer.Write(mapArray[i][j, k].pTrigger.TriggerPosition.Y);
                                writer.Write(mapArray[i][j, k].pTrigger.EventString.Length);
                                for (int p = 0; p < mapArray[i][j, k].pTrigger.EventString.Length; ++p)
                                {
                                    writer.Write(mapArray[i][j, k].pTrigger.EventString[p]);
                                }
                            }
                            else
                                writer.Write(-1);
                        }
                        else
                            writer.Write(-1);
                    }
                }
            }


                
            }
        



        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 5; ++i)
            {
                TileLayers[i].PointsClicked = null;
                TileLayers[i].TilePoints = null;
                TileLayers[i].PointsCollideable = null;
                TileLayers[i].TotalCollideableTiles = 0;
                TileLayers[i].TotalPointsClicked = 0;
                TileLayers[i].TotalTilePoints = 0;
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog dlg = new SaveFileDialog();
            if(DialogResult.OK == dlg.ShowDialog())
            {
                FileStream stream = new FileStream(dlg.FileName, FileMode.Create);
                BinaryWriter writer = new BinaryWriter(stream);
                writer.Write(5);
                writer.Write(TILE_WIDTH);
                writer.Write(TILE_HEIGHT);
                writer.Write((int)(CURRENT_WIDTH));
                writer.Write((int)(CURRENT_HEIGHT));

                for (int i = 0; i < 5; ++i )
                {
                    writer.Write(TileLayers[i].TotalPointsClicked);
                    for (int j = 0; j < TileLayers[i].TotalPointsClicked; ++j )
                    {
                        writer.Write(TileLayers[i].PointsClicked[j].X);
                        writer.Write(TileLayers[i].PointsClicked[j].Y);
                    }

                    writer.Write(TileLayers[i].TotalTilePoints);
                    for (int j = 0; j < TileLayers[i].TotalTilePoints; ++j )
                    {
                        writer.Write(TileLayers[i].TilePoints[j].X);
                        writer.Write(TileLayers[i].TilePoints[j].Y);
                    }

                    writer.Write(TileLayers[i].TotalCollideableTiles);
                    for (int j = 0; j < TileLayers[i].TotalCollideableTiles; ++j )
                    {
                        writer.Write(TileLayers[i].PointsCollideable[j].X);
                        writer.Write(TileLayers[i].PointsCollideable[j].Y);
                    }

                    writer.Write(TileLayers[i].TotalTriggers);
                    for (int j = 0; j < TileLayers[i].TotalTriggers; ++j )
                    {
                        writer.Write(TileLayers[i].Triggers[j].TriggerPosition.X);
                        writer.Write(TileLayers[i].Triggers[j].TriggerPosition.Y);
                        writer.Write(TileLayers[i].Triggers[j].EventString);
                    }
                }
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            if(DialogResult.OK == dlg.ShowDialog())
            {
                FileStream stream = new FileStream(dlg.FileName, FileMode.Open, FileAccess.Read);
                BinaryReader reader = new BinaryReader(stream);
                TILE_WIDTH = reader.ReadInt32();
                TILE_WIDTH = reader.ReadInt32();
                TILE_HEIGHT = reader.ReadInt32();
                CURRENT_WIDTH = reader.ReadInt32() * TILE_WIDTH;
                CURRENT_HEIGHT = reader.ReadInt32() * TILE_HEIGHT;

                int points = 0;
                int tiles = 0;
                int collide = 0;
                int triggers = 0;

                for (int i = 0; i < 5; ++i )
                {
                    points = reader.ReadInt32();
                    TileLayers[i].PointsClicked = new Point[points];
                    for (int j = 0; j < points; ++j )
                    {
                        TileLayers[i].PointsClicked[j].X = reader.ReadInt32();
                        TileLayers[i].PointsClicked[j].Y = reader.ReadInt32();
                    }
                    TileLayers[i].TotalPointsClicked = (short)points;

                    tiles = reader.ReadInt32();
                    TileLayers[i].TilePoints = new Point[tiles];
                    for (int j = 0; j < tiles; ++j )
                    {
                        TileLayers[i].TilePoints[j].X = reader.ReadInt32();
                        TileLayers[i].TilePoints[j].Y = reader.ReadInt32();
                    }
                    TileLayers[i].TotalTilePoints = (short)tiles;

                    collide = reader.ReadInt32();
                    TileLayers[i].PointsCollideable = new Point[collide];
                    for (int j = 0; j < collide; ++j )
                    {
                        TileLayers[i].PointsCollideable[j].X = reader.ReadInt32();
                        TileLayers[i].PointsCollideable[j].Y = reader.ReadInt32();
                    }
                    TileLayers[i].TotalCollideableTiles = (short)collide;

                    triggers = reader.ReadInt32();
                    TileLayers[i].Triggers = new Trigger[triggers];
                    for (int z = 0; z < triggers; ++z)
                    {
                        TileLayers[i].Triggers[z] = new Trigger();
                    }
                    for (int j = 0; j < triggers; ++j)
                    {
                        int stringCount = 0;
                        Point position = new Point();
                        position.X = reader.ReadInt32();
                        position.Y = reader.ReadInt32();
                        stringCount = reader.Read();
                        char[] events = new char[stringCount];
                        reader.Read(events, 0, stringCount);
                        TileLayers[i].Triggers[j].EventString = new String(events);
                    }
                    TileLayers[i].TotalTriggers = (short)triggers;

                }

            }
        } 
            
        
    }

    
}

        
    


       




    

