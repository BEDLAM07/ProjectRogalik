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
	void setFace(int pface)
	{
		face = pface;
	}

	// создаем метод сетерра (метод который записывает информацию в переменные класса)
	void setPosition(int px, int py) // создаем функцию, назначение которой запись значений в переменные
	{
		// проверка размеров экрана (валидация переменных)
		if (px >= 0 && px <= 79)
		{
			x = px;
			
		}
		if (py >= 0 && py <= 24)
		{
			y = py;
		}
		
	}
	//создаем метод отображения перса на экране
	void show()
	{
		gotoxy(x, y);
		cout << (char)face;// преобразовываем переменную к символьному типу
	};

	// метод изменяет координаты
	void move(int ch)
	{
		switch (ch)
		{
		case 77: // стрелка вправо
			x++;
			break;
		case 72: // стрелка вверх
			y--;
			break;
		case 80: // стрелка вниз
			y++;
			break;
		case 75: // стрелка влево
			x--;
			break;
		}
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	// создаем экземпляр класса
	CHero hero; // переменная
	
	// задаем координаты перса и отображаем на экране
	hero.setPosition(5, 3);
	hero.setFace(1);

	int ch;
	
	while (true)
	{
		ch = _getch();

		hero.move(ch);

		system("cls");

		hero.show();
	}
	_getch();
	return 0;
}