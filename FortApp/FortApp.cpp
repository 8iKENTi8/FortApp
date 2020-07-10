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
void FindScore(const list<T>& people,int &a)
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

	cout << endl << "Нажмите 1 чтобы продолжить: \n";
	int b;
	cin >> b;
	if (b == 1) system("cls");
	else a = 5;
}

//Поиск по имени
template <typename T>
void FindName(const list<T>& people,int &a)
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

	cout << endl << "Нажмите 1 чтобы продолжить: \n";
	int b;
	cin >> b;
	if (b == 1) system("cls");
	else a = 5;
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
			//Добавление позиций
		case 1:
		{
			system("cls");

			string n;
			double s;
			cout << "Введите имя студента: ";
			cin >> n;
			cout << "Введите балл студента: ";
			cin >> s;

			Student s2(n, s);

			cout << " 1 – Добавить вначало\n";
			cout << " 2 – Добавить в конец\n";
			cout << " 3 – Добавить в выбраную позицию\n";
			cin >> a;
			switch (a)
			{
				//Add to front
			case 1: {
				people.push_front(s2);
				system("cls");

			}
				  break;
				  //Add to back
			case 2: {
				people.push_back(s2);
				system("cls");

			}
				  break;
				  //Добавление по индексу
			case 3: {

				system("cls");
				cout << "Введите позицию на которую хотите вставить элемент\n";
				cout << "Select: ";
				auto it = people.begin();
				cin >> a;
				a--;
				advance(it, a);
				people.insert(it, s2);

			}
				  break;
				  system("cls");
			}
		}
		break;
		//Удаление позиций
		case 2:
		{
			system("cls");
			cout << " 1 – Удалить первый элемент\n";
			cout << " 2 – Удалить последний элемент\n";
			cout << " 3 – Удалить элемент по индексу\n";
			cin >> a;
			switch (a)
			{
			case 1: {
				people.pop_front();
				system("cls");
			}
				  break;
			case 2: {
				people.pop_back();
				system("cls");
			}
				  break;
			case 3:
			{
				system("cls");
				for (auto i : people)
					cout << "Имя: " << i.Name << " Баллы: " << i.Score << endl;

				cout << "Введите позицию  Которую хотите удалить\n";
				cout << "Select: ";
				auto it = people.begin();
				cin >> a;
				a--;
				advance(it, a);
				people.erase(it);
			}


			system("cls");
			}
		}
		break;
		case 3:
		{
			system("cls");
			cout << "Всего элементов: " << people.size() << endl << endl;

			for (auto i : people)
				cout << "Имя: " << i.Name << " Баллы: " << i.Score << endl;
			cout << endl<<"Нажмите 1 чтобы продолжить: \n";
			int b;
			cin >> b;
			if (b == 1) system("cls");
			else a = 5;
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
			case 1: FindName(people,a);
				break;
			case 2: FindScore(people,a);
				break;
			}
			break;
		case 5: a = 5;
		}

		}
	}
}