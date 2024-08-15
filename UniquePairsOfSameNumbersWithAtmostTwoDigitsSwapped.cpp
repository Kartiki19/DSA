#include<iostream>
using namespace std;
#include<map>
#include<vector>

bool differByAtmostTwoDigits(const string& cur_str, const string& str){
    int diffCount = 0;
    for(int i = 0; i < str.size(); ++i){
        if(cur_str[i] != str[i]){
            diffCount++;
            if(diffCount > 2) return false;
        }
    }
    return  diffCount <= 2;
}
int countPairs(const vector<int>& nums){
    int count = 0;

    unordered_map<string, vector<string>>  sortedStrs;

    for(int i = 0; i < nums.size(); ++i){
        string cur_str = to_string(nums[i]);
        string sorted_cur_str = cur_str;
        sort(sorted_cur_str.begin(), sorted_cur_str.end());

        if(sortedStrs.find(sorted_cur_str) != sortedStrs.end()){
            for(string it : sortedStrs[sorted_cur_str]){
                if(differByAtmostTwoDigits(cur_str, it)){
                    count++;
                }
            }
        }
        sortedStrs[sorted_cur_str].push_back(cur_str);
    }
    return count;
}

int main() {
    vector<int> nums = {1, 23, 156, 1650, 651, 165, 32};
    int result = countPairs(nums);
    cout << "Number of distinct pairs: " << result << endl; // Output should be 3
    return 0;
}