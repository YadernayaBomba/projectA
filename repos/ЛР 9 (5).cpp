#include <iostream>
#include <algorithm>
using namespace std;

// Функция, которая выводит переданный двумерный массив
void Output(int** Array, const int M, const int N )
{
	for (int i = 0; i < M; i += 1)
	{
		for (int j = 0; j < N; j += 1)
			cout << " | " << Array[i][j];
		cout << " | " << endl;
	}
}

// Возвращает номер первого попавшегося столбца, в котором все элементы положительны
int Column_num(int** Array, const int M, const int N)
{
	int Column = -1;
	for (int j = 0; j < N; j += 1)
	{
		bool Minus = false;
		for (int i = 0; i < M; i += 1)
			if (Array[i][j] < 0) { Minus = true; break; }
		if (!Minus) { Column = j; break; }
	}
	return Column;
}

// Возвращает указатель на одномерный массив, значения элементов которого соответствуют
// количеству одинаковых элементов в строках переданного двумерного массива
int* pNewArray(int** Array, const int M, const int N)
{
	int** CopyOfArray = new int* [M];
	for (int i = 0; i < M; i += 1)
	{
		CopyOfArray[i] = new int[N];
		for (int j = 0; j < N; j += 1)
			CopyOfArray[i][j] = Array[i][j];
		sort(CopyOfArray[i], CopyOfArray[i] + N);
	}
	
	int* Arr = new int[M];
	for (int i = 0; i < M; i += 1)
	{
		int SumCount = 0;
		for (int j = 0; j < N; )
		{
			int Count = 0;
			while (++j < N && CopyOfArray[i][j] == CopyOfArray[i][j - 1]) Count += 1;
			if (Count) SumCount += Count + 1;
		}
		Arr[i] = SumCount;
		delete[] CopyOfArray[i];
	}
	delete[] CopyOfArray;
	return Arr; 
}

// Сортирует строки переданной двумерной матрицы в соответствии с переданной 
// одномерной матрицей (по возрастанию)
void ReplacingElem(int** Array, int Arr[], const int M, const int N)
{
	for (int i = 0; i < M; i += 1)
		for (int l = i + 1; l < M; l += 1)
			if (Arr[l] < Arr[i])
			{
				swap(Arr[i], Arr[l]);
				swap(Array[i], Array[l]);
			}
}


// Главная функция
int main()
{
	setlocale(LC_ALL, "ru");

	//Объявление и инициализация двумерного динамического массива
	const int I = 5, J = 5; //Размеры массива
	int** Matrix = new int* [I]
	{
		new int[J] { -6, -2, 3, -4, 3 },
		new int[J] { -1, -6, 2, -3, 8 },
		new int[J] { -4, -9, 6, -9, 6 },
		new int[J] { -2, -2, 8, -2, 7 },
		new int[J] { -1, -6, 3, -1, 6 }
	};
	
	// Результат работы функций
	cout << "Исходный массив:\n"; Output(Matrix, I, J);
	cout << "\nНомер столбца, где все числа положительны: " << Column_num(Matrix, I, J) + 1; cout << endl;

	int* newArray = pNewArray(Matrix, I, J);
	ReplacingElem(Matrix, newArray, I, J);

	cout << "\nОтсортированный массив:\n"; Output(Matrix, I, J);

	// Освобождение памяти
	for (int i = 0; i < I; i += 1)
		delete[] Matrix[i];
	delete[] Matrix;
	delete[] newArray;
}