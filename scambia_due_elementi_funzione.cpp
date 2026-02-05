/*
 * Scambia due elementi di un array usando la funzione swap
 * L'utente inserisce 10 numeri, poi sceglie quali scambiare
 */

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int arr[10];
    int n = 10;

    cout << "Questo programma scambia due elementi se non in ordine" << endl << endl;

    // Inserimento dei 10 numeri
    cout << "Inserisci 10 numeri:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Stampa dell'array
    cout << endl << "Array inserito: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chiedi quali posizioni scambiare
    int pos1, pos2;
    cout << endl << "Inserisci la prima posizione (da 1 a 10): ";
    cin >> pos1;
    cout << "Inserisci la seconda posizione (da 1 a 10): ";
    cin >> pos2;

    // Scambia solo se non in ordine crescente
    if(arr[pos1 - 1] > arr[pos2 - 1]) {
        swap(arr, pos1 - 1, pos2 - 1);

        cout << endl << "Elementi scambiati!" << endl;
        cout << "Array dopo lo scambio: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << endl << "Elementi gia' in ordine crescente, nessuno scambio necessario." << endl;
    }

    return 0;
}
