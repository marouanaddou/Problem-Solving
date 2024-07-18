

# include "RemoveZeroSumConsecutiveNodesFromLinkedList.hpp"

struct ListNode *creatLInkedList(int *arr, int size)
{
    struct ListNode *head;
    for (int i = 0; i < size; i++)
    {
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->val = arr[i];
        head->next->val = arr[++i];
    }
}
int main()
{

}