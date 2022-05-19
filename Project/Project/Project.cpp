// Project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include<string>
using namespace std;

bool visitedCheck(vector<bool>& visited) {
    int ans = 0;
    for (auto it : visited) {
        if (it)
            ans++;
    }
    return (ans == visited.size());
}

class Graph {
private:
    int vertices;
    int edges;
    vector<vector<int>> inc;
public:
    Graph(vector<vector<int>> matrix) :
        inc(matrix), vertices(matrix.size()), edges(matrix[0].size()) {}
    vector<int> dfs(int start, int end, vector<bool> visited);
};

vector<int> Graph::dfs(int start, int end, vector<bool> visited) {
    int cur = start;
    int i = -1;
    vector<int> dist(vertices);
    dist[start] = 0;
    while (i < edges) {
        i++;
        if (inc[cur][i] == 1 && visited[i] == false) {
            for (int j{ 0 }; j < vertices; ++j) {
                if (inc[j][i] == 1 && j != cur) {
                    visited[i] = true;
                    dist[j] = dist[cur] + 1;
                    start = cur;
                    cur = j;
                    i = -1;
                    break;
                }
            }
        }
        if (i == edges - 1) {
            if (visitedCheck(visited))
                break;
            if (cur < start)
                cur++;
            else
                cur--;
            i = -1;
        }
    }
    return dist;
}

int main() {
    vector<int> ans;
    int v, e;
    int count = -1;
    ifstream example;
    ofstream out;
    
    example.open("example1.txt");
    out.open("output.txt");
    example >> v >> e;
    vector<vector<int>> matrix;
    for (int i{ 0 }; i < v; ++i) {
        vector<int> temp;
        for (int j{ 0 }; j < e; ++j) {
            int el;
            example >> el;
            temp.push_back(el);
        }
        matrix.push_back(temp);
    }
    Graph g{ matrix };
    for (int i{ 0 }; i < v; ++i) {
        auto test = g.dfs(i, v - 1, vector<bool>(e, false));
        ans.push_back(*max_element(test.begin(), test.end()));
    }
    for (auto it : ans) {
        count++;
        out << count << ") " << it << endl;
    }
    out.close();
    example.close();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
