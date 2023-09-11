#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
//функция заполнения массива случайными числами
void randPrintMassiv(int* initmassiv, int sizemassiv, int rangemin, int rangemax) {
	//seed для генерации
	srand(time(NULL));
	//заполнение массива числами и вывод
	for (int i = 0; i != sizemassiv; i++) {
		*(initmassiv + i) = rangemin + rand()%(rangemax - rangemin + 1);
		printf("[%d]%d\n", i, *(initmassiv + i));
	}
}
int main() {
	int size = 0;
	//ввод размера массива от пользователя
	printf("Enter size of array: ");
	(void)scanf("%d", &size);	
	//выделение памяти для дин. массива, размером size
	int* massiv = (int*)malloc(sizeof(int) * size);
	//заполнение массива случайными числами
	randPrintMassiv(massiv, size, -1000, 1000);
	//если нельзя выделить память - выход из программы
	if (!massiv)
		return 1;
	//максимальное и минимальное значение соответствует первому элементу массива
	int max = *massiv, min = *massiv;
	//поиск максимального и минимального элемента массива
	for (int i = 1; i != size; i++) {
		if (*(massiv + i) > max)
			max = *(massiv + i);
		if (*(massiv + i) < min)
			min = *(massiv + i);
	}
	//вывод разницы между макс. и мин. элементами
	printf("\nmax - min = %d - %d = %d", max, min, max - min);
	//освобождение блока памяти
	free(massiv);
	return 0;
}