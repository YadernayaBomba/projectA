#include<iostream>
using namespace std;

// Функция, которая определяет лежат ли три точки на одной прямой
bool line(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return(((x3 - x1) / (x2 - x1)) == (y3 - y1) / (y2 - y1));
}

// Функция, которая определяет попадание точки в теругольник 
bool in_triangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float S = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	float S1 = 0.5 * abs(x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2));
	float S2 = 0.5 * abs(x1 * (y3 - y4) + x3 * (y4 - y1) + x4 * (y1 - y3));
	float S3 = 0.5 * abs(x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3));
	return(S == round((S1 + S2 + S3) * 1000) / 1000);
}

// Главная функция
int main()
{
	setlocale(LC_ALL, "ru");
	const int N = 12; // N - кол-во точек в массиве

	//Объявление и инициализация двумерного динамического массива
	float** Point = new float*[N]
	{ 
		new float[2]{0, 0},
		new float[2]{2, 6}, 
		new float[2]{6, 2}, 
		new float[2]{2, 2}, 
		new float[2]{2, 5}, 
		new float[2]{5, 2}, 
		new float[2]{3.5, 2.5}, 
		new float[2]{2.5, 3}, 
		new float[2]{2.5, 4}, 
		new float[2]{7, 2}, 
		new float[2]{3.5, 4}, 
		new float[2]{1.5, 4} 
	};

	// Перебор вершин для 1-го трегуольника
	for (int a = 0; a < N - 2; a += 1)
		for (int b = a + 1; b < N - 1; b += 1)
			for (int c = b + 1; c < N; c += 1)
			{
				// проверка: лежат ли три вершины 1-го треугольника на одной прямой
				if (line(Point[a][0], Point[a][1], Point[b][0], Point[b][1], Point[c][0], Point[c][1])) continue;
				for (int d = 0; d < N - 2; d += 1)	// перебор 1-й вершины для 2-го треугольника
				{
					// проверка: лежит ли точка в 1-ом треугольнике и не совпадает ли с какой-нибудь из его вершин
					if (!in_triangle(Point[a][0], Point[a][1], Point[b][0], Point[b][1], Point[c][0], Point[c][1], Point[d][0], Point[d][1])) continue;
					if ((Point[d][0] == Point[a][0] and Point[d][1] == Point[a][1]) or (Point[d][0] == Point[b][0] and Point[d][1] == Point[b][1]) or (Point[d][0] == Point[c][0] and Point[d][1] == Point[c][1])) continue;
					for (int e = d + 1; e < N - 1; e += 1)	// Перебор 2-й вершины для 2-го треугольника
					{
						// проверка: лежит ли точка в 1-ом треугольнике и не совпадает ли с какой-нибудь из его вершин
						if (!in_triangle(Point[a][0], Point[a][1], Point[b][0], Point[b][1], Point[c][0], Point[c][1], Point[e][0], Point[e][1])) continue;
						if ((Point[e][0] == Point[a][0] and Point[e][1] == Point[a][1]) or (Point[e][0] == Point[b][0] and Point[e][1] == Point[b][1]) or (Point[e][0] == Point[c][0] and Point[e][1] == Point[c][1])) continue;
						for (int f = e + 1; f < N; f += 1)	// Перебор 3-й вершины для 2-го треугольника
						{
							// проверка: лежит ли точка в 1-ом треугольнике и не совпадает ли с какой-нибудь из его вершин
							if (!in_triangle(Point[a][0], Point[a][1], Point[b][0], Point[b][1], Point[c][0], Point[c][1], Point[f][0], Point[f][1])) continue;
							if (line(Point[d][0], Point[d][1], Point[e][0], Point[e][1], Point[f][0], Point[f][1])) continue;
							// проверка: лежат ли вершины 2-го треугольника на одной прямой
							if ((Point[f][0] == Point[a][0] and Point[f][1] == Point[a][1]) or (Point[f][0] == Point[b][0] and Point[f][1] == Point[b][1]) or (Point[f][0] == Point[c][0] and Point[f][1] == Point[c][1])) continue;
							for (int g = 0; g < N - 2; g += 1)	// Перебор 1-й вершины 3-го треугольника
							{
								// проверка: лежит ли точка во 2-ом треугольнике и не совпадает ли с какой-нибдуь из его вершин
								if (!in_triangle(Point[d][0], Point[d][1], Point[e][0], Point[e][1], Point[f][0], Point[f][1], Point[g][0], Point[g][1])) continue;
								if ((Point[g][0] == Point[d][0] and Point[g][1] == Point[d][1]) or (Point[g][0] == Point[e][0] and Point[g][1] == Point[e][1]) or (Point[g][0] == Point[f][0] and Point[g][1] == Point[f][1])) continue;
								for (int h = g + 1; h < N - 1; h += 1)	// Перебор 2-й вершины 3-го треугольника
								{
									// проверка: лежит ли точка во 2-ом треугольнике и не совпадает ли с какой-нибудь из его вершин
									if (!in_triangle(Point[d][0], Point[d][1], Point[e][0], Point[e][1], Point[f][0], Point[f][1], Point[h][0], Point[h][1])) continue;
									if ((Point[h][0] == Point[d][0] and Point[h][1] == Point[d][1]) or (Point[h][0] == Point[e][0] and Point[h][1] == Point[e][1]) or (Point[h][0] == Point[f][0] and Point[h][1] == Point[f][1])) continue;
									for (int i = h + 1; i < N; i += 1)	// Перебор 3-й вершины 3-го треугольника
									{
										// проверка: лежит ли точка во 2-ом треугольнике и не совпадает ли с какой-нибудь из его вершин
										if (!in_triangle(Point[d][0], Point[d][1], Point[e][0], Point[e][1], Point[f][0], Point[f][1], Point[i][0], Point[i][1])) continue;
										if (line(Point[g][0], Point[g][1], Point[h][0], Point[h][1], Point[i][0], Point[i][1])) continue;
										// проверка: лежат ли вершины 3-го треугольника на одной прямой
										if ((Point[i][0] == Point[d][0] and Point[i][1] == Point[d][1]) or (Point[i][0] == Point[e][0] and Point[i][1] == Point[e][1]) or (Point[i][0] == Point[f][0] and Point[i][1] == Point[f][1])) continue;
										// Когда три тройки точек (вершин) удовлетворяют всем условиям, то они выводятся
										cout << "\n1-Й ТРЕУГ: (" << Point[a][0] << "; " << Point[a][1] << ") (" << Point[b][0] << "; " << Point[b][1] << ") (" << Point[c][0] << "; " << Point[c][1] 
											<< ")  2-Й ТРЕУГ: (" << Point[d][0] << "; " << Point[d][1] << ") (" << Point[e][0] << "; " << Point[e][1] << ") (" << Point[f][0] << "; " << Point[f][1] 
											<< ")  3-Й ТРЕУГ: (" << Point[g][0] << "; " << Point[g][1] << ") (" << Point[h][0] << "; " << Point[h][1] << ") (" << Point[i][0] << "; " << Point[i][1] << ")" << endl;
									}
								}
							}
						}
					}
				}
			}

	//Освобождение памяти
	for (int i = 0; i < N; i += 1)
		delete[] Point[i];
	delete[] Point;
}