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

const int MOD = 1000000007;

int n, k;
int dp[2001][2001];
main(){
	scanf("%d%d", &n, &k);
	dp[0][1] = 1;
	REP(i, k){
		for(int j=1;j<=n;j++){
			if(dp[i][j]) for(int l=j;l<=n;l+=j) (dp[i+1][l] += dp[i][j]) %= MOD;
		}
	}
	ll ans = 0;
	for(int j=1;j<=n;j++) ans += dp[k][j];
	printf("%I64d\n", ans % MOD);
	return 0;
}