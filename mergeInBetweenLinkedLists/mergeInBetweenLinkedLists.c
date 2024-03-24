
# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    struct ListNode* start = list1;
    struct ListNode* end = list1;
    struct ListNode* tmp;
    int i = 0;
    for (;i + 1 < a; i++)
    {
        start = start->next;
        end = end->next;
    }
    end = end->next;
    for (;i < b ; i++)
    {
        tmp =  end;
        end = end->next;
        free(tmp);
    }

    start->next = list2;
    for (;list2 != NULL && list2->next != NULL;)
    {
        list2 =  list2->next;
    }
    list2->next = end;
    return list1;
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
    int nums1[6] = {10,1,13,6,9,5};
    int nums2[3] = {1000000,1000001,1000002};
    struct ListNode* list1 = ft_lstnew(nums1[0]);
    struct ListNode* list2 = ft_lstnew(nums2[0]);
    for (int i = 1; i < 6; i++)
    {
        struct ListNode* new = ft_lstnew(nums1[i]);
        ft_lstadd_back(&list1, new);
    }
    for (int i = 1; i < 3; i++)
    {
        struct ListNode* new = ft_lstnew(nums2[i]);
        ft_lstadd_back(&list2, new);
    }
    printList(list1);
    mergeInBetween(list1,3,4,list2);
    printList(list1);
    freeList(list1);
}

/***************************************** TEST *************************************/