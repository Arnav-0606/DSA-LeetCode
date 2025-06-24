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
    ListNode * reverse(ListNode * head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;       
        }
        return prev;
    }
    void merge(ListNode* l1,ListNode * l2){
        while(l1 and l2){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            l1->next = l2;
            if (!l1_next) break;
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *  l2 = reverse(slow->next);
        slow->next = NULL;
        merge(head,l2);
    }
};