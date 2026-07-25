class Solution {
public:
    int maxProduct(int n) {
        vector<int> m ;
        while(n>0){
            int k = n%10 ;
            m.push_back(k);
            n /= 10 ;
        }
        sort(m.begin(),m.end());
        int t = m.size();
        return m[t-1] * m[t-2];
    }
};