#pragma once
#include "Room.h"


// конструктор по умолчанию
Room::Room()
{
	cout << "Room - Конструктор по умолчанию \n";
	this->name = new char[strlen("hall") + 1];
	strcpy_s(this->name, strlen("hall") + 1, "hall");
	this->area = 20;
}

// конструктор с параметрами
Room::Room(const char *name, int area) 
{

	cout << "Room - Конструктор с параметрами \n";
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->area = area;
}

// конструктор копирования объекта
Room::Room(const Room &obj) 
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

// сеттер названия комнаты и площади
void Room::setNameArea()
{
	char entName[30];
	cout << "\nВведите название комнаты -> ";
	cin >> entName;
	cout << "\nВведите площадь комнаты -> ";
	cin >> this->area;
	cout << "\n\n";
	
	cout<<strnlen_s(entName, 1000);
	cout << strlen(entName)<<"\n\n";
	if (this->name!= nullptr) delete[] this->name;
	int x = strlen(entName);
	this->name = new char[++x];
	cout <<"Длина имени"<< strlen(this->name) << endl;
	strcpy_s(this->name, x, entName);
	cout << name;
}

// геттер информации о названии комнаты
const char* Room::getName()const 
{ return name; }

// геттер информации о площади комнаты
int Room::getArea()const 
{ return area; }

// метод перезаписи информации о комнате
void Room::rewrite(const Room &p) 
{
	if (strlen(this->name) != strlen(p.name))  // если длина имени комнаты не равна длине имени комнаты из объекта комната
	{
		if(this->name!=nullptr) delete[]this->name;	// очищаем массив имени комнаты
		this->name = new char[strlen(p.name) + 1]; // выделяем динамическую память под массив размером названия длины комнаты + /0
	}
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
	this->area = p.area;
}

// деструктор
Room::~Room()
{
	delete[]this->name; // освобождаем динамическую память
}


