#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <cstdio>
#include <stack>
#include <complex>
#include <climits>
#include <bitset>
#include <deque>
#include <set>
#include <list>
#include <valarray>
#include <functional>
#include <new>
#include <iterator>
#include <stdexcept>
#include <cstddef>
#include <fstream>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <bool> vb;

#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF INT_MAX

//Tip for reading input : scanf("%s%d", &s, &d);!

//A
/*
int main()
{
	//int i;
	//int i, j;
	//int count = 0;
	//int n;
	//cin >> n;
	vi vec;
	int n, k, x;
	cin >> n >> k;
	//int array[n];
	forloopp(i, 0, n - 1)
	{
		cin >> x;
		vec.push_back(x);
	}
	
	sort(vec.begin(), vec.end());
	
	int m;
	cin >> m;
	int sum = 0;
	
	if(m <= n)
	{
		forloopp(i, 0, m - 1)
		{
			sum += vec.at(i);
		}
		//cout << "1" << endl;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			//cout << "Here";
			sum += vec.at(i);
		}
		for(int i = 0; i < m - n; i++)
		{
			sum -= k;
		}
	}
	cout << sum;
	return 0;
}*/

//B
//int memo[100010][100010];

int main()
{
	int n, m;
	//n = 100000, m = 100000;
	cin >> n >> m;
	int record[n];
	int array[n];
	set <int> mset;
	int select[m];
	//int sol[m];
	
	forloopp(i, 0, n - 1)
	{
		//array[i] = 100000;
		cin >> array[i];
	}
	for(int i = n - 1; i >= 0; i--)
	{
		mset.insert(array[i]);
		record[i] = mset.size();
		//cin >> array[i];
	}
	forloopp(i, 0, m - 1)
	{
		//select[i] = 100000;
		cin >> select[i];
	}
	for(int i = 0; i < m; i++)
	{
		cout << record[select[i] - 1] << endl;
	}
	return 0;
}


//C
/*
int main()
{
	return 0;
}
*/

//D
/*
int main()
{
	return 0;
}
*/

//E
/*
int main()
{
	return 0;
}
*/