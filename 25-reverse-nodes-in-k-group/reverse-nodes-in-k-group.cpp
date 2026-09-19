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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Dummy node 
        ListNode* dummy = new ListNode(0);
        dummy->next=head;

        ListNode* groupPrev = dummy;
        while(true){
            //Find kth node
            ListNode* kth=groupPrev;
            for(int i=0;i<k;i++){
                kth = kth->next;

                // Less than k nodes remaining
                if(kth == NULL){
                    return dummy->next;
                }

            }
            //Node after current group
            ListNode* groupNext = kth->next;
            //Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev = curr;
                curr=temp;
            }
            //connect previous group to reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next=kth;
            //Move groupPrev to end of reversed group
            groupPrev=temp;

        }
        return dummy->next;
    }
};