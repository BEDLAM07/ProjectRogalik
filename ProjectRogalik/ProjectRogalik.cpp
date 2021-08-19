#include <iostream>
#include <windows.h> // библиотека для подключения оператора sleep
#include <time.h>
#include <conio.h> // библиотека необходимая для подключения оператора _getch();
using namespace std;

using namespace std;

void gotoxy(int x, int y)
{
	COORD Coor;
	Coor.X = x; Coor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
}

//класс
class CHero
{

private:
	int x, y; //координаты положения персонажа на экране
	int face; // отображение персонажа на экране

public:
	//создаем метод отображения перса на экране
	void show()
	{
		x = 5;
		y = 3;
		gotoxy(x, y);
		cout << face;
	};
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	// создаем экземпляр класса
	CHero hero; // переменная

	hero.show();

	_getch();
	return 0;
}