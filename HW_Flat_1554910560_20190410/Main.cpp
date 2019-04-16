#include"Flat.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Room hall("Зал", 40);
	//hall.info();
	//Room bedroom("Спальня", 25);
	//Room kitchen("Кухня", 25);
	//Room bathroom("Ванная", 5);

	Flat first;
	first.addRoom(hall);
	/*first.addRoom(bedroom);
	first.addRoom(kitchen);
	first.addRoom(bathroom);*/
	//first.setPrice(333);
	////first.info();
	//cout << endl<<endl;


	//Flat second;
	//second.addRoom(hall);
	//second.addRoom(bedroom);
	//second.addRoom(kitchen);
	////second.addRoom(bathroom);

	//cout << first.getFlatArea() << endl;
	//cout << second.getFlatArea() << endl;

	////Проверка метода - метод для проверки относятся ли квартиры  к одному типу(одно, двух, трехкомнатная)
	//first.compareCntRooms(second);

	////Проверка метода - метод для проверки равенства площадей  квартир
	//first.compareCntFlatsArea(second);

	////Проверка метода - метод для сравнения цены квартир
	//first.setPrice(100);
	//second.setPrice(200);
	//first.compareFlatsPrice(second);

	//Проверка метода - метод для копирования объектов Flat
	Flat copy;
	copy.info();
	copy.copyFlats(first);
	cout << "\nПосле копирования содержимое copy \n\n";
	copy.info();

	/*hall.setNameArea();
	hall.info();
	cout << endl << endl;*/

	system("pause");
}