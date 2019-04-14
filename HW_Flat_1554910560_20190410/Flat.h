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
	void setPrice(int price);
	int getFlatArea() const;
	int getFlatCntRooms() const;
	void compareCntRooms(Flat const &obj2) const;
	void compareCntFlatsArea(Flat const &obj2) const;
	void compareFlatsPrice(Flat const &obj2) const;
	void copyFlats(Flat const & obj2);
	void info();
	~Flat();
};
