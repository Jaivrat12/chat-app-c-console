#include "windows.h"

#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

#define CLS system("CLS")
#define PAUSE system("PAUSE")
#define X(n) _sleep(n * 1000)

// IMP NOTE: This "gotoxy()" needs "windows.h" library to be made!!!
static const COORD startCoords = {0,0};

int gotoxy(int x,int y) {

    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/*
Alternative gotoxy()...

// IMP NOTE: This "gotoxy()" needs "windows.h" library to be made!!!
void gotoxy(int x, int y) {

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD new = {x, y};
    SetConsoleCursorPosition(out, new);
}
*/
