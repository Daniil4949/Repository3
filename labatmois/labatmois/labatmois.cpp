// labatmois.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <clocale>

using namespace std;

int* Perechislenie(int mM);
int* Talk_A(int mM);            
int* Talk_B(int mM);
void neto();
void mn(int* A, int mA, int* B, int mB);
int* edin(int* A, int* B, int mA, int mB);
int* peresechenie(int* A, int* B, int mA, int mB);
int* Pa3HocTb(int* U, int* W, int mU, int mW);
int* Add(int* M, int mM);
int* SimmRaz(int* A, int* B, int mA, int mB);
int* Dekart(int* A, int* B, int mA, int mB);

int main() {
	setlocale(LC_ALL, "rus");
	int* A, * B;
	int mA, mB, mC, mD, mR, mY, mE, mP, mS;
	int i, Operaziya = 0, ZMA = 0, ZMB = 0;
	//Элементы мн-ва натуральные числа от -999 до 999
	//cout << "Введите мощность множества А (от 0 до 50):  ";
	//cin >> mA;      //задается мощность  множества A
	//A = new int[mA];
	//cout << endl;
	//cout << "Введите мощность множества B (от 0 до 50):  ";
	//cin >> mB;  //задается мощность множества В
	//B = new int[mB];
	cout << "Выберите способ задания множества А:  " << endl;
	cout << "   1. Перечисление.\n   2. Высказывание.\n";
	cin >> ZMA; //Пользователь выбирает способоб задания множества А
	switch (ZMA) {
	case 1:
		cout << "Введите мощность множества А (от 0 до 50):  ";
		cin >> mA;      //задается мощность  множества A
		A = new int[mA];
		cout << endl;
		A = Perechislenie(mA);//перечисление
		break;
	case 2:
		cout << "Введите мощность множества А (от 0 до 50):  ";
		cin >> mA;      //задается мощность  множества A
		A = new int[mA];
		cout << endl;
		A = Talk_A(mA);//высказывание
		break;
	default:
		neto();
		return 0;
	}
	cout << endl << endl;
	cout << "Выберите способ задания множества B:  " << endl;//пользователь выбирает способ задания множества В
	cout << "   1. Перечисление.\n   2. Высказывание.\n";
	cin >> ZMB;
	switch (ZMB) {
	case 1:
		cout << "Введите мощность множества B (от 0 до 50):  ";
		cin >> mB;  //задается мощность множества В
		B = new int[mB];
		B = Perechislenie(mB);//перечисление
		break;
	case 2:
		cout << "Введите мощность множества B (от 0 до 50):  ";
		cin >> mB;  //задается мощность множества В
		B = new int[mB];
		B = Talk_B(mB);//высказывание
		break;
	default:
		neto();
		return 0;
	}
	/*cout << "Введите мощность множества А (от 0 до 50):  ";
	cin >> mA;      //задается мощность  множества A
	A = new int[mA];
	cout << endl;
	cout << "Введите мощность множества B (от 0 до 50):  ";
	cin >> mB;  //задается мощность множества В
	B = new int[mB];*/
	while (true) {
		system("pause");
		system("cls");
		mn(A, mA, B, mB);
		cout << "Выберите операцию:" << endl;
		cout << "   1. Пересечение множеств\n   2. Объединение множеств\n   3. "//Пользователем производится выбор операции
			"Разность A и В\n    4. Симметрическая разность А и В\n   "
			"   5. Дополнение А до U\n   6. "
			"Декартово произведение A на B\n    "
			;
		cin >> Operaziya;
		system("cls");
		switch (Operaziya) {
		case 2: {
			cout << "Объединение множеств" << endl;
			int* C = new int[mA + mB];//объединение множеств
			C = edin(A, B, mA, mB);
			mC = C[0];
			for (int i = 1; i <= mC; i++) cout << C[i] << " ";
			cout << endl;
		} break;
		case 1: {
			cout << "Пересечение множеств" << endl;
			int* D = new int[mA + mB];//перечисление множеств
			D = peresechenie(A, B, mA, mB);
			mD = D[0];
			for (int i = 1; i <= mD; i++) cout << D[i] << " ";
			cout << endl;
		} break;
		case 3: {
			cout << "Разность A и В" << endl;
			int* R = new int[mA];//разность множеств А и В
			R = Pa3HocTb(A, B, mA, mB);
			mR = R[0];
			for (int i = 1; i <= mR; i++) cout << R[i] << " ";
			cout << endl;
		} break;
		
		case 5: {
			cout << "Дополнение А до U" << endl;//дополнение множества А
			int* E = new int[1001];
			E = Add(A, mA);
			mE = E[0];
			for (int i = 1; i <= mE; i++) cout << E[i] << " ";
			cout << endl;
		} break;
		case 4: {
			cout << "Симметричная разность А и В" << endl;
			int* S = new int[mA + mB + 2];//симметрическая разность 
			S = SimmRaz(A, B, mA, mB);
			mS = S[0];
			for (int i = 1; i <= mS; i++) cout << S[i] << " ";
			cout << endl;
		} break;
		case 6: {
			cout << "Декартово произведение A на B" << endl;//декартово произведение А на В
			int* P = new int[2 * (mA * mB) + 2];
			P = Dekart(A, B, mA, mB);
			mP = P[0];
			for (int i = 1; i <= mP; i++) {
				cout << "<" << P[i] << ", " << P[i + 1] << ">";
				if (i < mP - 1) cout << ", ";
				i++;
			}
			cout << endl;
		} break;
		
		case 0:
			return 0;
		}
	}
}

