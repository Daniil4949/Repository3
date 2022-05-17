// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int** A;
	int n;
	int m;
	cout << "Введите количество строк первой матрицы" << endl;
	cin >> n;
	cout << "Введите количество столбцов первой матрицы" << endl;
	cin >> m;
	vector<int> b;
	vector<int> c;
	vector<int> res;
	A = new int* [n];
	for (int i = 0; i < n; ++i) {
		A[i] = new int;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> A[i][j];
		}
	}
	cout << "Введите количество строк второй матрицы" << endl;
	int** B;
	int k;
	cin >> k;
	B = new int* [k];
	for (int i = 0; i < k; ++i) {
		B[i] = new int[m];
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> B[i][j];
		}
	}
	int i = 0;
	while (i < n) {
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y < m; ++y) {
				if (A[i][y] == B[x][y]) {
					//cout << x<<" ";
					b.push_back(x);
				}
			}
		}
		++i;
	}
	int s = 1;
	if (b.size() != 0) {
		for (int i = 0; i < b.size() - 1; ++i) {
			if (b[i] == b[i + 1]) {
				++s;
				if (s == m) {
					c.push_back(b[i]);
					s = 1;
				}
			}
		}
	}
	cout << endl;
	if (c.size() != 0) {
		for (int i = 0; i < c.size(); ++i) {
			//cout << c[i] << " ";
		}
		int** S;
		S = new int* [c.size()];
		for (int i = 0; i < c.size(); ++i) {
			S[i] = new int[m];
		}
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0; j <m; ++j) {
				S[i][j] = 0;
			}
		}
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0; j < m; ++j) {
				  S[i][j] = B[c[i]][j];
			}

		}
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0;j < m; ++j) {
				cout << S[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Пересечение - пустой массив." << endl;
	}

	//int i = 0;
	//while (i < n) {
	//	for (int x = 0; x < k; ++x) {
	//		for (int y = 0; y < m; ++y) {
	//			if (A[i][y] == B[x][y]) {
	//				//cout << x<<" ";
	//				b.push_back(x);
	//			}
	//		}
	//	}
	//	++i;
	//}
	//int s = 1;
	//if (b.size() != 0) {
	//	for (int i = 0; i < b.size() - 1; ++i) {
	//		if (b[i] == b[i + 1]) {
	//			++s;
	//			if (s == m) {
	//				c.push_back(b[i]);
	//				s = 1;
	//			}
	//		}
	//	}
	//}
	//cout << endl;
	//for (int i = 0; i < c.size(); ++i) {
	//	//cout << c[i] << " ";
	//}
	//int** S;
	//cout << endl;
	//int rasmer = n + k - c.size();
	//S = new int*[rasmer];
	//for (int i = 0; i < rasmer; ++i) {
	//	S[i] = new int[m];
	//}
	//for (int i = 0; i < rasmer; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		S[i][j] = 0;
	//	}
	//}
	//if (c.size() != 0) {
	//	for (int i = 0; i < n; ++i) {
	//		for (int j = 0; j < m; ++j) {

	//			S[i][j] = A[i][j];


	//		}
	//	}
	//	for (int i = 0; i < k; ++i) {
	//		for (int j = 0; j < c.size(); ++j) {
	//			if (i != c[j]) {
	//				res.push_back(i);
	//			}
	//		}
	//	}
	//	for (int i = n; i < rasmer; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			S[i][j] = B[res[i - n]][j];
	//		}
	//	}
	//	for (int i = 0; i < rasmer; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			cout << S[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//}
	//else {
	//	for (int i = 0; i < n; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			S[i][j] = A[i][j];
	//		}
	//	}
	//	for (int i = n; i < rasmer; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			S[i][j] = B[i - n][j];
	//		}
	//	}
	//	for (int i = 0; i < rasmer; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			cout << S[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//}
	//return 0;
}

