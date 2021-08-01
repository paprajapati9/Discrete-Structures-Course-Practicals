/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
#include<vector>

using namespace std;

/**
 * Q1 : Write a Program to create a SET A and determine the cardinality of SET 
 * for an input array of elements (repetition allowed) and perform the following 
 * operations on the SET:
 * 
 * a) ismember (a, A): check whether an element belongs to set or not and 
 * return value as true/false.
 * 
 * b) powerset(A): list all the elements of power set of A.
 */

#define MAX 1000

//size of set
int size = 0;

void printSet(std::vector<int> set){
	cout<<"{ ";
	for (int i = 0; i < set.size(); ++i)
	{
		cout<<set[i]<<" ";
	}
	cout<<"}";
	cout<<endl;
}

/**
 * Checks if element entered by user is present in the set
 */
bool isMember(int a, vector<int> setA){
	for(int i = 0; i<size; i++){
		if(setA[i] == a) return 1;
	}
	return 0;
}

/**
 * Prints the powerset of a given set, which
 * is a set containing all the subsets of the set
 */
void powerSet(vector<int> setA, int start, vector<int> subset = {}){
	if(start > setA.size()) {
		return;
	}
	printSet(subset);
	for (int i = start; i < setA.size(); ++i)
	{
		subset.push_back(setA[i]);

		powerSet(setA, i+1, subset);

		subset.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	int flag = 1, check;
	int arr[MAX], arr_size=0, unique=1;
	vector<int> setA, subset;
	while(flag){
		cout<<"Enter a element of the set: ";
		cin>>arr[arr_size];
		arr_size++;
		cout<<"Do you want to enter more elements (0/1): ";
		cin>>flag;
	}

	//finding unique elements and getting our set
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(arr[i] == setA[j]) {
				unique = 0;
				break;
			}
		}
		if(unique){
			setA.push_back(arr[i]);
			size++;
		}
		unique = 1;
	}

	cout<<"\nThe setA is: { ";
	for (int i = 0; i < size; i++)
	{
		if(i < (size-1)){
			cout<<setA[i]<<", ";
		}else{
			cout<<setA[i]<<" }";
		}
	}
	
	cout<<"\nThe cardinality of the set is: "<<size;
	cout<<"\nEnter a element to check if it is present in the set: ";
	cin>>check;
	if(isMember(check, setA)){
		cout<<"It is a member of the set";
	}
	else{
		cout<<"It is not a member of the set";
	}
	
	cout<<"\nThe power set is: \n";
	powerSet(setA, 0);
	return 0;
}
