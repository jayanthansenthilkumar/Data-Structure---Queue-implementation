#include<iostream>
using namespace std;
class Node {
public:
    Node* next;
    int data;
    Node(int x) : data(x), next() {}
};
class Queue {
private:
    Node* head;
    int front, rear;
public:
    Queue() : head(), front(-1), rear(-1) {}
    void push(int x) {
        Node* newNode = new Node(x);
        if (rear == -1) {
            head = newNode;
            front = rear = 0;
        } else {
            Node* temp = head;
            while (temp->next != 0) {
                temp = temp->next;
            }
            temp->next = newNode;
            rear++;
        }
    }
    void pop() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == 0) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue s1;
    int ch;
    while (1) {
        cout << "\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter an element: ";
                cin >> ch;
                s1.push(ch);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
