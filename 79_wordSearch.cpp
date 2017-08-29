bool exist(vector<vector<char>>& board, string word)
{
	int m = board.size();
	if(m == 0) return false;
	int n = board[0].size();
	vector<vector<int>> visited(m, vector<int>(n, 0));
	string tmp;
	int count = 0;
    for(int i=0; i<=m-1; i++)
		for(int j=0; j<=n-1; j++)
		{
			if(board[i][j]==word[0])
			{
				if(DFS(board, word, i, j, count, visited))
					return true;
			}
		}
	return false;
}

bool DFS(vector<vector<char>>& board, string word, int row, int col, int count, vector<vector<int>> visited)
{
	count++;
	if(count == word.size())
		return true;
	visited[row][col] = 1;
	int m = board.size();
	int n = board[0].size();
	if(row+1<=m-1 && board[row+1][col]==word[count] && visited[row+1][col] == 0)
		if(DFS(board, word, row+1, col, count, visited))
			return true;
	if(row-1>=0 && board[row-1][col]==word[count] && visited[row-1][col] == 0)
		if(DFS(board, word, row-1, col, count, visited))
			return true;
	if(col+1<=n-1 && board[row][col+1]==word[count] && visited[row][col+1] == 0)
		if(DFS(board, word, row, col+1, count, visited))
			return true;
	if(col-1>=0 && board[row][col-1]==word[count] && visited[row][col-1] == 0)
		if(DFS(board, word, row, col-1, count, visited))
			return true;
	visited[row][col] == 0;
	return false;
}

