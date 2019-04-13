#include"Flat.h"

void main()
{
	setlocale(LC_ALL, "RUS");

	Room hall("Зал", 40);
	Room bedroom("Спальня", 25);
	Room kitchen("Кухня", 25);
	Room bathroom("Ванная", 5);

	Flat first;
	first.addRoom(hall);
	first.addRoom(bedroom);
	first.addRoom(kitchen);
	first.addRoom(bathroom);

	cout << endl<<endl;

	//hall.setNameArea();
	//hall.info();

	first.info();

	cout << endl << endl;

	system("pause");
}