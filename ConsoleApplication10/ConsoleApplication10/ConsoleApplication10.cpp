
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
    vector<int> adjacentVertices = std::vector<int>();

    for (int i = 0; i < E; ++i)
    {

        if (graph[sourceVertex][i] > 0)
        {
            for (int j = 0; j < V; ++j)
            {
                if (j == sourceVertex)
                {
                    continue;
                }
                if (graph[j][i] > 0)
                {
                    adjacentVertices.push_back(j);
                }
            }

        }
    }
    return adjacentVertices;
}
int GetAdjacentIndex(vector<vector<int>>graph, int adjacentVertex, int sourceVertex, int V, int E)
{

    for (int j = 0; j < E; ++j)
    {
        if (graph[adjacentVertex][j] > 0 && graph[sourceVertex][j] > 0)
        {
            return j;
        }
    }
    return -1;

}
vector<VertexData> Algorithm(vector<vector<int>>graph, int sourceVertex, int V, int E)
{
    vector<VertexData> vertexDataList = vector<VertexData>();
    for (int i = 0; i < V; ++i)
    {
        VertexData vertexData = VertexData();
        vertexData.Distance = INT_MAX;
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
            int adjacentIndex = GetAdjacentIndex(graph, adjacentVertices[i], index, V, E);
            if (vertexDataList[adjacentVertices[i]].Distance > vertexDataList[index].Distance + graph[index][adjacentIndex])
            {
                vertexDataList[adjacentVertices[i]].Distance = vertexDataList[index].Distance + graph[index][adjacentIndex];
                vertexDataList[adjacentVertices[i]].Parent = index;
                queue.emplace(adjacentVertices[i]);
            }
        }
        adjacentVertices.clear();
    }

    return vertexDataList;

}
int main()
{   fstream file;
    vector<string> fileContent;
    string dataFromFile;
    string graphName;
        graphName = "graph1";
        file.open("graph1.txt");
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
        for (int j = 0; j < fileContent[i].size(); ++j)
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
        resultList = Algorithm(graph, i, V, E);
        int max = resultList[0].Distance;
        for (int i2 = 0; i2 < resultList.size(); ++i2)
        {
            if (resultList[i2].Distance > max && resultList[i2].Parent >= 0)
            {
                max = resultList[i2].Distance;
            }
        }
        graphEccentricities[i] = max;
        resultList.clear();
    }
    for (int i = 0; i < V; ++i)
    {
        if (graphEccentricities[i] == INT_MAX)
        {
            cout << graphName << " vertex " << i+1 << " eccentricity is : -" << endl;
        }
        else
            cout << graphName << " vertex " << i+1 << " eccentricity is : " << graphEccentricities[i] << endl;
    }
    return 0;
}