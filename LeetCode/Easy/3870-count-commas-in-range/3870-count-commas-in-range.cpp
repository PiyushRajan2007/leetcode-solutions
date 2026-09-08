class Solution {
public:
    int countCommas(int n) {
       if(n<1000)
       return 0;
       else if(n==1000)
        return 1;
        else 
        return n - 1000 + 1; 
         
    }
};