#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at beginning
void insertBegin(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, head};
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Delete from end
void deleteEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

// Delete from beginning
void deleteBegin(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

// Display the list
void display(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertBegin(head, value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertEnd(head, value);
            break;
        case 3:
            deleteBegin(head);
            break;
        case 4:
            deleteEnd(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
