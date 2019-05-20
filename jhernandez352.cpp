#include <climits>//INT_MIN
#include <iostream>
using namespace std;
//Referenced sudo code for Find-Max-Crossing-Subarray from textboook on pg. 71.
int findMaxCrossingSubarray(int *data, int start, int mid, int end){
	//Calculate max of left side.
	int leftSum = INT_MIN , rightSum = INT_MIN, sum = 0;
	for(int i = mid; i >= start; i--){
		sum += data[i];
		if( sum >= leftSum )
				leftSum = sum;
	}
	//calculate max of right side.
	sum = 0;
	for(int j = mid + 1; j <= end; j++){
		sum += data[j];
		if( sum >= rightSum )
				rightSum = sum;
	}
	//Return the sum of the max of both sides.
	return leftSum + rightSum;
}
//Referenced sudo code for Find-Maximum-Subarray from textboook on pg. 72. Recursive.
int findMaximumSubarray(int *data, int start, int end){
	//Base case.
	if(end == start)
		return data[start];
	//if base case is passed...
	else{
		int mid = (start + end) / 2;
		//Define all maximums to compare in the if and if else statements.
		int leftMax = findMaximumSubarray(data, start, mid), rightMax = findMaximumSubarray(data, mid + 1, end), crossMax = findMaxCrossingSubarray(data, start, mid, end);
		//if staments will find the max essentially.
		if(leftMax >= rightMax && leftMax >= crossMax)
			return leftMax;
		else if(rightMax >= leftMax && rightMax >= crossMax)
			return rightMax;
		else
			return crossMax;
	}
}
//Main
int main(int argc, char **argv){
	//initialize variables.
	int size;
	cin >> size;
	int *data = new int[size];
	//Collect data.
	for(int i = 0; i < size; i++)
		cin >> data[i];
	//print maximum.
	//Need to figure out why size - 1 works for these divinde and conquer algorithms...
	cout << findMaximumSubarray(data, 0, size - 1);
	//delete the array from memory.
	delete[] data;
	return 0;
}	
	
	