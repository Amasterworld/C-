/*You are given the heads of two sorted linked lists: list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/

/*SOLUTION:  firstly, create a list namely ptr, and assign it to the one of two lists, 
e.g. ListNode * ptr = list1.
    Secondly, d compare the first  two element of two list: list1 and list2, if list1->val > list2->val
    because, ptr is assigned to list1, then only list1 = list1->next;
    else switch ptr = list2 and list2 = list2->next;
    Thirdly, create temp or curr pointer to traveser the list. to connect based on the conditions
    Finally, which list is finished 1st will be connected the the rest of the bigger list   and return ptr;



*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution{
public:
    ListNode * mergeTwoLists(ListNode *list1, ListNode *list2){

        // check whether list1 and list2 is NULL
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // create ptr and assigne
        ListNode * ptr = list1;
        // compare the two first vals of list1 and list2
        if (list1->val > list2->val){
            //switch
            ptr = list2;
            list2 = list2->next;
        }
        else{ //ptr is pointed to the list1 then does not need to switch, only move forward the pointer
            list1 = list1->next;
            
        }
        // create a pointer to traveser the lists
        ListNode * curr = ptr;
        // connect curr to the node of two lists based on the condition until
        // reach the end of one of two lists (==nullptr)

        while (list1 && list2){ // == while(list1 != nullptr && list2 != nullptr)
            
            if(list1->val > list2->val){
                // we want to get the list from smaller to bigger then we need to get the smaller
                curr->next = list2;
                list2 = list2->next;

            }
            else {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;

        }
        // assign the smaller list to the rest of the bigger list
        // if list1 is the smaller list (finished b4 list2)
        if (list1 == nullptr)  curr->next = list2;
        if (list2 == nullptr)  curr->next = list1;
        return ptr;
        
    }

};