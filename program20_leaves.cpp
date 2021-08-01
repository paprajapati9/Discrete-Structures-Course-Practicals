/**
  * Author: Pankaj Prajapati
  * Roll No.: 31
*/

/**
  * Question: Given a full m-ary tree with i internal vertices.
  * Write a Program to find the number of leaf nodes.
*/

#include<iostream>

using namespace std;

//M ary tree class
class mAryTree
{
	//number of nodes from each internal node
	int mAry;
	int internalNodes;

	public:
		//tree constructor
		mAryTree(int mAry, int internalNodes){
			this->mAry = mAry;
			this->internalNodes = internalNodes;
		}

		//getLeaves
		int getLeaves(){
			int leaves = (mAry - 1)*internalNodes + 1;
			return leaves;
		}
	
};

int main(int argc, char const *argv[])
{
	int mAry, internalNodes;
	cout<<"Enter the value of m in the m-ary tree: ";
	cin>>mAry;
	cout<<"Enter the number of internal nodes in the tree: ";
	cin>>internalNodes;
	mAryTree tree = mAryTree(mAry, internalNodes);
	cout<<"Number of leaves in the "<<mAry<<"-ary tree are: "<<tree.getLeaves();
	return 0;
}