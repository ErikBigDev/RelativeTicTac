#include "game.hpp"
#include <vector>


using namespace std;


#define windowLength 750000

extern bool won;
extern int cameraX;
extern int cameraY;

extern vector<shape> shapeList;



shape** getVisableShapes(int & len){

	shape** tmp = new shape*[64];	
	int shapeCount = 0;


	for(int i = 0 ; i < shapeList.size();i++){
		if(shapeList[i].x >= cameraX - windowLength * 0.5 && shapeList[i].x <= cameraX + windowLength * 0.5 && shapeList[i].y <= cameraY + windowLength * 0.5 && shapeList[i].y >= cameraY - windowLength * 0.5)
			tmp[shapeCount++] = &shapeList[i];
	};

	shape** res = new shape*[shapeCount];

	for(int i = 0 ; i < shapeCount; i++) res[i] = tmp[i];

	delete [] tmp;

	len = shapeCount;
	return res;
};
