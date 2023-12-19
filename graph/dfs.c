#include<stdio.h>
#define max 10
void depthfirstsearch(int adj[][max],int visited[],int start){
    int stack[max],top = -1,i;
    stack[++top] = start;
    printf("%c\t",start+65);
    visited[start] = 1;
    while (top!=-1)
    {
        start = stack[top];
        for ( i = 0; i < max; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                printf("%c\t",i+65);
                visited[i] = 1;
                break;
            }
            
        }
        if (i  == max)
        {
            top--;
        }
    }
}
void main(){
    int adj[max][max],visited[max]={0};
    int i,j;
    printf("\nEnter adjancey matrix:");
    for ( i = 0; i < max; i++)
    {
        for ( j = 0; j < max; j++)
        {
              scanf("%d",&adj[i][j]);
        }
    }
    depthfirstsearch(adj,visited,0);
}