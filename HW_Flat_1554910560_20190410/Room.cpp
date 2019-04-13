#pragma once
#include "Room.h"


// конструктор по умолчанию
Room::Room()
{
	cout << "Конструктор по умолчанию \n";
	this->name = new char[strlen("hall") + 1];
	strcpy_s(this->name, strlen("hall") + 1, "hall");
	this->area = 20;
}

// конструктор с параметрами
Room::Room(const char *name, int area) 
{
	cout << "Конструктор с параметрами \n";
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->area = area;
}

// конструктор копирования
Room::Room(const Room&obj) 
{
	this->area = obj.area;
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

// метод вывода информации о комнате
void Room::info() const
{
	cout<< "\n Назначение комнаты \t" << this->name
		<< "\n Площадь \t\t" << this->area << endl;
}

// сеттер названия комнаты и площадь
void Room::setNameArea()
{
	cout << "Введите название комнаты -> ";
	cin >> this->name;
	cout << "Введите площадь комнаты -> ";
	cin >> this->area;
	
	Room::Room(name, area);
}

// геттер информации о названии комнаты
const char* Room::getName()const 
{ return name; }

// геттер информации о площади комнаты
int Room::getArea()const 
{ return area; }

// метод перезаписи информации о комнате
void Room::rewrite(const Room&p) {
	this->area = p.area;
	if (strlen(this->name) != strlen(p.name)) {
		delete[]this->name;
		this->name = new char[strlen(p.name) + 1];
	}
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
}

// деструктор
Room::~Room()
{
	delete[]this->name; // освобождаем динамическую память
}


