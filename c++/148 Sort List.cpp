// Source : https://leetcode.com/problems/sort-list/
// Author : FangY
// Date   : 2019-1-10
/*******************************************************************************
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*******************************************************************************/
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;//用于切断链表
        return merge(sortList(head),sortList(slow));

    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1) temp->next=l1;
        if(l2) temp->next=l2;
        return head->next;
    }
};



