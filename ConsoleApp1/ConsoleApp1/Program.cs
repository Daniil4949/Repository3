using System;
using System.Collections.Generic;


namespace GraphBFS
{
    class VertexData
    {
        public int? Distance { get; set; }
        public int? Predecessor { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Random randomGenerator = new Random();
            int randomNumber = randomGenerator.Next(3);
            string graphName = null;
            string[] fileContent;
            if (randomNumber == 0)
            {
                fileContent = System.IO.File.ReadAllLines("graph1.txt");
                graphName = "graph1";
            }
            else if (randomNumber == 1)
            {
                fileContent = System.IO.File.ReadAllLines("graph2.txt");
                graphName = "graph2";
            }
            else if (randomNumber == 2)
            {
                fileContent = System.IO.File.ReadAllLines("graph3.txt");
                graphName = "graph3";
            }
            else
            {
                fileContent = System.IO.File.ReadAllLines("graph1.txt");
                graphName = "graph1";
            }
            for (int itr = 0; itr < fileContent.Length; ++itr)
            {
                fileContent[itr] = fileContent[itr].Substring(fileContent[itr].IndexOf('=') + 1);
            }
            string[] matrixValues = fileContent[2].Split(' ');

            int V = int.Parse(fileContent[0]);
            int E = int.Parse(fileContent[1]);
            int[,] graph = new int[V, E];
            int counter = 0;
            for (int itr = 0; itr < V; ++itr)
            {
                for (int itr2 = 0; itr2 < E; ++itr2)
                {

                    graph[itr, itr2] = int.Parse(matrixValues[counter]);
                    counter++;
                }

            }
            List<VertexData> resultList = new List<VertexData>();
            int?[] graphEccentricities = new int?[V];
            for (int itr = 0; itr < V; ++itr)
            {
                resultList = BFS(graph, itr, V, E);
                int? max = resultList[0].Distance;
                for (int itr2 = 0; itr2 < resultList.Count; ++itr2)
                {
                    if (resultList[itr2].Distance > max)
                    {
                        max = resultList[itr2].Distance;
                    }
                }
                graphEccentricities[itr] = max;
                resultList.Clear();
            }
            for (int itr = 0; itr < V; ++itr)
            {
                if (graphEccentricities[itr] == null)
                {
                    Console.WriteLine($"{graphName} vertex {itr} eccentricity is: -");
                }
                Console.WriteLine($"{graphName} vertex {itr} eccentricity is: {graphEccentricities[itr]}");
            }
        }
        static List<int> GetAdjacentVertices(int[,] graph, int V, int E, int sourceVertex)
        {
            List<int> adjacentVertices = new List<int>();

            for (int itr = 0; itr < E; ++itr)
            {
                if (graph[sourceVertex, itr] == 1)
                {
                    for (int itr2 = 0; itr2 < V; ++itr2)
                    {
                        if (itr2 == sourceVertex)
                        {
                            continue;
                        }
                        if (graph[itr2, itr] == 1)
                        {
                            adjacentVertices.Add(itr2);
                        }
                    }

                }
            }
            return adjacentVertices;
        }
        static List<VertexData> BFS(int[,] graph, int sourceVertex, int V, int E)
        {
            List<VertexData> vertexDataList = new List<VertexData>();
            for (int itr = 0; itr < V; ++itr)
            {
                VertexData vertexDataInstance = new VertexData();
                vertexDataList.Add(vertexDataInstance);
            }

            vertexDataList[sourceVertex].Distance = 0;
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(sourceVertex);

            while (queue.Count != 0)
            {

                int index = queue.Dequeue();
                List<int> adjacentVertices = GetAdjacentVertices(graph, V, E, index);
                for (int itr = 0; itr < adjacentVertices.Count; ++itr)
                {
                    if (vertexDataList[adjacentVertices[itr]].Distance == null)
                    {
                        vertexDataList[adjacentVertices[itr]].Distance = vertexDataList[index].Distance + 1;
                        vertexDataList[adjacentVertices[itr]].Predecessor = index;
                        queue.Enqueue(adjacentVertices[itr]);
                    }
                }
                adjacentVertices.Clear();
            }

            return vertexDataList;
        }
        
    }
       
}
