/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>

using namespace std;

/**
 * Write a Program to calculate Permutation and Combination for an input value n and r using
 * recursive formula of nCr and nPr .
 */


//recursive factorial
int recFactorial(int num){
	int result = 1;
	if(num <= 1) return 1;
	result = num * recFactorial(num-1);
	return result;
}

int main(){
    int n, r;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Enter value of r: ";
    cin>>r;
    int permutation = recFactorial(n)/recFactorial(n-r);
  	int combination = recFactorial(n)/(recFactorial(n-r)*recFactorial(r));
    cout << "Permutation "<<n<<"P"<<r<<" is :- "<<permutation<<endl;
    cout << "Combination "<<n<<"C"<<r<<" is :- "<<combination<<endl;
}