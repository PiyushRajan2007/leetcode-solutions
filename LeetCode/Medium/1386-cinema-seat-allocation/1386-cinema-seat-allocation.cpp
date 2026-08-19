class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Store reserved seats as a bitmask
        for (auto &r : reservedSeats) {
            int row = r[0];
            int seat = r[1];

            if (seat >= 2 && seat <= 9)
                mp[row] |= (1 << (seat - 2));
        }

        // Rows with no relevant reservations can have 2 groups
        int ans = 2 * (n - mp.size());

        for (auto &[row, mask] : mp) {

            // Seats 2,3,4,5
            bool left = (mask & 0b00001111) == 0;

            // Seats 4,5,6,7
            bool middle = (mask & 0b00111100) == 0;

            // Seats 6,7,8,9
            bool right = (mask & 0b11110000) == 0;

            // Left and right blocks don't overlap
            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};