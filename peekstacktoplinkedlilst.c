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

int isempty(struct node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isfull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->next = top;
        n->data = x;
        top = n;
        return n;
    }
}
int peek(struct node *top, int position)
{
    struct node *ptr = top;
    // if position 3 then 2 baar ptr will move
    for (int i = 0; (i < position && ptr != NULL - 1); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return 0;
    }
}
int stacktop(struct node *top)
{
    return top->data;
}
int stackbottom(struct node *top)
{
    // n is ptr pointing top at firstand then traversing
    struct node *n = top;
    while (n->next != NULL)
    {
        n = n->next;
    }
    return n->data;
}

int main()
{
    struct node *top = NULL;
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 285);
    linkedlisttraversal(top);
    //peek starting from 1
    for (int i = 1; i <=  4; i++)
    {
        printf("value at position %d is: %d\n", i, peek(top, i));
    }
    printf("the topmost element is %d\n", stacktop(top));

    printf("the bottommost element is %d\n", stackbottom(top));
    return 0;
}