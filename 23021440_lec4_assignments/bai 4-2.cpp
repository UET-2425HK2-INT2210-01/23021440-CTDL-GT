#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    int priority;
    node* next;
    node* prev;
};

class doublyLinkedList {
    node* head;
public:
    doublyLinkedList() : head(NULL) {};
    void enqueue(int x, int p) {
        node* newNode = new node();
        newNode->data = x;
        newNode->priority = p;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL || p > head->priority) {
            newNode->next = head;
            if (head != NULL) {
                newNode->prev = newNode;
            }
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL && temp->next->data >= p) {
            temp = temp->next;

        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

    }
    void dequeue() {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;

    }
    void print() {
        node* temp = head;
        while (temp != NULL) {
            cout << "(" << temp->data << "," << temp->priority << "); ";
            temp = temp->next;
        }

    }


};

int main() {
    int n;
    cin >> n;
    doublyLinkedList list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int x, p;
            cin >> x >> p;
            list.enqueue(x, p);
        }
        else if (s == "dequeue") {
            list.dequeue();
        }

    }
    list.print();
}
