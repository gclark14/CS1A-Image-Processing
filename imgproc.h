#ifndef _IMGPROC_H
#define _IMGPROC_H
#include <iostream>
#include <cstring>
#include <fstream>
#define WIDTH 644
#define HEIGHT 410
using namespace std;

int domenu();

int readImg(string inFile, unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT]);

void saveImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT]);

int horzFlip(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT]);

int vertFlip(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT]);

void ageImg(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int zoomImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char B[][HEIGHT]);

void sharpenImg(unsigned char R[][HEIGHT], unsigned char G[][HEIGHT], unsigned char charB[][HEIGHT]);

#endif
