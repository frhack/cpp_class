#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int L = 6;

/*
    Riempie tutta la griglia con il carattere '.'
    che rappresenta una casella non ancora tentata.
*/
void initGrid(char grid[L][L]) {
    // DA COMPLETARE
}

/*
    Mostra la griglia a video.

    Attenzione:
    - se in una casella c'e' la nave '#', NON deve essere mostrata
    - al posto di '#' bisogna stampare '.'
    - dopo ogni carattere stampare uno spazio per rendere la griglia leggibile
*/
void showGrid(char grid[L][L]) {
    // DA COMPLETARE
}

/*
    Sceglie casualmente la posizione della nave:
    - assegna a boatPos[0] una riga casuale tra 0 e L-1
    - assegna a boatPos[1] una colonna casuale tra 0 e L-1
    - inserisce nella griglia il carattere '#'
      nella posizione scelta

    Suggerimento:
    - rand() genera un numero intero casuale
    - rand() % L genera un numero tra 0 e L-1

    Esempio:
    se L vale 6, allora rand() % L puo' generare:
    0, 1, 2, 3, 4, 5
*/
void setBoat(char grid[L][L], int boatPos[2]) {
    // DA COMPLETARE
}

/*
    Calcola e restituisce la distanza euclidea
    tra il tentativo e la posizione della nave.

    Parametri:
    - trial[0] = riga scelta
    - trial[1] = colonna scelta
    - boatPos[0] = riga della nave
    - boatPos[1] = colonna della nave
*/
double distance(int trial[2], int boatPos[2]) {
    // DA COMPLETARE
}

/*
    Gestisce un tentativo di colpire la nave.

    Parametri:
    - grid: la griglia di gioco
    - trial: array di 2 interi
      trial[0] = riga scelta
      trial[1] = colonna scelta
    - boatPos: array di 2 interi
      boatPos[0] = riga della nave
      boatPos[1] = colonna della nave

    Cosa deve fare:
    - se il tentativo coincide con la posizione della nave:
        - scrivere '_' nella griglia
        - stampare "Colpito e affondato!"
        - restituire true
    - altrimenti:
        - scrivere 'x' nella casella tentata
        - calcolare la distanza euclidea dalla nave
          chiamando la funzione distance
        - stampare:
            "Acqua!" se distanza > L / 2.0
            "Fuochino!" se distanza > L / 3.0
            "Fuoco!" negli altri casi
        - restituire false
*/
bool setTrial(char grid[L][L], int trial[2], int boatPos[2]) {
    // DA COMPLETARE
}

int main() {
    char grid[L][L];
    int boatPos[2];
    int trial[2];
    int numTentativi = 0;
    bool affondata;

    srand(time(0));

    initGrid(grid);
    setBoat(grid, boatPos);

    cout << "=== CACCIA ALLA NAVE ===" << endl;
    cout << "Griglia " << L << "x" << L << endl;
    cout << "Inserisci le coordinate come riga colonna" << endl;
    cout << "'.' = casella non ancora tentata" << endl;
    cout << "'x' = tentativo a vuoto" << endl;
    cout << "'_' = nave affondata" << endl;

    do {
        showGrid(grid);

        cout << "Inserisci riga e colonna: ";
        cin >> trial[0] >> trial[1];

        numTentativi++;
        affondata = setTrial(grid, trial, boatPos);

        if (!affondata) {
            cout << "Tentativi effettuati: " << numTentativi << endl;
        }

    } while (!affondata);

    showGrid(grid);
    cout << "Hai trovato la nave in " << numTentativi << " tentativi." << endl;

    return 0;
}
