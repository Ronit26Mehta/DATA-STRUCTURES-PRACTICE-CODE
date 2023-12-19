#include<stdio.h>
#define max 10
void breadth_first_search(int adj[][max],int visited[],int start){
    int queue[max],rear = -1,front = -1,i;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[front++];
        if (start == 4)
        {
            printf("5\t");
        }
        else
        {
            printf("%c\t",65+i);
        }
        for (int i = 0; i < max; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
              queue[rear++] = 1;
              visited[i] = 1;   
            }
        }
    }
}
void main(){
    int visited[max] = 0;
    int adj[max][max] ,i,j;
    printf("\nEnter adjancey matrix:");
    for ( i = 0; i < max; i++)
    {
        for ( j = 0; j < max; j++)
        {
            scanf("%d",adj[i][j]);
        }
    }
    breadth_first_search(adj,visited,0);
}