// Source : https://oj.leetcode.com/problems/valid-sudoku/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* 
* A partially filled sudoku which is valid.
* 
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
* 
*               
**********************************************************************************/
#if 0
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int cnt = 9;
        bool row_mask[cnt][cnt] = {false};
        bool col_mask[cnt][cnt] = {false};
        bool area_mask[cnt][cnt] = {false};
        //check each rows and cols
        for(int r=0; r<board.size(); r++){
            for (int c=0; c<board[r].size(); c++){
                if (!isdigit(board[r][c])) continue;
                int idx =  board[r][c] - '0' - 1;
                
                //check the rows
                if (row_mask[r][idx] == true){
                    return false;
                }
                row_mask[r][idx] = true;
                
                //check the cols
                if (col_mask[c][idx] == true) {
                    return false;
                }
                col_mask[c][idx] = true;
                
                //check the areas
                int area = (r/3) * 3 + (c/3);
                if (area_mask[area][idx] == true) {
                    return false;
                }
                area_mask[area][idx] = true;
            }
        }
        
        return true;
    }
};
#else

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	int len = 9;
	int row[len][len] = {false};
	int col[len][len] = {false};
	int area[len][len] = {false};
	int r = 0;
	int c = 0;
	int num = 0;
	int index = 0;
	int n = 0;
	
	for (r = 0; r < boardRowSize; r++ )
	{
		for (c = 0; c < boardColSize; c++)
		{
			if (!isdigit(board[r][c])) continue;

			num = board[r][c] - '0' - 1;
			
			if (row[r][num] == true) return false;
			row[r][num] = true;

			if (col[c][num] == true) return false;
			col[c][num] = true;			

			index = (r / 3) * 3 + (c / 3);
			if (area[index][num] == true) return false;
			r[r][num] = true;
		}
	}

	return true;
}

#endif
