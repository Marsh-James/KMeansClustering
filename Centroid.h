#pragma once
class Centroid
{
public:
	int uid;
	//number of position references is dependent on the data-set, IRIS dataset is using 4
	double wPos= 0, xPos = 0, yPos = 0, zPos = 0;

	Centroid();
	void SetID(int id);
};

