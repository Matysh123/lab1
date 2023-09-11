#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>
//структура
struct student {
	char famil[20], name[20], facult[20];
	int nomzach;
};
//поиск студента
int searchStudent(struct student* structstud, const int sizearray) {
	//переменные для поиска. count для счёта найденных студентов.
	char sefamil[20] = "", sename[20] = "", sefacult[20] = "";
	int senomzach = 0, count = 0;
	//ввод параметров для поиска
	printf("Search\nEnter name of student: ");
	(void)scanf("%s", sename);
	printf("Enter surname of student: ");
	(void)scanf("%s", sefamil);
	printf("Enter elective's name of student: ");
	(void)scanf("%s", sefacult);
	printf("Enter gradecard's number of student: ");
	(void)scanf("%i", &senomzach);
	//поиск среди студентов
	for (int i = 0; i != sizearray; i++) {
		if (strstr((structstud + i)->name, sename) && strstr((structstud + i)->famil, sefamil) && strstr((structstud + i)->facult, sefacult) && (structstud + i)->nomzach == senomzach) {
			printf("\nfound student %d\n Name: %s\n Surname: %s\n Elective's name: %s\n Gradecard's number: %d\n", i + 1, (structstud + i)->name, (structstud + i)->famil, (structstud + i)->facult, (structstud + i)->nomzach);
			count++;
		}
	}
	return count;
}
int main() {
	//размер массива со структурами
	const int size = 2;
	//инициализация массива структур
	struct student stud[size];
	memset(&stud, 0, sizeof(stud));
	//ввод параметров для массива
	for (int i = 0; i != size; i++) {
		printf("Enter name of %d student: ", i+1);
		(void)scanf("%s", stud[i].name);
		printf("Enter surname of %d student: ", i+1);
		(void)scanf("%s", stud[i].famil);
		printf("Enter elective's name of %d student: ", i+1);
		(void)scanf("%s", stud[i].facult);
		printf("Enter gradecard's number of %d student: ", i+1);
		(void)scanf("%i", &stud[i].nomzach);
		printf("\n");
	}
	//если не будет найден студент с соответствующими параметрами - вывод соответствующего сообщения
	if (!searchStudent(stud, size)) {
		printf("No one was found");
	}
	return 0;
}