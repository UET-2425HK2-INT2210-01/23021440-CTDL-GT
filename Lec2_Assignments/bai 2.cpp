#include <iostream>
using namespace std;

void insert(int arr[], int &size, int p, int x) {
    for (int i = size; i > p; i--) {
        arr[i] = arr[i - 1];
    }
    arr[p] = x;
    size++;
}

void remove(int arr[], int &size, int p) {
    for (int i = p; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[100], size = 0;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int p, x;
            cin >> p >> x;
            insert(arr, size, p, x);
        } else if (op == "delete") {
            int p;
            cin >> p;
            remove(arr, size, p);
        }
    }

    printList(arr, size);
    return 0;
}
