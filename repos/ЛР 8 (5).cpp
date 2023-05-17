#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	//Объявление и иницаилизация двумерного динамического массива
	const int I = 5, J = 5; //Размеры массива
	int** Matrix = new int* [I] 
	{
		new int[J]{ -6, -2, 3, -4, 3 }, 
		new int[J]{ -1, -6, 2, -3, 8 }, 
		new int[J]{ -4, -9, 6, -9, 6 }, 
		new int[J]{ -2, -2, 8, -2, 7 }, 
		new int[J]{ -1, -6, 3, -1, 6 }
	};

	//Объявление копии исходного массива (вспомогательный массив для дальнейших преобразований)
	int** CopyOfMatrix = (int**) new int [I][J];
	for (int i = 0; i < I; i += 1)
		CopyOfMatrix[i] = new int[J]; 

	//Вывод исходного массива
	cout << "Исходный массив:\n";
	for (int i = 0; i < I; i += 1)
	{

		for (int j = 0; j < J; j += 1)
		{
			CopyOfMatrix[i][j] = Matrix[i][j];  //Копирование исходного массива в вспомогательный
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}

	//Поиск 1-го попавшегося номера столбца, в котором все числа положительны
	int* nLine = new int(-1); //Динамическая переменная, в которую сохраняется номер искомого столбца
	for (int j = 0; j < J; j += 1)
	{
		bool Minus = false;
		for (int i = 0; i < I; i += 1)
		{
			if (Matrix[i][j] < 0) { Minus = true; break; }
		}
		if (Minus == false) { *nLine = j; break; }
	}
	
	//Вывод номера нужного столбца (при наличии)
	if (*nLine != -1) cout << "Номер столбца с положительными числами: " << *nLine + 1 << endl;
	else cout << "Нет столбцов, в которых все числа положительны";
	delete nLine; //Освобождение памяти

	//Подсчет кол-ва всех одинаковых чисел в строках вспомогательного массива (их кол-во равно кол-ву в исходном)
	int* nEquals = new int[I]; //Создание вспомогательного одномерного массива, кол-во элементов которого равно кол-ву строк в исходном массиве
	for (int i = 0; i < I; i += 1)
	{
		sort(*(CopyOfMatrix + i), *(CopyOfMatrix + i) + J); //Сортировка элементов строки по возрастанию в вспомогательном массиве
		int SumCount = 0; //Сумма количеств одинаковых чисел в строке обнуляется
		for (int j = 0; j < J;)
		{
			int Count = 0; //Кол-во определенных одинаковых чисел обнуляется
			while (++j < J && CopyOfMatrix[i][j] == CopyOfMatrix[i][j - 1]) Count += 1;
			if (Count != 0) SumCount += Count + 1;
		}
		nEquals[i] = SumCount; //Присваивание суммы количеств всех одинаковых чисел (в строке) элементам одномерного массива
		delete[] CopyOfMatrix[i];
	}
	delete[] CopyOfMatrix;

	//Сортировка строк исходного массива в соответствии с сортировкой одномерного массива
	for (int i = 0; i < I; i += 1)
	{
		for (int l = i + 1; l < I; l += 1)
		{
			if (nEquals[l] < nEquals[i]) 
			{
				swap(nEquals[l], nEquals[i]);
				swap(Matrix[i], Matrix[l]);
			}
		}

	}

	//Вывод отсортированной матрицы
	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < I; i += 1)
	{
		for (int j = 0; j < J; j += 1) cout << Matrix[i][j] << "\t";
		cout << "Одинаковых элементов: " << nEquals[i] << endl;
		delete[] Matrix[i];
	}
	delete[] Matrix, nEquals;
}