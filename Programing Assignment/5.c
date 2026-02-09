#include <stdio.h>

int graph[10][10], visited[10];
int n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    int i;
    for ( i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int queue[10], front = 0, rear = 0;
    int i;
    for ( i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        int i;
        for ( i = 0; i < n; i++)
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    int i,j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("DFS: ");
    DFS(0);

    printf("\nBFS: ");
    BFS(0);

    return 0;
}
