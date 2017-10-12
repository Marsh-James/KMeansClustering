#include "stdafx.h"
#include <stdlib.h> 

//Non-standard libs
#include "Centroid.h"

using namespace std;

Centroid::Centroid()
{
	//WIP - Improved method of getting initial positions
	xPos = rand() % 65536 + 1; //2 out of 4 bytes used
	yPos = rand() % 65536 + 1;
}

void Centroid::SetID(int id)
{
	uid = id;
}
