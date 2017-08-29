int myAtoi(string str)
{
	int sign = 1;
	int i = 0;
	long long result = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == '+')
	{
		if(str[i+1] == '-') return 0;
		i++;
	}
	if(str[i] == '-')
	{
		if(str[i+1] == '+') return 0;
		sign = -1;
		i++;
	}
	while(i<str.size())
	{
		if(str[i]>='0' && str[i]<='9')
		{
			result = result*10 + str[i]-'0';
			i++;
			if(result > INT_MAX)
				return sign<0 ? INT_MIN : INT_MAX;
		}
		else
			break;
	}
	result = result * sign;
	return (int)result;
}