#include <iostream>
using namespace std;

class Vector {
private:
    int* arr;
    int capacity;
    int size;

public:
    Vector() {
        arr = new int[1];
        capacity = 1;
        size = 0;
    }

    void push(int data) {
        if (size == capacity) {
            int* temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = data;
        size++;
    }

    void insert(int data, int index) {
        if (index == size) {
            push(data);
        } else if (index >= 0 && index < size) {
            arr[index] = data;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    int get(int index) {
        if (index < size && index >= 0) {
            return arr[index];
        }
        return -1; 
    }

    void pop() {
        if (size > 0) {
            size--;
        }
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void clear() {
        size = 0;
    }

    void resize(int newSize) {
        if (newSize > capacity) {
            int* temp = new int[newSize];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = newSize;
        }
        size = newSize;
    }

    bool contains(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    void print() {
        if (size == 0) {
            cout << "Vector is empty." << endl;
            return;
        }
        cout << "Vector elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Vector() {
        delete[] arr;
    }
};

void menu() {
    Vector vec;
    int choice, value, index;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Insert\n";
        cout << "3. Get\n";
        cout << "4. Pop\n";
        cout << "5. Get Size\n";
        cout << "6. Get Capacity\n";
        cout << "7. Clear\n";
        cout << "8. Resize\n";
        cout << "9. Contains\n";
        cout << "10. Set\n";
        cout << "11. Print\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            vec.push(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter index to insert at: ";
            cin >> index;
            vec.insert(value, index);
            break;
        case 3:
            cout << "Enter index to get value from: ";
            cin >> index;
            cout << "Value at index " << index << " is " << vec.get(index) << endl;
            break;
        case 4:
            vec.pop();
            cout << "Last element popped\n";
            break;
        case 5:
            cout << "Current size: " << vec.getSize() << endl;
            break;
        case 6:
            cout << "Current capacity: " << vec.getCapacity() << endl;
            break;
        case 7:
            vec.clear();
            cout << "Vector cleared\n";
            break;
        case 8:
            cout << "Enter new size: ";
            cin >> value;
            vec.resize(value);
            cout << "Vector resized\n";
            break;
        case 9:
            cout << "Enter value to check: ";
            cin >> value;
            if (vec.contains(value)) {
                cout << "Value found in vector\n";
            } else {
                cout << "Value not found in vector\n";
            }
            break;
        case 10:
            cout << "Enter index to set value at: ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> value;
            vec.set(index, value);
            break;
        case 11:
            vec.print();
            break;
        case 12:
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

