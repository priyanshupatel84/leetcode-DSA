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
        ListNode* prev = new ListNode(0);
        ListNode* head = NULL;

        if( list1 == NULL){
            return list2;
        }else if(list2 == NULL){
            return list1;
        }

        if(list1 -> val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2 -> next;
        }

        prev = head;

        while( list1 && list2){
            if(list1-> val <= list2-> val){
                prev -> next = list1;
                prev = prev->next;
                list1 = list1 -> next;
                cout << prev->val;
            }
            else if(list2 -> val < list1->val){
                prev -> next = list2;
                prev = prev -> next;
                list2 = list2-> next;
                cout << prev->val;
            }
        }

        if(!list1){
            prev -> next = list2;
        }
        else if(list2 == NULL) {
            prev ->next = list1;
        }

        return head;
    }
};