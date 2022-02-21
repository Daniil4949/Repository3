#include <iostream>
#include<fstream>
#include<string>
#include<cmath> 
#include<iomanip>
#include<vector>
using namespace std;
vector<int> result;
struct student {
	string surname;
	string name;
	string date_of_birth;
	string group;
	string phys;
	string math;
	string inf;
	string chem;
};
void read() {
	ifstream file;
	int num;
	vector<int> temp;
	file.open("read_it.txt");
	if (file.is_open()) {
		file >> num;
		file.ignore();
		temp.push_back(num);

	}
	cout << num;
	cout << endl;
	string s;
	int i = 0;
	while (i < num) {
		getline(file, s);
		cout << s << endl;
		file.ignore();
		++i;
	}
}
void create() {
	student arr[50];
	int n;
	cout << "Введите количество студентов:" << endl;
	cin >> n;
	ofstream file;
	file.open("read_it.txt");
	file << n << "\n";
	string s = "";
	for (int i = 0; i < n; ++i) {
		cout << "Введите фамилию студента:" << endl;
		cin >> arr[i].surname;
		s += arr[i].surname;
		s += " ";
		cout << "Введите инициалы студента:" << endl;
		cin >> arr[i].name;

		s += arr[i].name;
		s += " ";
		cout << "Введите группу студента:" << endl;
		cin >> arr[i].group;

		s += arr[i].group;
		s += " ";
		cout << "Введите дату рождения студента:" << endl;
		cin >> arr[i].date_of_birth;

		s += arr[i].date_of_birth;
		s += " ";
		cout << "Введите оценку по физике студента:" << endl;
		cin >> arr[i].phys;

		s += arr[i].phys;
		s += " ";
		cout << "Введите оценку по математике студента:" << endl;
		cin >> arr[i].math;

		s += arr[i].math;
		s += " ";
		cout << "Введите оценку по информатике студента:" << endl;
		cin >> arr[i].inf;

		s += arr[i].inf;
		s += " ";
		cout << "Введите оценку по химии студента:" << endl;
		cin >> arr[i].chem;

		s += arr[i].chem;
		s += " ";
		double a = (stoi(arr[i].inf) + stoi(arr[i].math) + stoi(arr[i].phys) + stoi(arr[i].chem)) / 4.0;
		if (a >= 9) {
			result.push_back(i);
		}
		string str = to_string(a);
		s += str;
		a = 0;
		file << s;
		file << "\n";
		s = " ";

	}
	file.close();
}
void rez() {
	ifstream file;
	file.open("read_it.txt");
	int n;
	vector<int> temp;
	if (file.is_open()) {
		file >> n;
		temp.push_back(n);
		file.ignore();
	}
	student arr[50];
	string line;
	vector<int> info;
	string s;
	for (int i = 0; i < n; ++i) {
		getline(file, s);
		for (int j = 0; j < s.size(); ++j) {
			//if (s[j] == '4' || s[j] == '5' && (s[j - 1] == ' ' && s[j + 1] == ' ')) {
			//	/*if (
			//		(s[j + 2] == '9' && s[j + 4] == '9' && s[j + 6] == '9') ||
			//		(s[j + 2] == '1' && s[j + 3] == '0' && s[j + 5] == '1' && s[j + 6] && s[j + 8] == '1' && s[j + 9] == '0') ||
			//		(s[j + 2] == '9' && s[j + 4] == '1' && s[j + 5] == '0' && s[j + 7] == '9') ||
			//		(s[j + 2] == '9' && s[j + 4] == '1' && s[j + 5] == '0' && s[j + 7] == '1' && s[j + 8] == '0') ||
			//		(s[j + 2] == '1' && s[j + 3] == '0' && s[j + 5] == '1' && s[j + 6] == '0' && s[j + 8] == '9') ||
			//		(s[j + 2] == '9' && s[j + 4] == '9' && s[j + 6] == '1' && s[j + 7] == '0') ||
			//		(s[j + 2] == '1' && s[j + 3] == '0' && s[j + 5] == '9' && s[j + 7] == '9') ||
			//		(s[j + 2] == '1' && s[j + 3] == '0' && s[j + 5] == '9' && s[j + 7] == '1' && s[j + 8] == '0')) {
			//		info.push_back(i);
			//	}*/
			//}

		}
	}

	file.close();
	file.open("read_it.txt");
	int num;
	vector<int> temp1;
	if (file.is_open()) {
		file >> num;
		file.ignore();
		temp1.push_back(num);

	}
	cout << endl;
	string z = "";
	ofstream file2;
	file2.open("out.txt");
	file2.clear();
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < info.size(); ++j) {
			if (i == result[i]) {
				getline(file, z);
				file2 << z;
				file2 << "\n";
				file.ignore();
				z = " ";
			}
		}
	}
	file2.close();
}
void redact() {
	student arr[50];
	int n;
	cout << "Введите количество студентов:" << endl;
	cin >> n;
	ofstream file;
	file.open("read_it.txt");
	file.clear();
	file << n << "\n";
	string s = "";
	for (int i = 0; i < n; ++i) {
		cout << "Введите фамилию " << i + 1 << " студента:" << endl;
		cin >> arr[i].surname;
		s += arr[i].surname;
		s += " ";
		cout << "Введите инициалы " << i + 1 << " студента:" << endl;
		cin >> arr[i].name;

		s += arr[i].name;
		s += " ";
		cout << "Введите группу " << i + 1 << " студента:" << endl;
		cin >> arr[i].group;

		s += arr[i].group;
		s += " ";
		cout << "Введите дату рождения " << i + 1 << " студента:" << endl;
		cin >> arr[i].date_of_birth;

		s += arr[i].date_of_birth;
		s += " ";
		cout << "Введите оценку по физике " << i + 1 << " студента:" << endl;
		cin >> arr[i].phys;

		s += arr[i].phys;
		s += " ";
		cout << "Введите оценку по математике " << i + 1 << " студента:" << endl;
		cin >> arr[i].math;

		s += arr[i].math;
		s += " ";
		cout << "Введите оценку по информатике " << i + 1 << " студента:" << endl;
		cin >> arr[i].inf;

		s += arr[i].inf;
		s += " ";
		cout << "Введите оценку по химии " << i + 1 << " студента:" << endl;
		cin >> arr[i].chem;

		s += arr[i].chem;
		s += " ";
		double b = (stoi(arr[i].inf) + stoi(arr[i].math) + stoi(arr[i].phys) + stoi(arr[i].chem)) / 4.0;
		double a = int(b * 100) / 100.0;
		string str = to_string(a);
		a = 0;
		s += str;
		file << s;
		file << "\n";
		s = " ";
	}
	file.close();
}

void main()
{
	system("chcp 1251>nul");
	int a;
	cout << "Если хотите прочесть файл-нажмите 1. Если хотите записать информацию в файл-нажмите 2.\n";
	cout << "Если хотите редактировать файл-нажмите 3. Если хотите вывести результат-нажмите 4.\n";
	cout << endl;
	cin >> a;
	cout << endl;
	switch (a) {
	case 1:
		read();
		break;
	case 2:
		create();
		break;
	case 3:
		redact();
		break;
	case 4:
		rez();
		break;
	}

}

