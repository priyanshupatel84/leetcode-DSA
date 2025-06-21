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
    ListNode *detectCycle(ListNode *head) {
    ListNode* temp = head;
    unordered_map<ListNode*, int> mp;
    int flag = 0;

    while(temp != NULL)
    {
        mp[temp]++;
        if(mp[temp] == 2)
        {
            flag = 1;
            break;
        }
        temp = temp-> next;
    }
    if(flag == 0) return NULL;
    else{
        return temp;
    }

    }
};