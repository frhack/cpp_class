/*
 * Chiede 10 numeri all'utente e li stampa
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

int main() {
    int arr[10];
    int n = 10;

    chiediNumeri(arr,n);
    cout << endl << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
