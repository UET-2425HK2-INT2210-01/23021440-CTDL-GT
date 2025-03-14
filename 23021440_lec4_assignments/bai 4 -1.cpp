#include <iostream>;
#include <string>;
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL){}
    void append(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void search(int x) {
        node* temp = head;
        int dem = 0;
        while (temp) {
            if (temp->data == x) {
                cout << dem << endl;
                break;
            }
            else {
                dem++;
                temp = temp->next;
            }
        }

    }

    void reverse(){
        node* prev = NULL;
        node* cur = head;
        node* next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

    }
    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    ~linkedList() {
        node* temp;
        while (temp) {
            temp = head;
            head = head->next;
            delete temp;
        }

    }

};

int main() {
    int n;
    cin >> n;
    linkedList list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "append") {
            int x;
            cin >> x;
            list.append(x);
        }
        else if (s == "search") {
            int x;
            cin >> x;
            list.search(x);
        }
        else if (s == "reverse") {
            list.reverse();
            list.print();
        }
    }
    return 0;
}