//Расчетка, да поможет мне бог
//#include<iostream>
//using namespace std;
//int cost[100][100], n, m;
//int getMin(int dist[], bool visited[]) {
//    int key = 0;
//    int min = INT_MAX;
//    for (int i = 0; i < n; i++) {
//        if (!visited[i] && dist[i] < min) {
//            min = dist[i];
//            key = i;
//        }
//    }
//    return key;
//}
//
//void dijkstra() {
//	int src=0;
//	for (int i = 0; i < n; i++) {
//		int par[100], dist[100];
//		bool visited[100] = { 0 };
//		fill(dist, dist + n, INT_MAX);
//		dist[src] = 0;
//		par[src] = -1;
//		int max = 1;
//		for (int g = 0; g < n; g++) {
//			int u = getMin(dist, visited);
//			visited[u] = true;
//
//			int temporary = 0;
//			if (max < u) {
//				max = temporary;
//				temporary = u;
//				max = u;
//			}
//			for (int v = 0; v < m; v++) {
//				if (!visited[v] && (dist[u] + cost[u][v]) < dist[v] && cost[u][v] != 9999)
//				{
//					par[v] = u;
//					dist[v] = dist[u] + cost[u][v];
//				}
//			}
//		}
//		cout << "Эксцентриситет для " << i + 1 << " вершины равен: " << max << endl;
//	}
//}
//
// int main() {
//	 system("chcp 1251>nul");
//    cout << "Введите количество вершин: ";
//    cin >> n;
//    cout << "Введите количество ребер:  ";
//    cin >> m;
//    cout << " Введите матрицу инциндентности: "<<endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++)cin >> cost[i][j];
//    }
//    int src;
//	cout << endl;
//    
//    dijkstra();
//	system("pause");
//	return 0;
//}


//тут матрица смежности 


//#include<iostream>
//using namespace std;
//int cost[100][100], n;
//int getMin(int dist[], bool visited[]) {
//    int key = 0;
//    int min = INT_MAX;
//    for (int i = 0; i < n; i++) {
//        if (!visited[i] && dist[i] < min) {
//            min = dist[i];
//            key = i;
//        }
//    }
//    return key;
//}
//void dijkstra(int src) {
//    int par[100], dist[100];
//    bool visited[100] = { 0 };
//    fill(dist, dist + n, INT_MAX);
//    dist[src] = 0;
//    par[src] = -1;
//    int max = 1;
//    for (int g = 0; g < n - 1; g++) {
//        int u = getMin(dist, visited);
//        visited[u] = true;
//
//        int temporary = 0;
//        if (max < u) {
//            max = temporary;
//            temporary = u;
//            max = u;
//        }
//        for (int v = 0; v < n; v++) {
//            if (!visited[v] && (dist[u] + cost[u][v]) < dist[v] && cost[u][v] != 9999)
//            {
//                par[v] = u;
//                dist[v] = dist[u] + cost[u][v];
//            }
//        }
//    }
//    cout << "max " << max;
//}
//void main() {
//	cout << "Enter n : ";
//	cin >> n;
//	cout << "Enter cost matrix : \n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)cin >> cost[i][j];
//	}
//	int src;
//	cout << endl;
//	cout << "Enter source : ";  cin >> src;
//	dijkstra(src);
//}
//#include <vector>
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//int dst[10000];
//int used[10000];
//int main() {
//	system("chcp 1251>nul");
//	int n=0,m=0;
//	int graph[1000][1000];
//	cout << "Введите количество вершин: " << endl;
//	cin >> n;
//	cout << "Введите количество ребер: " << endl;
//	cin >> m;
//	cout << "Введите матрицу инциндентности: " << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> graph[i][j];
//		}
//	}
//	for (int k = 0; k < 10000; k++) {
//		dst[k] = -1;
//	}
//	queue<int> q;
//	q.push(0);
//	used[0] = true;
//
//	dst[0] = 0;         //теперь при добавлении каждой вершины в очередь мы вычисляем расстояние до неё
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//
//		for (int neighbor : graph[cur]) {
//			if (!used[neighbor]) {
//				q.push(neighbor);
//				used[neighbor] = true;
//				dst[neighbor] = dst[cur] + 1;   //вот и весь код расчёта расстояния
//			}
//		}
//	}
//
//
//	for (int i = 0; i < n; i++) {
//		if (dst[i] != -1) {
//			cout << "Distance between vertices 1 and " << i + 1 << " is " << dst[i] << endl;
//		}
//		else {
//			cout << "Vertex " << i + 1 << " cannot be reached from vertex 1." << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

























