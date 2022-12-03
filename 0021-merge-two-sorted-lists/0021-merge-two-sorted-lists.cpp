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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        
        ListNode *tail=nullptr, *head=nullptr;
        
        if(list1->val <= list2->val)
        {
            tail=head=list1;
            list1=list1->next;
        }
        else 
        {
            tail=head=list2;
            list2=list2->next;
        }
        
        while(list1 and list2)
        {
            if(list1->val <= list2->val)
            {
                tail->next=list1; tail=list1; list1=list1->next; 
            }
            else 
            {
                tail->next=list2; tail=list2; list2=list2->next; 
            }
        }
        if(list1==nullptr) tail->next=list2;
        else tail->next=list1;
        return head;
    }
};