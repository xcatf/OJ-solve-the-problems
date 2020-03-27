/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode*l1,ListNode*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeHalf(int l,int r,vector<ListNode*>& lists){
        if(l==r) return lists[l];
        int mid=(l+r)>>1;
        ListNode* l1=mergeHalf(l,mid,lists);
        ListNode* l2=mergeHalf(mid+1,r,lists);
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeHalf(0,lists.size()-1,lists);
    }
};