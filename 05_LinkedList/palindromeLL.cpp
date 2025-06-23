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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next ) return true;

        ListNode* slow= head;
        ListNode* fast = head;
        // to find mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // to reverse the second half

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //compare first and second half

        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;

    }
};