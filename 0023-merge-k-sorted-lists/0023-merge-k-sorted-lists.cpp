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

    ListNode* mergeTwo(ListNode*L, ListNode* R){
        if(L == NULL){
            return R;
        }else if(R == NULL){
            return L;
        }
        ListNode* tail = NULL;
        ListNode* head = NULL;

        if(L->val <= R-> val){
            head = L;
            tail = head;
            L = L->next;
        }else{
            head = R;
            tail = head;
            R = R->next;
        }

        while(L && R){
            if(L-> val <= R->val){
                tail -> next = L;
                tail = tail->next;
                L = L->next;
            }
            else{
                tail->next = R;
                tail = tail->next;
                R = R->next;
            }
        }

        if(L == NULL){
            tail ->next = R;
        }else{
            tail ->next = L;
        }
        return head;
    }

    ListNode* partition(int s, int e, vector<ListNode*> &lists){
        if(s>e){
            return NULL;
        }
        if(s == e){
            return lists[s];
        }

        int mid = s +(e-s)/2;
        ListNode* L = partition(s, mid, lists);
        ListNode* R = partition(mid+1, e, lists);

        return mergeTwo(L, R);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // // using priority queue
        // priority_queue <ListNode*, vector<ListNode*>, comparator> pq;
        // int n = lists.size();
        // // push first element of all ll
        // for(int i = 0; i<n; i++){
        //     ListNode* head = lists[i];
        //     if(head != NULL){
        //         pq.push(head);
        //     }
        // }

        // ListNode* head = NULL;
        // ListNode* tail = NULL;

        // while(!pq.empty()){
        //     ListNode* topele = pq.top();
        //     pq.pop();

        //     if(head == NULL){
        //         head = topele;
        //         tail = head;
        //         if(tail->next != NULL){
        //             pq.push(tail->next);
        //         }
        //     }
        //     else{
        //         tail->next = topele;
        //         tail = topele;
        //         if(tail->next != NULL){
        //             pq.push(tail->next);
        //         }
        //     }
        // }
        // return head;

        // // second approach 
        int n = lists.size();
        int s = 0;
        int e = n-1;

        return partition(s, e, lists);
    }
};