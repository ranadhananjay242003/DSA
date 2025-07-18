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
        if(!head||!head->next||k==0){
            return head;
        }

        int len = 1;
        ListNode* last = head;
        while(last->next){
            len++;
            last = last->next;
        }
        last->next = head;
        k=k%len;
        int whereissecondlast = len-k;

        ListNode* second = head;

        for(int i=1; i<whereissecondlast;i++){
            second=second->next;
        }

        ListNode* newhead =  second->next;
        second->next = nullptr;
        return newhead;
        
    }
};