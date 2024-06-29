/// Time Complexity = O(nm)
/// Space Complexity = O(nm) -> for board copy for simultaneous check

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
        int n = 0; int m = 0;
    public:
    int calculateLiveNeighbors(vector<vector<int>>& board, int i, int j){ /// O(9) -> constant
        int liveNeighboars = 0;
        vector<int> deltaRow = {-1, 0, 1};
        vector<int> deltaCol = {-1, 0, 1};

        for(int dr = 0; dr < 3; dr++){ /// O(3)
            for(int dc = 0; dc < 3; dc++){ /// O(3)
                if(dr == 1 && dc == 1) continue;
                if(i+deltaRow[dr] >= 0 && i+deltaRow[dr] < n &&
                    j+deltaCol[dc] >= 0 && j+deltaCol[dc] < m && 
                    board[i+deltaRow[dr]][j+deltaCol[dc]] == 1) liveNeighboars++;
            }
        }
        return liveNeighboars;
    }
    void gameOfLife(vector<vector<int>>& board){ 
        /// O(n.m)
        n = board.size();
        m = board[0].size();

        vector<vector<int>> board_copy = board; /// O(nm) = SC
        for(int i = 0; i < n; ++i) /// O(n)
        {
            for(int j = 0; j < m; ++j) /// O(m)
            {
                int liveNeighborsCount = calculateLiveNeighbors(board_copy, i, j); /// O(9) -> constant -> O(1)
                ///cout<< "Live Neighbors for " << i << ", " << j << " is: " << liveNeighborsCount << endl;
                if(board_copy[i][j] == 0 && liveNeighborsCount == 3) {
                    board[i][j] = 1;
                }
                else if(board_copy[i][j] == 1 && (liveNeighborsCount > 3 || liveNeighborsCount < 2)){
                    board[i][j] = 0;
                }
            }
        }
    }

    void displayBoard(vector<vector<int>>& board){
        cout << "Board : " << endl;
        for(auto v : board){
            for(int num: v){
                cout << num << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main(){
    vector<vector<int>> board_1 = {
        {1, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    vector<vector<int>> board_2 = {
        {1, 1},
        {1, 0}
    };
    
    Solution s;

    cout << "Before: " << endl;
    s.displayBoard(board_2);
    
    s.gameOfLife(board_2);  /// O(n.m)

    cout << "After: " << endl;
    s.displayBoard(board_2);
    return 0;
}