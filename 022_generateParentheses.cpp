vector<string> generateParenthesis(int n)
{
	vector<string> result;
	generate(result, n, n, "");
	return result;
}

void generate(vector<string>& result, int left, int right, string element)
{
	if(left == 0 && right == 0) result.push_back(element);
	if(left > 0) generate(result, left-1, right, element + '(');
	if(right > 0 && right > left) generate(result, left, right-1, element + ')');
}