#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "prepod.h"
#include "fio.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	prepod* t;
	FILE* f;
	int n = 0, menu;
	t = (prepod*)malloc(n * sizeof(prepod));
		prepod::loadTeacher("data.txt", &t, n);
		n--;
	while (1) {
		printf("%s\n", "");
		printf("%s\n", "Меню");
		printf("%s\n", "1 - Добавить преподавателя");
		printf("%s\n", "2 - Распечатать информацию о всех преподавателях");
		printf("%s\n", "3 - Поиск преподавателя по фио");
		printf("%s\n", "4 - Фильтр по статусу (найти преподавателей заданного статуса)");
		printf("%s\n", "5 - Сортировка по алфавиту");
		printf("%s\n", "0 - Выход ");
		printf("%s", "Пункт меню: ");
		scanf("%d", &menu);

		switch (menu) {

		case 1: prepod::Addprepod(&t, n);
			prepod::count++;
			n++;
			break;

		case 2: prepod::printAllTeachers(t, n);


			break;

		case 3: prepod::searchTeacher(t, n);

			break;


		 case 4: filterStatus(t, n);

			break;

		case 5: sortTeachers(t, n);

			break;

		case 0: prepod::saveTeacher("data.txt", t, n);
			free(t);
			return 0;
			break;

		default:cout << "Введите нужную цифру!" << endl;

			break;

		}
	}
}