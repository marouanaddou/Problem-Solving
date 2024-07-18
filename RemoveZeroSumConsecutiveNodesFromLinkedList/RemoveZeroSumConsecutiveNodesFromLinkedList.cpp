
# include "RemoveZeroSumConsecutiveNodesFromLinkedList.hpp"

int *linkedListToArray(struct ListNode* head, int *size)
{
    int *arr = (int *)malloc(sizeof(int));
    if (!arr)
        return NULL;
    struct ListNode* tmp = head;
    for (;tmp != NULL;)
    {
        arr[*size] = tmp->val;
        tmp = tmp->next;
        *size++;
    }
    return arr;
}

// struct ListNode* removeZeroSumSublists(struct ListNode* head) 
// {
//     int size = 0;
//     int *arr = linkedListToArray(head, &size);
//     for ()
// }
