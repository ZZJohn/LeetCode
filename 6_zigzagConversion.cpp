string convert(string s, int numRows)
{
	if(numRows == 1) return s;
	vector<vector<char>> text(numRows, vector<char>());
	string res;
	int curr = 0;
	int ind = 1;
	for(int i=0; i<s.size(); i++)
	{
		text[curr].push_back(s[i]);
		if(curr == numRows-1)
			ind = -1;
		else if(curr == 0)
			ind = 1;
		curr += ind;
	}
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<text[i].size(); j++)
			res += text[i][j];
	}
	return res;
}