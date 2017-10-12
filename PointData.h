#pragma once
class PointData
{
public:
	int closestID = 0;
	float featureX, featureY; //Can add to include more features, maybe dynamic?

	PointData();
	float GetIdDistance(float centroidXPos, float centroidYPos);

	void SetClosestID(int id);

};

