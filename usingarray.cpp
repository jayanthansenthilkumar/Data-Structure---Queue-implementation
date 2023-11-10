#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class queue {
private:
    int queue1[5];
    int rear, front;
public:
    queue() {
        rear = -1;
        front = -1;
    }
    void insert(int x) {
        if (rear >= 4) {
            cout << "Queue overflow" <<endl;
            return;
        }
        queue1[++rear] = x;
        cout << "Inserted " << x << endl;
    }
    void del() {
        if (front == rear) {
            cout << "Queue underflow" << endl;
            return;
        }

        cout << "Deleted " << queue1[++front] << endl;
    }
    void display() {
        if (rear == front) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front + 1; i <= rear; i++) {
            cout << queue1[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int ch;
    queue qu;
    while (1) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter the element: ";
            cin >> ch;
            qu.insert(ch);
            break;
        case 2:
            qu.del();
            break;
        case 3:
            qu.display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
