#include"Flat.h"

void main()
{
	setlocale(LC_ALL, "RUS");

	Room hall("���", 40);
	Room bedroom("�������", 25);
	Room kitchen("�����", 25);
	Room bathroom("������", 5);

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