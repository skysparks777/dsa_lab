// write a program to add polynomials using single linked list 
#include <iostream>
using namespace std;

struct Node {
    int coeff, power;
    Node* next;
};

// Function to create a new node
Node* createNode(int c, int p) {
    Node* newNode = new Node;
    newNode->coeff = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insert(Node*& head, int c, int p) {
    Node* newNode = createNode(c, p);
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 && p2) {
        if (p1->power == p2->power) {
            insert(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1) {
        insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    
    int a,b;
    for(int i=0;i<3;i++){
        cout<<"Enter 2 numbers for poly1 : ";
        cin>>a>>b;
        insert(poly1, a, b);
    }
    for(int i=0;i<3;i++){
        cout<<"Enter 2 numbers for poly2(num,power): ";
        cin>>a>>b;
        insert(poly2, a, b);
    }

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPoly(poly1, poly2);

    cout << "Sum: ";
    display(sum);

    return 0;
}
