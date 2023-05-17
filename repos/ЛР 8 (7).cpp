#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

struct ZNAK
{
	string Name;
	string SurName;
	string znak;
	unsigned short Birth[3] = { 0, 0, 0 };
};

// Главная функция
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int const N = 5;

	/*15 02 2002
	  15 01 2002
	  17 09 2000
	  29 07 2004
	  28 07 2004*/
	// Массив с данными 5-ти человек
	ZNAK** Data = new ZNAK*[N];	
		
	// Заполнение массива
	for (int i = 0; i < N; i += 1)
	{
		Data[i] = new ZNAK;
		cout << "Фамилия и имя: ";
		cin >> Data[i]->SurName >> Data[i]->Name;
		cout << "Дата рождения: ";
		cin >> Data[i]->Birth[2] >> Data[i]->Birth[1] >> Data[i]->Birth[0];
		cout << "Знак зодиака: ";
		cin >> Data[i]->znak; cout << "\n";
	}

	// Сортировка записей по убыванию даты рождения
	for (int i = 0; i < N; i += 1)
		for (int j = i + 1; j < N; j += 1)
		{
			if ((Data[j]->Birth[0] > Data[i]->Birth[0]) or (Data[j]->Birth[0] == Data[i]->Birth[0] and Data[j]->Birth[1] > Data[i]->Birth[1]) or (Data[j]->Birth[0] == Data[i]->Birth[0] and Data[j]->Birth[1] == Data[i]->Birth[1] and Data[j]->Birth[2] > Data[i]->Birth[2]))
			{
				swap(Data[j], Data[i]);
				continue;
			}
		}

	// Вывод отсортированных записей 
	for (int i = 0; i < N; i += 1)
		cout << "Дата рождения: " << Data[i]->Birth[2] << " " << Data[i]->Birth[1] << " " << Data[i]->Birth[0] << ". " << Data[i]->SurName << " " << Data[i]->Name << ". Знак: " << Data[i]->znak << "\n";

	// Работа с пользователем
	while (true)
	{
		int Command;
		cout << "\nВведите действие (0 - завершить программу; 1 - поиск по знаку зодиака): ";
		cin >> Command;
		if (Command == 0) break;
		if (Command == 1)
		{
			string zodiak;
			cout << "Введите знак: ";
			cin >> zodiak;
			cout << "Результат:\n";
			int count = 0;
			for (int i = 0; i < N; i += 1)
			{
				if (zodiak == Data[i]->znak)
				{
					cout << Data[i]->SurName << " " << Data[i]->Name << " " << Data[i]->Birth[0] << " " << Data[i]->Birth[1] << " " << Data[i]->Birth[2] << "\n";
					count += 1;
				}
			}
			if (count == 0) cout << "Нет людей с таким знаком" << endl;
		}
	}
	for (int i = 0; i < N; i += 1)
		delete[] Data[i];
	delete[] Data;
}
Сидоров И 15 02 2002 телец Иванов И 15 01 2002 телец Кузнецов К 17 09 2000 водолей Попов П 29 07 2004 скорпион Сеченов Д 28 07 2004 весы

