vector<string> restoreIpAddresses(string s)
{
	vector<string> res;
	string path;
	helper(0, 0, path, s, res);
	return res;
}

void helper(int pos, int num, string path, string s, vector<string>& res)
{
	if(pos == s.size() && num == 4)
	{
		res.push_back(path.substr(0, path.size()-1));
		return;
	}
	if(s.size()-pos>3*(4-num))
		return;
	if(pos <= s.size()-1)
	{
		path += s.substr(pos, 1) + ".";
		helper(pos+1, num+1, path, s, res);
		path = path.substr(0, path.size()-2);
	}
	if(pos <= s.size()-2 && s.substr(pos, 1) != "0")
	{
		path += s.substr(pos, 2) + ".";
		helper(pos+2, num+1, path, s, res);
		path = path.substr(0, path.size()-3);
	}
	if(pos <= s.size()-3 && s.substr(pos, 1) != "0" && s.substr(pos, 3) <= "255")
	{
		path += s.substr(pos, 3) + ".";
		helper(pos+3, num+1, path, s, res);
		path = path.substr(0, path.size()-4);
	}
	return;
}
