class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int check = 0;

        while (temp != NULL && check < k) {
            temp = temp->next;
            check++;
        }
        if (check < k) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        check = 0;
        while (curr != NULL && check < k) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            check++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
return prev;
    }
};
