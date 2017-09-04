#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num) {
	vector<int> result; 
	int count = 1;
	result.push_back(0);
	if(num == 0)
		return result;
	for(int i = 1; i <= num; i++){
		if(i%2 == 1)
			result.push_back(result[i-1]+1);
		else
			result.push_back(result[i/2]);
	}
	return result;
}

int main(){
	int num;
	cin >> num;
	vector<int> result;
	result = countBits(num);
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}