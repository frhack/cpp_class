/*
 * Questo programma ordina un array di numeri interi con l'algoritmo insertion sort
 * usare le seguenti funzioni: chiediNumeri, stampaNumeri, scambia, inserisci (da completare)
 * Completare la funzione inserisci e il main
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

//la funzione inserisci prende l'elemento in posizione i
//e lo sposta verso sinistra finche' non trova la posizione corretta
//suggerimento: usare un ciclo for con j che parte da i e scende fino a 1
//confrontare arr[j] con arr[j-1] e scambiare se arr[j] < arr[j-1]
void inserisci(int arr[], int i) {
    //completare la funzione
}

int main() {
    int arr[10];
    const int n = 10;

    cout << "Questo programma ordina un array di numeri interi con insertion sort" << endl << endl;

    //chiediNumeri(arr,n);

    // Stampa dell'array
    cout << endl << "Array inserito: ";

    //stampaNumeri(arr,n);

    //ordina l'array con insertion sort: inserire qui il codice
    //suggerimento: usare un ciclo for da i=1 a n-1
    //e chiamare la funzione inserisci(arr, i) ad ogni passo


    // Stampa dell'array dopo l'ordinamento
    cout << endl << "Array ordinato: ";
    //stampaNumeri(arr,n);
    cout << endl;

    return 0;
}
