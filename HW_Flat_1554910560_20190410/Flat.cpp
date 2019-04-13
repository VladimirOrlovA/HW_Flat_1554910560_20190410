#pragma once
#include "Flat.h"

// ����������� �� ���������
Flat::Flat()
{
	this->price = 150;
	this->rooms = nullptr;
	this->cntRooms = 0;
}

// ����������� � ����������
Flat::Flat(int price)
{
	this->price = price;
	this->rooms = nullptr;
	this->cntRooms = 0;
}

// ����������� ����������� ������� ������ Room
void Flat::addRoom(const Room &r) 
{
	if (this->rooms == nullptr) 
	{
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
// ������ ��� ������� - ������ ��������� ������� �������� - ������� ������������ �������� ������
int Flat::getFlatArea() const 
{
	int area = 0;
	for (size_t i = 0; i < cntRooms; i++)
	{
		area += rooms[i].getArea(); // ����� ������ ��������� ������� �������
	}
	return area;
}
// ����� ������ ���������� � ��������
void Flat::info() 
{
	cout<< "\n ��������� �������� ---- " << this->price
		<< "\n ������� �������� ------ " << this->getFlatArea()
		<< "\n ���-�� ������ --------- " << cntRooms
		
		<< "\n\n �������:\n";
	for (size_t i = 0; i < cntRooms; i++)
	{
		rooms[i].info(); // ����� ������ ���������� � �������
	}
}
Flat::~Flat()
{
}

