/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
using namespace std;

int number_of_comparisons = 0;

/**
  * Funtion to swap 2 elements by reference
*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
  * Funtion to print an array
*/
void printArray(int print[], int arr_size){
    for(int i=0; i< arr_size; i++){
        cout<<print[i]<<" ";
    }
    cout<<endl;
}
 
/**
  * Funtion to implement bubble sort
*/
void bubbleSort(int arr[], int arr_size)
{
    number_of_comparisons = 0;
    for (int i = 0; i < arr_size-1; i++){
    // Last i elements are already in place

        for (int j = 0; j < arr_size-i-1; j++){

            number_of_comparisons++;
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);

            printArray(arr, arr_size);

        }

    } 
}
 

 

int main()
{
    int arr_size=0;
    
    while(arr_size <=0){
        cout<<"Enter the size of array (>0): ";
        cin>>arr_size;
    }

    int arr[arr_size]; //declaring the array

    cout<<"Enter the elements of the array: ";

    for(int i=0; i<arr_size; i++){
        //cin>>arr[i];
        arr[i] = arr_size-i;
    }



    bubbleSort(arr, arr_size);
    cout<<"Sorted array: \n";
    printArray(arr, arr_size);
    cout<<"Number of comparisons = "<<number_of_comparisons;
    return 0;
}