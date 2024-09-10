#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
     printf("%d\n",ptr->data);\
     ptr= ptr->next;
    }
}

void SelectionSort(struct Node* start)
{
    int temp;
    struct Node *p,*q,*r,*end;
    for(end=NULL;end!=start->next;end=q)
    {
        for(r=p=start;p->next!=end;p=p->next)
        {
            q=p->next;
            
        }
    }
}

int main()
{
     struct Node *head;
 struct Node *second;
 struct Node *third;


head=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=77;
head->next= second;

second->data=10;
second->next=third;

third->data=900;
third->next=NULL;

printf("Before Sorting:"); // IF some bullshit error occurs in the terminal(red wala application failed bullshit) remove \n because C compiler is absolutely dogshit
linkedlistTraversal(head);

SelectionSort(head);
printf("After Sorting:");
linkedlistTraversal(head);

free(head);
free(second);
free(third);

return 0;
}