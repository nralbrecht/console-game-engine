#include "Map.h"
#include <string>
#include <Windows.h>

void Map::up()
{
	karte[player] = symbolEmpty;
	player = player - breite;
	karte[player] = symbolPlayer;
	setStatus("Up");
}

void Map::left()
{
	karte[player] = symbolEmpty;
	player = player - 1;
	karte[player] = symbolPlayer;
	setStatus("Left");
}

void Map::right()
{
	karte[player] = symbolEmpty;
	player = player + 1;
	karte[player] = symbolPlayer;
	setStatus("Right");
}

void Map::down()
{
	karte[player] = symbolEmpty;
	player = player + breite;
	karte[player] = symbolPlayer;
	setStatus("Down");
}

void Map::printMap()
{
	sprintf_s(buffer, "%s\n%s", status.c_str(), karte.c_str());
	fprintf(stdout, "%s", buffer);
}

void Map::setPoint(int pos, char foo)
{
	karte[pos] = foo;
}

char Map::getPoint(int pos)
{
	return karte[pos];
}

void Map::setStatus(std::string status)
{
	this->status.clear();
	this->status = status;
}

int Map::getStatusSize()
{
	return status.size();
}

int Map::Breite()
{
	return breite;
}

int Map::Hoehe()
{
	return hoehe;
}

char Map::getSymbolPlayer()
{
	return symbolPlayer;
}

char Map::getSymbolEmpty()
{
	return symbolEmpty;
}

int Map::getPos()
{
	return player;
}

void Map::setPos(int foo)
{
	player = foo;
}

void Map::cls()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets the window handle
    COORD coord = {0, 0}; // sets coordinates to 0,0
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi); // gets the buffer info (screen)
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);// fill all characters as ' ' (empty the screen)
    SetConsoleCursorPosition(hStdOut, coord); // resets the cursor position
}

Map::Map(int breite, int hoehe , char empty, char player)
	:breite(breite), hoehe(hoehe), symbolEmpty(empty), symbolPlayer(player) , player(920)
{
	for (int i = 0; i < hoehe*breite; i++)
	{
		Map::karte.push_back(symbolEmpty);
	}
}

Map::~Map(void)
{
}
