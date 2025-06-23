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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;
        int cnt1 = 0;
        
        int cnt2 = 0;
        ListNode* temp = head;
        while(temp){
            cnt1++;
            temp = temp->next;
        }

        ListNode* del = head;
        ListNode* prev = head;
        if(cnt1 == n){
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        while(del!= NULL){
            cnt2++;
            if(cnt2 == cnt1 - n+1){
                prev->next = del->next;
                delete del;
                break;
            }
            prev = del;
            del = del->next;
        }
    return head;
    }
};