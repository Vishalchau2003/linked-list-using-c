#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttravesal(struct node *ptr)
{
    while (ptr!= NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    // struct node is a datatype so creating a function
    // which returns something with struct node datatype
}

// case=1

// struct node is a datatype so creating a function
// which returns something with struct node datatype

struct node *insertatfirst(struct node *head, int data)
{ // ek naya node created named ptr
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
    // ptr is new head so we returning it
    //  new head
    // here ptr is struct node datatype
}
// case=2
struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // naya node ready
    struct node *p = head;
    // initialise p to head
    // p ptr me head hoga
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

// case=3
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // naya node ready
    struct node *p = head;
    // initialise p to head
    // p ptr me head hoga
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// case=4
struct node *insertafternode(struct node *head, struct node *previousnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = previousnode->next;
    previousnode->next = ptr;
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

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = forth;
    forth->data = 66;
    forth->next = NULL;
    printf("linked list before insertion\n");
    linkedlisttravesal(head);

    // insertion at first

    //  head = insertatfirst(head, 56);
    // head is a ptr storing address of head node
    // change in head in function definition will change the value in main function because head is pointter and have the addres of head node
    //   linkedlisttravesal(head);
    // function return pointer ptr and now head will be updted to ptr
    // head is a ptr storing address of head node

    // insertion at index

    // insert at 0 won't work in insertatindex because at index 0 it will be insertatfirst
    //  head = insertatindex(head, 56,3);
    //   linkedlisttravesal(head);

    // insertion at end

    // head = insertatend(head, 56);
    // printf("linked list after insertion\n");
    // linkedlisttravesal(head);

    // insert after node
    // suppose second node is given

    head = insertafternode(head, second, 45);
    printf("linked list after insertion\n");
    linkedlisttravesal(head);
    return 0;
}