#include<stdio.h>
#include<malloc.h>
struct node{
    char vertex;
    struct node *next;
};
struct node *gnode;
void displayGraph(struct node *adj[],int no_of_nodes);
void deleteGraph(struct node *adj[],int no_of_nodes);
void createGraph(struct node *adj[],int no_of_nodes);
void main(){
    struct node *adj[10];
    int i,no_of_nodes;
    printf("\nEnter the Number of nodes:");
    scanf("%d",&no_of_nodes);
    for ( i = 0; i < no_of_nodes; i++)
    {
        adj[i] = NULL;;
    }
    createGraph(adj,no_of_nodes);
    printf("\nThe graph is:");
    displayGraph(adj,no_of_nodes);
    deleteGraph(adj,no_of_nodes);
}
void createGraph(struct node *adj[],int no_of_nodes){
    struct node *new_nodes,*last;
    int i,j,n,val;
    for ( i = 0; i < no_of_nodes; i++)
    {
        printf("\nEnter the neighbours %d to %d",i);
        scanf("%d",&val);
        new_nodes = (struct node*)malloc(sizeof(struct node));
        new_nodes->vertex= val;
        new_nodes->next = NULL;
        if (adj[i] == NULL)
        {
            adj[i] = new_nodes;
        }
        else
        {
            last->next = new_nodes;
        }
        last = new_nodes;
    }
}
void displayGraph(struct node *adj[],int no_of_nodes){
    struct node *ptr;
    int i;
    for ( i = 0; i < no_of_nodes; i++)
    {
        ptr = adj[i];
        printf("\nThe neighbours of node %d are",i);
        while (ptr != NULL)
        {
            printf("\t%d",ptr->vertex);
            ptr = ptr->next;
        }
    }
}
void deleteGraph(struct node *adj[],int no_of_nodes){
    int i;
    struct node *temp,*ptr;
    for ( i = 0; i < no_of_nodes; i++)
    {
        ptr = adj[i];
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr ->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}