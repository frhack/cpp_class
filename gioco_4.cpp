#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <mmsystem.h>
using namespace std;
using namespace std::chrono;

bool DEBUG = false;

const int FPS=60;
const float DT=1.0f/FPS;
const microseconds DT_MICROSECONDS(1000000/FPS);

// dimensioni del mondo
const int LARGHEZZA=186;
const int ALTEZZA=140;
const int Y_SUOLO= -ALTEZZA/2 + 30;

// ogni pixel di gioco usa 2 celle console
const int COLONNE = LARGHEZZA * 2;
const int RIGHE = ALTEZZA;

const int SPRITE_SIZE = 32;
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
const int COLORE_DEBUG = MAGENTA_CHIARO;

CHAR_INFO buffer[COLONNE * RIGHE];
HANDLE hConsole;

// sprite = piccola matrice di colori
struct Sprite {
    int image[SPRITE_SIZE][SPRITE_SIZE];
    int larghezza;
    int altezza;
    double x, y;
    double vx, vy;
};

// disegna un pixel
void setPixel(int x, int y, int colore) {
	int sx = x + LARGHEZZA/2;
	int sy = ALTEZZA/2 - y;
    if (sx < 0 || sx >= LARGHEZZA || sy < 0 || sy >= ALTEZZA) return;
    int i = sy * COLONNE + sx * 2;
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

void creaQuadrato(Sprite& s, int colore) {
	s.larghezza = 16;
	s.altezza = 16;
	for(int y = 0; y < SPRITE_SIZE; y++){
		for(int x = 0; x < SPRITE_SIZE; x++){
			s.image[y][x] = colore;
		}
	}
}

//sfondo: cielo,erba,terra
void disegnaSfondo(){
	for(int y = -ALTEZZA/2; y < ALTEZZA/2; y++){
		int colore;
		if (y > Y_SUOLO) colore = CIANO_CHIARO;
		else if (y == Y_SUOLO) colore = VERDE;
		else colore = GIALLO;
		for (int x = -LARGHEZZA/2; x < LARGHEZZA/2; x++){
			setPixel(x, y, colore);
		}
	}
}

// disegna uno sprite
void disegnaSprite (const Sprite& s){
	int x0=(int)s.x;
	int y0=(int)s.y;
	for(int y = 0; y <s.altezza; y++){
		for(int x = 0; x < s.larghezza; x++){
			int colore = s.image[y][x];
			if(colore == TRASPARENTE){
				if (!DEBUG) continue;
				colore = COLORE_DEBUG;
			}
			setPixel(x0 + x, y0+ (s.altezza - 1 - y), colore);
			
		}
	}
}

void creaDino(Sprite& s, int colore) {
	string righe[] = {
	"..........########.",
	".........##########",
	".........##*#######",
	".........##########",
	".........##########",
	".........#####.....",
	".........########..",
	"#.......#####......",
	"#......######......",
	"##...##########....",
	"###.#########.#....",
	"#############......",
	"#############......",
	".###########.......",
	"..##########.......",
	"...########........",
	"....###.##.........",
	"....##...#.........",
	"....#....#.........",
	"....##...##........"
	};
	
	s.larghezza=19;
	s.altezza=20;
	
	for(int y = 0; y < s.altezza; y++) {
		for(int x = 0; x < s.larghezza; x++){
			if(righe[y][x] == '#') {
				s.image[y][x] = colore;
			}else if(righe[y][x] == '.') {
				s.image[y][x] = TRASPARENTE;	
			}else if(righe[y][x] == '*') {
				s.image[y][x] = ROSSO;	
			} 
		} 
	}
}

HWND focusTerminal() {
    HWND hwnd = FindWindowW (L"CASCADIA_HOSTING_WINDOW_CLASS", nullptr);
    if (!hwnd) {
        std::cerr << "Windows Terminal non trovato\n";
        return nullptr;
    }
    if (IsIconic(hwnd)) ShowWindow(hwnd, SW_RESTORE);
    SetForegroundWindow(hwnd);
    Sleep(150);
    return hwnd;
}

// Simula la pressione di un tasto (eventualmente insieme a CTRL).
bool sendKey(WORD vk, bool ctrl = false) {
    INPUT input[4] = {};
    int n = 0;
    auto addKey = [&](WORD key, DWORD flags = 0) {
        input[n].type = INPUT_KEYBOARD;
        input[n].ki.wVk = key;
        input[n].ki.dwFlags = flags;
        n++;
    };
    if (ctrl) addKey(VK_CONTROL);
    addKey(vk);
    addKey(vk, KEYEVENTF_KEYUP);
    if (ctrl) addKey(VK_CONTROL, KEYEVENTF_KEYUP);
    return SendInput(n, input, sizeof(INPUT)) == n;
}

// Preme CTRL + - per "times" volte (rimpicciolisce il carattere).
bool zoomOutTerminal(int times) {
    if (!focusTerminal()) return false;
    for (int i = 0; i < times; i++) {
        if (!sendKey(VK_OEM_MINUS, true)) return false;
        Sleep(50);
    }
    return true;
}

// Preme F11 (mette il terminale a tutto schermo).
bool fullscreenTerminal() {
    if (!focusTerminal()) return false;
    return sendKey(VK_F11);
}


int main(){
	timeBeginPeriod(1);
	fullscreenTerminal();
	zoomOutTerminal(8);
	setupConsole();
	
	Sprite dino, cactus;
	creaDino(dino, GRIGIO_SCURO);
	creaQuadrato(cactus, VERDE);
	
	dino.x= -20; dino.y= Y_SUOLO +1;
	dino.vx= 0; dino.vy= 0;
	
	cactus.x=30; cactus.y= Y_SUOLO +1;
	cactus.vx=-60;
	cactus.vy=0;
	auto prossimoFrame = steady_clock::now();
	while (true){
		cactus.x += cactus.vx * DT;
		if (cactus.x + cactus.larghezza < -LARGHEZZA/2) cactus.x= LARGHEZZA/2;
		
		disegnaSfondo();
		disegnaSprite(dino);
	    disegnaSprite(cactus);
		presenta();
		
		prossimoFrame += DT_MICROSECONDS;
		this_thread::sleep_until(prossimoFrame);
	}
}



















