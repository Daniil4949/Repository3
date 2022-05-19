//#include<iostream>
//#include<clocale>
//#include<vector>
//using namespace std;
//
//int** PereChislenie(int key);
//void  Watch(int** M, int mM);
//void  KonZap();
//void  menu();
//int** InOne(int** A, int** B, int mA, int mB);		// Объединение графиков
//int** Peresek(int** A, int** B, int mA, int mB);	// Пересечение графиков
//int** Pa3HocTb(int** U, int** W, int mU, int mW);	// Разность 
//int** SimRas(int** A, int** B, int mA, int mB);		// Симметричная разность A u B
//int** Inversion(int** M, int mM);					// Инверсия
//int** Exposition(int** A, int** B, int mA, int mB);	// Композиция графиков
//int** Dopolnenie(int** A, int** B, int ma, int mB);
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	cout << "Введите мощность графика А:\t";
//	int mA;
//	cin >> mA;  // Пользователь вводит мощность n первого графика A.
//	int** A = PereChislenie(mA); // Пользователь последовательно вводит n пар первого графика.
//	cout << "Введите мощность графика B:\t";
//	int mB;
//	cin >> mB; //Пользователь вводит мощность m второго графика B.
//	int** B = PereChislenie(mB);// Пользователь последовательно вводит m пар второго графика.
//	KonZap();
//	while (true)
//	{
//		system("cls");
//		cout << "A =  ";	Watch(A, mA);
//		cout << "B =  ";	Watch(B, mB);
//		menu();   //меню
//		int Operaziya;
//		cin >> Operaziya; //Пользователь выбирает исполняемую операцию:
//		system("cls");
//		switch (Operaziya)
//		{
//		case 1: // Пересечение графиков
//		{
//			cout << "Пересечение графиков :" << endl;
//			int mD = mA + mB + 1;
//			int** D = new int* [mD]; //  Создаём пустой график D.
//
//			for (int i = 0; i <= mD; i++)
//				D[i] = new int[3];
//			D = Peresek(A, B, mA, mB);
//			mD = D[0][0];
//			Watch(D, mD); //Выводим на экран график D
//			system("pause");
//		}
//		break;
//		case 2: // Объединение графиков
//		{
//			cout << "Объединение графиков :" << endl;
//			int mC = mA + mB + 1;
//			int** C = new int* [mC];   //Создаём пустой график С
//			for (int i = 0; i <= mC; i++)
//				C[i] = new int[3];
//			C = InOne(A, B, mA, mB);
//			mC = C[0][0];
//			Watch(C, mC);//Выводим на экран график C
//			system("pause");
//		}
//		break;
//		case 3: // Разность A и В 
//		{
//			cout << "Разность A и В :" << endl;
//			int mR = mA + 1;
//			int** R = new int* [mR];//  Создаём пустой график R.
//			for (int i = 0; i <= mR; i++)
//				R[i] = new int[3];
//			R = Pa3HocTb(A, B, mA, mB);
//			mR = R[0][0];
//			Watch(R, mR);//Выводим на экран график R
//			system("pause");
//		}
//		break;
//		
//		case 4:// Симметричная разность A u B
//		{
//			cout << "Симметричная разность A u B :" << endl;
//			int mS = mB + mA + 1;
//			int** S = new int* [mS];//  Создаём пустой график S.
//
//			for (int i = 0; i <= mS; i++)
//				S[i] = new int[3];
//			S = SimRas(B, A, mB, mA);
//			mS = S[0][0];
//			Watch(S, mS);//Выводим на экран график S
//			system("pause");
//		}
//		break;
//		case 5:// Инверсия А 
//		{
//			cout << "Инверсия А :" << endl;
//			int mI = mA;
//			int** I = new int* [mI];//Создаём пустой график I
//			for (int i = 0; i <= mI; i++)
//				I[i] = new int[3];
//			I = Inversion(A, mA);
//			mI = I[0][0];
//			Watch(I, mI);//Выводим на экран график I
//			system("pause");
//		}
//		break;
//		
//		case 6:// Композиция графиков A и B
//		{
//			cout << "Композиция графиков A и B :" << endl;
//			int mK = mB * mA + 1;
//			int** K = new int* [mK];//Создаём пустой график K
//			for (int i = 0; i <= mK; i++)
//				K[i] = new int[3];
//			K = Exposition(A, B, mA, mB);
//			mK = K[0][0];
//			Watch(K, mK);//Выводим на экран график K
//			system("pause");
//		}
//		break;
//		case 7:
//		{
//			cout << "Дополнение графика А до универсума: " << endl;
//			int** D = InOne(A, B, mA, mB);
//			int** W = Pa3HocTb(D, A, D[0][0], mA);
//			Watch(W, W[0][0]);
//			system("pause");
//		}
//		break;
//		case 0:// Выход
//			return 0; //Завершаем программу
//		}
//	}
//}
//
//int** PereChislenie(int mM)
//{
//	int** M;
//	M = new int* [mM];
//	for (int i = 1; i <= mM; i++)
//		M[i] = new int[3];
//	if (mM < 1)
//	{
//		cout << "Пустой график!" << endl;
//		return M;
//	}
//	cout << "Введите пары графика:\n";
//	for (int i = 1; i <= mM; i++)
//	{
//		cout << "Пара №" << i << endl;
//		for (int j = 1; j < 3; j++)
//		{
//			cin >> M[i][j]; //Пользователь последовательно вводит пары графика 
//		}
//	}
//	cout << endl;
//	return M;
//}
//void  Watch(int** M, int mM)
//{
//	cout << "{";
//	for (int i = 1; i <= mM; i++)
//	{
//		cout << "<";
//		for (int j = 1; j < 3; j++)
//		{
//			cout << M[i][j];
//			if (j == 1)
//				cout << ", ";
//		}
//		cout << ">";
//		if (i < mM)
//			cout << ", ";
//	}
//	cout << "}" << endl;
//}
//void  KonZap()
//{
//	cout << "Графики заполнены." << endl;
//	system("pause");
//	system("cla");
//}
//void  menu()
//{
//	cout << endl << "Выберите операцию:" << endl;
//	cout << "	1. Пересечение графиков\n	2. Объединение графиков\n	3. Разность A и В\n	4. Симметричная разность A u B\n	5. Инверсия А\n	6. Композиция графиков A и B\n	7. Дополнение графика А до универсума\n	0. Выход\n";
//	cout << "-->";
//}
//int** InOne(int** A, int** B, int mA, int mB)
//{
//	int mC = mA + mB + 1;
//	int i, j;
//	int** C = new int* [mC]; //Создаём пустой график С
//	for (int i = 0; i <= mC; i++)
//		C[i] = new int[3];
//	if (mB == 0 && mA == 0) //  Если числа n и m одновременно равны нулю, то график С -  пустой график. 
//
//	{
//		cout << "Пустой график!  -  ";
//		return C;
//
//	}
//	if (mA == 0)//Если число n равно нулю, тогда добавляем кортежи графика В в график С
//	{
//		for (i = 1; i <= mB; i++)
//		{
//			for (j = 1; j < 3; j++)
//			{
//				C[i][j] = B[i][j];
//			}
//		}
//		C[0][0] = mB;
//		return C;
//
//	}
//	if (mB == 0)//  Если число m равно нулю, тогда добавляем кортежи графика А в график С.  
//
//	{
//		for (i = 1; i <= mA; i++)
//		{
//			for (j = 1; j < 3; j++)
//			{
//				C[i][j] = A[i][j];
//			}
//		}
//		C[0][0] = mA;
//		return C;
//
//	}
//	for (i = 1; i <= mA; i++)//i = 1 (для графика A).
//	{
//		for (j = 1; j < 3; j++)//  j = 1 (для графика B).
//		{
//			C[i][j] = A[i][j];
//		}
//	}
//	for (int b = 1; b <= mB; b++)
//	{
//		for (int a = 1; a <= mA; a++)
//		{
//			if (B[b][1] == A[a][1] && B[b][2] == A[a][2])//Если первая компонента i-й пары графика A равна первой компоненте j-й пары графика B
//														
//
//				break;
//			if (B[b][1] != A[a][1] || B[b][2] != A[a][2]) //  Если первая компонента i-й пары равна первой компоненте одной из пар графика D
//														
//
//			{
//				if (a == (mA))
//				{
//					C[i][1] = B[b][1];
//					C[i][2] = B[b][2];
//					i++;
//				}
//				else continue;
//			}
//		}
//
//	}
//	C[0][0] = i - 1;
//	return C;
//}
//int** Peresek(int** A, int** B, int mA, int mB)
//{
//	int mD = mA + mB + 1;
//	int** D = new int* [mD];//Создаём пустой график D
//	for (int i = 0; i <= mD; i++)
//		D[i] = new int[3];
//	int i = 0;
//	if (mA == 0 || mB == 0)//  Если число n = 0 (m = 0) , тогда график D -  пустой график.
//
//	{
//		cout << "Пустой график!  -  ";
//		return D;
//	}
//	for (int b = 1; b <= mB; b++) //i = 1 (для графика A).
//
//	{
//		for (int a = 1; a <= mA; a++) //j = 1 (для графика B).
//		{
//			if (B[b][1] == A[a][1] && B[b][2] == A[a][2])
//
//			{
//				i++;//  Увеличиваем на единицу число i.
//				D[i][1] = B[b][1];  // 1.1  Добавляем i-ю пару графика A в график D.
//				D[i][2] = B[b][2];
//			}
//		}
//	}
//	if (i == 0)
//		cout << "Пустой график!  -  ";
//	D[0][0] = i;
//	return D;//Выводим на экран график D.
//}
//int** Pa3HocTb(int** U, int** W, int mU, int mW)
//{
//	int mR = mU + 1;
//	int** R = new int* [mR]; // Создаём пустой график R.
//	for (int i = 0; i <= mR; i++)
//		R[i] = new int[3];
//	int r = 0;
//	if (mU == 0) // 1.1  Если число n равно нулю, тогда график R - пустой график. 
//	{
//		cout << "Пустой график!  -  ";
//		return R;
//	}
//	if (mW == 0)   // 1.1  Если число m равно нулю, тогда добавляем кортежи графика А в график R. 
//	{
//		for (int i = 1; i <= mU; i++)
//		{
//			R[i][1] = U[i][1];
//			R[i][2] = U[i][2];
//		}
//		R[0][0] = mU;
//		return R;
//	}
//
//	for (int i = 1; i <= mU; i++)//   i = 1 (для графика A).
//
//	{
//		for (int j = 1; j <= mW; j++)  //   j = 1 (для графика B).
//
//		{
//			if (U[i][1] == W[j][1] && U[i][2] == W[j][2]) // Если первая компонента i-й пары графика A равна первой компоненте j-й пары графика B
//														 
//				break;
//			if (j == (mW)) // 1.1  Если j < m, переходим к пункту 18.6.
//			{
//				r++;
//				R[r][1] = U[i][1];
//				R[r][2] = U[i][2];
//			}
//		}
//	}
//	if (r == 0)
//		cout << "Пустой график!  -  ";
//	R[0][0] = r;
//	return R;
//}
//int** SimRas(int** A, int** B, int mA, int mB)
//{
//	int mS = mA * mB + 2;
//	int** S = new int* [mS];   // Создаём пустой график S.
//	for (int i = 0; i <= mS; i++)
//		S[i] = new int[3];
//	int s = 0, o = 0;
//	if (mA == 0 && mB == 0) 
//
//	{
//		cout << "Пустой график!";
//		return  S;
//	}
//	if (mA == 0)// Если число n = 0 , добавляем элементы множества А во множество S.
//	{
//		for (int i = 1; i <= mB; i++)
//		{
//			S[i][1] = B[i][1];
//			S[i][2] = B[i][2];
//
//		}
//		S[0][0] = mB;
//		return S;
//	}
//	if (mB == 0)// Если число m = 0 , добавляем элементы множества B во множество S.
//	{
//		for (int i = 1; i <= mA; i++)
//		{
//			S[i][1] = A[i][1];
//			S[i][2] = A[i][2];
//
//		}
//		S[0][0] = mA;
//		return S;
//	}
//	for (int i = 1; i <= mA; i++)//  i = 1 (для графика A).
//	{
//		for (int j = 1; j <= mB; j++)//  j = 1 (для графика B).
//
//		{
//			o = 0;
//			if (A[i][1] == B[j][1] && A[i][2] == B[j][2])// 1.1  Если первая компонента i-й пары графика A равна первой компоненте j-й пары графика B 
//														
//
//				continue;
//			for (int l = 1; l <= s; l++)
//			{
//				if (S[l][1] == A[i][1] && S[l][2] == A[i][2])// Если первая компонента i-й пары равна первой компоненте одной из пар графика S
//															
//
//
//				{
//					o = 1;
//					break;
//				}
//			}
//			for (int v = 1; v <= mB; v++)
//			{
//				if (A[i][1] == B[v][1] && A[i][2] == B[v][2])//  Если первая компонента i-й пары равна первой компоненте одной из пар графика В 
//															
//
//
//				{
//					o = 1;
//					break;
//				}
//			}
//			if (o == 1)
//				continue;
//			s++;
//			S[s][1] = A[i][1];//  Добавляем i-ю пару в график S.
//			S[s][2] = A[i][2];
//		}
//	}
//	for (int i = 1; i <= mB; i++)
//	{
//		for (int j = 1; j <= mA; j++)
//		{
//			o = 0;
//			if (B[i][1] == A[j][1] && B[i][2] == A[j][2])
//				continue;
//			for (int l = 1; l <= s; l++)
//			{
//				if (S[l][1] == B[i][1] && S[l][2] == B[i][2])//Если первая компонента j-й пары равна первой компоненте одной из пар графика S 
//															
//
//
//				{
//					o = 1;
//					break;
//				}
//			}
//			for (int v = 1; v <= mA; v++)
//			{
//				if (B[i][1] == A[v][1] && B[i][2] == A[v][2])//  Если первая компонента j-й пары равна первой компоненте одной из пар графика A 
//															
//
//				{
//					o = 1;
//					break;
//				}
//			}
//			if (o == 1)
//				continue;
//			s++;
//			S[s][1] = B[i][1];// Добавляем j-ю пару в график S.
//			S[s][2] = B[i][2];
//		}
//	}
//	if (s == 0)
//		cout << "Пустой график!  -  ";
//	S[0][0] = s;
//	return S;//  График S – симметрическая разность графиков A и B.
//}
//int** Inversion(int** M, int mM)
//{
//	int** I = new int* [mM];//Создаём пустой график I.
//	int i = 0;
//	for (int l = 0; l <= mM; l++)
//		I[l] = new int[3];
//	if (mM == 0)// Если число n равно нулю, тогда график I – пустой график. 
//
//	{
//		cout << "Пустой график!  -  ";
//		return I;//Переходим к пункту 21.10
//	}
//	for (i = 1; i <= mM; i++)
//	{
//		I[i][1] = M[i][2];// Добавляем вторую компоненту i-й пары графика А на место первой компоненты пары а.
//		I[i][2] = M[i][1];//Добавляем первую компоненту i-й пары графика A на место второй компоненты пары а.
//
//	}
//	I[0][0] = mM;
//	return I;//График I — инверсия графика A.
//
//}
//int** Exposition(int** A, int** B, int mA, int mB)
//{
//	int a = 0;
//	int b = 1;
//	int mO = mA * mB + 1;
//	int** K = new int* [mO]; //  Создаём пустой график К.
//	int k = 0;
//	for (int p = 0; p <= mO; p++)
//		K[p] = new int[3];
//	if (mA == 0 || mB == 0)//  Если число n или m равно 0, тогда график К - пустой график. 
//
//	{
//		cout << "Пустой график!  -  ";
//		return K;
//	}
//	for (int i = 1; i <= mA; i++)//  i = 1 (для графика A).
//	{
//		for (int j = 1; j <= mB; j++)// j = 1 (для графика B).
//
//		{
//			int o = 0;
//			if (A[i][2] != B[j][1])
//
//				continue;
//			for (int l = 1; l <= k; l++)
//				if (A[i][1] == K[l][1] && B[j][2] == K[l][2])
//				{
//					o = 1;
//					break;
//				}
//			if (o == 1)
//				continue;
//			k++;
//			K[k][1] = A[i][1];// Добавляем первую компоненту i-й пары графика A на место первой компоненты пары a.
//
//			K[k][2] = B[j][2];//  Добавляем вторую компоненту j-й пары графика B на место второй компоненты пары a.
//
//			o = 0;
//		}
//	}
//	if (k == 0)
//		cout << "Пустой график!  -  ";
//	K[0][0] = k;//Добавляем пару a в график K.
//	if (a == b) 
//	{
//		cout << "a deleted";//проверка на наличие одинаковых кортежей
//	}
//	return K;
//}
//
//
//
//


