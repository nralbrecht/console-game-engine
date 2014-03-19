#include "Map.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

/*
TO-DO:
- funktion/class drawRoom(int eckeObenL, int eckeUntenR);
- klasse player
- klasse npcs
- klasse 
*/

using namespace std;

void setCursorXY(int x,int y);

void main()
{
	Map m(80, 24, ' ', '@');
	m.setPoint(m.getPos(), m.getSymbolPlayer());

	m.setStatus("Wilkommen zu meinem Spiel!");

	while (true)
	{
		m.cls();
		m.printMap();
		setCursorXY(m.getStatusSize(), 0);

		int input = _getch();
		switch (input)
		{
		case 224:
			input = _getch();
			switch (input)
			{
			case 72://up
				if(m.getPos() <= 79) break;
				m.up();
				break;
			case 75://left
				if(m.getPos() <= 0) break;
				m.left();
				break;
			case 77://right
				if(m.getPos() > m.Breite()*m.Hoehe() - 2) break;
				m.right();
				break;
			case 80://down
				if(m.getPos() >= m.Breite() * m.Hoehe() - m.Breite()) break;
				m.down();
				break;
			default:
				break;
			}
			break;
		case 'w':
			if(m.getPos() <= 79) break;
			m.up();
			break;
		case 'a':
			if(m.getPos() <= 0) break;
			m.left();
			break;
		case 's':
			if(m.getPos() >= m.Breite() * m.Hoehe() - m.Breite()) break;
			m.down();
			break;
		case 'd':
			if(m.getPos() > m.Breite()*m.Hoehe() - 2) break;
			m.right();
			break;
		default:
			break;
		}
		if(m.getPos() < 0) m.setPos(m.getPos() + m.Hoehe());
		else if(m.getPos() > m.Breite()*m.Hoehe()) m.setPos(m.getPos() - m.Hoehe());

		
	}

	_getch();
}

void setCursorXY(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}