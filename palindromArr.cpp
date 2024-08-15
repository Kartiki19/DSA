#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {3, 4, 5, 6, 5, 3};

    int l = 0;
    int r = arr.size()-1;

    while(l < r){
        if(arr[l] != arr[r]){
            cout << "false";
            return 0;
        } 
        l++;
        r--;
    }
    cout << "true";

    return 0;
}