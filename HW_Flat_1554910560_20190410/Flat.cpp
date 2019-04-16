#pragma once
#include "Flat.h"

// конструктор по умолчанию
Flat::Flat()
{
	this->price = 150;
	this->rooms = nullptr;
	this->cntRooms = 0;
}

// конструктор с параметром
Flat::Flat(int price)
{
	this->price = price;
	this->rooms = nullptr;
	this->cntRooms = 0;
}

// конструктор копирования объекта класса Room
void Flat::addRoom(const Room &r) 
{
	if (this->rooms == nullptr) // проверка есть ли хоть одна комната во Flat
	{
		this->rooms = new Room[1]; // создаем массив комнат из одной комнаты
		rooms[0].rewrite(r);	// для 0 элемента записываем объект комната
		cntRooms = 1;
		return;
	}
	Room *tmp = new Room[cntRooms + 1];
	for (size_t i = 0; i < cntRooms; i++)
		tmp[i].rewrite(rooms[i]);

	tmp[cntRooms].rewrite(r);
	delete[]rooms;
	rooms = tmp;
	cntRooms++;
}
// сеттер для цены квартиры
void Flat::setPrice(int price)
{
	if (!price)
	{
		cout << "Установите цену квартиры -> ";
		cin >> price;
		this->price = price;
		return;
	}
	this->price = price;
}
// геттер для площади - расчет суммарной площади квартиры - методом суммирования площадей комнат
int Flat::getFlatArea() const 
{
	int area = 0;
	for (size_t i = 0; i < cntRooms; i++)
	{
		area += rooms[i].getArea(); // вызов метода получения площади комнаты
	}
	return area;
}
// геттер для получения инф о кол-ве комнат
int Flat::getFlatCntRooms() const
{
	return cntRooms;
}
// метод для проверки относятся ли квартиры  к одному типу (одно, двух, трехкомнатная)
void Flat::compareCntRooms(Flat const &obj2) const
{
	if (this->cntRooms == obj2.cntRooms)
		cout << "\n Выбранные квартиры однотипные - одинаковое кол-во комнат \n\n";
	else cout << "\n Выбранные квартиры разного типа - разное кол-во комнат \n\n";
}
// метод для проверки равенства площадей  квартир
void Flat::compareCntFlatsArea(Flat const &obj2) const
{
	if (this->getFlatArea() == obj2.getFlatArea())
		cout << "\n Выбранные квартиры имеют одинаковую площадь \n\n";
	else
	{
		int dif = this->getFlatArea() - obj2.getFlatArea();
		if (dif>0)	cout << "\n Площадь в квартире для сравнения меньше на " << dif << " кв.м. \n\n";
		else cout << "\n Площадь в квартире для сравнения больше на " << dif*(-1) << " кв.м. \n\n";
	}
}
// метод для сравнения цены квартир
void Flat::compareFlatsPrice(Flat const & obj2) const
{
	if (this->price == obj2.price)
		cout << "\n Выбранные квартиры имеют одинаковую площадь \n\n";
	else
	{
		int dif = this->price - obj2.price;
		if (dif > 0)	cout << "\n Цена квартиры для сравнения меньше на " << dif << " т.дол. \n\n";
		else cout << "\n Цена квартиры для сравнения больше на " << dif * (-1) << " т.дол. \n\n";
	}
}
// метод для копирования объектов Flat
void Flat::copyFlats(Flat const & obj2)
{
	this->price = obj2.price;
	
	Room *tmp = new Room[obj2.getFlatCntRooms()];
	for (size_t i = 0; i < obj2.getFlatCntRooms(); i++)
	{
		tmp[i].rewrite(obj2.rooms[i]);
	}
	delete[]rooms;
	rooms = tmp;
	this->cntRooms = obj2.cntRooms;
}
// метод вывода информации о квартире
void Flat::info() 
{
	cout<< "\n Стоимость квартиры ---- " << this->price
		<< "\n Площадь квартиры ------ " << this->getFlatArea()
		<< "\n Кол-во комнат --------- " << this->cntRooms
		
		<< "\n\n Комнаты:\n";
	for (size_t i = 0; i < cntRooms; i++)
	{
		rooms[i].info(); // вызов метода информации о комнате
	}
}
Flat::~Flat()
{
	delete[] rooms;
}

