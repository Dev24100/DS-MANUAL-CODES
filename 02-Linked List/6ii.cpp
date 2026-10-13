/*  Write a program to implement a singly linked list and perform the following operations:
 ii. Delete a node (first node, last node, node after a given node)    */
Display all the nodes
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Delete first node
void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete last node
void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete node after a given node
void deleteAfter()
{
    int value;

    cout << "Enter node after which to delete: ";
    cin >> value;

    Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;
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
        cout << "\n1. Delete First";
        cout << "\n2. Delete Last";
        cout << "\n3. Delete After";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: deleteFirst(); break;
        case 2: deleteLast(); break;
        case 3: deleteAfter(); break;
        case 4: display(); break;
        case 5: break;
        default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
