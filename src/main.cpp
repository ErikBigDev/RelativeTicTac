#include <iostream>
#include "GLFW/glfw3.h"
#include "renderSys.hpp"
#include "controls.hpp"
#include "game.hpp"
#include <vector>


using namespace std;


#define windowLength  750


int cameraX,cameraY;
bool won = false;
vector<shape> shapeList;



GLFWwindow* window;

int main(int argc ,char ** argv){

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(windowLength , windowLength, "RelativeTicTac", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }


    glfwSetWindowSizeLimits(window, windowLength , windowLength,  windowLength , windowLength);
    glfwMakeContextCurrent(window);


	registerCallBacks(window);

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
	display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
};
