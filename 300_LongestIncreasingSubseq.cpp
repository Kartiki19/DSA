/*
DP using Tabulation
Time Compelxity = O(n2)
Space Compexity = O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int lengthOfLIS(const vector<int>& nums){ 
        int n = nums.size();
        int answer = 1;
        vector<int> dp(n); /// SC = O(n)
        dp[0] = 1;
        for(int i = 1; i < n; ++i){ /// TC = O(n-1)
            int maxLength = 1;
            for(int j = 0; j < i; ++j){ /// TC = O(n)
                if(nums[i] > nums[j]) maxLength = max(maxLength, dp[j]+1);
            }
            dp[i] = maxLength;
            answer = max(answer, maxLength);
        }

        return answer;
    }
};
int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums_1 = {0,1,0,3,2,3};
    vector<int> nums_2 = {7,7,7,7,7,7,7};
    vector<int> nums_3 = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    Solution s;
    cout << "Longest Increasing Subsequence lenght is : " << s.lengthOfLIS(nums_3) << endl;
    return 0;
}
