#include<iostream>
#include<string>
using namespace std;
struct student {
	string surname;
	string name;
	string date_of_birth;
	int group;
	int phys;
	int math;
	int chem;
	int inf;
	double avr;
};
int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Введите количество студентов: ";
	cin >> n;
	student arr[100];
	for (int i = 0; i < n; ++i) {
		cout << "Введите Фамилию "<<i+1<<" студента:" << endl;
		cin >> arr[i].surname;
		cout << "Введите инициалы "<<i+1<<" студента: " << endl;
		cin >> arr[i].name;
		cout << "Введите дату рождения "<<i+1<<" студента: " << endl;
		cin >> arr[i].date_of_birth; 
		cout << "Введите номер группы "<<i+1<<" студента: " << endl;
		cin >> arr[i].group;
		cout << "Введите оценку по физике "<<i+1<<" студента: " << endl;
		cin >> arr[i].phys;
		cout << "Введите оценку по математике "<<i+1<<" студента: " << endl;
		cin >> arr[i].math;
		cout << "Введите оценку по химии "<<i+1<<" студента: " << endl;
		cin >> arr[i].chem;
		cout << "Введите оценку по информатике "<<i+1<<" студента: " << endl;
		cin >> arr[i].inf;
		cout << "Введите средний балл по выше перечисленным оценкам "<<i+1<<" студента: " << endl;
		cin >> arr[i].avr;
	}
	for (int i = 0; i < n; ++i) {
		if ((arr[i].phys == 4 || arr[i].phys == 5) && arr[i].math>8 && arr[i].inf>8 && arr[i].chem>8 && arr[i].inf > 8) {
			cout <<"Фамилия: " << arr[i].surname << ". Инициалы: " << arr[i].name << " Дата рождения: " << arr[i].date_of_birth << ". Номер группы: " << arr[i].group << endl;
		}
	}
	return 0;
}
