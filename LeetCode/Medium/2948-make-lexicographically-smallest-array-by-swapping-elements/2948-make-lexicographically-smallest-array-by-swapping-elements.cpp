class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
         
            while (j < n && (j == i || (arr[j].first - arr[j - 1].first <= limit))) {
                j++;
            }
            
          
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(arr[k].second);
            }
            
            sort(indices.begin(), indices.end());
            
        
            for (int k = 0; k < indices.size(); ++k) {
                res[indices[k]] = arr[i + k].first;
            }
            
            i = j;
        }
        
        return res;
    }
};