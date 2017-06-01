/*******************************************
* imgprocf.cpp
* header function added
* horzFlip funct started development 12/2/16
*******************************************/
#include "imgproc.h"
int domenu()
{
  int choice;
  cout << "1. Flip horizontally" << endl;
  cout << "2. Flip vertically" << endl;
  cout << "3. Age" << endl;
  cout << "4. Sharpen" << endl;
  cout << "5. BONUS: Zoom in" << endl;
  cout << "6. Exit" << endl;
  cout << endl; cout << endl;
  cout << "Enter a number for what you would like to do.";
  cin >> choice;
  cin.ignore(100, '\n');
  cout << endl; cout << endl;
  return choice;
}

int readImg(string inFile, unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  // variables
  ifstream fin; 
  fin.open(inFile.c_str());
  fin.ignore(100, '\n'); fin.ignore(100, '\n'); fin.ignore(100, '\n');  
  for (int i=0; i < HEIGHT; i++)
  {
    for (int j=0; j < WIDTH; j++)
    {
      R[j][i] = fin.get();
      G[j][i] = fin.get();
      B[j][i] = fin.get();  
    }
  }
  fin.close();
  return 0;
}

void saveImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  ofstream fout;
  string Name;
  cout << "Enter a name for new file.\n";
  getline(cin, Name);
  fout.open(Name.c_str());
  fout << "P6\n";
  fout << "644 410\n";
  fout << "255\n";
 
  for (int i=0; i < HEIGHT; i++)
  {
    for (int j=0; j < WIDTH; j++)
    {
      fout << R[j][i];
      fout << G[j][i];
      fout << B[j][i];
    }
  }//loops
fout.close();
}//Imgsav

int horzFlip(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  int temp;
 
  for (int i =0; i < HEIGHT; ++i)
  {
    for(int j =0; j < WIDTH/2; ++j)
    {
     
      temp = R[j][i];
      R[j][i] = R[WIDTH-1-j][i];
      R[WIDTH-1-j][i] = temp;
    
      temp = G[j][i];
      G[j][i] = G[WIDTH-1-j][i];
      G[WIDTH-1-j][i] = temp;

      temp = B[j][i];
      B[j][i] = B[WIDTH-1-j][i];
      B[WIDTH-1-j][i] = temp;
    }
  }
  return 0;
}

int vertFlip(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  int temp;
  for (int i =0; i < HEIGHT/2; ++i)
  {
    for(int j =0; j < WIDTH; ++j)
    {
      temp = R[j][i];
      R[j][i] = R[j][HEIGHT-1-i];
      R[j][HEIGHT-1-i] = temp;
    
      temp = G[j][i];
      G[j][i] = G[j][HEIGHT-1-i];
      G[j][HEIGHT-1-i] = temp;

      temp = B[j][i];
      B[j][i] = B[j][HEIGHT-1-i];
      B[j][HEIGHT-1-i] = temp;
    }
  }
  return 0;
}

void ageImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  for(int y=0; y< HEIGHT; y++) 
  for(int x =0; x< WIDTH; x++)
  {
  B[x][y]=(R[x][y]+G[x][y]+B[x][y])/5;
  R[x][y]=B[x][y]*1.6;
  G[x][y]=B[x][y]*1.6;
  }
}
void sharpenImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  int tempr, tempg, tempb;
  int w=0; int h=0;
  unsigned char tempR[WIDTH][HEIGHT], tempG[WIDTH][HEIGHT], tempB[WIDTH][HEIGHT];
  for (w =0; w < WIDTH; w++)
  {
    for (h=0; h < HEIGHT; h++)
    {
      tempr = R[w][h];
	    tempr= (-1*R[w-1][h-1])+(-1*R[w][h-1])+(-1*R[w+1][h-1])+(-1*R[w-1][h])+9*R[w][h]+(-1*R[w][h+1])+(-1*R[w-1][h+1])+(-1*R[w-1][h])+(-1*R[w+1][h+1]);
 	  	if(tempr > 255)
 	  	{
 	  		tempr =255;
 	  	}
      if(tempr < 0)
      {
        tempr = 0;
      } 
      tempR[w][h] = tempr;
      
      tempg = G[w][h];
      tempg= (-1*G[w-1][h-1])+(-1*G[w][h-1])+(-1*G[w+1][h-1])+(-1*G[w-1][h])+9*G[w][h]+(-1*G[w][h+1])+(-1*G[w-1][h+1])+(-1*G[w-1][h])+(-1*G[w+1][h+1]);
 	  	if(tempg > 255)
 	  	{
 	  		tempg =255;
      }
		  if(tempg < 0)
      {
        tempg = 0;
      }	
			tempG[w][h] = tempg; 
			
			tempb= B[w][h];
			tempb= (-1*B[w-1][h-1])+(-1*B[w][h-1])+(-1*B[w+1][h-1])+(-1*B[w-1][h])+9*B[w][h]+(-1*B[w][h+1])+(-1*B[w-1][h+1])+(-1*B[w-1][h])+(-1*B[w+1][h+1]);
 	  	if(tempb > 255)
 	  	{
 	  		tempb =255;
  		}
      if(tempb < 0)
      {
        tempb = 0;
      }
      tempB[w][h] = tempb;
    }
  }

for(w =0; w < WIDTH-1; w++)
  {
    for(h =0; h < HEIGHT-1; h++)
    {
      R[w][h] = tempR[w][h];
      G[w][h] = tempG[w][h];
      B[w][h] = tempB[w][h];
    }
  }
} 

int zoomImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT])
{
  int tempR[WIDTH][HEIGHT], tempG[WIDTH][HEIGHT], tempB[WIDTH][HEIGHT];
  int x=0; int y=0;
  int cx, cy, mag;
  for(y=0; y < HEIGHT; y++)
  for(x=0; x < WIDTH; x++)
  {
    tempR[x][y] = R[x][y];
    tempG[x][y] = G[x][y]; 
    tempB[x][y] = B[x][y];
  }
  printf("Enter center x:");
  cin >> cx;
  printf("Enter center y:");
  cin >> cy;
  printf("Enter magnitude:");
  cin >> mag;
  cout << "Center x = " << cx << endl;
  cout << "Center y = " << cy << endl;
  cout << "Magnitude = " << mag << endl;
  cin.ignore(100, '\n');
  for(int h=0; h < HEIGHT; h++)
  {
    for(int w=0; w < WIDTH; w++)
    {
      x=w;
      y=h;
      if(x >= 0 && x < WIDTH)  
      {
        x =(w-WIDTH/2)/mag+cx;
      }
      if(y >= 0 && y < HEIGHT)  
      {
        y =(h-HEIGHT/2)/mag+cy;
      } 
      tempR[w][h] = R[x][y];
      tempG[w][h] = G[x][y];
      tempB[w][h] = B[x][y];
    }  
  }
  for(y=0;y<HEIGHT;y++)
  for(x=0;x<WIDTH;x++)
  {
    R[x][y]=tempR[x][y];
    G[x][y]=tempG[x][y];
    B[x][y]=tempB[x][y];
  }
  return 0;
}

