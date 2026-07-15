class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int sumOdd = 0;
      int sumEven = 0;
      for(int i = 0 ; i < 2*n + 1 ; i++ ){
        if ( i%2 == 0){
            sumEven+=i;
        }
        else
        sumOdd += i ;
      }  
      return std::gcd(sumOdd, sumEven);
    }
};