#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

struct Node
{
	Node* left = NULL;
	Node* right = NULL;
	string info;
	int key;
};

void Task(Node*, vector<int>&, int = 0);
void Add(Node*&, int, string);
void DeleteNode(Node*&);
void DeleteTree(Node*&);
void ShowTree(Node*, int = 0);
void Traversal_1(Node*);
void Traversal_2(Node*);
void GetNodes(Node*, vector<Node*>&);
void BubbleSort(vector<Node*>&);
Node* Balance(Node*&, vector<Node*>&, int = -1, int = 0);
Node*& GetNodeByKey(Node*&, int);
Node*& GetMaxNode(Node*&, Node*** = NULL);
int main()
{
	system("chcp 1251>nul");
	Node* root = NULL;
	bool fact = true;
	while (fact == true)
	{
		int key;
		string name;
		Node* keyNode;
		vector<Node*> nodes;
		cout << "Если хотите создать дерево, то нажмите 1" << endl;
		cout << "Если хотите выполнить задание, то нажмите 2" << endl;
		cout << "Если хотите добавить значение в дерево, то нажмите 3" << endl;
		cout << "Если хотите удалить информацию из дерева, то нажмите 4" << endl;
		cout << "Если хотите просмотреть информацию из дерева, то нажмите 5" << endl;
		cout << "Если хотите осуществить поиск в дереве по заданному ключу, то нажмите 6" << endl;
		cout << "Если хотите сбалансировать дерево, то нажмите 7" << endl;
		cout << "Если хотите распечатать, то нажмите 8" << endl;
		cout << "Если хотите завершить программу, то нажмите 9" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			DeleteTree(root);
			int size, key = -1, nameRange = 8, keyRange;
			cout << "Введите размер: " << endl;
			cin >> size;
			keyRange = size;
			cout << "\n";
			for (int i = 0; i < size; i++)
			{
				cout << "Введите ключ " << i + 1 << " добавляемого элемента: " << endl;
				cin >> key;
				cout << "Введите информацию " << i + 1 << " добавляемого элемента: " << endl;
				string name = "";
				cin >> name;
				cout << name << ": " << key << "\n";
				Add(root, key, name);
			}
			break;
		}
		case 2:
		{
			vector<int> nodeCount;
			Task(root, nodeCount);
			for (int i = 0; i < (int)nodeCount.size(); i++)
			{
				cout << "Уровень " << i + 1 << ": " << nodeCount[i] << "\n";
			}
			break;
		}
		case 3:
			cout << "Введите ключ: " << endl;
			cin >> key;
			while (GetNodeByKey(root, key))
			{
				cout << "Введите другой ключ: " << endl;
				cin >> key;
			}
			cout << "Введите имя: ";
			cin >> name;
			Add(root, key, name);
			break;
		case 4:
			cout << "Введите ключ: " << endl;
			cin >> key;
			DeleteNode(GetNodeByKey(root, key));
			break;
		case 5:
			ShowTree(root);
			break;
		case 6:
			cout << "Введите ключ: " << endl;
			cin >> key;
			keyNode = GetNodeByKey(root, key);
			if (keyNode)
			{
				cout << "Имя: " << keyNode->info << "\n";
			}
			else
			{
				cout << "Элемент не найден\n";
			}
			break;
		case 7:
			GetNodes(root, nodes);
			BubbleSort(nodes);
			Balance(root, nodes);
			break;
		case 8:
			cout << "Если хотите распечатать прямым обходом, то нажмите 1" << endl;
			cout << "Если хотите распечатать обратным обходом, то нажмите 2" << endl;
			cout << "Если хотите распечатать в порядке возрастания ключа, то нажмите 3" << endl;
			int choise;
			cin >> choise;
			switch (choise)
			{
			case 1:
				Traversal_1(root);
				break;
			case 2:
				Traversal_2(root);
				break;
			case 3:
				GetNodes(root, nodes);
				BubbleSort(nodes);
				for (int i = 0; i < nodes.size(); ++i)
				{
					cout << nodes[i]->info << " ";
				}
				break;
			}
			cout << "\n";
			break;
		case 9:
			fact = false;
		}
		cout << "\n";
	}
}

