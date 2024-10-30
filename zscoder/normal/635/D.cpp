#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define scan scanf
#define print printf
#define mp make_pair
#define ones __builtin_popcountll
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/
void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}

ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if(a == 0) return b;
	else if(b == 0) return a;
    return b ? gcd(b, a%b) : a;
}
//__gcd(value1, value2)
//

/*ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    // q is odd
            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}
*/

/*
ll choose(ll n, ll r)
{
	if(r == 0)
	{
		return 1;
	}
	if(n == r)
	{
		return 1;
	}
	long long denom = 1;
	for (long long i = 2; i <= r; i++)
	{
		denom = (denom * i) % MOD;
	}
	long long res = 1;
	for (long long i = n; i > n - r; i--) 
	{
		res = (res * i) % MOD;
	}
	res = (res * power(denom, p- 2)) % MOD;
	return res;
}
*/

/*bool comp(ii a, ii b)
{
	if(a.first != b.first) return (a.first < b.first);
	else return (a.second < b.second);
}
*/

/*Graph Struct (Unweighted), Weighted add another i
vvi graph;
vi empty;
forp(i, 0, n)
{
	graph[i].pb(empty);
}
*/

/*DFS
bool visited[MAX_N + 1];
memset(visited, false, sizeof(visited));

void dfs(int u)
{
	visited[u] = true;
	stack<int> s;
	s.push(u);
	int v, w;
	while(!s.empty())
	{
		v = s.top();
		s.pop();
		forp(i, 0, graph[v].size())
		{
			w = graph[v][i];
			if(!visited[w])
			{
				s.push(w);
			}
			visited[w] = true;
		}
	}
}
*/

/*BFS (SSSP Unweighted)
int dist[MAX_N + 1];
memset(dist, -1, sizeof(dist));

void bfs(int u)
{
	dist[u] = 0;
	queue<int> q;
	q.push(u);
	int v, w;
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		forp(i, 0, graph[v].size())
		{
			w = graph[v][i];
			if(dist[w] == -1)
			{
				dist[w] = dist[u] + 1;
				q.push(w);
			}
		}
	}
}
*/

/*
Dijkstra
ll dist[MAXN + 1];
void dijkstra(int v)
{
	dist[v] = 0;
	int u;
	priority_queue<ii, vii, less<ii> > > pq;
	pq.push(ii(dist[v], v));
	while(!pq.empty())
	{
		u = pq.top().second;
		pq.pop();
		forp(i, 0, graph[u].size())
		{
			ii p = graph[u][i]
			if(dist[p.first] > dist[u] + p.second)
			{
				d[p.first] = d[u] + p.second;
				pq.push(ii(d[p.first], p.first));
			}
		}
	}
}
*/

/*BIT Sample
ll tree[MAX_N + 1];
void update(int p, ll val)
{
	for(int i = p; i <= n; i += (i & -i))
	{
		tree[i] += val;
	}
}
ll sum(int p)
{
	ll ans = 0;
	for(int i = p; i > 0 ;i -= (i & -i))
	{
		ans += tree[i];
	}
	return ans;
}
*/

/*Segment Tree
ll tree[4*MAX_N + 1];
void build(int id = 1, int l = 0, int r = n)
{
	if(r - l < 2)
	{
		tree[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void modify(int p, int x, int id = 1, int l = 0, int r = n)
{
	tree[id] += x - a[p];
	if(r - l < 2)
	{	
		a[p] = x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
	{
		modify(p, x, id * 2, l, mid);
	}
	else
	{
		modify(p, x, id * 2 + 1, mid, r);
	}
}

ll sum(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(x >= r || l >= y)	return 0;
	if(x <= l && r <= y)	return tree[id];
	int mid = (l+r)/2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

//Lazy part
//Increase Update
ll lazy[4*MAX_N + 1];
void upd(int id, int l, int r, int x)
{
	lazy[id] += x;
	tree[id] += (r - l) * x;
}

void shift(int id, int l, int r)
{
	int mid = (l + r)/2;
	upd(id*2, l, mid, lazy[id]);
	upd(id*2 + 1, mid, r, lazy[id]);
	lazy[id] = 0;
}

void increase(int x, int y, ll v, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y)
	{
		upd(id, l, r, v);
		return ;
	}
	shift(id, l, r);
	int mid = (l+r)/2;
	increase(x, y, v, id * 2, l, mid);
	increase(x, y, v, id*2+1, mid, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll sum(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return tree[id];
	shift(id, l, r);
	int mid = (l+r)/2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}
*/

