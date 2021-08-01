/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include<iostream>
 
using namespace std;

/**
 * Q1. Write a Program to accept a directed graph G and compute the in-degree and out-degree of
 * each vertex.
 */

#define MAX 1000

int adjMatrix[MAX][MAX];
 
//function to add an edge to the matrix
void addEdge(int node1, int node2){
	adjMatrix[node1][node2] = 1;
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
		cin>>edge1;
		cin>>edge2;
		addEdge(edge1-1, edge2-1);
	}

	//print the adjacency matrix of the graph
	cout<<"The adjacency matrix is"<<endl;
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//check for outdegree of each vertex in the graph
	int outDegree = 0;
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			if(adjMatrix[i][j] == 1) outDegree++;
		}
		cout<<"Out degree of vertex "<<i+1<<" is: "<<outDegree<<endl;
		outDegree = 0;
	}
	cout<<endl;

	//check for indegree of each vertex in the graph
	int inDegree = 0;
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			if(adjMatrix[j][i] == 1) inDegree++;
		}
		cout<<"In degree of vertex "<<i+1<<" is: "<<inDegree<<endl;
		inDegree = 0;
	}
	return 0;
}