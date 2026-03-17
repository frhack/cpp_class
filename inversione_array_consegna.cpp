/*
 * Questo programma inverte un array di numeri interi
 * usare le seguenti funzioni: chiediNumeri, stampaNumeri, scambia, inverti (da completare)
 * Completare la funzione inverti e il main
 */


#include <iostream>
using namespace std;

void chiediNumeri(int arr[], int n) {
    cout << "Inserisci " << n << " numeri:" << endl;
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

//la funzione inverti scambia il primo elemento con l'ultimo,
//il secondo con il penultimo, e cosi' via
//suggerimento: usare un ciclo for con i che va da 0 a n/2
//e scambiare arr[i] con arr[n - 1 - i]
void inverti(int arr[], int n) {
    //completare la funzione
}

int main() {
    const int n = 10;
    int arr[n];

    cout << "Questo programma inverte un array di numeri interi" << endl << endl;

    //chiediNumeri(arr, n);

    cout << endl << "Array inserito: ";
    //stampaNumeri(arr, n);

    //invertire l'array chiamando la funzione inverti

    cout << endl << "Array invertito: ";
    //stampaNumeri(arr, n);
    cout << endl;

    return 0;
}
