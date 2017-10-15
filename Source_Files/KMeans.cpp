// KMeans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h> 
#include <fstream>
#include <string>

//Non-standard libs
#include "Centroid.h"
#include "PointData.h"

using namespace std;

void ReadData(PointData data[], string irisClass[]) 
{

	ifstream dataSetFile("Iris-Data-Set/IRISDATA.txt");
	string dataLine;
	int currentDataPos = 0;

	do { //Worth noting that number of iterations loop == data[] memory locations, therefore there is no check performed
		getline(dataSetFile, dataLine);

		//Counter used for parsing IRIS data-set specific data
		int counter = 1;

		//Following parsing is specific for the IRIS dataset (https://archive.ics.uci.edu/ml/datasets/iris)
		for (int i = 0; i < dataLine.length(); i++) {


			if (dataLine.substr(i, 1) == ",") {
				switch(counter) {
					case 1: data[currentDataPos].sepalLen = stod(dataLine.substr(0, 3));
							//cout << data[currentDataPos].sepalWid << endl;
							counter++;
							break;
					case 2: data[currentDataPos].sepalWid = stod(dataLine.substr(i - 3, 3));
							//cout << data[currentDataPos].sepalWid << endl;
							counter++;
							break;
					case 3: data[currentDataPos].petalLen = stod(dataLine.substr(i - 3, 3));
							//cout << data[currentDataPos].petalLen << endl;
							counter++;
							break;
					case 4: data[currentDataPos].petalWid = stod(dataLine.substr(i - 3, 3));
							//cout << data[currentDataPos].petalWid << endl;
							counter++;
							break;
				}
			}
			else if (counter == 5 && i == 16){
				irisClass[currentDataPos] = dataLine.substr(i, dataLine.length() - i);
				//cout << irisClass[currentDataPos] << endl;
				//getchar();
			}
		}

		/*Parse data type
		1. sepal length in cm
		2. sepal width in cm
		3. petal length in cm
		4. petal width in cm
		5. class:
		-- Iris Setosa
		-- Iris Versicolour
		-- Iris Virginica
		*/
		currentDataPos++;
	} while (!dataSetFile.eof());

}

void AllocateDataToCentroid(int N, int K, PointData data[], Centroid centroids[]) 
{
	double closestDist = 1e7, distance;
	int closestID = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {

			distance = data[i].GetIdDistance(centroids[j].wPos, centroids[j].xPos, centroids[j].yPos, centroids[j].zPos);
			if (distance < closestDist) {
				closestDist = distance;
				data[i].closestID = centroids[j].uid;
			}
		}
	}
}

void UpdateCentroidPos(int N, int K, PointData data[], Centroid centroids[]) {
	for (int i = 0; i < K; i++) {
		
		double sumW = 0, sumX = 0, sumY = 0, sumZ = 0; //Number of vairables dependent on dataset, 4 initialized here for the IRIS Dataset

		for (int j = 0; j < N; j++) {
			if (data[j].closestID == i) {
				sumW += data[j].sepalLen;
				sumX += data[j].sepalWid;
				sumY += data[j].petalLen;
				sumZ += data[j].petalWid;
			}
		}
		centroids[i].wPos = sumW / K;
		centroids[i].xPos = sumX / K;
		centroids[i].yPos = sumY / K;
		centroids[i].zPos = sumZ / K;
	}
}

int main()
{
	srand(time(NULL));

	const int K = 3; //Number of clusters to form
	const int N = 150; //Number of data points to use
	Centroid centroids[K]; //Some centroid must exist
	PointData data[N];

	string irisClass[150]; //Debugging, see if clustered together

	for (int i = 0; i < K; i++) {
		centroids[i].SetID(i);
	}
	
	//Method for data read-in?
	ReadData(data, irisClass);
	
	for (int i = 0; i < 50; i++) {
		AllocateDataToCentroid(N, K, data, centroids);
		UpdateCentroidPos(N, K, data, centroids);
	}
    return 0;
}
