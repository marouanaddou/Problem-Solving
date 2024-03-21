


# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) 
{
    if (head != NULL)
    {
        struct ListNode* prev = NULL;
        struct ListNode* curr = head;
        struct ListNode* next = head->next;
        for (;curr != NULL;)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != NULL)
                next = next->next;
        }
        head = prev;
    }
    return head;
}

/********************************* TEST **********************************/

void ft_lstadd_back(struct ListNode **lst, struct ListNode *new)
{
    struct ListNode *head = *lst;
    for (;head->next != NULL;)
        head = head->next;
    head->next = new;
}

struct ListNode *ft_lstnew(int val)
{
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!new)
        return NULL;
    new->val = val;
    new->next = NULL;
    return new;
}

void printList(struct ListNode* head)
{
    for (;head != NULL;)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head)
{
    struct ListNode *tmp = head;
    for (;head != NULL;)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

int main()
{
    struct ListNode* head = ft_lstnew(0);
    for (int i = 1; i <= 5; i++)
    {
        struct ListNode* new = ft_lstnew(i);
        ft_lstadd_back(&head, new);
    }
    
    printList(head);

    head = reverseList(head);

    printList(head);

    freeList(head);
}

/********************************* TEST **********************************/