int* Perechislenie(int mM) {
	int* M = new int[mM];
	if (mM == 0) {
		cout << endl << "Пустое множество!" << endl;
		return M;
	}
	cout << endl << "Введите элементы множества:  " << endl;//Пользователь вводит элементы множества
	for (int i = 0; i < mM; i++) cin >> M[i];
	return M;
}
int* Talk_A(int n) {
	int* A = new int[n];
	int a = 0;
	cout << endl << "Элементы множества А:  ";
	if (n == 0) {
		cout << endl << endl << "Пустое множество!";
		return A;
	}
	for (int x = 0; x < n; x++) {
		a = 2 * x + 1;//Множество А задается перечислением
		A[x] = a;
		cout << endl << a << " ";
	}
	return A;
}

int* Talk_B(int m) {
	int* B = new int[m];
	int b = 0;
	cout << endl << "Элементы множества B:  ";
	if (m == 0) {
		cout << endl << endl << "Пустое множество!";
		return B;
	}
	for (int y = 0; y < m; y++) {
		b = 5*y -4;
		B[y] = b;
		cout << endl << b << " ";
	}
	return B;
}

void neto() {
	cout << endl
		<< endl
		<< endl
		<< "........Error............"
		<< endl
		<< endl
		<< endl;
	system("pause");
}
void mn(int* A, int mA, int* B, int mB) {
	cout << "A =  ";
	cout << "{";
	for (int i = 0; i < mA; i++) {
		cout << A[i];
		if (i < (mA - 1)) cout << ", ";
	}
	cout << "}" << endl;

	cout << "B =  ";
	cout << "{";
	for (int i = 0; i < mB; i++) {
		cout << B[i];
		if (i < (mB - 1)) cout << ", ";
	}
	cout << "}" << endl;
}
int* edin(int* A, int* B, int mA, int mB) {
	int mO = mA + mB + 1, i = 0;
	int* C = new int[mO];
	if (mB == 0 && mA == 0) {
		cout << "Пустое множество!";
		return C;
	}
	if (mA == 0) {
		for (i = 0; i < mB; i++) {
			C[i + 1] = B[i];
		}
		C[0] = i;//операция объединения множеств
		return C;
	}
	if (mB == 0) {
		for (i = 0; i < mA; i++) {
			C[i + 1] = A[i];
		}
		C[0] = i;
		return C;
	}
	for (i = 0; i < mA; i++) {
		C[i + 1] = A[i];
	}
	for (int b = 0; b < mB; b++) {
		for (int a = 0; a < mA; a++) {
			if (B[b] == A[a]) break;
			if (B[b] != A[a]) {
				if (a == (mA - 1)) {
					i++;
					C[i] = B[b];
				}
				else
					continue;
			}
		}
	}
	C[0] = i;
	return C;
}
int* peresechenie(int* A, int* B, int mA, int mB) {
	int* D = new int[mB + mA];
	int i = 0;
	if (mA == 0 || mB == 0) {
		cout << "Пустое множество!";
		return D;
	}
	for (int b = 0; b < mB; b++) {
		for (int a = 0; a < mA; a++) {
			if (B[b] == A[a]) {
				i++;                    //операция пересечения множеств
				D[i] = B[b];
			}
		}
	}
	if (i == 0) cout << endl << "Пустое множество!" << endl;
	D[0] = i;
	return D;
}
int* Pa3HocTb(int* U, int* W, int mU, int mW) {
	int* R = new int[mU + 1];
	int r = 0;
	if (mU == 0) {
		cout << "Пустое множество!";
		return R;
	}
	if (mW == 0) {
		for (int i = 0; i < mU; i++) {           //операция разнрсти множеств А и В
			R[i + 1] = U[i];
		}
		R[0] = mU;
		return R;
	}
	for (int i = 0; i < mU; i++) {
		for (int j = 0; j < mW; j++) {
			if (U[i] == W[j]) break;
			if (j == (mW - 1)) {
				r++;
				R[r] = U[i];
			}
		}
	}
	if (r == 0) cout << "Пустое множество!";
	R[0] = r;
	return R;
}
int* Add(int* M, int mM) {
	int* U = new int[50];
	for (int u = 1; u <= 50; u++) U[u] = u;
	int* E = new int[51];
	int e = 0;             //операция дополнения множества А 
	if (mM == 0) {
		U[0] = 50;
		return U;
	}
	for (int i = 1; i < 51; i++) {
		for (int j = 0; j < mM; j++) {
			if (U[i] == M[j]) break;
			if (U[i] != M[j]) {
				if (j == (mM - 1)) {
					e++;
					E[e] = U[i];
				}
				else
					continue;
			}
		}
	}
	E[0] = e;
	return E;
}
int* SimmRaz(int* A, int* B, int mA, int mB) {
	int* S = new int[mA + mB + 2];
	int s = 0, o = 0;
	if (mA == 0 && mB == 0) {
		cout << "Пустое множество!";
		return S;
	}
	if (mA == 0) {
		for (int i = 0; i < mB; i++) {
			S[i + 1] = B[i]; //операция симметрической разности
		}
		S[0] = mB;
		return S;
	}
	if (mB == 0) {
		for (int i = 0; i < mA; i++) {
			S[i + 1] = A[i];
		}
		S[0] = mA;
		return S;
	}
	for (int i = 0; i < mA; i++) {
		for (int j = 0; j < mB; j++) {
			o = 0;
			if (A[i] == B[j]) continue;
			for (int l = 1; l <= s; l++) {
				if (S[l] == A[i]) {
					o = 1;
					break;
				}
			}
			for (int v = 0; v < mB; v++) {
				if (A[i] == B[v]) {
					o = 1;
					break;
				}
			}
			if (o == 1) continue;
			s++;
			S[s] = A[i];
		}
	}
	for (int i = 0; i < mA; i++) {
		for (int j = 0; j < mB; j++) {
			o = 0;
			for (int l = 1; l <= s; l++) {
				if (S[l] == B[j]) {
					o = 1;
					break;
				}
			}
			for (int v = 0; v < mA; v++) {
				if (A[v] == B[j]) {
					o = 1;
					break;
				}
			}
			if (o == 1) continue;
			s++;
			S[s] = B[j];
		}
	}
	if (s == 0) cout << "Пустое множество!";
	S[0] = s;
	return S;
}
int* Dekart(int* A, int* B, int mA, int mB) {
	int* P = new int[2 * (mA * mB) + 2];
	int p = 0, o = 0;
	if (mA < 1 || mB < 1) {
		cout << "Пустое множество!"; //операция Декартова произведения
		return P;
	}
	for (int i = 0; i < mA; i++) {
		for (int j = 0; j < mB; j++) {
			o = 0;
			for (int k = 1; k < p; k += 2) {
				if (A[i] == P[k] && B[j] == P[k + 1]) {
					o = 1;
					break;
				}
			}
			if (o == 1) continue;
			p++;
			P[p] = A[i];
			p++;
			P[p] = B[j];
		}
	}
	P[0] = p;
	return P;
}


