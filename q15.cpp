#include <bits/stdc++.h>
using namespace std;

template<class T>
void insertionSort(T arr[], int n){
	for(int i=1;i<n;i++){
		T key = arr[i];
		int j = i - 1;
		while(j>=0 && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

template<class U>
void selectionSort(U arr[], int n){
	for(int i=0;i<n-1;i++){
		int min_idx = i;
		for(int j=i+1;j<n;j++){
			if(arr[i] < arr[min_idx])
				min_idx = i;
		}
		U temp = arr[min_idx];
		arr[min_idx] = arr[min_idx+1];
		arr[min_idx+1] = temp;
	}
}

template<class P>
void displayArray(P arr[],int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){

	int data[5] = {20,12,10,15,2};
	float d2[5] = {20.2,12.23,10.05,15.123,2.3};
	selectionSort<int>(data,5);
	displayArray<int>(data,5);

	insertionSort<float>(d2,5);
	displayArray<float>(d2,5);
	return 0;
}
