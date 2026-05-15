class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If middle element is greater than the last element,
            // the minimum lies in the right half.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, the minimum is in the left half (including mid).
            else {
                high = mid;
            }
        }

        // low == high, pointing to the minimum element
        return nums[low];
    }
};