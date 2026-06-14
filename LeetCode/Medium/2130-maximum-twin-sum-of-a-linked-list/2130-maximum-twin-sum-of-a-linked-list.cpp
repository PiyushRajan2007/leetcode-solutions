class Solution {
public:
    int pairSum(ListNode* head) {

        stack<int> s;

        int n = 0;
        ListNode* temp = head;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        ListNode* curr = head;

        for(int i = 0; i < n/2; i++){
            s.push(curr->val);
            curr = curr->next;
        }

        int ans = 0;

        while(curr != NULL){
            int sum = s.top() + curr->val;
            ans = max(ans, sum);
            s.pop();
            curr = curr->next;
        }

        return ans;
    }
};