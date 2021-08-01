/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include<iostream>
 
using namespace std;

/**
 * Q1. Given an adjacency matrix of a graph, write a program to check whether a given set of
 * vertices {v1,v2,v3.....,vk} forms an Euler path / Euler Circuit (for circuit assume vk=v1).
 */

#define MAX 1000

int adjMatrix[MAX][MAX];
 
//function to add an edge to the matrix
void addEdge(int node1, int node2){
	adjMatrix[node1][node2] += 1; //for multigraphs
	adjMatrix[node2][node1] += 1; //for multigraphs
}
 
int main(){
	int testCases, totalEdges, totalVertices, edge1, edge2;
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
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<endl;
	}

	//check for euler ciurcuit and path in the graph
	//chinking number of vertices with odd degree
	int oddDegree=0,degree=0;
	for(int i=0; i<totalVertices; i++){
		for(int j=0; j<totalVertices; j++){
			if(adjMatrix[i][j] != 0){
				degree+=adjMatrix[i][j]; //for multigraphs
			}
		}
		if(degree%2 != 0) oddDegree++;
		degree = 0;
	}
	if(oddDegree == 0){
		cout<<"Graph has a Euler Circuit and Euler Path";
	}
	else if(oddDegree == 2){
		cout<<"Graph does not have a Euler Circuit but has a Euler Path";
	}
	else{
		cout<<"Graph does not have a Euler Circuit and Euler Path";
	}
	return 0;
}