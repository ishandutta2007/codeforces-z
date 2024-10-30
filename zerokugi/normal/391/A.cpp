#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n;
main(){
	string s;
	while(cin >> s){
		char prev = ' ';
		int c = 1;
		s += " ";
		int ans = 0;
		REP(i, s.size()){
			if(s[i] == prev) c++;
			else{
				if(c%2 == 0) ans ++;
				c = 1;
				prev = s[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}