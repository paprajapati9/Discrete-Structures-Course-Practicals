/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>

using namespace std;

/**
 * Q13. Write a Program to accept the truth values of variables x and y, and print the 
 * truth table of the following logical operations:
 */

int main(int argc, char const *argv[])
{
    bool x, y;
    cout<<"Enter truth value of x: ";
    cin>>x;
    cout<<"Enter truth value of y: ";
    cin>>y;
    cout<<"\nConjunction x & y is: "<<(x&y ? "True": "False");
    cout<<"\nDisjunction x V y is: "<<(x|y ? "True": "False");
    cout<<"\nExclusive OR is x^y: "<<(x^y ? "True": "False");
    cout<<"\nConditional x->y: "<<((!x)|y ? "True": "False");
    cout<<"\nBi-Conditional x<->y: "<<( ( ((!x)|y) & ((!y)|x) ) ? "True": "False");
    cout<<"\nExclusive NOR is !(x^y): "<<(!(x^y) ? "True": "False");
    cout<<"\nNegation of x !x is: "<<(!x ? "True": "False");
    cout<<"\nNAND is !(x & y): "<<(!(x&y) ? "True": "False");
    cout<<"\nNOR is: !(x V y): "<<(!(x|y) ? "True": "False");
    return 0;
}