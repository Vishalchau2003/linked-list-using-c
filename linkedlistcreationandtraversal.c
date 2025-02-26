#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// traversal
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        // pehle aapko ptr ponting to head so head ka data will be printed
        // the ptr will point to next whichhaad data of second node
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{ // head is also a struct ptr pointing the 1st node
    struct node *head;
    struct node *second;
    struct node *third;

    // allocating memory for nodes(head,second,third) in heap
    // ek pointer bana rhe taaki memeory mil jaaye heap me
    // dynamic memory allocatio
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // link first and second node
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at third node
    third->data = 66;
    third->next = NULL;

    linkedlisttraversal(head);
    // head is pointer of struct node*

    return 0;
}