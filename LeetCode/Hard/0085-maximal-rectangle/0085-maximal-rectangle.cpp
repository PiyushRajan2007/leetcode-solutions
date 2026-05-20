class Solution {
public:
    // Largest Rectangle in Histogram - O(n)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);   // Sentinel to process all bars
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back(); //original vector
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int answer = 0;

        for (int i = 0; i < rows; i++) {
            //histogram for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            // Find largest rectangle 
            answer = max(answer, largestRectangleArea(heights));
        }

        return answer;
    }
};