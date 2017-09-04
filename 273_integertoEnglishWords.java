public static final String[] lessthan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
	"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
public static final String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public static final String[] thousands = {"", "Thousand", "Million", "Billion"};
public String numberToWords(int num)
{
	if(num==0) return "Zero";
	StringBuilder res = new StringBuilder();
	int count = 0;
	while(num > 0)
	{
		if(num%1000 != 0)
			res.insert(0, helper(num%1000)+thousands[count]+" ");
		count++;
		num = num/1000;
	}
	return res.toString().trim();
}

private String helper(int num)
{
	if(num==0)
		return "";
	else if(num < 20)
		return lessthan20[num]+" ";
	else if(num<100)
		return tens[num/10]+" "+helper(num%10);
	else
		return lessthan20[num/100]+" Hundred "+helper(num%100);
}