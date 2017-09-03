bool isValid(string s)
{
	stack<char> parentheses;
	int n = s.size();
	if(n==0) return true;
	for(int i=0; i<n; i++)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
		else
		{
			if(parentheses.empty()) return false;
			if(s[i] == ')' && parentheses.top() == '(') parentheses.pop();
			else if(s[i] == ']' && parentheses.top() == '[') parentheses.pop();
			else if(s[i] == '}' && parentheses.top() == '{') parentheses.pop();
			else return false;
		}
	}
	if(parentheses.empty()) return true;
	return false;
}