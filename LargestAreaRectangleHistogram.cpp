#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int answer = INT_MIN;
    int leftSmaller[n];
    int rightSmaller[n];
    stack<int> st;
    

    for(int i = 0; i < n; ++i){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) leftSmaller[i] = 0;
        else leftSmaller[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int j = n-1; j >=0; j--){
        while(!st.empty() && heights[st.top()] >= heights[j]) st.pop();
        if(st.empty()) rightSmaller[j] = n-1;
        else rightSmaller[j] = st.top() - 1;

        answer = max(answer,  heights[j] * (rightSmaller[j] - leftSmaller[j] + 1));

        st.push(j);
    }
    return answer;
}

int maxRectangle(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> heights(n, 0);
    int ans = INT_MIN;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '0') heights[j] = 0;
            else heights[j] += 1;
        }
        ans = max(ans, largestRectangleArea(heights));
    }
    return ans;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
   // cout << largestRectangleArea(heights) << endl;

    vector<vector<int>> matrix = {{'1','0','1','0','0'}, 
                                    {'1','0','1','1','1'}, 
                                    {'1','1','1','1','1'}, 
                                    {'1','0','0','1','0'}};
                                
    cout << maxRectangle(matrix) << endl;
    return 0;
}