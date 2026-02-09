#include <stdio.h>
#define INF 999

int main() {
    int n, source;
    int graph[10][10], dist[10], visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
int i,j,v;
    printf("Enter adjacency matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for ( i = 0; i < n; i++)
        dist[i] = graph[source][i];

    visited[source] = 1;
    dist[source] = 0;

    for ( i = 1; i < n; i++) {
        int min = INF, u;
        for ( j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;
        for ( v = 0; v < n; v++)
            if (!visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances:\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d\n", i, dist[i]);

    return 0;
}
