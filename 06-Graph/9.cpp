#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

// DFS
void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS
void BFS(int start)
{
    int queue[10];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}