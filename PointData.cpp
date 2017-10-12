#include "stdafx.h"
#include <math.h>
//Non-standard libs
#include "PointData.h"

float PointData::GetIdDistance(float centroidXPos, float centroidYPos)
{
	return sqrt(pow(centroidXPos - featureX, 2) + pow(centroidYPos - featureY, 2)); //Pythag
}

PointData::PointData()
{
}

void PointData::SetClosestID(int id)
{
	closestID = id;
}
