/*
 * Questo programma ordina un array di numeri interi con l'algoritmo bubble sort
 * usare le seguenti funzioni: chiediNumeri, stampaNumeri, scambia
 * Completare il main con il codice per ordinare l'array con bubble sort
 */


#include <iostream>
using namespace std;

void chiediNumeri(int arr[], int n) {
    cout << "Inserisci 10 numeri:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void stampaNumeri(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void scambia(int & a, int & b) {
        int t = a;
    a = b;
    b = t;
}

int main() {
    int arr[10];
    const int n = 10;

    cout << "Questo programma ordina un array di numeri interi con bubble sort" << endl << endl;

    //chiediNumeri(arr,n);

    // Stampa dell'array
    cout << endl << "Array inserito: ";

    //stampaNumeri(arr,n);

    //ordina l'array con bubble sort: inserire qui il codice
    //suggerimento: usare due cicli for annidati
    //nel ciclo interno confrontare arr[j] con arr[j+1]
    //e scambiare se arr[j] > arr[j+1]


    // Stampa dell'array dopo l'ordinamento
    cout << endl << "Array ordinato: ";
    //stampaNumeri(arr,n);
    cout << endl;

    return 0;
}
