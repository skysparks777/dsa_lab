#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// OrderedLinkedList class
class OrderedLinkedList {
private:
    Node* head;

public:
    // Constructor
    OrderedLinkedList() {
        head = nullptr;
    }

    // Function to insert a node in order
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};

        // If list is empty or new node goes before head
        if (head == nullptr || value < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            // Find correct position
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        cout << "Ordered Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~OrderedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    OrderedLinkedList list;
    int n, value;

    cout << "How many elements do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    list.display();

    return 0;
}
