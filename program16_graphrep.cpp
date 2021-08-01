/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include<iostream>
 
using namespace std;


/**
 * Q1. Write a Program to represent Graphs using the Adjacency Matrices and check if it is a
 * complete graph.
 */

#define MAX 1000

int adjMatrix[MAX][MAX];
 
//function to add an edge to the matrix
void addEdge(int node1, int node2){
	adjMatrix[node1][node2] = 1;
	adjMatrix[node2][node1] = 1;
}
 
int main(){
	int testCases, totalEdges, totalVertices, edge1, edge2, isComplete=1;
	cout<<"Enter total number of vertices: ";
	cin>>totalVertices;
	cout<<"Enter total number of edges: ";
	cin>>totalEdges;
	//create the adjacency matrix with no edges
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			adjMatrix[i][j] = 0;
		}
	}

	//add edges to the specified vertices
	for(int i=0; i<totalEdges; i++){
		cout<<"\nEnter edge vertices : ";
		cin>>edge1;
		cin>>edge2;
		addEdge(edge1-1, edge2-1);
	}

	//print the adjacency matrix of the graph
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<endl;
	}

	//check for completeness of the graph
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			if(adjMatrix[i][j] == 0 && i!=j){
				isComplete = 0; //break if one such point is found
				break;
			}
		}
		if(!isComplete) break;
	}
	if(isComplete){
		cout<<"Graph is complete";
	}else{
		cout<<"Graph is not complete";
	}
	return 0;
}