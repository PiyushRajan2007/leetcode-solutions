class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        int f=-1,l=-1,m=1e9,i=1,p=h->val;
        
        for(h=h->next;h->next;h=h->next,i++){
            if((h->val>p&&h->val>h->next->val)||
               (h->val<p&&h->val<h->next->val)){
                if(f<0) f=i;
                else m=min(m,i-l);
                l=i;
            }
            p=h->val;
        }
        
        return f==l?vector<int>{-1,-1}:vector<int>{m,l-f};
    }
};