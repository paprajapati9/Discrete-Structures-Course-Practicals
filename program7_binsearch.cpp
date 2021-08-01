/**
  * Author: Pankaj Prajapati
  * Roll No.: 31
*/

/**
  * Question: Write a program to perform binary search recursively
*/

#include<iostream>
#include <algorithm>

using namespace std;


bool compareArrays(int arr1[], int arr2[], int arr_size){
	for (int i = 0; i < arr_size; ++i)
	{
		if(arr1[i] != arr2[i]) return false;
	}
	return true;
}

int binarySearch(int arr[], int begin, int end, int search){
	if(begin <= end){
		int mid = (begin+end)/2;
		if(arr[mid] == search) return mid+1;
		if(arr[mid] > search) binarySearch(arr, begin, mid-1, search);
		else binarySearch(arr, mid+1, end, search);
	}
	else return -1;
}

int main(){
	int arr_size=0, cont = 1, position, search;
	
	cout<<"Enter the size of array: ";
	cin>>arr_size;

	int unsorted_arr[arr_size], sorted_arr[arr_size]; //declaring the array
	cout<<"Enter the elements of the array: ";
	for(int i=0; i<arr_size; i++){
		cin>>unsorted_arr[i];
		sorted_arr[i] = unsorted_arr[i];
	}
	sort(sorted_arr, sorted_arr + arr_size);

	if(!compareArrays(sorted_arr, unsorted_arr, arr_size)){
		cout<<"Warning!! The array was not sorted. We have sorted the array";
	}

	cout<<"\nArray: ";

	for(int i=0; i< arr_size; i++){
		cout<<sorted_arr[i]<<" ";
	}
	cout<<endl;

	cout<<"\nEnter the element you want to search: ";
	cin>>search;
	
	position = binarySearch(sorted_arr, 0, arr_size-1, search);

	cout<<position;
		
	return 0;
}
