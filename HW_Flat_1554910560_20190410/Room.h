#pragma once
#include <iostream>
#include <locale.h>
using namespace std;

class Room {
	char*name;
	int area;
public:
	Room();
	Room(const char*name, int area);
	Room(const Room&obj);
	void info()const;
	void setNameArea();
	const char* getName()const;
	int getArea()const;
	void rewrite(const Room &p);	
	~Room();
};