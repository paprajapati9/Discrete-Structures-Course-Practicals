/**
 * Name: Pankaj Prajapati
 * Roll No. : 31
 */

#include <iostream>

using namespace std;


//recursive fibonacci
int recFibonacci(int num){
	if (num <= 1) return num;
    return recFibonacci(num-1) + recFibonacci(num-2);
}

int main(int argc, char const *argv[])
{
	int k;
	cout<<"Enter the element you want in the series: ";
	cin>>k;

	//recursive fibonacci
	cout<<"Fibonacci series: ";
	for(int i=0;i<k;i++) {
		cout<<recFibonacci(i)<<" ";
	}
	return 0;
}