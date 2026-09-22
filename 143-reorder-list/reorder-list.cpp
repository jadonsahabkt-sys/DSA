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
    void reorderList(ListNode* head) {
        if(head ==NULL || head->next == NULL)
        return;
        //Step 1: find middle
        ListNode* slow = head;
        ListNode* fast  = head;
        while(fast !=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //step 2: Reverse second half 
        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        slow->next=NULL; // split the list

        while(curr != NULL){
            ListNode* next= curr->next;
            curr->next=prev;
            prev =curr;
            curr=next;
        }
        //prev = head of reversed second half

        //step 3. Merge both halves
        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL){
            ListNode* temp1= first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;

            first = temp1;
            second = temp2;
        }

    }
};