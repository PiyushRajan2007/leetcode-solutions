class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Optimize unordered_set to avoid heavy re-hashing and collisions
        unordered_set<int> st(nums.begin(), nums.end());
        
        int longestStreak = 0;

        for (int num : st) {
            // Check if it's the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};