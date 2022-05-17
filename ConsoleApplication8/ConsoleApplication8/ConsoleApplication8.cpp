#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
struct VertexData
{
    int Distance;
    int Parent;
};

vector<int> GetAdjacentVertices(vector<vector<int>> graph, int V, int E, int sourceVertex)
{
    vector<int> adjacentVertices = vector<int>();

    for (int i = 0; i < E; ++i)
    {
        if (graph[sourceVertex][i] == 1)
        {
            for (int i2 = 0; i2 < V; ++i2)
            {
                if (i2 == sourceVertex)
                {
                    continue;
                }
                if (graph[i2][i] == 1)
                {
                    adjacentVertices.push_back(i2);
                }
            }

        }
    }
    return adjacentVertices;
}
vector<VertexData> BFS(vector<vector<int>>graph, int sourceVertex, int V, int E)
{
    vector<VertexData> vertexDataList = vector<VertexData>();
    for (int i = 0; i < V; ++i)
    {
        VertexData vertexData = VertexData();
        vertexData.Distance = -1;
        vertexData.Parent = -1;
        vertexDataList.push_back(vertexData);
    }

    vertexDataList[sourceVertex].Distance = 0;
    queue<int> queue = std::queue<int>();
    queue.push(sourceVertex);

    while (queue.size() != 0)
    {

        int index = queue.front();
        queue.pop();
        vector<int> adjacentVertices = GetAdjacentVertices(graph, V, E, index);
        for (int i = 0; i < adjacentVertices.size(); ++i)
        {
            if (vertexDataList[adjacentVertices[i]].Distance == -1)
            {
                vertexDataList[adjacentVertices[i]].Distance = vertexDataList[index].Distance + 1;
                vertexDataList[adjacentVertices[i]].Parent = index;
                queue.emplace(adjacentVertices[i]);
            }
        }
        adjacentVertices.clear();
    }

    return vertexDataList;
}
int main()
{
    
    fstream file;
    vector<string> fileContent;
    string dataFromFile;
   
    string graphName;
    
        graphName = "graph3";
        file.open("graph3.txt");
        if (file.is_open())
        {
            while (getline(file, dataFromFile))
            {
                fileContent.push_back(dataFromFile);
            }


            file.close();
        }
    vector<string> matrixValues;
    int counter = 0;
    for (int i = 5; i < fileContent.size(); ++i)
    {
        for (int i2 = 0; i2 < fileContent[i].size(); ++i2)
        {
            counter++;
        }
    }
    matrixValues.resize(counter);
    int i = 0;
    for (int i2 = 5; i2 < fileContent.size(); ++i2)
    {
        int i3 = 0;
        stringstream stringStreamIn(fileContent[i2]);
        while (stringStreamIn.good() && i3 < fileContent[i2].size())
        {
            stringStreamIn >> matrixValues[i];
            ++i;
            ++i3;
        }
    }
    int V = stoi(fileContent[1]);
    int E = stoi(fileContent[3]);
    vector<vector<int>> graph(V, vector<int>(E));
    int counter2 = 0;
    for (int i = 0; i < V; ++i)
    {
        for (int i2 = 0; i2 < E; ++i2)
        {

            graph[i][i2] = stoi(matrixValues[counter2]);
            counter2++;
        }

    }
    vector<VertexData> resultList = vector<VertexData>();

    vector<int> graphEccentricities = vector<int>(V);
    for (int i = 0; i < V; ++i)
    {
        resultList = BFS(graph, i, V, E);
        int max = resultList[0].Distance;
        for (int i2 = 0; i2 < resultList.size(); ++i2)
        {
            if (resultList[i2].Distance > max)
            {
                max = resultList[i2].Distance;
            }
        }
        graphEccentricities[i] = max;
        resultList.clear();
    }
    for (int i = 0; i < V; ++i)
    {
        cout << graphName << " vertex " << i+1 << " eccentricity is : " << graphEccentricities[i] << endl;
    }
    return 0;
}