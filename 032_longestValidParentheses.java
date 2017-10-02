public int longestValidParentheses(String s) 
{
	int n = s.length();
	Stack<Integer> st = new Stack<>();
	for(int i=0; i<=n-1; i++)
	{
		if(s.charAt(i) == '(' || st.isEmpty())
			st.push(i);
		else
		{
			if(s.charAt(st.peek()) == '(')
				st.pop();
			else
				st.push(i);
		}
	}
	int res = 0;
	if(st.isEmpty())
		return n;
	int a=n, b=0;
	while(!st.isEmpty())
	{
		b = st.pop();
		res = Math.max(res, a-b-1);
		a = b;
	}
	res = Math.max(res, a);
	return res;
}