/*Mo's Algorithm (sqrt-decompression)
int block;
int cnt[MAX_N + 1];
bool cmp(iii x, iii y)
{
	if(x.first.first/block != y.first.first/block) return x.first.first/block < y.first.first/block;
	return x.first.second < y.first.second;
}

void add(int pos)
{
	
}

void remove(int pos)
{

}

int currL = 1, currR = 1;
for(int i=0; i<m; i++) 
{
	int L = q[i].first.first, R = q[i].first.second;
	while(currL < L) {
		remove(currL);
		currL++;
	}
	while(currL > L) {
		add(currL-1);
		currL--;
	}
	while(currR <= R) {
		add(currR);
		currR++;
	}
	while(currR > R+1) {
		remove(currR-1);
		currR--;
	}
	ans[q[i].i] = answer;
}
*/

/*KMP
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
*/

/*struct matrix {
  // N is the size of the matrix
  ll m[N][N];
  matrix()
  {
     memset(m,0,sizeof(m));
  }
  matrix operator * (matrix b)
	{
		matrix c = matrix();
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j) 
                c.m[i][j] = (c.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
    return c;
	}
  ...
};

matrix modPow(matrix m,ll n)
{
  if ( n == 0 )
    return unit; // the unit matrix - that is 1 for principal diagonal , otherwise 0
  matrix half = modPow(m,n/2);
  matrix out = half * half;
  if ( n % 2 )
    out = out * m;
  return out; 
}

*/


/*DSU (Values are -ve)
memset(par, -1, sizeof(par));
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/

/*
bool prime[10000001];
vector<ll> primes;
void Sieve(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	for(int i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			primes.push_back(i);
		}
	}
}

bool is_prime(ll n)
{
	for(int i = 0; primes[i]*primes[i]<=n; i++)
    {
        if(n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}
*/

/*
ll graph[2][2];
ll unit[2][2];
ll tp[2][2];

void mul(int mode) 
{
	ll i, j, k, val;
	if(mode == 1)
	{
	for (i = 0; i < 2; i++) 
	{
		for (j = 0; j < 2; j++) 
		{
			val = 0;
			for (k = 0; k < 2; k++) val = (val + (unit[i][k] * graph[k][j]) % MOD)%MOD;
			tp[i][j] = val;
		}
	}
	for (i = 0; i < 2; i++) 
	{
		for (j = 0; j < 2; j++) 
		{
			if(tp[i][j] < 0) tp[i][j] += MOD;
			unit[i][j] = tp[i][j];
		}
	}	
	}
	else
	{
	for (i = 0; i < 2; i++) 
	{
		for (j = 0; j < 2; j++) 
		{
			val = 0;
			for (k = 0; k < 2; k++) val = (val + (graph[i][k] * graph[k][j]) % MOD)%MOD;
			tp[i][j] = val;
		}
	}
	for (i = 0; i < 2; i++) 
	{
		for (j = 0; j < 2; j++) 
		{
			if(tp[i][j] < 0) tp[i][j] += MOD;
			graph[i][j] = tp[i][j];
		}
	}	
	}
}
*/


#define fastio ios_base::sync_with_stdio(false)
#define read(x) scan("%d", &x);
//Main Program
/*A
int pos[11][11];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	memset(pos, 0, sizeof(pos));
	int r, c, n, k;
	cin >> r >> c >> n >> k;
	int x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos[x][y] = 1;
	}
	ll ans = 0;
	ll counter = 0;
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			for(int p = i; p <= r; p++)
			{
				for(int q = j; q <= c; q++)
				{
					counter = 0;
					for(int d = i; d <= p; d++)
					{
						for(int e = j; e <= q; e++)
						{
							if(pos[d][e] == 1) counter++;
						}
					}
					if(counter >= k) ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
*/

