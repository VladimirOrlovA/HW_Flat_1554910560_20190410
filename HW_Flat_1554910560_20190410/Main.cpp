#include"Flat.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Room hall("���", 40);
	//hall.info();
	//Room bedroom("�������", 25);
	//Room kitchen("�����", 25);
	//Room bathroom("������", 5);

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

	////�������� ������ - ����� ��� �������� ��������� �� ��������  � ������ ����(����, ����, �������������)
	//first.compareCntRooms(second);

	////�������� ������ - ����� ��� �������� ��������� ��������  �������
	//first.compareCntFlatsArea(second);

	////�������� ������ - ����� ��� ��������� ���� �������
	//first.setPrice(100);
	//second.setPrice(200);
	//first.compareFlatsPrice(second);

	//�������� ������ - ����� ��� ����������� �������� Flat
	Flat copy;
	copy.info();
	copy.copyFlats(first);
	cout << "\n����� ����������� ���������� copy \n\n";
	copy.info();

	/*hall.setNameArea();
	hall.info();
	cout << endl << endl;*/

	system("pause");
}