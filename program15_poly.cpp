/**
  * Author: Pankaj Prajapati
  * Roll No.: 31
*/

/**
 * Question: Write a Program to store a function (polynomial/exponential), and then evaluate the
 * polynomial. (For example store f(x) = 4n3 + 2n + 9 in an array and for a given value
 * of n, say n = 5, evaluate (i.e. compute the value of f(5)).
 */

#include<iostream>

using namespace std;

#define MAX 1000

//Polynomial class
class polynomial
{

	/* 0th place denotes the coeff of x^0 and ith place denotes 
	   coeff of x^i */
	int coefficients[MAX]; 
	int degree;
	int xValue;

	public:
		//polynomial constructor
		polynomial(int degree, int xValue, int coeff[]){
			this->degree = degree;
			this->xValue = xValue;
			for (int i = 0; i <= degree; ++i)
			{
				coefficients[i] = coeff[i];
			}
		}

		int powerX(int x, int pow){
			int result = 1;
			for (int i = 0; i < pow; ++i)
			{
				result*=x;
			}
			return result;
		}

		//get the value of the polynomial
		int getValue(){
			int value=0;
			for (int i = 0; i <= degree; ++i)
			{
				value += coefficients[i]*powerX(xValue, i);
			}
			return value;
		}

		void show(){
			for (int i = degree; i >= 0; i--)
			{
				cout<<coefficients[i]<<"x^"<<i;
				if(i > 0) cout<<" + ";
			}
		}
	
};

int main(int argc, char const *argv[])
{
	int degree, xValue;
	cout<<"Enter the degree of the polymonial: ";
	cin>>degree;
	cout<<"Enter the coefficients of the dergees: \n";
	int coefficients[degree+1];
	for (int i = 0; i <= degree; ++i)
	{
		cout<<"Enter the coefficient of the x^"<<i<<" : ";
		cin>>coefficients[i];
		while(i == degree && coefficients[i]==0){
			cout<<"The coefficient of x^"<<degree<<" cannot be 0"<<endl;
			cout<<"Enter the coefficient of the x^"<<i<<" : ";
			cin>>coefficients[i];
		}
	}
	cout<<"Enter the value of x in the polymonial: ";
	cin>>xValue;
	polynomial poly = polynomial(degree, xValue, coefficients);
	cout<<"\nThe polynomial is: ";
	poly.show();
	cout<<"\n\nThe value of the polynomial at x = "<<xValue<<" is: "<<poly.getValue();
	return 0;
}