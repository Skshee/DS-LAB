#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedlisttraversal(struct Node* ptr)
{
 while(ptr!=NULL) // Dumbo put if instead of while
 { 
    printf("%d\n",ptr->data);
    ptr=ptr->next;
 }
}

void BubbleSort(struct Node *start)
{
    struct Node *end,*p,*q;
    int temp;
    for(end=NULL;end!=start->next;end=q) // end=q ensures that end gets updated and loop runs only till q
    {
        for(p=start;p->next!=end;p=p->next)
        {
         q=p->next;
         if(p->data>q->data)
         {
            temp=p->data;
            p->data=q->data;
            q->data=temp;
         }
          p = p->next;
        }
        end=p;// Updating end so that we don't repeat the sorting
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
linkedlisttraversal(head);

BubbleSort(head);
printf("After Sorting:");
linkedlisttraversal(head);

free(head);
free(second);
free(third);

return 0;
}
