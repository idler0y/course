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
//		cout << "1)������� �������" << endl;
//		cout << "2)������� �������" << endl;
//		cout << "3)����������� ����" << endl;
//		cout << "4)�����" << endl;
//		cin >> choice;
//		switch (choice) {
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		default:cout << "��� ����� �������"<<endl;
//		}
//	}
//}

int authorized()
{
	string log, pass,temp;
	int lev;
	bool status=false;
	ifstream user("user.txt");
	cout << "������� �����: ";
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
			cout << "������� ������: ";
			std::getline(std::cin,pass, '\n');
			if (pass == temp) { user.close(); return lev; }
			else if(i<2)cout << "������ ������ �������"<<endl;
			else cout << "������ �����������" << endl;
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
		std::cout << "��������� ����!" << std::endl;
	}
	return choice;
}

//void menu(int level)
//{
//	int i = 1;
//	cout << "\t����" << endl;
//	if (level == 0) {
//		cout << "1)�������� ���� ������" << endl;
//		cout << "2)����� ����" << endl;
//		cout << "2)�����" << endl;
//	}
//	else{
//		switch (level) {
//		case 3:
//			cout <<i++<< ")�������� ������� ������(����������)" << endl;
//			cout << i++ << ")������� ������� ������(����������)" << endl;
//			cout << i++ << ")��������� ������� �������" << endl;
//		case 2:
//			cout << i++ << ")�������� ����" << endl;
//			cout << i++ << ")������� ����" << endl;
//		case 1:
//			cout << i++ << ")�������� ���� ������" << endl;
//			cout << i++ << ")������������� �����" << endl; //1) �� ���� ������, 2) �� ������ ����������, 3)�� ����� ��������
//			cout << i++ << ")����� ����" << endl; ////1) �� ���� ������, 2) �� ������ ����������, 3)�� ����� ��������
//			cout << i++ << ")������������� �����" << endl;
//			cout << i++ << ")���������� �����" << endl; // ����� ������������
//			cout << i++ << ")�������� ������ ������" << endl;
//		}
//		cout << i++ << ")�����" << endl;
//	}
//}

void menu(int level)
{
	int i = 1;
	cout << "\t����" << endl;
	if (level>=0) {
		cout << i++ << ")�������� ���� ������" << endl;
		cout << i++ << ")����� ����" << endl;
		cout << i++ << ")������������� �����" << endl; //1) �� ���� ������, 2) �� ������ ����������, 3)�� ����� ��������
		if (level >=1) {
			cout << i++ << ")������������� �����" << endl;
			cout << i++ << ")���������� �����" << endl; // ����� ������������
			cout << i++ << ")�������� ������ ������" << endl;
			if (level >=2) {
				cout << i++ << ")�������� ����" << endl;
				cout << i++ << ")������� ����" << endl;
				if (level == 3) {
					cout << i++ << ")�������� ������� ������(����������)" << endl;
					cout << i++ << ")������� ������� ������(����������)" << endl;
					cout << i++ << ")��������� ������� �������" << endl;
				}
			}
		}
	}
		cout << i++ << ")�����" << endl;
}