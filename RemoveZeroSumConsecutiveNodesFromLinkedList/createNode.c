

# include "RemoveZeroSumConsecutiveNodesFromLinkedList.hpp"

struct ListNode* createNode(int data)
{
    struct ListNode *Node = (struct node *)malloc(sizeof(struct ListNode));
    if (!Node)
        return NULL;
    Node->val = data;
    Node->next = NULL;
    return Node;
}