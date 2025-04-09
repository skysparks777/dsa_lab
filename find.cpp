// finding particular element in a linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Search element in the list
void search(Node* head, int key) {
    int pos = 1;
    bool found = false;
    while (head != NULL) {
        if (head->data == key) {
            cout << "Element " << key << " found at position " << pos << ".\n";
            found = true;
            break;
        }
        head = head->next;
        pos++;
    }
    if (!found)
        cout << "Element " << key << " not found in the list.\n";
}

// Display the list
void display(Node* head) {
    cout << "Linked List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = NULL;
    int n, value, key;

    cout << "How many elements do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        insert(head, value);
    }

    display(head);

    cout << "Enter element to search: ";
    cin >> key;

    search(head, key);

    return 0;
}
