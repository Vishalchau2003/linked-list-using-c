#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// case:1
struct node *deleteatfirst(struct node *head)
{
    struct node *ptr = head;

    head = head->next;
    free(ptr);
    return head;
}
// case : 2

struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
// case:3

struct node *deleteatlast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
// case:4

struct node *deleteatgivenvalule(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if ((q->data == value))
    {
        p->next = q->next;
      
    }
    free(q);
    return head;

}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 8;
    third->next = forth;
    forth->data = 1;
    forth->next = NULL;

    printf("linked list before deletion\n");
    linkedlisttraversal(head);
    printf("\n");

    // for deleting first element in list

    // head = deleteatfirst(head);
    // printf("linked list after deletion\n");
    // linkedlisttraversal(head);

    // for deleting at index

    //    for deleting at last node
      head = deleteatlast(head);
    printf("linked list after deletion\n");
    linkedlisttraversal(head);

    // deleting given value
    // head = deleteatgivenvalule(head, 8);
    // printf("linked list after deletion\n");
    // linkedlisttraversal(head);

    return 0;
}