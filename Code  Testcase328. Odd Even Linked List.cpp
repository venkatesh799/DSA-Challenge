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
        ListNode *even_head, *odd_head, *even, *odd;
        if(head == NULL) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }
        if(head->next->next == NULL) {
            return head;
        }
        even_head = head->next;
        even = head->next;
        odd_head = head;
        odd = head;
        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return odd_head;
    }
};
