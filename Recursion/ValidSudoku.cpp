
bool isSafe(int row,int  col,int matrix[][9],int val){
    for(int i=0;i<9;i++){
        //row check
        if(matrix[row][i] == val){
            return false;
        }
        if(matrix[i][col] == val){
            return false;
        }
        // 3*3 ka matrix check karna hain
        if(matrix[3*(row/3) + i/3][3*(col/3)+i%3] == val){
            return false;
        }
    }
    return true;
}
bool solve(int matrix[][9]){
    int n = 9;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(matrix[row][col] == 0){
                for(int val =1 ;val<=9;val++){
                    if(isSafe(row, col, matrix, val)){
                        matrix[row][col] = val;
                        // aage recursion sambhal lega
                         bool nextSol = solve(matrix);
                        if(nextSol) {
                            return true;
                        }
                        else{
                            //backtrack
                            matrix[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }   
    }
    return true; 
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    solve(matrix);
}
