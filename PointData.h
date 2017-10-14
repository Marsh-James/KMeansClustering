#pragma once
#include <string>
class PointData
{
public:
	int closestID = 0;
	//double featureX, featureY; Preset default features

	double sepalLen, sepalWid, petalLen, petalWid;

	/* Parse data type (From the IRIS Dataset (https://archive.ics.uci.edu/ml/datasets/iris)
	1. sepal length in cm
	2. sepal width in cm
	3. petal length in cm
	4. petal width in cm
	5. class:
	-- Iris Setosa
	-- Iris Versicolour
	-- Iris Virginica
	*/

	PointData();
	double GetIdDistance(double centroidWPos, double centroidXPos, double centroidYPos, double centroidZPos); //override?

	void SetClosestID(int id);

};

