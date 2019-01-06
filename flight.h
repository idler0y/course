#pragma once
#include"pch.h"
/////////////////////		FLIGHT		////////////

enum direction { to, from, via };

class Time {
	int hour;
	int minute;
public:
	Time();
	Time(int, int);
	void setTime();
	void display();
};

class fligth_number {
public:
	char air_company[3];
	int number;
	fligth_number();
	void show();
	void set_flight_number();
};

class plane {
	string type;
	string model;
	int quantity_of_places;
public:
	plane();
	string get_type();
	string getmodel();
	int getquantity();
	//plane& operator--();
	//plane& operator++();
	void set_plane();
};

class ticket {
	person passenger;
	char terminal;
	unsigned gate;
public:
	ticket();
	void display_gate();
	void set_gate();
	void setperson();
	void show_name();
	void show_surname();
	void show_patronymic();
	friend void person::show_date();
};

class flight {
	fligth_number flight_figure;
	direction to_from;
	string destination;
	Date boarding_date;
	Time boarding_time;
	plane plane_info;
	vector<ticket> tickets;
	float price;
public:
	flight();
	string getdestination();
	void setdirection();
	void setflight();
	void displayPassengers();
};
