#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
#include <iostream>
using namespace std;

fio::fio() {

}
fio::fio(char* fam, char* name, char* father)
{
	setFam(fam); setName(name); setFath(father);
}
fio:: ~fio() {
	cout << "Destructor started" << endl;
	cout << fam << endl;
	cout << name << endl;
	cout << father << endl;
	free(fam);
	free(name);
	free(father);
}
char* fio::getFam() {
	return fam;
}
char* fio::getName() {
	return name;
}
char* fio::getFath() {
	return father;
}
void fio::setFam(char* f) {
	char buff[4096];
	cin>>buff;
	char* fam = (char*)malloc(strlen(buff) + 1);
	strcpy(fam, f);
	/*fam = f;*/
}
void fio::setName(char* n) {
	char buff[100];
	cin >> buff;
	char* name = (char*)malloc(strlen(buff) + 1);
	strcpy(name, n);
}
void fio::setFath(char* o) {
	char buff[100];
	cin >> buff;
	char* father = (char*)malloc(strlen(buff) + 1);
	strcpy(father, o);
}
