/*
 * Trova il minimo in un array
 * Utilizza la funzione indice_minimo
 */

#include <iostream>
using namespace std;

// Funzione che trova l'indice del minimo in un array
// a partire dalla posizione 'inizio' fino alla fine
int indice_minimo(int arr[], int n, int inizio) {
    int pos_min = inizio;

    for(int j = inizio + 1; j < n; j++) {
        if(arr[j] < arr[pos_min]) {
            pos_min = j;
        }
    }

    return pos_min;
}

int main() {
    int arr[5] = {64, 25, 12, 22, 11};
    int n = 5;

    // Stampa dell'array
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Trova l'indice del minimo (partendo dalla posizione 0)
    int pos_min = indice_minimo(arr, n, 0);

    // Stampa il risultato
    cout << "Il minimo e' " << arr[pos_min] << endl;
    cout << "Si trova in posizione " << pos_min << endl;

    return 0;
}
