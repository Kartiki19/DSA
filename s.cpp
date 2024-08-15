#include <vector>
#include<iostream>
#include <unordered_map>
using namespace std;

int solution(vector<int>& arr) {
    int n = arr.size();
    vector<long long> prefixSum(n + 1, 0);
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j] && arr[i] == (prefixSum[i] - prefixSum[j + 1])) {
                ++count;
            }
        }
    }
    
    return count;
}


int main(){
    vector<int> arr = {2, 1, 1, 2, 6, 2, 1, 1, 2, 6};
    cout << solution(arr);
    return 0;
}