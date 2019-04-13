#pragma once
#include "room.h"

class Flat 
{
	int price;
	Room *rooms;
	int cntRooms;
public:
	Flat();
	Flat(int price);
	void addRoom(const Room &r);
	int getFlatArea() const;
	void info();
	~Flat();
};
