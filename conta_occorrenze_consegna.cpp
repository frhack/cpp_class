/*
 * Questo programma conta quante volte un valore compare in un array
 * usare le seguenti funzioni: chiediNumeri, stampaNumeri, contaOccorrenze (da completare)
 * Completare la funzione contaOccorrenze e il main
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

//la funzione contaOccorrenze conta quante volte il valore compare nell'array
//suggerimento: usare un contatore inizializzato a 0
//scorrere l'array con un ciclo for e incrementare il contatore quando arr[i] == valore
//restituire il contatore
int contaOccorrenze(int arr[], int n, int valore) {
    //completare la funzione
}

int main() {
    const int n = 10;
    int arr[n];

    cout << "Questo programma conta le occorrenze di un valore in un array" << endl << endl;

    //chiediNumeri(arr, n);

    cout << endl << "Array inserito: ";
    //stampaNumeri(arr, n);

    //chiedere all'utente il valore da cercare
    //suggerimento: dichiarare una variabile int valore e leggerla con cin

    //chiamare contaOccorrenze e stampare il risultato
    //suggerimento: stampare "Il valore X compare Y volte"

    cout << endl;

    return 0;
}
