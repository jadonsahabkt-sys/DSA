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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){
            // Connect odd node
            odd->next = even->next;
            odd =odd->next;
            // connect even node 
            even->next = odd->next;
            even = even->next;
        }
        //join odd list with even list
        odd->next =evenHead;
        return head;
        
    }
};