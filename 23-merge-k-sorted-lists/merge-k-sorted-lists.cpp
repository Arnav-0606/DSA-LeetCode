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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) minHeap.push({lists[i]->val,lists[i]});
        }
        ListNode * n = new ListNode(0);
        ListNode * temp =n;
        while(!minHeap.empty()){
            auto [v,adr] = minHeap.top();
            temp->next = adr;
            temp = temp->next;
            minHeap.pop();
            if (adr->next) {
                minHeap.push({adr->next->val, adr->next});
            }
        }
        return n->next;
    }
};