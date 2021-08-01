/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    public:
    int totalVertices, totalEdges;
    vector<vector<bool>> adjMatrix;
    public:
    Graph(int vertices, int edges)
    {
        totalVertices = vertices;
        totalEdges = edges;
        adjMatrix.resize(vertices);
        for(int i = 0; i < vertices; i++) adjMatrix[i].resize(vertices);

    }

    void addEdge(int node1, int node2){
        adjMatrix[node1][node2] = 1;
    }

    void set()
    {
        int vertex1, vertex2;
        cout<<"\nEnter vertices pair for edges:\n\n";
        for(int i=0; i<totalEdges; i++){
            cout<<"Vertices pair "<<i+1<<" :";
            cin>>vertex1>>vertex2;
            addEdge(vertex1-1, vertex2-1);
        }

    }

    void show()
    {
        for(int i = 0; i < totalVertices; i++)
        {
            for(int j = 0; j < totalVertices; j++)
            {
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void paths(int pathLength,int begin,int end)
    {
        vector<vector<int>> graphPower(totalVertices);

        for(int i = 0; i < totalVertices; i++) graphPower[i] = vector<int>(totalVertices, 0);
    
        for(int i = 0; i < totalVertices; i++)
        {
            for(int j = 0; j < totalVertices; j++)
            {
                graphPower[i][j]=adjMatrix[i][j];
            }
        }

        cout<<"Possible paths between vertex "<<begin<<" -> "<<end<<": ";
        cout<<possiblePaths(pathLength,begin-1,end-1,graphPower)<<endl;
    }
    
    int possiblePaths(int pathLength,int begin,int end,vector<vector<int>> graphPower)
    {
        vector<vector<int>> tempMatrix(totalVertices);

        for(int i = 0; i < totalVertices; i++) tempMatrix[i] = vector<int>(totalVertices, 0);

        if(pathLength==1) return graphPower[begin][end];
        
        for(int i = 0; i < totalVertices; i++)
        {
            for(int j = 0; j < totalVertices; j++)
            {
                for(int k = 0; k < totalVertices; k++)
                {
                    tempMatrix[i][j] += (graphPower[i][k]*adjMatrix[k][j]);
                }
            }
        }
        
        graphPower=tempMatrix;
        
        return possiblePaths(pathLength-1,begin,end,graphPower);
    }
};

int main()
{
    int vertices, edges, begin, end, plength;

    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter total number of edges: ";
    cin>>edges;
    Graph g(vertices, edges);
    g.set();
    cout<<"\n\nAdjacency Matrix:\n";
    g.show();
    
    cout<<"\n\nEnter Starting point index number: ";
    cin>>begin;
    cout<<"\nEnter Ending point index number: ";
    cin>>end;
    cout<<"\nEnter Path length: ";
    cin>>plength;

    g.paths(plength,begin,end);
    return 0;
}