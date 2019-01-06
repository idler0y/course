#include"Identity.h"
#include"pch.h"

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(const Date &prev)
{
	this->day = prev.day;
	this->month = prev.month;
	this->year = prev.year;
}

void Date::setDate()
{
	int change;
	cout << "Введите дату(в формате дд.мм.гг): ";
	cin >> *(this);
	do {
		change = 0;
		if (this->month <= 0) { change++; this->month = 1; }
		else if (this->month > 12) {
			change++;
			this->year += (this->month / 12);
			this->month %= 12;
		}
		if (this->day <= 0) { change++; this->day = 1; }
		else if (((this->month % 2 == 1 && this->month < 8) || (this->month >= 8 && this->month < 13 && this->month % 2 == 0)) && this->day > 31) {
			change++;
			this->month += this->day / 31;
			this->day %= 31;
		}
		else if (this->month == 2 && this->day > 28) {
			change++;
			this->month += this->day / 28;
			this->day %= 28;
		}
		else if (this->day > 30) {
			change++;
			this->month += this->day / 30;
			this->day %= 30;
		}
		if (this->year > 2018 || this->year < 1900) {
			change++;
			this->year = 1991;
		}
	} while (change != 0);
}

void Date::showDate()
{
	cout << "Дата рождения: " << *(this);
}

ostream& operator<<(ostream& out, Date loc)
{
	out << loc.day << '.' << loc.month << '.' << loc.year << endl;
	return out;// TODO: вставьте здесь оператор return
}

istream& operator>>(istream& in, Date& loc)
{
	char buff[100], num[100];
	int convert, flag = 1;
	in.sync();
	//in.getline(buff, 100);
	in >> buff;

	int i = 0, j = 0;
	do {
		if ((int)buff[i] >= 48 && (int)buff[i] <= 57)
			num[j] = buff[i];
		else {
			j = -1;
			convert = atoi(num);
			switch (flag) {
			case 1:loc.day = convert; break;
			case 2:loc.month = convert; break;
			case 3:loc.year = convert; break;
			default: return in;
			}
			flag++;
		}
		i++; j++;
	} while (i < strlen(buff) + 1);
	return in;// TODO: вставьте здесь оператор return
}

person::person()
{
	name = "N/A";
	surname = "N/A";
	patronymic = "N/A";
}

string person::getname()
{
	return name;
}

string person::getsurname()
{
	return surname;
}

string person::getpatronymic()
{
	return patronymic;
}

void person::show_date()
{
	birthday.showDate();
}

void person::set()
{
	cout << "Имя: ";
	cin >> name;
	cout << "\nФамилия: ";
	cin >> surname;
	cout << "\nОтчество: ";
	cin >> patronymic;
	cout << "\nДата рождения(в формате дд.мм.гг): ";
	cin >> birthday;
}

employee::employee():access_level(0)
{
	login = "N/A";
	password = "N/A";
}

employee::employee(int level):person()
{
	cout << "Введите логин: ";
	cin >> login;
	cout << "\nВведите пароль: ";
	cin >> password;
	person::set();
	if (level < 0 || level>3)access_level = 1;
	else access_level = level;
}

//void employee::encpryption()
//{
//	for (int i = 0; i < login.length(); i++) {
//		login.at[i]+=2;
//	}
//	for (int i = 0; i < password.length(); i++) {
//		password.at[i] += 2;
//	}
//}
//
//void employee::decipher()
//{
//	for (int i = 0; i < login.length(); i++) {
//		login.at[i] -= 2;
//	}
//	for (int i = 0; i < password.length(); i++) {
//		password.at[i] -= 2;
//	}
//}

void employee::setlogin(string log)
{
	login = log;
}

void employee::setpassword(string pass)
{
	password = pass;
}

int employee::getlevel()
{
	return access_level;
}

string employee::getlogin()
{
	return login;
}

string employee::getpassword()
{
	return password;
}

