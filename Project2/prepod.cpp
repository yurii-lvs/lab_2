#define _CRT_SECURE_NO_WARNINGS
#include "prepod.h"
#include "fio.h"
#include <iostream>
using namespace std;
int prepod::count = 0;
prepod::prepod(int departament, fio fi, int status) {
	setDep(departament);
	setFio(fi);
	setSt(status);
}
void prepod::Addprepod(prepod** t, int n) {
	*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
	printf("%s\n", "");
	printf("%s\n", "Добаваление нового преподавателя");
	printf("%s", "Введите кафедру (1-ИПОВС, 2-ВМ, 3-ВТ): ");
	cin >> t[0][n].departament;
	char buff[100];
	while (getchar() != '\n');
	printf("%s", "Введите фамилию: ");
	gets_s(buff);
	t[0][n].fi.fam = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.fam, buff);
	printf("%s", "Введите имя: ");
	gets_s(buff);
	t[0][n].fi.name = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.name, buff);
	printf("%s", "Введите отчество: ");
	gets_s(buff);
	t[0][n].fi.father = (char*)malloc(strlen(buff) + 1);
	strcpy(t[0][n].fi.father, buff);
	printf("%s", "Введите ученое звание (1- преподаватель, 2- доцент,3-доктор наук): ");
	cin >> t[0][n].status;
	cout << "prepod finish";
}
prepod::~prepod() {

}
int prepod::getDep() {
	return departament;
}

fio prepod::getFio() {
	return fi;
}
int prepod::getSt() {
	return status;
}
void prepod::setDep(int d) {
	departament = d;
}
void prepod::setFio(fio f) {
	fi = f;
}
void prepod::setSt(int s) {
	status = s;
}


void prepod::printTable() {
	printf("%s\n", "");
	printf("%s", "Фамилия");
	printf("%18s", "Имя");
	printf("%23s", "Отчество");
	printf("%22s", "Кафедра");
	printf("%28s\n", "Ученое звание");
	for (int i = 0; i < 98; i++) {
		printf("%s", "-");
	}
	printf("%s\n", "");
}

void prepod::loadTeacher(const char* fileName, prepod** t, int& n) {
	FILE* f;
	if ((fopen(fileName, "r+")) == NULL)
	{
		printf("%s", "Файла нет создание\n");
		f = fopen(fileName, "w+");
		fclose(f);
	}
	char buff[100];
	f = fopen(fileName, "r");
	for (int i = 0; !feof(f); i++) {
		*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
		fscanf(f, "%99s", buff);
		t[0][i].departament = atof(buff);
		fscanf(f, "%99s", buff);
		t[0][i].fi.fam = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.fam, buff);
		fscanf(f, "%99s", buff);
		t[0][i].fi.name = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.name, buff);
		fscanf(f, "%s", buff);
		t[0][i].fi.father = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].fi.father, buff);
		fscanf(f, "%s", buff);
		t[0][i].status = atof(buff);
		n++;
	}
	fclose(f);
}

void prepod::saveTeacher(const char* fileName, prepod* t, int n) {
	FILE* f;
	f = fopen(fileName, "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", t[i].departament);
		fprintf(f, "%s ", t[i].fi.fam);
		fprintf(f, "%s ", t[i].fi.name);
		fprintf(f, "%s ", t[i].fi.father);
		fprintf(f, "%d ", t[i].status);
	}
	fclose(f);
}

void prepod::printTeacher(prepod* t, int i)
{
	printf("%s", t[i].fi.fam);
	for (int j = 0; j < 15 - strlen(t[i].fi.fam) + 7; j++) printf("%s", " ");
	printf("%s", t[i].fi.name);
	for (int j = 0; j < 15 - strlen(t[i].fi.name) + 3; j++) printf("%s", " ");
	printf("%s", t[i].fi.father);
	int temp = 0;
	for (int j = 0; j < 15 - strlen(t[i].fi.father) + 8; j++) printf("%s", " ");
	if (t[i].departament == 1) printf("%s", "ИПОВС");
	if (t[i].departament == 2) printf("%s", "ВМ");
	if (t[i].departament == 3) printf("%s", "ВТ");
	if (t[i].departament == 1) temp = 5;
	if (t[i].departament == 2) temp = 2;
	if (t[i].departament == 3) temp = 2;
	for (int j = 0; j < 15 - temp + 7; j++) printf("%s", " ");
	if (t[i].status == 1) printf("%s\n", "преподаватель");
	if (t[i].status == 2) printf("%s\n", "доцент");
	if (t[i].status == 3) printf("%s\n", "доктор наук");

}

void prepod::printAllTeachers(prepod* t, int n) {
	printf("%s\n", "");
	printf("%s", "Список всех преподавателей");
	prepod::printTable();
	for (int i = 0; i < n; i++) {
		printTeacher(t, i);
	}
	for (int i = 0; i < 98; i++) {
		printf("%s", "-");
	}
	printf("%s\n", "");
	count=n;
	cout << "Всего объектов: " << count<<endl;
}

void prepod::searchTeacher(prepod* t, int n) {
	printf("%s\n", "");
	printf("%s\n", "Поиск преподавателя по фио");
	char sur[100]; char im[100]; char ot[100];
	printf("%s", "Введите фамилию: ");
	while (getchar() != '\n');
	gets_s(sur);
	printf("%s", "Введите имя: ");
	gets_s(im);
	printf("%s", "Введите отчество: ");
	gets_s(ot);
	int temp1 = -1, temp2 = -1, temp3 = -1;
	for (int i = 0; i < n; i++) {
		if (strcmp(t[i].fi.fam, sur) == 0) temp1 = i;
		if (strcmp(t[i].fi.name, im) == 0) temp2 = i;
		if (strcmp(t[i].fi.father, ot) == 0) temp3 = i;
	}
	if (temp1 != -1 && temp2 != -1 && temp3 != -1) {
		if (temp1 == temp2 && temp2 == temp3)
		{
			cout << endl << "Преподаватель найден!";
			printTable();
			printTeacher(t, temp1);
			for (int i = 0; i < 98; i++) {
				printf("%s", "-");
			}
			printf("%s\n", "");
		}
	}
	else
	{
		printf("%s\n", "");
		printf("%s\n", "Такого преподавателя нет!");
	}
}

void filterStatus(prepod* t, int n)
{
	printf("%s\n", "");
	printf("%s\n", "Фильтр по статусу");
	int temp;
	printf("%s", "Введите статус (1- преподаватель, 2- доцент, 3-доктор наук): ");
	scanf("%d", &temp);
	prepod::printTable();
	for (int i = 0; i < n; i++) {
		if (t[i].status == temp) prepod::printTeacher(t, i);
	}
	for (int i = 0; i < 98; i++) {
		printf("%s", "-");
	}
	printf("%s\n", "");
}

void sortTeachers(prepod* t, int n) {
	printf("%s\n", "");
	printf("%s\n", "Сортировка");
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = j + 1; i < n; i++)
		{
			if (strcmp(t[j].fi.getFam(), t[i].fi.getFam()) > 0)
			{
				char* p = t[j].fi.getFam();
				t[j].fi.setFam(t[i].fi.getFam());
				t[i].fi.setFam(p);
				p = t[j].fi.getName();
				t[j].fi.setName(t[i].fi.getName());
				t[i].fi.setName(p);
				p = t[j].fi.getFath();
				t[j].fi.setFath(t[i].fi.getFath());
				t[i].fi.setFath(p);
				swap(t[j].status, t[i].status);
				swap(t[j].departament, t[i].departament);
			}
		}
	}
	prepod::printAllTeachers(t, n);
}
