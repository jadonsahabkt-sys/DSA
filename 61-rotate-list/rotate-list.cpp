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
    ListNode* rotateRight(ListNode* head, int k) {
        // Empty list or single node
        if(head == NULL || head->next == NULL || k==0)
        return head;
        // find length and tail
        int n=1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail=tail->next;
            n++;
        }
        // Remove unnecessary rotations
        k=k%n;
        if(k==0)
        return head;
       //make circular list
       tail->next=head;
       //find new tail
       int steps = n-k;
       ListNode* newTail = head;
       for(int i=1;i<steps;i++){
          newTail=newTail->next;
       }
       //New head is next of new tail
       ListNode* newHead=newTail->next;
       //Break the circle
       newTail->next=NULL;

       return newHead;
    }
};