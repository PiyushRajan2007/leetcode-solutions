#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    // memo[pos][tight][is_started][last][last2]
    // pos up to 16, tight (2), is_started (2), last (11), last2 (11)
    long long memo[16][2][2][11][11];
    string s;

    // Helper to clear the memoization table
    void resetMemo() {
        memset(memo, -1, sizeof(memo));
    }

    long long dp(int pos, bool tight, bool is_started, int last, int last2) {
        // Base case: if we've reached the end of the string, no more waviness can be added
        if (pos == s.length()) {
            return 0;
        }

        // Return cached result if already calculated
        if (memo[pos][tight][is_started][last][last2] != -1) {
            return memo[pos][tight][is_started][last][last2];
        }

        long long total_waviness = 0;
        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = tight && (d == limit);
            bool next_started = is_started || (d > 0);

            long long waviness_contributed = 0;
            
            // Check if the previous digit (last) forms a peak or valley
            if (is_started && last2 != 10) { 
                if ((last > last2 && last > d) || (last < last2 && last < d)) {
                    waviness_contributed = 1;
                }
            }

            if (!next_started) {
                // If we haven't started yet (still placing leading zeros)
                total_waviness += dp(pos + 1, next_tight, false, 10, 10);
            } else {
                // If we have started or are starting right now
                int next_last = d;
                int next_last2 = is_started ? last : 10;

                // 1. Waviness propagated from deeper transitions
                long long future_waviness = dp(pos + 1, next_tight, true, next_last, next_last2);
                
                // 2. The local waviness contribution at 'last' multiplied by the number of valid sequences it can form
                long long ways_to_form_sequences = countWays(pos + 1, next_tight, true, next_last, next_last2);

                total_waviness += future_waviness + waviness_contributed * ways_to_form_sequences;
            }
        }

        return memo[pos][tight][is_started][last][last2] = total_waviness;
    }

    // Secondary DP table to count total valid combinations/numbers that can be formed from a state
    long long count_memo[16][2][2][11][11];
    
    long long countWays(int pos, bool tight, bool is_started, int last, int last2) {
        if (pos == s.length()) {
            return is_started ? 1 : 0;
        }
        if (count_memo[pos][tight][is_started][last][last2] != -1) {
            return count_memo[pos][tight][is_started][last][last2];
        }

        long long ways = 0;
        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = tight && (d == limit);
            bool next_started = is_started || (d > 0);

            if (!next_started) {
                ways += countWays(pos + 1, next_tight, false, 10, 10);
            } else {
                ways += countWays(pos + 1, next_tight, true, d, is_started ? last : 10);
            }
        }
        return count_memo[pos][tight][is_started][last][last2] = ways;
    }

    long long solve(long long num) {
        if (num < 100) return 0; // Waviness is 0 for numbers with fewer than 3 digits
        s = to_string(num);
        
        memset(memo, -1, sizeof(memo));
        memset(count_memo, -1, sizeof(count_memo));
        
        return dp(0, true, false, 10, 10); // 10 denotes a dummy/empty digit state
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};