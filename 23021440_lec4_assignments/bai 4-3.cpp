#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL) {}
    void push(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;

    }
    void pop() {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }
    bool empty() {
        return head == NULL;
    }
    char top() {
        if (head == NULL) {
            return '\0';
        }
        return head->data;
    }

};

bool valid(string s) {
    linkedList stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                stack.pop();
            }
            else {
                return false;
            }
        }

    }
    return stack.empty();
}
int main() {
    string s;
    while (cin >> s) {
        if (valid(s)) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }
    return 0;

}
