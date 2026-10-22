#include <iostream>
using namespace std;

int q[5], front = -1, rear = -1;

void enqueue()
{
    int x;
    if ((rear + 1) % 5 == front)
        cout << "Queue Overflow\n";
    else
    {
        cout << "Enter element: ";
        cin >> x;
        if (front == -1)
            front = 0;
        rear = (rear + 1) % 5;
        q[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Queue Underflow\n";
    else
    {
        cout << "Deleted: " << q[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 5;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is Empty\n";
    else
    {
        cout << "Queue: ";
        int i = front;
        while (true)
        {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: enqueue(); break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 4: break;
        default: cout << "Invalid Choice\n";
        }
    } while (ch != 4);
    return 0;
}