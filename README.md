# lab_2
Программирование с использованием классов.
Создать класс prepod со следующими элементами:
данные-члены класса:
 int department;  // кафедра (1-ИПОВС, 2-ВМ, 3-ВТ)
char* fio; 	   //фио преподавателя
int status;	   //ученое звание ( 1- преподаватель, 2- доцент,3-доктор наук)
static int count;        // счетчик существующих объектов класса
функции-члены класса:
1.	Создать обязательные функции, указанные в общих требованиях (МК).
2.	Создать функции для данного варианта: 
•	Поиск преподавателя по фио   (МК)
•	Фильтр по статусу (найти преподавателей заданного статуса) (ДФ)
•	Сортировать по алфавиту (ДФ)
1.	Создать новый класс fio, данные-члены класса (все pri):
char	*familia, 	// указатели на строки с фамилией,
	*imya, 	// именем и отчеством
*otchestvo;
функции-члены класса fio: решайте сами, какие методы необходимы
2.	В классе prepod поле  char* fio;   заменить на встроенный объект класса fio
3.	Добавить функции-члены класса prepod:
•	перегруженные конструкторы (по умолчанию, с параметрами по умолчанию)
•	конструкторы копирования
4.	Изменить все МК и ДФ в соответствии с дополненными элементами
