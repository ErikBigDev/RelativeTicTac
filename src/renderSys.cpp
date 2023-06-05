#include "renderSys.hpp"
#include "GLFW/glfw3.h"
#include <cmath>
#include <vector>
#include "game.hpp"
#include <iostream> 

using namespace std;


#define windowLength  750
#define segmentNum 128 
#define defaultRadius 40
#define xSize 40


extern int cameraX;
extern int cameraY;
extern vector<shape> shapeList;


void drawX(int x ,int y);
void drawO(int x, int y);
void display();
void drawCircle(int x, int y, int r);


void display(){

	int len;

	shape** visibleShape = getVisableShapes(len);

	for(int i = 0 ; i < len; i++){
		if(visibleShape[i]->t == tic){
			drawX(-(cameraX - visibleShape[i]->x ),-(cameraY - visibleShape[i]->y));
			continue;
		};

		drawO(-(cameraX - visibleShape[i]->x ),-( cameraY - visibleShape[i]->y));
	};

};


void drawX(int x,int y){
	float rx = x + xSize;
	float lx = x - xSize;
	float ly = y - xSize;
	float uy = y + xSize;

	rx = rx - windowLength/2;
	uy = windowLength/2 - uy;
	lx = lx - windowLength/2;
	ly = windowLength/2 - ly;

	rx = 2*rx/windowLength;
	uy = 2*uy/windowLength;
	lx = 2*lx/windowLength;
	ly = 2*ly/windowLength;

	float xOffset = 0.02;
	float yOffset = 0.02;

	glColor3f(1.0,0.2,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(lx,uy);
	glVertex2f(lx + xOffset,uy);
	glVertex2f(rx, ly - yOffset);
	glVertex2f(rx,ly);
	glVertex2f(rx - xOffset,ly);
	glVertex2f(lx,uy+yOffset);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(rx,uy);
	glVertex2f(rx - xOffset,uy);
	glVertex2f(lx, ly - yOffset);
	glVertex2f(lx,ly);
	glVertex2f(lx + xOffset,ly);
	glVertex2f(rx,uy+yOffset);
	glEnd();
};


void drawO(int x , int y){
	glColor3f(1.0,1.0,1.0);
	drawCircle(x,y,defaultRadius);
	glColor3f(0,0,0);
	drawCircle(x,y,defaultRadius-10);
	glColor3f(1.0,1.0,1.0);
};



void drawCircle(int x, int y, int r){

	glBegin(GL_POLYGON);

	float cx = x - windowLength/2;
	float cy = windowLength/2 - y;
	float cr = r;
	cr = 2*cr/windowLength;
	cx = 2*cx/windowLength;
	cy = 2*cy/windowLength;

	float angle = 0;
	float dAngle = 2*M_PI/segmentNum;

	for(int i = 0 ;i < segmentNum;i++){
		glVertex2f(cx+cr*cos(angle), cy+cr*sin(angle));
		angle+=dAngle;
	};

	glEnd();
};
