#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    int x;
    cout << "Enter value: ";
    cin >> x;

    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd()
{
    int x;
    cout << "Enter value: ";
    cin >> x;

    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// Insert after a given node
void insertAfter()
{
    int value, x;

    cout << "Enter node after which to insert: ";
    cin >> value;

    cout << "Enter new value: ";
    cin >> x;

    Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
        cout << "Node not found\n";
    else
    {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Display
void display()
{
    Node *temp = head;

    cout << "List: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert Beginning";
        cout << "\n2. Insert End";
        cout << "\n3. Insert After";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: insertBeginning(); break;
        case 2: insertEnd(); break;
        case 3: insertAfter(); break;
        case 4: display(); break;
        case 5: break;
        default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}