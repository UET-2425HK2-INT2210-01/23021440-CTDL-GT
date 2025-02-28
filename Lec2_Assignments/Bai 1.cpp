#include <iostream>
using namespace std;

int countPairs(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countPairs(arr, n) << endl;
    return 0;
}
