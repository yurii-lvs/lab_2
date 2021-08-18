#pragma once
#include"fio.h"
class prepod
{
	friend class fio;
	friend void filterStatus(prepod* t, int n);
	friend void sortTeachers(prepod* t, int n);
public:
	static int count;
	prepod(int departament, fio fi, int status);
	static void Addprepod(prepod** t, int n);
	~prepod();
	int getDep();
	fio getFio();
	int getSt();
	void setDep(int d);
	void setFio(fio f);
	void setSt(int s);
	static void searchTeacher(prepod* t, int n);
	static void printTeacher(prepod* t, int i);
	static void printTable();
	static void printAllTeachers(prepod* t, int n);
	static void loadTeacher(const char* fileName, prepod** t, int& n);
	static void saveTeacher(const char* fileName, prepod* t, int n);

private:
	int departament;
	fio fi;
	int status;

};

