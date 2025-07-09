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
    ListNode* oddEvenList(ListNode* head) {
         if (!head or !head->next) return head;
        int cnt=1;
        ListNode * oddit = head;
        ListNode * t = head->next;
        ListNode * n = new ListNode(0);
        ListNode * evenit = n;
        while(t){
            cnt++;
            ListNode * next = t->next;
            t->next = NULL;
            if(cnt&1){
                oddit->next = t;
                oddit = oddit->next;
            }
            else{
                evenit ->next = t;
                evenit = evenit->next;
            }
            t = next;
        }
        oddit->next = n->next;
        return head;
        
    }
};