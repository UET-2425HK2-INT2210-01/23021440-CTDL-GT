#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int queue[n], front = 0, back = 0;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "enqueue") {
            int x;
            cin >> x;
            queue[back++] = x;
        } else if (op == "dequeue") {
            if (front < back) front++;
        }
    }

    for (int i = front; i < back; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
    return 0;
}