void Task(Node* p, vector<int>& nodeCount, int level)
{
	if (!p)
	{
		return;
	}
	if (nodeCount.size() <= level)
	{
		nodeCount.push_back(1);
	}
	else
	{
		nodeCount[level]++;
	}
	Task(p->left, nodeCount, level + 1);
	Task(p->right, nodeCount, level + 1);
}

void Add(Node*& root, int key, string info)
{
	Node** p = &root;
	while (*p)
	{
		if (key < (*p)->key)
		{
			p = &(*p)->left;
		}
		else if (key > (*p)->key)
		{
			p = &(*p)->right;
		}
	}
	Node* newNode = new Node;
	newNode->key = key;
	newNode->info = info;
	*p = newNode;
}


void DeleteNode(Node*& target)
{
	if (!target) return;
	Node* tempPtr = NULL;
	if ((target->left && !target->right) || (!target->left && target->right))
	{
		if (target->left)
		{
			tempPtr = target->left;
		}
		else
		{
			tempPtr = target->right;
		}

	}
	else if (target->left && target->right)
	{
		Node** prevPtr = NULL;
		tempPtr = GetMaxNode(target->left, &prevPtr);
		if (!prevPtr)
		{
			tempPtr->right = target->right;
		}
		else
		{
			if (tempPtr->left)
			{
				(*prevPtr)->right = tempPtr->left;
			}
			else (*prevPtr)->right = NULL;
			tempPtr->right = target->right;
			tempPtr->left = target->left;
		}
	}
	else
	{
		target = NULL;
	}
	delete target;
	target = tempPtr;
}

