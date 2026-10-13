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
        if(!head->next)return;
        int len = 0;
        ListNode* temp = head;
        vector<int> nodeVal;
        while(temp){
            len++;
            nodeVal.push_back(temp->val);
            temp = temp->next;
        }
        temp = head->next;
        int l=1,r=len-1;
        for(int i=1;i<len;i++){
            if(i%2){
                temp->val = nodeVal[r];
                r--;
            }
            else{
                temp->val = nodeVal[l];
                l++;
            }
            temp = temp->next;
        }
    }
};
