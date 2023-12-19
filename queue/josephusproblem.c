#include<stdio.h>
#include<malloc.h>
struct node{
    int player_id;
    struct node *next;
};
struct node *start,*ptr,*new_node;
void main(){
    int n,k,i,count;
    printf("\nEnter the numbers of players:");
    scanf("%d",&n);
    printf("\nEnter the value of k:");
    scanf("%d",&k);
    start =  malloc(sizeof(struct node));
    start->player_id = 1;
    ptr = start;
    for (i = 2;i<=n;i++){
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next=start;
        ptr = new_node;
    }
    for (count = n ; count > 1; count --)
    {
        for (int i = 0; i < k - 1; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
    }
    printf("\nthe winning person is:%d",ptr->player_id);   
}