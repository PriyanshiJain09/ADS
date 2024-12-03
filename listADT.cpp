#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void insertAtFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtFront(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Position out of bounds\n";
        }
    }

    void deleteFromFront() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty\n";
        }
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromPosition(int position) {
        if (position == 0) {
            deleteFromFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        } else {
            cout << "Position out of bounds\n";
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~List() {
        while (head != nullptr) {
            deleteFromFront();
        }
    }
};

void menu() {
    List list;
    int choice, value, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            list.insertAtFront(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;
        case 4:
            list.deleteFromFront();
            cout << "Deleted from front\n";
            break;
        case 5:
            list.deleteFromEnd();
            cout << "Deleted from end\n";
            break;
        case 6:
            cout << "Enter position to delete from: ";
            cin >> position;
            list.deleteFromPosition(position);
            break;
        case 7:
            list.display();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

