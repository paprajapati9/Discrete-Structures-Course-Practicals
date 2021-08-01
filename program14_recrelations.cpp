/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include<iostream>
 
using namespace std;

/**
 * Write a program to accept an input n from the user and graphically represent the values of
 * T(n) where n varies from 0 to n for the recurrence relations. For e.g. T(n) = T(n-1) + n,
 * T(0) = 1, T(n) = T(n-1) + n^2, T(0) =1, T(n) = 2*T(n/2) + n, T(1)=1.
 */

/**
 * Relation : T(n) = T(n-1) + n
 * Boundary Condition : T(0) = 1
 */
int rec_relation1(int n){
    if(n==0) {
        cout<<"T(0) = "<<1<<endl;
        return 1;
    }

    int t = rec_relation1(n-1) + n;
    cout<<"T("<<n<<") = "<<t<<endl;
    return t;
}

/**
 * Returns T(0) for rec relation 2
 */
int rec_relation2_lower(int n){
    if(n==2) {
        return 5;
    }

    int t = rec_relation2_lower(n+1) - (n+1)*(n+1);
    return t;
}


/**
 * Relation : T(n) = T(n-1) + n^2
 * Boundary Condition : T(2) = 5
 */
int rec_relation2(int n, int t){
    if(n==0) {
        cout<<"T(0) = "<<t<<endl;
        return t;
    }

    int r = rec_relation2(n-1, t) + n*n;
    cout<<"T("<<n<<") = "<<r<<endl;
    return r;
}

/**
 * Relation : T(n) = T(n/2) + n -1
 * Boundary Condition : T(0) = 4
 */
void rec_relation3(int n){
    int arr[n] = {0};
    arr[0] = 4;
    cout<<"T(0) = "<<4<<endl;
    for (int i = 1; i <= n; ++i)
    {
        int rec = arr[i/2]+i-1;
        cout<<"T("<<i<<") = "<<rec<<endl;   
        arr[i] = rec;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    //relation 1
    cout<<"\nT(n) = T(n-1) + n ,  T(0) = 1\n\n";
    rec_relation1(n);

    //relaation 2
    cout<<"\nT(n) = T(n-1) + n^2 ,  T(2) = 5\n\n";
    int t_zero = rec_relation2_lower(0); //first find 0th term
    rec_relation2(n, t_zero); //calculate the rec relation elements based on 0th term as boundary condition

    //relation 3
    cout<<"\nT(n) = T(n/2) + n -1 ,  T(0) = 4\n\n";
    rec_relation3(n);

    return 0;
}