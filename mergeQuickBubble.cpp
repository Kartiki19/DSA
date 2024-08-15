#include<iostream>
#include<vector>

using namespace std;

void printVector(const vector<int>& v){
    for(int i: v){
        cout << i << "\t";
    }
    cout<< endl;
}

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;

    int left = low, right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else if(arr[right] < arr[left]) temp.push_back(arr[right++]);
    }

    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i = low; i <= high; ++i){
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low >= high) return;
    int mid = low + (high-low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;

    while(i < j){
        while(arr[i] <= pivot && i < high) i++;
        while(arr[j] >= pivot && j > low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pid = partition(arr, low, high);
        quickSort(arr, low, pid-1);
        quickSort(arr, pid+1, high);
    }
}

void bubbleSort(vector<int>& arr, int n){
    bool swapped = false;
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n-1-i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
int main(){
    vector<int> arr = {20, 24, 2, 4, 9, 56, 10};
    int n = arr.size();

    vector<int> m = arr;
    vector<int> q = arr;
    vector<int> b = arr;

    cout << "\nOriginal array: " << endl;
    printVector(arr);

    mergeSort(m, 0, n-1);
    cout << "\nAfter Merge Sort: " << endl;
    printVector(m);

    quickSort(q, 0, n-1);
    cout << "\nAfter Quick Sort: " << endl;
    printVector(q);

    bubbleSort(b, n);
    cout << "\nAfter Bubble Sort: " << endl;
    printVector(b);


    return 0;
}