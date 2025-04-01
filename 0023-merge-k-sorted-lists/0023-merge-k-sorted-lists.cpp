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
class comparator{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using priority queue
        priority_queue <ListNode*, vector<ListNode*>, comparator> pq;
        int n = lists.size();


        // push first element of all ll
        for(int i = 0; i<n; i++){
            ListNode* head = lists[i];
            if(head != NULL){
                pq.push(head);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* topele = pq.top();
            pq.pop();

            if(head == NULL){
                head = topele;
                tail = head;
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
            else{
                tail->next = topele;
                tail = topele;
                if(tail->next != NULL){
                    pq.push(tail->next);
                }
            }
        }

        return head;
    }
};