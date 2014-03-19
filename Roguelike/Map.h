#pragma once
#include <string>

class Map
{
private:
	std::string karte; //Map
	std::string status;
	char buffer[2000];
	int player;
	int breite;
	int hoehe;
	char symbolPlayer;
	char symbolEmpty;
public:
	void up();
	void left();
	void right();
	void down();

	void printMap();
	void setPoint(int pos, char foo);
	char getPoint(int pos);
	void setStatus(std::string foo);
	int getStatusSize();
	char getSymbolPlayer();
	char getSymbolEmpty();
	int Breite();
	int Hoehe();
	int getPos();
	void setPos(int foo);
	
	void cls();
	
	Map(int breite, int hoehe , char empty, char player);
	~Map(void);
};