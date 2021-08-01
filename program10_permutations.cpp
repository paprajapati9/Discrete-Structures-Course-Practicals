/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Q2. Write a Program that generates all the permutations of a given set of  
 * digits, with or without repetition. (For example, if the given set is {1,2}, 
 * the permutations are 12 and 21).
 */


/**
 * Function to swap 2 numbers by reference
 */
void swapNum(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

/**
 * Prints the elements of a given vector
 */
void printVector(vector<int> vec){
	for (int i = 0; i < vec.size(); ++i){
		cout<<vec[i]<<" ";
	}
}


/**
 * Backtracking algo to print all permutations of a given vector
 * of integer elements.
 */
void getPermutations(vector<int>& permutation, int level){
    if(level == permutation.size()){
        printVector(permutation);
        cout<<endl;
        return;
    }
    for(int i=level;i < permutation.size();++i){
        swapNum(permutation[i], permutation[level]);
        getPermutations(permutation, level + 1);
        swapNum(permutation[level], permutation[i]);
    }
}

int main(){
    vector <int> permutation;
    int size, number;
    cout << "Enter the size of array :- ";
    cin>>size;
    cout << "\nEnter the numbers to find permutations :- ";
    for (int i = 0; i < size; ++i){
    	cin>>number;
    	permutation.push_back(number);
    }
    cout<<"\nAll the permutations are: \n";
    getPermutations(permutation, 0);
}