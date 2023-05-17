#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	// Ввод размера массива
	int* N = new int();
	cout << "Введите размер массива: ";
	cin >> *N;	// 10
	float* Arr = new float[*N];	// {4, -0.58, 9, 2.1, -17, 5.56, -6.44, 7.6, 5.49, -2.13};

	// Заполнение массива
	for (int i = 0; i < *N; i += 1)
	{
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		cin >> *(Arr + i);
	}

	// Объявление и инициализация динамических переменных для работы с массивом
	int* Count = new int();
	float* nMin = new float(abs(*Arr));
	int* j = new int();
	float* Summ = new float();

	//Вывод исходного массива
	cout << "\nИсходный массив: | ";
	for (int i = 0; i < *N; i += 1)
	{
		cout << *(Arr + i) << " | ";
		if (*(Arr + i) < 0) // Счетчик отрицательных чисел
			*Count += 1;
		if (abs(*(Arr + i)) < *nMin) // Поиск миниимаьного по модулю элемента
		{
			*nMin = abs(*(Arr + i));
			*j = i;
		}
	}
	cout << "\nКол-во отрицательных элементов: " << *Count << endl;

	// Вычисление суммы чисел, стоящих после минимального по модулю
	for (int i = 0; i < *N; i += 1)
	{
		if (i > *j)
			*Summ += abs(*(Arr + i));
		// Замена отрицательных чисел их квадратами
		if (*(Arr + i) < 0)
			*(Arr + i) = pow(*(Arr + i), 2);
	}

	cout << "Сумма чисел после минимального по модулю: " << *Summ << endl;
	sort(Arr, Arr + *N); // Сортировка массива по возрастанию

	// Вывод преобразованного массива
	cout << "\nОтсортированный массив: | ";
	for (int i = 0; i < *N; i += 1)
		cout << *(Arr + i) << " | ";
	cout << endl;

	// Освобождение памяти
	delete N, Count, nMin, j, Summ;
	delete[] Arr;
}