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

// конструктор копирования
void Flat::addRoom(const Room &r) {
	if (this->rooms == nullptr) {

		this->rooms = new Room[1];

		rooms[0].rewrite(r);
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
int Flat::getFlatArea() const 
{
	int area = 0;
	for (size_t i = 0; i < cntRooms; i++)
	{
		area += rooms[i].getArea();
	}
	return area;
}
void Flat::info() 
{
	cout<< "\n Стоимость квартиры ---- " << this->price
		<< "\n Площадь квартиры ------ " << this->getFlatArea()
		<< "\n Кол-во комнат --------- " << cntRooms
		
		<< "\n\n Комнаты:\n";
	for (size_t i = 0; i < cntRooms; i++)
	{
		rooms[i].info();
	}
}
Flat::~Flat()
{
}

