#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<int>& arr, int x, int y, int operations) {
    long long total = 0;
    for (int num : arr) {
        if (num > operations * y) {
            total += (num - operations * y + x - 1) / x;
        }
    }
    return total <= operations;
}

int minOperationsToZero(vector<int>& arr, int x, int y) {
    int left = 0, right = *max_element(arr.begin(), arr.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(arr, x, y, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> arr = {10, 20, 30};
    int x = 5;
    int y = 1;
    int result = minOperationsToZero(arr, x, y); // result should be 10
    return 0;
}