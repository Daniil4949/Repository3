#include<iostream>
#include"Header.h"
#include<fstream>
using namespace std;
struct arr {
	int** A;
	int n;
	int m;
};
void read() {
	arr array1;
	ifstream file;
	file.open("test1_5.txt");
	ifstream file2;
	file2.open("test2_5.txt");
	file >> array1.n;
	file >> array1.m;
	int** a;
	a = new int* [array1.n];
	for (int i = 0; i < array1.n; ++i) {
		a[i] = new int[array1.m];
	}
	for (int  i = 0; i < array1.n; ++i) {
		for (int j = 0; j < array1.m; ++j) {
			file >> a[i][j];
		}
	}
	array1.A = a;
	cout << "Первый массив: " << endl;
	for (int i = 0; i < array1.n; ++i) {
		for (int j = 0; j < array1.m; ++j) {
			cout << array1.A[i][j] << " ";
		}
		cout << endl;
	}
	sort_massiv(array1.A, array1.n, array1.m);
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < array1.n; ++i) {
		for (int j = 0; j < array1.m; ++j) {
			cout << array1.A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Введите элемент для поиска: " << endl;
	int x;
	cin >> x;
	int* X =search(array1.A,array1.n,array1.m,x);
	cout << "Строка: " << X[0] +1<< " Столбец: " << X[1]+1 << endl;
	cout << "Введите элемент, который хотите добавить: " << endl;
	int y;
	cin >> y;
	cout << "Введите номер строки: " << endl;
	int n1, m1;
	cin >> n1;
	cout << "Введите номер столбца: " << endl;
	cin >> m1;
	--n1;
	--m1;
	add(array1.A, array1.n, array1.m, y, n1, m1);
	for (int i = 0; i < array1.n; ++i) {
		for (int j = 0; j < array1.m; ++j) {
			cout << array1.A[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	arr array2;
	array2.m = array1.m;	
	int** B;
	file2 >> array2.n;
	B = new int* [array2.n];
	for (int i = 0; i < array2.n; ++i) {
		B[i] = new int[array2.m];
	}
	
	for (int i = 0; i < array2.n; ++i) {
		for (int j = 0; j < array2.m; ++j) {
			file2 >> B[i][j];
		}
	}
	array2.A = B;
	cout << "Второй массив: " << endl;
	for (int i = 0; i < array2.n; ++i) {
		for (int j = 0; j < array2.m; ++j) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Пересечение: " << endl;
	intersection(array1.A, array1.n, array1.m, array2.A, array2.n);
	cout << endl;
	cout << "Объединение: " << endl;
	association(array1.A, array1.n, array1.m, array2.A, array2.n);
	cout << endl;
}

void read2() {
	int** a;
	arr arr1;
	cout << "Введите количество строк первой матрицы : " << endl;
	cin >> arr1.n;
	cout << "Введите количество столбцов первой матрицы : " << endl;
	cin >> arr1.m;
	a = new int*[arr1.n];
	for (int i = 0; i < arr1.n; ++i) {
		a[i] = new int[arr1.m];
	}
	cout << "Введите матрицу: " << endl;
	for (int i = 0; i < arr1.n; ++i) {
		for (int j = 0; j < arr1.m; ++j) {
			cin>>a[i][j];
		}
	}
	arr1.A = a;
	cout << endl;
	sort_massiv(arr1.A, arr1.n, arr1.m);
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < arr1.n; ++i) {
		for (int j = 0; j < arr1.m; ++j) {
			cout<< arr1.A[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "Введите элемента для поиска: " << endl;
	int x;
	cin >> x;
	int* X=search(arr1.A, arr1.n, arr1.m, x);
	cout <<"строка: " << X[0] + 1 <<" столбец: " << X[1]+1;
	cout << endl;
	cout << "Введите элемент, который хотите добавить: " << endl;
	int y;
	cin >> y;
	cout << "Введите номер строки: " << endl;
	int n1;
	int m1;
	cin >> n1;
	--n1;
	cout << "Введите номер столбца: " << endl;
	cin >> m1;
	--m1;
	add(arr1.A, arr1.n, arr1.m, y, n1, m1);
	for (int i = 0; i < arr1.n; ++i) {
		for (int j = 0; j < arr1.m; ++j) {
			cout << arr1.A[i][j] << " ";
		}
		cout << endl;
	}
	arr arr2;
	cout << "Введите количество строк для второй матрицы: " << endl;
	cin >> arr2.n;
	arr2.m = arr1.m;
	int** B;
	B = new int* [arr2.n];
	for (int i = 0; i < arr2.n; ++i) {
		B[i] = new int[arr2.m];
	}
	cout << "Введите вторую матрицу:  " << endl;
	for (int i = 0; i < arr2.n; ++i) {
		for (int j = 0; j < arr2.m; ++j) {
			cin >> B[i][j];
		}
	}
	arr2.A = B;
	cout << "Пересечение: " << endl;
	 intersection(arr1.A, arr1.n, arr1.m, arr2.A, arr2.n);
	 cout << endl;
	 cout << "Объединение: " << endl;
	 association(arr1.A, arr1.n, arr1.m, arr2.A, arr2.n);
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	read();
	return 0;
}