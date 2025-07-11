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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = head;
        ListNode* nex = head;
        while(temp){
            if(temp->next == slow){
                nex = nex->next->next;
                temp->next = slow->next;
                delete slow;
                break;
            }
            nex = nex->next;
            temp = temp->next;
        }
        return head;
    }
};