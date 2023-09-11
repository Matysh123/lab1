#include <stdio.h>
int main() {
	//размеры двумерного массива rows - строки, coloumns - колонки
	const int rows = 5, coloumns = 4;
	//двумерный массив
	int massiv[rows][coloumns] = { {10, 20, 30, 40}, {50, 60, 70, 80}, {90, 100, 110, 120}, {130, 140, 150, 160}, {170, 180, 190, 200} };
	//массив сумм строк
	int sums[rows] = {};
	//вывод размеров массива
	printf("Array %dx%d\n", rows, coloumns);
	//вывод массива и нахождение суммы значений каждой строки
	for (int i = 0; i != rows; i++) {
		for (int j = 0; j != coloumns; j++) {
			printf("[%d][%d] %d\t", i, j, massiv[i][j]);
			sums[i] += massiv[i][j];
		}
		printf("|Sum = %d\n", sums[i]);
	}
	return 0;
}