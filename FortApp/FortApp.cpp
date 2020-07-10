#include <iostream>
#include <string>
#include <list>

using namespace std;

class Student
{
public:

	Student(string name, double score) {
		this->Name = name;
		this->Score = score;
	}


	string Name;
	double Score;
};

//Поиск по баллам
template <typename T>
void FindScore(const list<T>& people)
{
	system("cls");
	cout << "Введите Баллы: ";
	double a1;
	cin >> a1;
	for (auto i : people)
		if (i.Score == a1) {
			system("cls");
			cout << "Имя: " << i.Name << " Баллы: " << i.Score << endl;
			break;
		}
}

//Поиск по имени
template <typename T>
void FindName(const list<T>& people)
{
	system("cls");
	cout << "Введите имя: ";
	string a1;
	cin >> a1;
	for (auto i : people)
		if (i.Name == a1) {
			system("cls");
			cout << "Имя: " << i.Name << " Баллы: " << i.Score << endl;
			break;
		}
}

int main()
{
	setlocale(LC_ALL, "ru");

	int a = 0;

	list<Student> people{
	Student("Oleg",100),
	Student("Van",53),
	Student("vova",134),
	Student("vovka",323),
	Student("ana",141),
	};

	while (a != 5)
	{
		cout << " 1 – Добавить позиции\n";
		cout << " 2 – Удалить позиции\n";
		cout << " 3 – Вывести список позиций\n";
		cout << " 4 – Выполнять текстовый поиск позиции\n";
		cout << " 5 – Выход\n\n";


		cout << "Select: ";
		cin >> a;

		switch (a)
		{
		case 1:
		{

		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{
			system("cls");
			cout << " 1 – Поиск по имени\n";
			cout << " 2 – Поиск по баллам\n";

			cout << "Select: ";
			cin >> a;

			switch (a)
			{
			case 1: FindName(people);
				break;
			case 2: FindScore(people);
				break;
			}
			break;
		case 5: a = 5;
		}

		}
	}
}