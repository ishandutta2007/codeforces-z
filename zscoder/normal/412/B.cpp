#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	/*A
	int n, k;
	cin >> n >> k;
	char word[n+1];
	cin >> word;
	bool direct;
	int dist = min(k - 1, n - k);
	if(n - k > k - 1)
	{
		direct = false;
	}
	else
	{
		direct = true;
	}
	
	for(int i = 0; i < dist ; i++)
	{
		if(direct)
		{
			cout << "RIGHT" << endl;
		}
		else
		{
			cout << "LEFT" << endl;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(direct)
		{
			cout << "PRINT " << word[n - 1 - i] << endl;
			
			if(i != n - 1)
				cout << "LEFT" << endl;
		}
		else
		{
			cout << "PRINT " << word[i] << endl;
			if(i != n - 1)
			{
				cout << "RIGHT" << endl;
			}
		}
	}
	*/
	
	//*/
	int n, k;
	cin >> n >> k;
	int x;
	int sum = 0;
	vector<int> vec;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n; i++)
	{
		sum += vec.at(i);
	}
	cout << vec.at(n - k);
	//*/
	/*C
	
	*/
	/*D
	
	*/
	/*E
	
	*/
	
	return 0;
}