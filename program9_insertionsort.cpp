/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
using namespace std;

int number_of_comparisons = 0;

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
  * Funtion to implement insertion sort
*/
void insertionSort(int arr[], int arr_size)
{
    int key, insertLoc;
    for (int i = 1; i < arr_size; i++)
    {
        key = arr[i];
        insertLoc = i - 1;
        number_of_comparisons++;
 
        /* Shift the jth element to it's location 
           in the sorted sub graph */
        while (insertLoc >= 0 && arr[insertLoc] > key)
        {
            number_of_comparisons++;
            arr[insertLoc + 1] = arr[insertLoc];
            insertLoc = insertLoc - 1;
            printArray(arr, arr_size);
        }
        printArray(arr, arr_size);
        arr[insertLoc + 1] = key;
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

    insertionSort(arr, arr_size);
    cout<<"Sorted array: \n";
    printArray(arr, arr_size);
    cout<<"Number of comparisons to sort = "<<number_of_comparisons;
    return 0;
}