//using System;
//using System.Collections.Generic;
//
//namespace ForTests
//{
//    class Program
//    {
//        static int[] U;
//
//        static void Main()
//        {
//            int option, addOpt;
//            bool exit = false;
//            /* пункт 1 */ int[] s1 = NewSet("A"), /* пункт 2 */ s2 = NewSet("B");
//            U = Union(s1, s2);
//
//            while (!exit) //3 Пользователь выбирает операцию: пересечение множеств А и В, объединение множеств А и В, разность множеств А и В, симметрическая разность множеств А и В, дополнение множества А, декартово произведение множеств А и В, выход из программы.
//            {
//                Console.Clear();
//                PrintSet(s1, "s1");
//                PrintSet(s2, "s2");
//                Console.WriteLine("1 - New sets\n2 - Intersection\n3 - Union\n4 - Difference\n5 - Symmetric difference\n6 - Addition\n7 - Cartesian product\n0 - Exit\n");
//                Console.Write("Input option: ");
//                while (!int.TryParse(Console.ReadLine(), out option));
//                switch (option)
//                {
//                case 1:
//                    s1 = NewSet("A");
//                    s2 = NewSet("B");
//                    U = Union(s1, s2);
//                    break;
//                case 2: // 3.1 Если пользователь выбирает пересечение множеств А и В, переходим к пункту 4
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 3: // 3.2 Если пользователь выбирает объединение множеств А и В, переходим к пункту 5
//                    PrintSet(Union(s1, s2), "Union(s1, s2)");
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 4: // 3.3 Если пользователь выбирает разность множеств А и В, переходим к пункту 6
//                    PrintSet(Difference(s1, s2), "Difference(s1, s2)");
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 5: // 3.4 Если пользователь выбирает симметрическую разность множеств А и В, переходим к пункту 7
//                    PrintSet(SymmetricDifference(s1, s2), "Symmetric difference(s1, s2)");
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 6: // 3.5 Если пользователь выбирает дополнение множества, переходим к пункту 8
//                    PrintSet(Addition(s1), "Addition(s1)");
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 7: // 3.6 Если пользователь выбирает декартово произведение множеств А и В, переходим к пункту 9
//                    PrintSetByPairs(CartesianProduct(s1, s2), "Cartesian product(s1, s2)");
//                    Console.Write("Press any key...");
//                    Console.ReadKey(true);
//                    break;
//                case 0: // 3.7 Если пользователь выбирает выход из программы, завершаем работу программы
//                    exit = true;
//                    break;
//                default:
//                    Console.Write("Incorrect option, press any key...");
//                    Console.ReadKey(true);
//                    break;
//                }
//            }
//        }
//
//        static int[] NewSet(string name)
//        {
//            int opt = 0, element = 0;
//            Console.WriteLine("1 - Manual input\n2 - Input by formula\n"); // Пользователь выбирает способ задания множества А(B): перечислением или высказыванием.
//            Console.Write("Input option: ");
//            int[] result = null;
//            while (!int.TryParse(Console.ReadLine(), out opt) && (opt != 1 || opt != 2)); // Получаем выбор способа ввода пользователя 
//            switch (opt)
//            {
//            case 1:	// Если выбран способ задания перечислением, то:
//                Console.Write("Input power of set: "); // Пользователь выбирает мощность множества А(B), строго меньше 10. 
//                int powerOfSet = 0;
//                while (!int.TryParse(Console.ReadLine(), out powerOfSet) && powerOfSet < 10); // Если выбрана мощность больше либо равная 10, необходимо повторить ввод.
//                result = new int[powerOfSet];
//                for (int i = 0; i < powerOfSet; i++)
//                {
//                    while (!int.TryParse(Console.ReadLine(), out element) && element < 300); // Пользователь вводит элементы множества А(B), строго меньше 300. Если введён элемент больше либо равный 300, необходимо повторить ввод данного элемента.
//                    result[i] = element;
//                }
//                break;
//            case 2: // Если выбран способ задания множества высказыванием, то а = 2x^2, где а – элемент, задающийся высказыванием.
//                result = new int[10];
//                if (name == "A")
//                {
//                    for (int i = 1; i <= 10; i++) // х = 1, (1.2.2)Если х равен 10, то переходим к пункту 2. Увеличиваем х на единицу. Переходим к пункту 1.2.2.
//                    {
//                        result[i - 1] = 2 * i * i; // Вычисляем значение элемента а по формуле а = 2x^2 и заносим его во множество А.
//                    }
//                }
//                else if (name == "B") // Если выбран способ задания множества высказыванием, то b = 5x-4, где b – элемент, задающийся высказыванием. // Переходим к пункту 2.2.2
//                {
//                    for (int i = 1; i <= 10; i++) // х = 1, Если х равен 10, то переходим к пункту 3. Увеличиваем х на единицу.
//                    {
//                        result[i - 1] = 5 * i + 3; // Вычисляем значение элемента b по формуле b = 5x-4 и заносим его во множество А.
//                    }
//                }
//                break;
//            }
//            return result;
//        }
//
//        static int[] Intersection(int[] s1, int[] s2) // 4. Найдём пересечение множеств А и В:
//        {
//            List<int> list = new List<int>(); // 4.1 Создаём пустое множество С.
//
//            for (int i = 0; i < s1.Length; i++) // 4.2 i = 0. // 4.7 Увеличиваем i на единицу. // 4.8 Если значение i меньше или равно мощности множества А, то переходим к пункту 4.3
//            {
//                for (int j = 0; j < s2.Length; j++) // 4.3 j = 0. // 4.5 Увеличиваем j на единицу. // 4.6 Если значение j меньше или равно мощности множества B, то переходим к пункту 4.4
//                {
//                    if (s1[i] == s2[j]) list.Add(s1[i]); // 4.4 Если i-й элемент из множества А равен j-му элементу из множества В, то заносим его во множество С.
//                }
//            }
//            int[] result = list.ToArray(); // - Множество С – пересечение множеств А и В, выводим его на экран.
//            return result;
//        }
//
//        static int[] Union(int[] s1, int[] s2) // 5. Найдём объединение множеств А и В:
//        {
//            int[] i12 = Intersection(s1, s2); //Множество D – пересечение множеств А и В.
//            List<int> list = new List<int>(s1); // 5.2 Создаём множество E, равное множеству А.
//
//            if (i12.Length == 0)
//                for (int i = 0; i < s2.Length; i++)
//                    list.Add(s2[i]);
//
//            for (int i = 0; i < s2.Length; i++) // 5.3 i = 1. // 5.4 j = 1. // 5.5.4 Если i равно мощности множества В, переходим к пункту 5.9, иначе увеличиваем i на единицу, переходим к пункту 5.4.
//            {
//                for (int j = 0; j < i12.Length; j++) // 5.5.3 увеличиваем j на единицу и переходим к пункту 5.5.1.
//                {
//                    if (s2[i] == i12[j]) break; // 5.5.1 Если i-й элемент множества В равен j-у элементу D, то переходим к пункту 5.5.4
//                    if (j == i12.Length - 1) list.Add(s2[i]); // 5.5.2 Если j равно мощности множества D, то заносим i-й элемент множества В во множество E и переходим к пункту 5.5.4
//                }
//            }
//
//            int[] result = list.ToArray(); // - Множество E – объединение множеств А и В, выводим его на экран.
//            return result; // 5.9 Переходим к пункту 3.
//        }
//
//        static int[] Difference(int[] s1, int[] s2) // 6. Найдём разность множеств А и В:
//        {
//            int[] i12 = Intersection(s1, s2); // 6.1 Создаём множество F, равное результату операции пересечения множеств А и В:
//            List<int> list = new List<int>(); // 6.2 Создаём пустое множество G.
//
//            if (i12.Length == 0)
//                for (int i = 0; i < s1.Length; i++)
//                    list.Add(s1[i]);
//
//
//            for (int i = 0; i < s1.Length; i++)  // 6.4 j = 1 // 6.5.4 Если i равно мощности множества В, переходим к пункту 6.6, иначе увеличиваем i на единицу, переходим к пункту 6.4.
//                for (int j = 0; j < i12.Length; j++) // 6.3 i = 1. // 6.5.3 увеличиваем j на единицу, переходим к пункту 6.5.1.
//                {
//                    if (s1[i] == i12[j]) // 6.5.1 Если i-й элемент множества В равен j-у элементу множества F, то переходим к пункту 6.5.4
//                        break;
//                    if (j == i12.Length - 1) // 6.5.2 Если j равно мощности множества F, то заносим i-й элемент множества А во множество G и переходим к пункту 6.5.4
//                        list.Add(s1[i]);
//                }
//
//            int[] result = list.ToArray(); // - Множество G – разность множеств А и В, выводим его на экран.
//            return result; // 6.6. Переходим к пункту 3.
//        }
//
//        static int[] Addition(int[] s1) // Найдём дополнение множества А:
//        {
//            return Difference(U, s1); // 8.1 Создаём множество W равное результату операции разности универсального множества U, определённого выше, и множества А:
//        }
//
//        static int[] SymmetricDifference(int[] s1, int[] s2) // Найдём симметрическую разность множеств А и В:
//        {
//            return Union(Difference(s1, s2), Difference(s2, s1)); //Создаём множество L равное результату операции объединения множеств H (H – разность множеств А и В.) и K (K – разность множеств B и A.):
//        }
//
//        static int[] CartesianProduct(int[] s1, int[] s2) // 9. Найдём декартово произведение множеств А и В:
//        {
//            List<int> list = new List<int>(); // 9.1 Создаём пустое множество P.
//
//            for (int i = 0; i < s1.Length; i++) // 9.2 i = 1. // 9.4.5 Увеличиваем i на единицу. // 9.4.6 Если i меньше или равна мощности множества A, переходим к пункту 9.3, иначе далее по алгоритму.
//                for (int j = 0; j < s2.Length; j++) // 9.3 j = 1. // 9.4.3 Увеличиваем j на единицу. // 9.4.4 Если j меньше или равна мощности множества В, переходим к пункту 9.4.1, иначе далее по алгоритму.
//                {
//                    list.Add(s1[i]); // 9.4.1 Записываем i-й элемент множества А на первую позицию кортежа.
//                    list.Add(s2[j]); // 9.4.2 Записываем j-й элемент множества B на вторую позицию кортежа. // Заносим полученный кортеж во множество P.
//                }
//
//            int[] result = list.ToArray(); // - Множество P – декартово произведение множеств А и В, выводим его на экран
//            return result; // 9.5 Переходим к пункту 3.
//        }
//
//        static void PrintSet(int[] set, string name) // вывод множества на экран
//        {
//            Console.Write(name + " = ");
//            if (set != null && set.Length > 0)
//            {
//                Console.Write("{ ");
//                Console.Write(set[0]);
//                for (int i = 1; i < set.Length; i++)
//                {
//                    Console.Write(", " + set[i]);
//                }
//                Console.WriteLine(" }");
//            }
//            else Console.WriteLine("{ }");
//        }
//
//        static void PrintSetByPairs(int[] set, string name) // вывод множества кортежей длины 2 на экран
//        {
//            if (set.Length % 2 != 0)
//            {
//                PrintSet(set, name);
//                return;
//            }
//
//            Console.Write(name + " = ");
//            if (set != null && set.Length > 0)
//            {
//                Console.Write("{ ");
//                for (int i = 0; i < set.Length; i++)
//                {
//                    if (i % 2 == 0)
//                        Console.Write("<");
//
//                    Console.Write(set[i]);
//
//                    if (i % 2 == 0 && i != set.Length)
//                        Console.Write(", ");
//                    if (i % 2 != 0 && i != set.Length - 1)
//                        Console.Write(">, ");
//                    if (i % 2 != 0 && i == set.Length - 1)
//                        Console.Write(">");
//                }
//                Console.WriteLine(" }");
//            }
//            else Console.WriteLine("{ }");
//        }
//    }
//}
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int a[1000], b[1000], c[3000],p[200], n = 0, m, x, f = 0, h = 1, r = 1;
//    system("chcp 1251");
//    cout << "Введите количество элементов множества А" << "\n";//Пользователем задается мощность  множества А.
//    cin >> n;
//    x = n + 1;
//    cout << "Введите количество элементов множества B" << "\n";//Пользователем задается мощность множества В.
//    cin >> m;
//    cout << "Введите множество А" << "\n"; //Пользователь задает элементы множества А.
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    cout << "Введите множество B" << "\n";//Пользователь заадет элементы множества В.
//    for (int j = 1; j <= m; j++) {
//        cin >> b[j];
//    }
//    cout << "Введите значение переменной условия f" << "\n";
//    cout << "При f равном 0 будет выбрана операция объединения, при f равном 1 - пересечения." << "\n";//Пользователь выбирает либо операцию объединения,
//    cout << " При f равном 2-операция разности, при f равном 3-операция дополнения,при f равном 4-симметрическая разность " << endl;                                                                                                  //либо операцию пересечения.
//    cin >> f;
//    if (f == 0) {
//        for (int i = 1; i <= n; i++) {
//            c[i] = a[i];
//        }                                          //Создание множества С, результат которого-объединение множеств А и В.
//        for (int j = 1; j <= m; j++) {
//            for (int i = 1; i <= n; i++) {
//                if (a[i] == b[j]) {
//                    break;
//                }
//                if ((i == n) && a[i] != b[j]) {
//                    c[x] = b[j];
//                    x++;
//                }
//            }
//        }
//        cout << "Объединение множеств:" << "\n";//На экран выводится результат операции объединения.
//        for (int i = 1; i < x; i++) {
//            cout << c[i] << " ";
//        }
//    }
//    if (f == 1) {
//        for (int j = 1; j <= m; j++) {
//            for (int i = 1; i <= n; i++) {     //Создание множества С, результат которого-перечение
//                                               //множеств А и В.
//                if (a[i] == b[j]) {
//                    c[h] = b[j];
//                    h++;
//                }
//            }
//        }
//        cout << "Пересечение множеств" << "\n";//На экран выводится результат операции пересечения.
//        for (int i = 1; i < h; i++) {
//            cout << c[i] << " ";
//        }
//    }
//   
//    system("pause>nul");
//
//    return 0;
//
//
//
//}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
