#include "stdafx.h"
#include <math.h>
//Non-standard libs
#include "PointData.h"

double PointData::GetIdDistance(double cWPos, double cXPos, double cYPos, double cZPos) //maybe setup override?
{
	//Number of dimensions is perportionl to the number of features
	return sqrt(pow(cWPos - sepalLen, 2) + pow(cXPos - sepalWid, 2) + pow(cYPos - petalLen, 2) + +pow(cZPos - petalWid, 2));
}

PointData::PointData()
{
}

void PointData::SetClosestID(int id)
{
	closestID = id;
}
