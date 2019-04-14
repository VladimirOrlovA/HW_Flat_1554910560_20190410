#pragma once
#include "Room.h"


// ����������� �� ���������
Room::Room()
{
	cout << "Room - ����������� �� ��������� \n";
	this->name = new char[strlen("hall") + 1];
	strcpy_s(this->name, strlen("hall") + 1, "hall");
	this->area = 20;
}

// ����������� � �����������
Room::Room(const char *name, int area) 
{
	cout << "Room - ����������� � ����������� \n";
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->area = area;
}

// ����������� �����������
Room::Room(const Room &obj) 
{
	this->area = obj.area;
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

// ����� ������ ���������� � �������
void Room::info() const
{
	cout<< "\n ���������� ������� \t" << this->name
		<< "\n ������� \t\t" << this->area << endl;
}

// ������ �������� ������� � �������
void Room::setNameArea()
{
	/*char *entName;
	cout << "������� �������� ������� -> ";
	cin >> entName;
	cout << "������� ������� ������� -> ";
	cin >> this->area;
	
	if (strlen(this->name) != strlen(entName))
	{
		delete[] this->name;
		this->name = new char[strlen(entName) + 1];
	}
	strcpy_s(this->name, strlen(this->name) + 1, entName);*/

	//Room::Room(name, area);
}

// ������ ���������� � �������� �������
const char* Room::getName()const 
{ return name; }

// ������ ���������� � ������� �������
int Room::getArea()const 
{ return area; }

// ����� ���������� ���������� � �������
void Room::rewrite(const Room &p) 
{
	if (strlen(this->name) != strlen(p.name)) 
	{
		delete[]this->name;
		this->name = new char[strlen(p.name) + 1];
	}
	strcpy_s(this->name, strlen(p.name) + 1, p.name);
	this->area = p.area;
}

// ����������
Room::~Room()
{
	delete[]this->name; // ����������� ������������ ������
}