/*B
int ori[200001];
int final[200001];
vi vec1;
vi vec2;
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int x1, x2;
	for(int i = 0; i < n; i++)
	{
		cin >> ori[i];
		if(ori[i] == 0) x1 = i;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> final[i];
		if(final[i] == 0) x2 = i;
	}
	int z;
	for(int i = 0; i < n - 1; i++)
	{
		z = (i + 1 + x1)%n;
		vec1.pb(ori[z]);
	}
	for(int i = 0; i < n - 1; i++)
	{
		z = (i + 1 + x2)%n;
		vec2.pb(final[z]);
	}
	int idx;
	for(int i = 0; i < n - 1; i++)
	{
		if(vec2[i] == vec1[0])
		{
			idx = i;
			break;
		}
	}
	bool possible = true;
	for(int i = 0; i < n - 1; i++)
	{
		z = (idx + i)%(n-1);
		if(vec1[i] != vec2[z]) 
		{
			possible = false;
			break;
		}
	}
	if(possible) cout << "YES";
	else cout << "NO";
	return 0;
}
*/

/*C
int bit(ll n, ll pos)
{
	ll constant = 1LL<<pos;
	if(n & constant) return 1;
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//cout << bit(4, 0);
	//cout << bit(8589934592, 33);
	ll s, x;
	cin >> s >> x;
	ll ans = 1;
	bool possible = true;
	int b1, b2;
	int carry = 0;
	for(int i = 60; i >= 0; i--)
	{
		b1 = bit(s, i);
		b2 = bit(x, i);
		if(b2 == 0)
		{
			if(b1 == 1)
			{
				if(i == 0)
				{
					possible = false;
					break;
				}
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		else
		{
			if(b1 == 1)
			{
				if(carry)
				{
					possible = false;
					break;
				}
				else
				{
					carry = 0;
					ans *= 2;
				}
			}
			else
			{
				if(carry == 0)
				{
					possible = false;
					break;
				}
				else
				{
					if(i == 0)
					{
						possible = false;
						break;
					}
					carry = 1;
					ans *= 2;
				}
			}
		}
	}
	if(possible) 
	{
		if(s == x) ans -= 2;
		cout << ans;
	}
	else cout << 0;
	return 0;
}
*/
//typedef pair<pair<ll, ll>, ll> triple;

llll tree[800001];
ll arr[200001];
ll k, n, a, b, q;

void modify(ll p,ll x, ll id = 1,ll l = 0,ll r = n)
{
	ll d1 = 0, d2 = 0;
	d1 = min(arr[p] + x, b) - min(arr[p], b);
	d2 = min(arr[p] + x, a) - min(arr[p], a);

	//tree[id].se += x;
	tree[id].fi += d1;
	tree[id].se += d2;
	
	if(r - l < 2){	//	l = r - 1 = p
		arr[p] += x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid);
	else
		modify(p, x, id * 2 + 1, mid, r);
}

ll query(ll x,ll y,ll id = 1, ll l = 0,ll r = n, ll mode = 1)
{
	if(mode == 1) //Defected
	{
		if(x >= r || l >= y)	return 0;
		if(x >= y) return 0;
		if(x <= l && r <= y)	return tree[id].fi;
		int mid = (l+r)/2;
		return query(x, y, id * 2, l, mid, 1) + query(x, y, id * 2 + 1, mid, r, 1);
	}
	else
	{
		if(x >= r || l >= y)	return 0;
		if(x >= y) return 0;
		if(x <= l && r <= y)	return tree[id].se;
		int mid = (l+r)/2;
		return query(x, y, id * 2, l, mid, 2) + query(x, y, id * 2 + 1, mid, r, 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> n >> k >> a >> b >> q;
	ll d, e, f;
	ll sum = 0;
	for(int i = 0; i < q; i++)
	{
		sum = 0;
		cin >> d;
		if(d == 1)
		{
			cin >> e >> f;
			e--;
			modify(e, f, 1, 0, n);
		}
		else
		{
			cin >> e;
			e--;
			sum += query(0, e, 1, 0, n, 1);
			sum += query(e + k, n, 1, 0, n, 2);
			cout << sum << endl;
		}
	}
	return 0;
}


/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/