/*
Used Unordered Hash Set (For ordered set time complexity is O(log n))
Time Complexity = O(n+m.log10(max_element))
Space Complexity = O(log10(max_elelment))
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
    public:
    void createHashSet(vector<int>& arr, unordered_set<int>& prefixSet){
        for(int num: arr){ /// O(n)
            while(num){ /// O(log10(num)+1)
                prefixSet.insert(num); /// O(1) -> average case
                num = num/10;
            }
        }
    }
    void findLongestPrefix(vector<int>& arr, unordered_set<int>& prefixSet, int& ans){
        for(int num: arr){ /// O(m)
            while(num){ /// O(log10(num)+1)
                if(prefixSet.find(num) != prefixSet.end()){ /// O(1) -> avg
                    ans = max(static_cast<int>(log10(num)+1), ans);
                    break;
                }
                num  = num / 10;
            }
        }
    }
    int calculateLongestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_set<int> prefixSet; /// O(log10(max_element)+1)
        int ans = 0;
        (n1 < n2) ? createHashSet(arr1, prefixSet) : createHashSet(arr2, prefixSet); /// O(n. log10(max_element)))
        (n1 < n2) ? findLongestPrefix(arr2, prefixSet, ans) : findLongestPrefix(arr1, prefixSet, ans); /// O(m.log10(max_element))
        return ans;
    }
};

int main(){
    vector<int> arr1 = {1, 12, 1000, 1234};
    vector<int> arr2 = {4};

    Solution s;
    cout << s.calculateLongestCommonPrefix(arr1, arr2);
    
    return 0;
}