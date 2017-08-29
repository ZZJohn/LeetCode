bool isValidSudoku(vector<vector<char>>& board)
{
	for(int i=0; i<=8; i++)
	{
		unordered_map<char, bool> row;
		unordered_map<char, bool> col;
		unordered_map<char, bool> square;
		for(int j=0; j<=8; j++)
		{
			if(board[i][j]!='.')
			{
				if(row[board[i][j]] == true)
					return false;
				row[board[i][j]] = true;
			}
			if(board[j][i]!='.')
			{
				if(col[board[j][i]] == true)
					return false;
				col[board[j][i]] = true;
			}
			if(board[i/3*3+j/3][i%3*3+j%3]!='.')
			{
				if(square[board[i/3*3+j/3][i%3*3+j%3]] == true)
					return false;
				square[board[i/3*3+j/3][i%3*3+j%3]] = true;
			}
		}
	}
	return true;
}