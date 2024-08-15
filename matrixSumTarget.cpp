#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int calculateSum(int colStart, int colEnd, int rowStart, int rowEnd, const vector<vector<int>>& matrix){
    int sum = 0;
    for(int row = rowStart; row <= rowEnd; ++row){
        for(int col = colStart; col <= colEnd; ++col){
            sum += matrix[row][col];
        }
    }
    return sum;
}
int numSubmatrixSumTargetBrute(const vector<vector<int>>& matrix, const int& target){
    int answer = 0, m = matrix.size(), n = matrix[0].size();

    for(int colStart = 0; colStart < n; ++colStart){
        for(int colEnd = colStart; colEnd < n; ++colEnd){
            for(int rowStart = 0; rowStart < m; ++rowStart){
                for(int rowEnd = rowStart; rowEnd < m; ++rowEnd){
                    if(calculateSum(colStart, colEnd, rowStart, rowEnd, matrix) == target)
                        answer++;
                }
            }
        }
    }
    return answer;
}
int numSubmatrixSumTargetOptimal(const vector<vector<int>>& matrix, const int& target){
    int ans = 0, m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix_mat = matrix;

    for(int i = 0 ; i < m; ++i){
        for(int j = 1; j < n; ++j){
            prefix_mat[i][j] += prefix_mat[i][j-1];
        }
    }

    unordered_map<int, int> prefix_map;
    for(int colStart = 0; colStart < n; ++colStart){
        for(int colEnd = colStart; colEnd < n; ++colEnd){
            prefix_map = {{0, 1}};
            int sum = 0;
            for(int row = 0; row < m; ++row){
                sum += prefix_mat[row][colEnd] - (colStart ? prefix_mat[row][colStart-1] : 0);
                ans += prefix_map[sum-target];
                prefix_map[sum]++;
            }
        }
    }
    return ans;
}
    

int numSubmatrixSumTargetBetter(const vector<vector<int>>& matrix, const int& target){
    int ans = 0, m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix_mat = matrix;

    /// O(MN)
    for(int i = 0 ; i < m; ++i){
        for(int j = 1; j < n; ++j){
            prefix_mat[i][j] += prefix_mat[i][j-1];
        }
    }

    /// O(N2M2)
    for(int colStart = 0; colStart < n; ++colStart){ /// O(N)
        for(int colEnd = colStart; colEnd < n; ++colEnd){ /// O(N)
            for(int rowStart = 0; rowStart < m; ++rowStart){ /// (O(M))
                int sum = 0;
                for(int rowEnd = rowStart; rowEnd < m; ++rowEnd){ /// O(M)
                    sum += prefix_mat[rowEnd][colEnd] - (colStart ? prefix_mat[rowEnd][colStart-1] : 0);
                    if(sum == target) ans++;
                }
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> matrix = {{0,1,0}, {1,1,1}, {0,1,0}};
    int target = 0;
    ///cout << numSubmatrixSumTargetBrute(matrix, target);
    ///cout << numSubmatrixSumTargetOptimal(matrix, target);
    cout << numSubmatrixSumTargetBetter(matrix, target); /// O(MN) + O((MN)2) = O(M2N2)
    return 0;
}