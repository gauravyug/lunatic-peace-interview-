/**
 * 
 *@gaurav yadav
 * 
	84. Largest Rectangle in Histogram
	https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 * Maintain a stack
 * 
	a. If stack is empty  height[stack.top()] <= height[i])
		push this i into stack.
 * 	b. Else keep popooing from stack till value at i at top of stack is 
		less than value at current index.
	c. While popping calculate area
		if stack is empty 
			 area = i * height[top];
			it means that till this point value just removed has to be smallest element
 * 		if stack is not empty 
			area = height[top] * (i - stack.top() - 1);
			
 * Finally return maxArea

 * Time complexity is O(n)
 * Space complexity is O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int area = 0;
        int maxArea = 0;
        stack <int> s;
        int i;
        for (i = 0; i < height.size();) {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i++);
            }
            else {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    area = i * height[top];
                }
                else {
                    area = height[top] * (i- s.top() -1); 
                }
                if (area > maxArea)
                    maxArea = area;
            }
        }

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            if (s.empty()) {
                area = i * height[top];
            }
            else {
                area = height[top] * (i- s.top() -1); 
            }
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};
    /* On2 solutions
    int largestRectangleArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        //!!!!!!TLE when test input size is large!!!!!!!
        int maxArea = 0;
        for(int i = 0; i < height.size(); ++i){
            int minHeight = height[i];
            maxArea = max(maxArea, minHeight * 1);
            for(int j = i + 1; j < height.size(); ++j){
                minHeight = min(minHeight, height[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        return maxArea;
    }*/