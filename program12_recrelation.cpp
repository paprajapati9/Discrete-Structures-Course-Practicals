/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include<iostream>
 
using namespace std;

/**
 * For any number n, write a program to list all the solutions of the equation 
 * x1 + x2 + x3 + ...+ xn = C, where C is a constant (C<=10) and x1, x2,x3,...,xn 
 * are nonnegative integers using brute force strategy.
 */

void printArray(int arr[], int size){
    for (int i = 0; i < size; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/**
 * Recursively devide the sum problrm to smaller sub problem of one
 * size smaller and solve accordingly.
 */
void sumCombination(int remainingSize, int remainingSum, int combination[], int actualSize){
    if(remainingSum == 0 || remainingSize==0){ //boundary condition
        combination[remainingSize] = remainingSum;
        printArray(combination, actualSize); //print one such combination
        return;
    }
    for (int i = 0; i <= remainingSum; ++i)
    {
        combination[remainingSize] = i;
        sumCombination(remainingSize-1, remainingSum-i, combination, actualSize);
    }
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cout<<"Enter the size of numbers to find : ";
    cin>>n;
    cout<<"Enter desired sum of the numbers : ";
    cin>>sum;
    cout<<"\n";

    int combination[n] = {0};

    sumCombination(n-1, sum, combination, n);

    return 0;
}