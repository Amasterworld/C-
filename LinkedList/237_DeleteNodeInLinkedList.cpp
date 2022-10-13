/*
237. Delete Node in a Linked List - leetcode

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.



 

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val = x, next = NULL;
 * }
 */


/*Solution: we are not given access to the first node. That means we cannot traverser 
from head to the node before del_note to isolate it. 1->3->4->5, del_node =4, 
move to 3 then connect to 5.
instead we are given the del_node, then we know the address of its next node and val. 
Therefore instead of isolated it, we copy the val of its next and isolate its next 
(and delete it to avoid mem leak). For example: 1->3->4->5->9, del_node =4, we are given 4, we know 5 and its address,
then we replace 4 by 5 then connect to 9, our list will be: 1->3->4 - 5
                                                                  |->9 . to avoid mem leak we delete (temp_node_contain_5)        
*/

struct ListNode {
   int val;
   ListNode * next;
   ListNode(int x) : val = x, next = NULL;
}
class Solution{
public:
    void deleteNode(ListNode* del_node) {
        /*get the address of the next node of the del_node*/
        ListNode* next_del_node = del_node->next;
        /*replace the  del_node value by the value of the next_del_node*/
        del_node->val = next_del_node->val;
        /*connect the del_node the node after next_del_node*/
        del_node->next = next_del_node->next; // or = del_node->next->next;
        /*delete next_del_node, otherwise mem leak*/
        delete next_del_node;
    }
};