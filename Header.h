#pragma once
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int** sort_massiv(int** A,int n,int m);
int* search(int** A, int n, int m, int x);
int** add(int** A, int n, int m, int x, int y, int z);
int** association(int** A, int n, int m, int** B, int k);
int** intersection(int** A, int n, int m, int** B, int k);
int* binary_search(int* b, int n, int m,int x);
int** association2(int** S, int rasmer, int n, int m, int** A,int** B);
void empty() {
	cout << "Пересечение - пустой массив" << endl;
}
int** zero(int** S, int rasmer, int m) {
	for (int i = 0; i < rasmer; ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = 0;
		}
	}
	return S;
}
int** change(int** S, int** A,int m,int n ) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = A[i][j];
		}
	}
	return S;
}
int** show(int** S,int** B,int rasmer,int m,int n,vector<int> res) {
	for (int i = n; i < rasmer; ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = B[res[i - n]][j];
		}
	}
	for (int i = 0; i < rasmer; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	return S;
}
int* binary_search(int* b, int n, int m,int x) {
	int midd = 0;
	int right1 = n * m;
	int left1 = 0;
	int* res;
	int w = 2;
	res = new int[w];
	res[0] = 0;
	res[1] = 0;
	while (left1 <= right1)
	{
		midd = (left1 + right1) / 2;

		if (x < b[midd])
			right1 = midd - 1;
		else if (x > b[midd])
			left1 = midd + 1;
		else {
			res[0] = midd / m;
			res[1] = (midd % m);
			return res;
		}

	}
}
int** association2(int** S, int rasmer, int n, int m, int** A,int** B) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = A[i][j];
		}
	}
	for (int i = n; i < rasmer; ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = B[i - n][j];
		}
	}
	for (int i = 0; i < rasmer; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	return S;
}
int** sort_massiv(int** A, int n, int m) {
	int* b = new int[n * m];
	for (int i = 0; i < n * m; ++i) {
		b[i] = 0;
	}
	for (int i = 0, k = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[k++] = A[i][j];
		}
	}
	int temp;
	for (int i = 0; i < n * m - 1; i++) {
		for (int j = 0; j < n * m - i - 1; j++) {
			if (b[j] > b[j + 1]) {

				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	for (int i = 0, k = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			A[i][j] = b[k++];
		}
	}
	return A;
}
int* search(int** A, int n, int m, int x) {
	sort_massiv(A, n, m);
	int* b = new int[n * m];
	int s = 0;
	for (int i = 0, k = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (x == A[i][j]) {
				++s;
			}
		}
	}
	if (s == 0) {
		cout << "Нет такого элемента!" << endl;
		int* X = new int[2];
		X[0] = 55555;
		X[1] = 5555;
		return X;
	}
	else {
		for (int i = 0; i < n * m; ++i) {
			b[i] = 0;
		}
		for (int i = 0, k = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				b[k++] = A[i][j];
			}
		}
		binary_search(b, n, m, x);
	}
}
int** add(int** A, int n, int m, int x, int y, int z) { //x-значение, у-нужная строка,z-нужный столбец
	if (y <= n && z <= m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == y && j == z) {
					A[i][j] = x;
				}
			}
		}
		return A;
	}
	else {
		
		return A;
	}
}
int** association(int** A, int n, int m, int** B, int k) {
	vector<int> b;
	vector<int> c;
	vector<int> res;
	int i = 0;
	while (i < n) {
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y < m; ++y) {
				if (A[i][y] == B[x][y]) {
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
	int** S;
	cout << endl;
	int rasmer = n + k - c.size();
	S = new int* [rasmer];
	for (int i = 0; i < rasmer; ++i) {
		S[i] = new int[m];
	}
	zero(S, rasmer, m);
	if (c.size() != 0) {
		change(S, A,  m,  n);
		int isRepeat;
		for (int i = 0; i < k; ++i) {
			isRepeat = 0;
			for (int j = 0; j < c.size(); ++j) {
				if (i == j) {
					isRepeat = 1;
					break;
				}
			}
			if (isRepeat == 0) {
				res.push_back(i);
			}
		}
		show(S, B, rasmer, m, n, res);
	}
	else {
		S = association2(S, rasmer, n, m, A, B);
	}
	return S;
}
int** intersection(int** A, int n, int m, int** B, int k) {
	int i = 0;
	vector<int> c;
	vector<int> b;
	while (i < n) {
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y < m; ++y) {
				if (A[i][y] == B[x][y]) {
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
	int** S;
	S = new int* [c.size()];
	for (int i = 0; i < c.size(); ++i) {
		S[i] = new int[m];
	}
	for (int i = 0; i < c.size(); ++i) {
		for (int j = 0; j < m; ++j) {
			S[i][j] = 0;
		}
	}
	if (c.size() != 0) {
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0; j < m; ++j) {
				S[i][j] = B[c[i]][j];
			}
		}
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0; j < m; ++j) {
				cout << S[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		empty();
	}
	return S;
}
