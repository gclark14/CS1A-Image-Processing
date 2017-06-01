/******
* imgproc.cpp: main file
******/
#include "imgproc.h"
int main(){
  int option;
  string inFile;
  unsigned char R[WIDTH][HEIGHT];
  unsigned char G[WIDTH][HEIGHT]; 
  unsigned char B[WIDTH][HEIGHT];
cout << "Enter input file name: ";
getline(cin,inFile); 
option = domenu();
readImg(inFile, R,G,B);
switch (option)
{
  case 1:
    horzFlip(R, G, B);   
    saveImg(R,G,B);
    break;
  case 2:
    vertFlip(R,G,B);
    saveImg(R,G,B);
    break;
  case 3:
    ageImg(R,G,B);
    saveImg(R,G,B);
    break;
  case 4:
    sharpenImg(R,G,B);
    saveImg(R,G,B);
    break; 
  case 5:
    zoomImg(R,G,B);
    saveImg(R,G,B);
    break;
  default:
  cout << "Error. Incorrect menu item chosen.\n";
}  

return 0;
}
