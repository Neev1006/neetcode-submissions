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
        ListNode* newHead = head;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(n==len)return head->next;
        temp = head;
        for(int i=0;i<len-n-1;i++){
            temp = temp->next;
        }
        ListNode* t2 = temp->next;
        temp->next = t2->next;
        delete t2;
        return head;
    }
};
