#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* topNode;
    int count;

public:
    Stack() : topNode(nullptr), count(0) {}

    void push(int x) {
        Node* n = new Node(x);
        n->next = topNode;
        topNode = n;
        count++;
    }

    void pop() {
        if (!topNode) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int peek() {
        if (!topNode) return -1;
        return topNode->data;
    }

    void display() {
        Node* curr = topNode;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int size() {
        return count;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << s.peek() << endl;
    s.pop();
    s.display();
    cout << s.size() << endl;
    return 0;
}
