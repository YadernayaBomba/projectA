#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Функция, которая выводит переданный массив
void Output(const float Array[], const int Size)
{
	for (int i = 0; i < Size; i += 1)
		cout << Array[i] << " | ";
}

// Функция выводит количество отрицательных элементов массива
// или заменяет отрицательные элементы на их квадраты
int Minus_count(const bool ReplacingElem, float Array[], const int Size)
{
	if (!ReplacingElem)
	{	//Подсчет количества отрицательных элементов массива
		int Count = 0;
		for (int i = 0; i < Size; i += 1)
			if (Array[i] < 0) Count += 1;
		return Count;
	}
	if (ReplacingElem)
		// Замена отрицательных элементов массива их квадратами
		for (int i = 0; i < Size; i += 1)
			if (Array[i] < 0) Array[i] = pow(Array[i], 2);
}

// Функция выводит индекс минимального по модулю элемента массива
int Index_min_abs(const float Array[], const int Size)
{
	int Index = 0;
	for (int i = 0; i < Size; i += 1)
		if (abs(Array[i]) < abs(Array[Index])) Index = i;
	return Index;
}

// Функция выводит сумму модулей элементов массива в диапазоне
float Sum_of_elem(const float Array[], const int Size, int Begin, int End)
{
	if (Begin > End) swap(Begin, End);
	if (Begin < 0) Begin = 0;
	if (End > Size) End = Size - 1;
	float Sum = 0;
	for (int i = Begin; i < End; i += 1)
		Sum += abs(Array[i]);
	return Sum;
}


// Главная функция
int main()
{
	setlocale(LC_ALL, "RU");

	// Создание массива
	int N;
	cout << "Введите размер массива: "; cin >> N;	// 10
	float* Arr = new float[N];	// {4, -0.58, 9, 2.1, -17, 5.56, -6.44, 7.6, 5.49, -2.13};

	// Заполнение массива
	for (int i = 0; i < N; i += 1)
	{
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		cin >> *(Arr + i);
	}

	//Результат работы функций
	cout << "\nИсходный массив: | "; Output(Arr, N);
	cout << "\nКоличество отрицательных элементов: " << Minus_count(false, Arr, N);
	cout << "\nСумма элементов после минимального по модулю: " << Sum_of_elem(Arr, N, Index_min_abs(Arr, N)+1, N) << endl;
	Minus_count(true, Arr, N); sort(Arr, Arr + N);
	cout << "\nОтсортированный массив: | "; Output(Arr, N);
	cout << endl;

	delete[] Arr;
}