void DeleteTree(Node*& root)
{
	while (root) DeleteNode(root);
}

void ShowTree(Node* p, int level)
{
	string str;
	if (!p)
	{
		return;
	}
	ShowTree(p->right, level + 1);
	for (int i = 0; i < level; i++) str = str + "   ";
	cout << str << p->info << "\n";
	ShowTree(p->left, level + 1);
}

void Traversal_1(Node* p)
{
	if (!p) return;
	cout << p->info << " ";
	Traversal_1(p->left);
	Traversal_1(p->right);
}

void Traversal_2(Node* p)
{
	if (!p) return;
	Traversal_2(p->left);
	Traversal_2(p->right);
	cout << p->info << " ";
}

void GetNodes(Node* p, vector<Node*>& nodes)
{
	if (!p)
	{
		return;
	}
	nodes.push_back(p);
	GetNodes(p->left, nodes);
	GetNodes(p->right, nodes);
}

void BubbleSort(vector<Node*>& nodes)
{
	int n = nodes.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nodes[i]->key > nodes[j]->key)
			{
				Node* temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
}

Node* Balance(Node*& root, vector<Node*>& nodes, int k, int n)
{
	if (k == -1)
	{
		k = nodes.size();
		root = nodes[k / 2];
	}
	if (n == k)
	{
		return NULL;
	}
	int m = (n + k) / 2;
	nodes[m]->left = Balance(root, nodes, m, n);
	nodes[m]->right = Balance(root, nodes, k, m + 1);
	return nodes[m];
}

Node*& GetNodeByKey(Node*& root, int key)
{
	Node** p = &root;
	while (*p)
	{
		if ((*p)->key > key) p = &(*p)->left;
		else if ((*p)->key < key) p = &(*p)->right;
		else return *p;
	}
	return *p;
}

Node*& GetMaxNode(Node*& root, Node*** prev)
{
	Node** p = &root;
	while ((*p)->right)
	{
		if (prev) *prev = p;
		p = &(*p)->right;
	}
	return *p;
}