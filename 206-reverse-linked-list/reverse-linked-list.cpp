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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            //1. save the next node
            ListNode* next = curr->next;

            //2.Reverse the poiter
            curr->next =prev;

            //3. Move prev forward
            prev = curr;

            //4. Move curr forward
            curr = next;

        }
        return prev;
    }
};