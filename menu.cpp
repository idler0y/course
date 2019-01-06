#include"menu.h"
#include"pch.h"
//void menu_user()
//{
//	vector<employee> temp;
//	employee current;
//	ifstream fin("user.txt");
//	if (fin.is_open()) {
//		fin >> current.login;
//		fin >> current.password;
//		fin >> current.access_level;
//	}
//	while (true) {
//		int choice;
//		cout << "1)Создать профиль" << endl;
//		cout << "2)Удалить профиль" << endl;
//		cout << "3)Просмотреть всех" << endl;
//		cout << "4)Выход" << endl;
//		cin >> choice;
//		switch (choice) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		default:cout << "Нет такой функции"<<endl;
//		}
//	}
//}

int authorized()
{
	string log, pass,temp;
	int lev;
	bool status=false;
	ifstream user("user.txt");
	cout << "Введите логин: ";
	std::getline(std::cin, log, '\n');
	if (user.is_open()) {
		while (!user.eof()) {
			user >> temp;
			if (temp == log) { status = true; break; }
			user >> temp;
			user >> lev;
		}
		user >> temp;
		user >> lev;
		if (status == false) { user.close(); return 0; }
		for (int i = 0; i < 3; i++) {
			cout << "Введите пароль: ";
			std::getline(std::cin,pass, '\n');
			if (pass == temp) { user.close(); return lev; }
			else if(i<2)cout << "Пароль введен неверно"<<endl;
			else cout << "Ошибка авторизации" << endl;
		}
		user.close();
	}
	return 0;
}

int check_int(int choice, int max_numb)
{
	while (!(std::cin >> choice) || (std::cin.peek() != '\n') || (choice < 0) || (choice > max_numb))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Повторите ввод!" << std::endl;
	}
	return choice;
}

//void menu(int level)
//{
//	int i = 1;
//	cout << "\tМеню" << endl;
//	if (level == 0) {
//		cout << "1)Просмотр всех рейсов" << endl;
//		cout << "2)Найти рейс" << endl;
//		cout << "2)Выход" << endl;
//	}
//	else{
//		switch (level) {
//		case 3:
//			cout <<i++<< ")Добавить учетную запись(сотрудника)" << endl;
//			cout << i++ << ")Удалить учетную запись(сотрудника)" << endl;
//			cout << i++ << ")Измениить уровень доступа" << endl;
//		case 2:
//			cout << i++ << ")Добавить рейс" << endl;
//			cout << i++ << ")Удалить рейс" << endl;
//		case 1:
//			cout << i++ << ")Просмотр всех рейсов" << endl;
//			cout << i++ << ")Отфильтровать рейсы" << endl; //1) по дате вылета, 2) по пункту назначения, 3)по марке самолета
//			cout << i++ << ")Найти рейс" << endl; ////1) по дате вылета, 2) по пункту назначения, 3)по марке самолета
//			cout << i++ << ")Забронировать билет" << endl;
//			cout << i++ << ")Освободить билет" << endl; // снять бронирование
//			cout << i++ << ")Изменить данные билета" << endl;
//		}
//		cout << i++ << ")Выход" << endl;
//	}
//}

void menu(int level)
{
	int i = 1;
	cout << "\tМеню" << endl;
	if (level>=0) {
		cout << i++ << ")Просмотр всех рейсов" << endl;
		cout << i++ << ")Найти рейс" << endl;
		cout << i++ << ")Отфильтровать рейсы" << endl; //1) по дате вылета, 2) по пункту назначения, 3)по марке самолета
		if (level >=1) {
			cout << i++ << ")Забронировать билет" << endl;
			cout << i++ << ")Освободить билет" << endl; // снять бронирование
			cout << i++ << ")Изменить данные билета" << endl;
			if (level >=2) {
				cout << i++ << ")Добавить рейс" << endl;
				cout << i++ << ")Удалить рейс" << endl;
				if (level == 3) {
					cout << i++ << ")Добавить учетную запись(сотрудника)" << endl;
					cout << i++ << ")Удалить учетную запись(сотрудника)" << endl;
					cout << i++ << ")Измениить уровень доступа" << endl;
				}
			}
		}
	}
		cout << i++ << ")Выход" << endl;
}