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
	if (this->rooms == nullptr) // �������� ���� �� ���� ���� ������� �� Flat
	{
		this->rooms = new Room[1]; // ������� ������ ������ �� ����� �������
		rooms[0].rewrite(r);	// ��� 0 �������� ���������� ������ �������
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
// ������ ��� ���� ��������
void Flat::setPrice(int price)
{
	if (!price)
	{
		cout << "���������� ���� �������� -> ";
		cin >> price;
		this->price = price;
		return;
	}
	this->price = price;
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
// ������ ��� ��������� ��� � ���-�� ������
int Flat::getFlatCntRooms() const
{
	return cntRooms;
}
// ����� ��� �������� ��������� �� ��������  � ������ ���� (����, ����, �������������)
void Flat::compareCntRooms(Flat const &obj2) const
{
	if (this->cntRooms == obj2.cntRooms)
		cout << "\n ��������� �������� ���������� - ���������� ���-�� ������ \n\n";
	else cout << "\n ��������� �������� ������� ���� - ������ ���-�� ������ \n\n";
}
// ����� ��� �������� ��������� ��������  �������
void Flat::compareCntFlatsArea(Flat const &obj2) const
{
	if (this->getFlatArea() == obj2.getFlatArea())
		cout << "\n ��������� �������� ����� ���������� ������� \n\n";
	else
	{
		int dif = this->getFlatArea() - obj2.getFlatArea();
		if (dif>0)	cout << "\n ������� � �������� ��� ��������� ������ �� " << dif << " ��.�. \n\n";
		else cout << "\n ������� � �������� ��� ��������� ������ �� " << dif*(-1) << " ��.�. \n\n";
	}
}
// ����� ��� ��������� ���� �������
void Flat::compareFlatsPrice(Flat const & obj2) const
{
	if (this->price == obj2.price)
		cout << "\n ��������� �������� ����� ���������� ������� \n\n";
	else
	{
		int dif = this->price - obj2.price;
		if (dif > 0)	cout << "\n ���� �������� ��� ��������� ������ �� " << dif << " �.���. \n\n";
		else cout << "\n ���� �������� ��� ��������� ������ �� " << dif * (-1) << " �.���. \n\n";
	}
}
// ����� ��� ����������� �������� Flat
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
// ����� ������ ���������� � ��������
void Flat::info() 
{
	cout<< "\n ��������� �������� ---- " << this->price
		<< "\n ������� �������� ------ " << this->getFlatArea()
		<< "\n ���-�� ������ --------- " << this->cntRooms
		
		<< "\n\n �������:\n";
	for (size_t i = 0; i < cntRooms; i++)
	{
		rooms[i].info(); // ����� ������ ���������� � �������
	}
}
Flat::~Flat()
{
	delete[] rooms;
}

