#include"flight.h"
#include"pch.h"
///////////////////		FLIGHT		/////////////////////////

Time::Time() :hour(0), minute(0) {}

Time::Time(int hour, int minute) {
	if (minute < 0)minute = -minute;
	if (minute > 60) {
		hour += minute / 60;
		minute %= 60;
	}
	hour = hour < 0 ? -hour : hour;
	hour = hour > 24 ? hour % 24 : hour;
}

void Time::setTime() {
	cout << "Введите часы: ";
	cin >> hour;
	cout << "Введите минуты: ";
	cin >> minute;
	if (minute > 60) {
		hour += minute / 60;
		minute %= 60;
	}
	minute = minute > 0 ? minute : -60;
	hour = hour < 24 ? hour : hour % 24;
	hour = hour > 0 ? hour : -hour;
}


void Time::display() {
	cout << ((hour < 10) ? "0" : ""); cout << hour << ":";
	cout << ((minute < 10) ? "0" : ""); cout << minute;
}

fligth_number::fligth_number()
{
	number = 0;
	air_company[0] = '\0';
}

void fligth_number::show()
{
	cout << air_company << " " << number;
}

void fligth_number::set_flight_number()
{
	cout << "Инициал компании: ";
	gets_s(air_company);
	while (getchar() != '\n');
	cout << "Номер рейса: ";
	cin >> number;
}

plane::plane() :quantity_of_places(0)
{
	type = "N/A";
	model = "N/A";
}


string plane::get_type()
{
	return type;
}

string plane::getmodel()
{
	return model;
}

int plane::getquantity()
{
	return quantity_of_places;
}

//plane & plane::operator--()
//{
//	quantity_of_places--;
//	return *this;// TODO: вставьте здесь оператор return
//}

//plane & plane::operator++()
//{
//	quantity_of_places++;
//	return *this;// TODO: вставьте здесь оператор return
//}

void plane::set_plane()
{
	vector<plane> tmp;
	plane temp;
	int choice;
	ifstream fin("plane.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> temp.type;
			fin >> temp.model;
			fin >> temp.quantity_of_places;
			tmp.push_back(temp);
		}
	}
	fin.close();
	for (int i = 0; i < tmp.size(); i++) {
		cout << i << ")" << tmp[i].type << " " << tmp[i].model << endl;
	}
	cin >> choice;
	if (choice > 0 && choice < tmp.size()) {
		this->type = tmp[choice].type;
		this->model = tmp[choice].model;
		this->quantity_of_places = tmp[choice].quantity_of_places;
	}
}


ticket::ticket()
{
	passenger.set();
	set_gate();
}

void ticket::display_gate()
{
	cout << terminal << gate;
}

void ticket::set_gate()
{
	cout << "Терминал: ";
	cin >> terminal;
	cout << "Платформа: ";
	cin >> gate;
}

void ticket::setperson()
{
	passenger.set();
}

void ticket::show_name()
{
	cout <<passenger.getname();
}

void ticket::show_surname()
{
	cout<< passenger.getsurname();
}

void ticket::show_patronymic()
{
	cout << passenger.getpatronymic();
}


flight::flight()
{
	destination = "N/A";
}

string flight::getdestination()
{
	return destination;
}

void flight::setdirection()
{
	cout << "Куда/Откуда летит самолет: ";
	cin >> destination;
}

void flight::setflight()
{
	int choice;
	flight_figure.set_flight_number();
	plane_info.set_plane();
	cout << "Направление: " << endl;
	cout << "1)В этот аэропорт\n2)Из этого аэропорта\n3)Чартер";
	cin >> choice;
	if (choice == 1) to_from = to;
	if (choice == 2) to_from = from;
	if (choice == 2) to_from = via;
	cout << "Дата(в формате дд.мм.гг): ";
	cin >> boarding_date;
	boarding_time.setTime();
}

void flight::displayPassengers()
{
	cout << setw(15) << "Имя";
	cout << setw(15) << "Фамилия";
	cout << setw(15) << "Отчество";
	cout << setw(13) << "Дата рождения";
	for (int i = 0; i < tickets.size(); i++) {
		tickets[i].show_name();
		tickets[i].show_surname();
		tickets[i].show_patronymic();
	}
}
