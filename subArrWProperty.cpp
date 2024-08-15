#include<iostream>
#include<vector>
using namespace std;

int solution(vector<int>& arr){
    int count = 0;
    int n = arr.size();
    vector<int> prefixsum(n+1, 0);
    for(int i = 0; i < n; ++i){
        prefixsum[i+1] = prefixsum[i] + arr[i];
    }

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[i] == arr[j] && prefixsum[i] - prefixsum[j+1] == arr[i])
                count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {2, 1, 1, 2, 6, 2, 1, 1, 2, 6};
    cout << solution(arr);
    return 0;
}