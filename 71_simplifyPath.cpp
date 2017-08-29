string simplifyPath(string path)
{
	int n = path.size();
	string res = "";
	string tmp;
	if(n == 0) return res;
	int start = 0, end = 0;
	stack<string> stack;
	stack.push("/");
	while(start <= n-1)
	{
		while(start <= n-1 && path[start] == '/')
		{
			start++;
		}
		end = start;
		while(end <= n-1 && path[end] != '/')
		{
			end++;
		}
		tmp = path.substr(start, end-start);
		if(!stack.empty() && tmp == "..")
		{
			if(stack.top()!="/")
				stack.pop();
		}
		else if(tmp == "." || tmp == "");
		else
			stack.push(tmp);
		start = end;
		start++;
	}
	if(stack.size() == 1) return "/";
	while (stack.size() > 1) {  
		res = "/" + stack.top() + res;  
		stack.pop();  
	}  
	return res;
}