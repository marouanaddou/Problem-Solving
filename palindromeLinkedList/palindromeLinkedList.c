

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

            // method 1

// int lstsize(struct ListNode* head)
// {
//     int size = 0;
//     struct ListNode* tmp = head;
//     for (; tmp  != NULL ;)
//     {
//         size++;
//         tmp = tmp->next;
//     }
//     return size;
// }

// void convertListToArr(int *arr, struct ListNode* head)
// {
//     struct ListNode* tmp = head;
//     int i = 0;
//     for (;tmp != NULL;)
//     {
//         arr[i++] = tmp->val;
//         tmp = tmp->next;
//     }
// }

// bool isPalindrome(struct ListNode* head) 
// {
//     int size = lstsize(head);
//     int arr[size];
//     convertListToArr(arr, head);
//     int b = size - 1;
//     for ( int a = 0; a < size / 2; )
//     {
//         if (arr[a] == arr[b])
//         {
//             a++;
//             b--;
//         }
//         else
//             return 0;
//     }
//     return 1;
// }

// methode 2

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

bool isPalindrome(struct ListNode* head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    for (; fast != NULL && fast->next != NULL ; )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow); 
    
    for (; slow != NULL ;)
    {
        if (slow->val != head->val)
            return 0;
        slow = slow->next;
        head = head->next;
    }
    return 1;
}

/***************************************** TEST *************************************/

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
    int number[3] = {1,2,2};
    struct ListNode* head = ft_lstnew(number[0]);
    for (int i = 1; i < 3; i++)
    {
        struct ListNode* new = ft_lstnew(number[i]);
        ft_lstadd_back(&head, new);
    }
    
    printList(head);
    // isPalindrome(head);
    printf("%s", isPalindrome(head) == true ? "True" : "False"); // Result

    freeList(head);
}

/***************************************** TEST *************************************/