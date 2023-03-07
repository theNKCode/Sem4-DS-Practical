#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    char name[20];
    struct Node *next;
};

struct Node *insertathead(struct Node *head, int amt, char n[])
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = amt;
    strcpy(ptr->name, n);
    ptr->next = head;
    return ptr;
}

void linkedlisttraversal(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    printf("----Coffee Shop Bills----\nCoffee Name\tAmount\n");
    while (p->next != NULL)
    {
        printf("%s\t\t%d\n", p->name, p->data);
        p = p->next;
    }
}

void sum(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int sum = 0;
    while (p->next != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("%d\n", sum);
}

void max_min(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int max = INT_MIN;
    int min = INT_MAX;
    while (p->next != NULL)
    {
        if (p->data >= max)
        {
            max = p->data;
        }
        if (p->data <= min)
        {
            min = p->data;
        }
        p = p->next;
    }
    printf("Maximun Amount : %d\t\nMinimum Amount : %d\t\n", max, min);
}

int main()
{
    int ch, amt;
    char res, coffeename[20], r;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    printf("----Welcome to Coffee Shop----\n");
    printf("\tBill Portal\n");
getmore:
    printf("\nEnter Coffee Name :\t");
    scanf("%s", coffeename);
    printf("Enter Amount :\t");
    scanf("%d", &amt);
    head = insertathead(head, amt, coffeename);
    printf("\nDo you want to add more : ");
    scanf("%s", &res);
    if (res == 'y')
        goto getmore;
choice:
    printf("\n1.Print Bills\n2.Sum of all Bills\n3.Print Maximun and Minimum\n\nEnter 1/2/3: ");
    scanf("%d", &ch);
    if (ch == 1)
        linkedlisttraversal(head);
    else if (ch == 2)
        sum(head);
    else if (ch == 3)
        max_min(head);
    else if (ch != 1 || ch != 2 || ch != 3)
    {
        return 0;
    }
    goto choice;
}