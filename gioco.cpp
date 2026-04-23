#include <iostream>
#include <windows.h>
using namespace std;

// dimensioni del mondo
const int LARGHEZZA = 80;
const int ALTEZZA = 40;

// ogni pixel di gioco usa 2 celle console
const int COLONNE = LARGHEZZA * 2;
const int RIGHE = ALTEZZA;

const int SPRITE_SIZE = 16;
const int TRASPARENTE = -1;

// palette 16 colori console
const int NERO = 0;
const int BLU = 1;
const int VERDE = 2;
const int CIANO = 3;
const int ROSSO = 4;
const int MAGENTA = 5;
const int GIALLO = 6;
const int GRIGIO = 7;
const int GRIGIO_SCURO = 8;
const int BLU_CHIARO = 9;
const int VERDE_CHIARO = 10;
const int CIANO_CHIARO = 11;
const int ROSSO_CHIARO = 12;
const int MAGENTA_CHIARO = 13;
const int GIALLO_CHIARO = 14;
const int BIANCO = 15;

CHAR_INFO buffer[COLONNE * RIGHE];
HANDLE hConsole;

// sprite = piccola matrice di colori
struct Sprite {
    int image[SPRITE_SIZE][SPRITE_SIZE];
    int larghezza;
    int altezza;
};

// disegna un pixel
void setPixel(int x, int y, int colore) {
    if (x < 0 || x >= LARGHEZZA || y < 0 || y >= ALTEZZA) return;

    int i = y * COLONNE + x * 2;
    WORD attr = colore << 4;

    buffer[i].Char.UnicodeChar = L' ';
    buffer[i].Attributes = attr;
    buffer[i + 1].Char.UnicodeChar = L' ';
    buffer[i + 1].Attributes = attr;
}

void presenta() {
    COORD dim = { COLONNE, RIGHE };
    COORD zero = { 0, 0 };
    SMALL_RECT rect = { 0, 0, COLONNE - 1, RIGHE - 1 };
    WriteConsoleOutputW(hConsole, buffer, dim, zero, &rect);
}

// prepara la console
void setupConsole() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT tiny = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &tiny);

    COORD size = { COLONNE, RIGHE };
    SetConsoleScreenBufferSize(hConsole, size);

    SMALL_RECT win = { 0, 0, COLONNE - 1, RIGHE - 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &win);

    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(hConsole, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &ci);
}

