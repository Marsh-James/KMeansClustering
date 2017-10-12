// KMeans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h> 

//Non-standard libs
#include "Centroid.h"
#include "PointData.h"

using namespace std; 

int main()
{
	srand(time(NULL));

	const int K = 4; //Number of clusters to form
	const int N = 100; //Number of data points to use
	Centroid centroids[K]; //Some centroid must exist
	PointData data[N];

	for (int i = 0; i < K; i++) {
		centroids[i].SetID(i);
	}
	
	//Method for data read-in?
	AllocateDataToCentroid(N, K, data, centroids);
    return 0;
}

void AllocateDataToCentroid(int N, int K, PointData data[], Centroid centroids[]) {
	float closestDist = 1e7, distance;
	int closestID = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {

			distance = data[i].GetIdDistance(centroids[j].xPos, centroids[j].yPos);
			if (distance < closestDist) {
				closestDist = distance;
			}
		}
	}
}