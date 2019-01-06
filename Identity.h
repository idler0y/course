#pragma once
#include"pch.h"

/////////////////		Identity		////////////////////

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(const Date&);
	void setDate();
	void showDate();
	friend ostream& operator<<(ostream& out, Date loc);
	friend istream& operator>>(istream& in, Date& loc);
};

class person {
protected:
	string name;
	string surname;
	string patronymic;
	Date birthday;
public:
	person();
	string getname();
	string getsurname();
	string getpatronymic();
	void show_date();
	void set();
};


class employee :public person{
private:
	string login;
	string password;
	int access_level;
public:
	employee();
	employee(int);
	//void encpryption();
	//void decipher();
	void setlogin(string);
	void setpassword(string);
	int getlevel();
	string getlogin();
	string getpassword();
};

int authorized();