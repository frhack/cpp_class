/*
 * Questo programma cifra una parola con il cifrario di Cesare
 * Ogni lettera viene spostata di N posizioni nell'alfabeto
 * Esempio: "ciao" con N=3 diventa "fldr"
 * usare le seguenti funzioni: cifra (da completare)
 * Completare la funzione cifra e il main
 */


#include <iostream>
using namespace std;

//la funzione cifra sposta ogni lettera minuscola di n posizioni
//suggerimento: scorrere la stringa con un ciclo for
//per ogni carattere, se e' una lettera minuscola (c >= 'a' && c <= 'z'):
//  - sottrarre 'a' per ottenere un numero da 0 a 25
//  - aggiungere n (lo spostamento)
//  - usare % 26 per restare nell'alfabeto (dopo 'z' si ricomincia da 'a')
//  - aggiungere 'a' per tornare al carattere
void cifra(string & s, int n) {
    //completare la funzione
}

int main() {
    cout << "Questo programma cifra una parola con il cifrario di Cesare" << endl << endl;

    //chiedere all'utente una parola (minuscola) e leggerla con cin

    //chiedere lo spostamento N e leggerlo con cin

    //stampare la parola originale

    //chiamare cifra per cifrare la parola

    //stampare la parola cifrata

    cout << endl;

    return 0;
}
