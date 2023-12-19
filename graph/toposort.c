#include<stdio.h>
#define max 10
int n,adj[max][max];
int front = -1,rear = -1, queue[max];
void create_graph(void);
void display();
void insett_queue(int);
int delete_queue(void);
int find_indeg(int);
void main(){
    int node,j=0,del_node,i;
    int topsort[max],indeg[max];
    create_graph();
     printf("\nThe Adjancey matrix is:");
     display();
     for (node  = 1; node <= n ; node++)
     {
        indeg[node] = find_indeg(node);
        if (indeg[node] == 0)
        {
            insett_queue(node);
        }
     }
     while (front<=rear)
     {
        del_node = delete_queue();
        topsort[j] = del_node;
        j++;
        for (node = 1; node <= n; node++)
        {
            if (adj[del_node][node] == 1 )
            {
                adj[del_node][node] = 0;
                indeg[node] = indeg[node] -1;
                if (indeg[node] == 0)
                {
                    insett_queue(node);
                }
                
            }
            
        }
     }
     printf("\nThe Topological Sort is as follows:");
     for (node  = 0; node <= n; node++)
     {
          printf("%d\t",topsort[node]);
     }
}
void create_graph(){
    int i,max_edges,org,dest;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    max_edges = n*(n-1);
    for ( i = 1; i <= max_edges; i++)
    {
        printf("\nEnter the edges %d(0 to quit):",i);
        scanf("%d %d",&org,&dest);
        if ((org == 0) && (dest == 0))
        {
            break;
        }
        if ((org > n || dest > n || org <= 0 || dest <= 0))
        {
            printf("\nInvalid edge");
            i--;
        }
        else
        { 
            adj[org][dest] = 1;
        }
    }
}
void display(){
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            printf("%3d",adj[i],adj[j]);
        }
    }
}
void insett_queue(int node){
    if (rear == max -1)
    {
        printf("\noverflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = node;
    }
    else
    {
        rear ++;
        queue[rear] = node;
    }
}
int delete_queue(){
    int val;
    if (front == -1 || front> rear)
    {
        printf("\nUnderflow");
        return ;
    }
    else if (front == rear)
    {
         val = queue[front];
        front = rear = -1;
    }
    else
    {
        val = queue[front];
        front++;
        return val;   
    }
}
int find_indeg(int node){
    int i,indeg = 0;
    for(i =1;i<=n;i++){
        if (adj[i][node] == 1)
        {
            indeg++;
        }
    }
    return indeg;
}