#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for ( string op : operations) {
            if (op == "+") {
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                
                s.push(top1);           
                s.push(top1 + top2);    
            } 
            else if (op == "D") {
                s.push(s.top() * 2);    
            } 
            else if (op == "C") {
                s.pop();                
            } 
            else {
                s.push(stoi(op));  
            }
        }

        int totalSum = 0;
        while (!s.empty()) {
            totalSum += s.top();
            s.pop();
        }

        return totalSum;
    }
};