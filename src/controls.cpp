#include "controls.hpp"
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <vector>
#include <cmath>
#include <iostream>


using namespace std;


extern int cameraX;
extern int cameraY;
extern bool won;
extern vector<shape> shapeList;

bool shiftPressed = false;
int xVelocity = 0,yVelocity = 0;
int clickNum = 0;


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
bool checkValidity(double x , double y);
float roundUp(int numToRound, int multiple);
void registerCallBacks(GLFWwindow* window);



void registerCallBacks(GLFWwindow* window){
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
};

float roundUp(int numToRound, int multiple){    //rounds to the nearest multipe of a number
	if (multiple == 0) return numToRound;

	int remainder = abs(numToRound) % multiple;
	if (remainder == 0) return numToRound;

	if (numToRound < 0) return -(abs(numToRound) - remainder);
	else return numToRound + multiple - remainder;
};

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods){

	if(action != GLFW_PRESS) return;
	if(button != GLFW_MOUSE_BUTTON_LEFT) return;

	
	double x ,y;
	glfwGetCursorPos(window, &x, &y);


	int nx = roundUp(x,dist);
	int ny = roundUp(y,dist);

	if(checkValidity((double)nx,(double)ny)){
		type t = tic;
		if(clickNum %2 == 1) t = tac;

		cout << nx << ' ' << ny << endl;
		shapeList.push_back(shape(nx,ny,t));
		clickNum++;
	};
};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){

	if(key == GLFW_KEY_LEFT_SHIFT){ // checking if the key is left shift and if it is toggoling shiftPressed 
		switch(action){
			case GLFW_PRESS:
				shiftPressed = true;
				break;
			case GLFW_RELEASE:
				shiftPressed = false;
				break;
		}
		return;
	};


	int velocity = 1 + shiftPressed*14;  //checking if shift is pressed and then setting the velocity
	int keyActive = (action != GLFW_RELEASE);   //checking if the keys have been released . if they have than the var becomes 0

	switch (key){   //setting velocities 
		case GLFW_KEY_W:
			yVelocity = velocity * keyActive;
			break;
		case GLFW_KEY_A:
			xVelocity = -(velocity * keyActive);
			break;
		case GLFW_KEY_S:
			yVelocity = -(velocity * keyActive);
			break;
		case GLFW_KEY_D:
			xVelocity = velocity * keyActive;
			break;
		default:
			break;
	}

	cameraX +=xVelocity;    // adding velocities
	cameraY -=yVelocity;
	
};

bool checkValidity(double x , double y){

	if(shapeList.size() == 0) return true;

	for(int i = 0 ; i < shapeList.size();i++){
		if(shapeList[i].x == x && shapeList[i].y == y) return false;
	};
	for(int i = 0 ; i < shapeList.size();i++){
		if(abs(x-shapeList[i].x) <= 100 || abs(y-shapeList[i].y) <= 100) return true;
	};
	return false;
};
