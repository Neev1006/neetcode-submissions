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
    ListNode* mergeTwoLists(ListNode* l1 , ListNode* l2){
        if(!l1 && !l2)return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        while(t1 && t2){
            if(t1->val <= t2->val){
                t->next = t1;
                t1 = t1->next;
                t = t->next;
            }
            else{
                t->next = t2;
                t2 = t2->next;
                t = t->next;
            }
        }
        while(t1){
            t->next = t1;
            t1 = t1->next;
            t = t->next;
        }
        while(t2){
            t->next = t2;
            t2 = t2->next;
            t = t->next;
        }
        return dummy->next;
    }
    ListNode* divide(int l , int r , vector<ListNode*>& lists){
        if(l > r)return NULL;
        if(l == r)return lists[l];

        int m = (l+r)/2;
        ListNode* left = divide(l,m,lists);
        ListNode* right = divide(m+1,r,lists);
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        if(lists.size() == 1)return lists[0];
        return divide(0,lists.size()-1,lists);
    }
};
