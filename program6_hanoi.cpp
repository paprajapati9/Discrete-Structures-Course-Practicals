/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>

using namespace std;

/**
 * Q2. Write a Program to implement Tower of Hanoi using recursion.
 */
 

void hanoiTower(int disks, char fromRod, char toRod, char auxRod){
    if (disks == 1){
        cout << "Move disk 1 from rod " << fromRod <<" to rod " << toRod<<endl;
        return;
    }
    hanoiTower(disks - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << disks << " from rod " << fromRod <<" to rod " << toRod << endl;
    hanoiTower(disks - 1, auxRod, toRod, fromRod);
}
 
int main()
{
    int disks; // Number of disks
    cout<<"Enter number of disks in the tower: ";
    cin>>disks;
    int fromRod, toRod, auxRod;
    cout<<"Enter the staring rod (1, 2, 3): ";
    cin>>fromRod;
    cout<<"Enter the ending rod (1, 2, 3): ";
    cin>>toRod;
    auxRod = 6 - (fromRod+toRod); //6 is total sum - from rod - to rod
    hanoiTower(disks, 64+fromRod, 64+toRod, 64+auxRod); // A, B and C are names of rods
    return 0;
}