#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

map<ll, ll> l, r;
ll a[200001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin>>n>>k;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		r[a[i]]++;
	}
	for(int i = 0; i < n; i++)
	{
		r[a[i]]--;
		if(a[i] % k == 0)
		{
			ans += l[a[i]/k]*r[a[i]*k];
		}
		l[a[i]]++; 
	}
	cout << ans;
	return 0;
}