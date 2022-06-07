#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board,vector<vector<int>>& ans, int n) {
        vector<int> temp;
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }
    bool isSafe(int x, int y, vector<vector<int>>& board, int n){
        
        int row = x;
        int col = y;
        
        // check for same row (row, col--)
        while(col >= 0 ){
            if(board[row][col] == 1){
                return false;
            }
            col--;
        }
        
        row = x;
        col = y;
        //check for the diagonal
        // In both reducing condition i.e in above section of the row |
        while(row >=0 && col >= 0){
            if(board[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }
        row = x;
        col = y;
        // now in below level
        while(row < n && col >= 0){
            if(board[row][col] == 1){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<vector<int>>& board,vector<vector<int>>& ans, int n) {
        
        //base condition
        if(col == n){
            addSolution(board, ans, n);
            return;
        }
        // 1 case solve karni hain 
        for(int i=0;i<n;i++){
            if(isSafe(i,col, board, n)){
                board[i][col] = 1;
                solve(col+1, board, ans, n);
                //backtracking
                board[i][col] = 0;
            }
        }
    }
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        solve(0, board, ans, n);
        return ans;
}
