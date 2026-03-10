/*
 * Questo programma ordina un array di numeri interi con l'algoritmo bubble sort
 * usare le seguenti funzioni: chiediNumeri, stampaNumeri, scambia, passata (da completare)
 * Completare la funzione passata e il main
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

//la funzione passata fa una passata dell'array e sposta il massimo verso destra
//suggerimento: usare un ciclo for con j da 0 a fine-1
//confrontare arr[j] con arr[j+1] e scambiare se arr[j] > arr[j+1]
void passata(int arr[], int fine) {
    //completare la funzione
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
    //suggerimento: scrivere una funzione per il passo (passata)
    //che fa una singola passata dell'array, poi chiamarla ripetutamente nel main


    // Stampa dell'array dopo l'ordinamento
    cout << endl << "Array ordinato: ";
    //stampaNumeri(arr,n);
    cout << endl;

    return 0;
}
