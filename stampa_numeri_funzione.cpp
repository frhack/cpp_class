/*
 * Chiede 10 numeri all'utente e li stampa usando una funzione
 */

#include <iostream>
using namespace std;

void stampaNumeri(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10];
    int n = 10;

    cout << "Inserisci 10 numeri:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl << "Array: ";
    stampaNumeri(arr, n);

    return 0;
}