/*
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> graph[100000];
bool used[100000];
int dst[100000];

int main() {
	system("chcp 1251>nul");
	//Ввод графа...
	 


		         
	
	
	for (int i = 0; i < 100000; i++) {   //изначально заполним массив dst значением -1
		dst[i] = -1;                     //оно будет обозначать, что расстояние до этой вершины ещё неизвестно
	}

	queue<int> q;
	q.push(0);
	used[0] = true;
	dst[0] = 0;         //теперь при добавлении каждой вершины в очередь мы вычисляем расстояние до неё

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int neighbor : graph[cur]) {
			if (!used[neighbor]) {
				q.push(neighbor);
				used[neighbor] = true;
				dst[neighbor] = dst[cur] + 1;   //вот и весь код расчёта расстояния
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		if (dst[i] != -1) {
			cout << "Distance between vertices 1 and " << i + 1 << " is " << dst[i] << endl;
		}
		else {
			cout << "Vertex " << i + 1 << " cannot be reached from vertex 1." << endl;
		}
	}
	system("pause");
	return 0;


}
*/













//#include <iostream>
//#include <cmath>
//#include <vector> 
//#include <queue>
//using namespace std;
//int main()
//{	setlocale(LC_ALL, "Russian");
//    int n;
//    cin >> n;
//	int max = 1;
//	int temp = 0;
//	
//	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
//	for (int i = 0; i < n; i++) {
//		int a, b, d;
//		cin >> a >> b >> d;
//		v[a][b] = v[b][a] = d;
//	}
//
//	bool visite[100];
//	int dist[100];
//	for (int i = 0; i < n; i++) {
//		visite[i] = false;
//		dist[i] = INT_MAX;
//	}
//	int N = 0;
//	cout << "Введите номер вершины: " << endl;
//	cin >>N;
//	dist[N] = 0;
//	visite[N] = true;
//	queue<int>q;
//	q.push(N);
//	while (!q.empty()) {
//		int vertex = q.front();
//		q.pop();
//		for (int j = 1; j < v[vertex].size(); j++) {
//			if (!visite[j] && v[vertex][j]&&v[vertex][j]+dist[vertex]<dist[j]) {
//				dist[j] = v[vertex][j] + dist[vertex];
//				q.push(j);
//			}
//		}
//
//	}
//	for (int j = 1; j < 7; j++) {
//		if (dist[j] > max) {
//			max = dist[j];
//			
//			
//		}
//
//	}
//	cout << "Эксцентриситет для первой равен: " << max << endl;
//	
//
//	system("pause");
//		return 0;
//	}
	

/**#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int big_num(10000);
	int matrix[5][5] = { {0,5,12,0,0},       // матрица смежности моего графа, сам он на фотке
						{5,0,4,0,1},
						{12,4,0,2,0},
						{0,0,2,0,5},
						{0,1,0,5,0} };

	int pos[5], node[5], min(0), index_min(0);
	for (int i = 0; i < 5; ++i) {     // заполняем путь к вершине большими числами, желательно взять биг_нам ещё больше, но и так ок.
		pos[i] = big_num;       // а все вершины помечаем как "непройденные"
		node[i] = 0;
	}
	for (int i = 0; i < 5; ++i) {     // вывод матрицы
		for (int j = 0; j < 5; ++j) {
			cout << setw(4) << matrix[i][j];
		}
		cout << "\n";
	}
	pos[2] = 0;                // назначаем какую-то вершину началом алгоритма, узлом ( или так не говорят, хз)
	for (int i = 0; i < 4; ++i) {    // основной цикл
		min = big_num;
		for (int j = 0; j < 5; ++j) {     // находим вершину с минимальным к ней расстоянием, на первом шаге это будет узел
			if (!node[j] && pos[j] < min) {
				min = pos[j];
				index_min = j;
			}
		}
		node[index_min] = true;   // помечаем выбранную вершину как пройденную
		for (int j = 0; j < 5; ++j) {   // цикл, в котором мы даем всем вершинам, смежным с выбранной вес пути к ней
			if (!node[j] && matrix[index_min][j] > 0 && pos[index_min] != big_num && pos[index_min] + matrix[index_min][j] < pos[j]) {
				pos[j] = pos[index_min] + matrix[index_min][j];
			} // условие такое, если эта вершина не пройденная и она смежна с выбранной и если сумма веса выбранной вершины и ребра к текущей будет меньше, чем
		}     // вес текущей на данный момент, то  - меняем значение веса текущей вершины.
	}
	cout << pos[0] << "\n"; // теперь у нас в pos минимальные расстояния от выбранного узла к любой другой вершине

	cout << endl;
	return 0;
}**/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
