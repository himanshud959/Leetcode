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
    ListNode* swapNodes(ListNode* head, int k) {
        // vector<int>temp;
        // ListNode *che=head;
        // for(ListNode *curr=head;curr!=NULL;curr=curr->next)
        // {
        //     temp.push_back(curr->val);
        // }
        // int n=size(temp);
        // swap(temp[k-1],temp[n-k]);
        // reverse(temp.begin(),temp.end());
        // for(ListNode *curr=head;curr!=NULL;curr=curr->next)
        // {
        //     curr->val=temp.back();
        //     temp.pop_back();
        // }
        // return head;
        
        ListNode *p1 = head;
        for(int i=1; i<k; i++)
            p1 = p1->next;
    
        ListNode *slow = head, *fast = p1->next;
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    
        swap(slow->val, p1->val);
        return head;
    }
};