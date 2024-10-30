#include <bits/stdc++.h>


using namespace std;

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
#define gcd __gcd
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define scan scanf
#define print printf
#define mp make_pair

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
//__gcd(value1, value2)
//

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
            for (ll i=p*2; i<=n; i += p)
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

/*A
char a[1001][1001];
ll row[1001];
ll col[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	ll colsum = 0;
	ll rowsum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == 'C')	{row[i]++; col[j]++;}
		}
	}
	for(int i = 0; i < n; i++)
	{
		rowsum += (row[i]*(row[i]-1))/2;
		colsum += (col[i]*(col[i]-1))/2;
	}
	ll ans = rowsum + colsum;
	cout << ans;
	return 0;
}
*/

/*
ll male[370];
ll female[370];
ll start[5001];
ll en[5001];
ii dp[370][370];

char gend[5001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	memset(male, 0, sizeof(male));
	memset(female, 0, sizeof(female));
	
	for(int i = 0; i < n; i++)
	{
		cin >> gend[i];
		cin >> start[i] >> en[i];
		for(int j = start[i]; j <= en[i]; j++)
		{
			if(gend[i] == 'M') male[j]++;
			else female[j]++;
		}
	}
	
	ll ans = 0;
	
	for(int i = 1; i <= 366; i++)
	{
		ans = max(ans, ll(min(female[i], male[i])*2LL));
	}
	cout << ans;
	return 0;
}
*/

/*
string s;
ll m, n;

bool check_prefix(int r)
{
	int left = 0;
	int right = 0;
	for(int i = 0; i < r; i++)
	{
		if(s[i] == '(') left++;
		else right++;
		if(right > left) return false;
	}
	return true;
}


ll solve(int leng, int l, int r, int idxl, int idxr, int left, int right)
{
	if(leng == m)
	{
		if(check_prefix(m - 1)) return 1;
		else return 0;
	}
	if(s[idxl] == '(')
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	cin >> s;
	if(n % 2) 
	{
		cout << 0;
		return 0;
	}
	ll len = n/2;
	int cntl, cntr;
	cntl = 0;
	cntr = 0;
	for(int i = 0; i < m; i++)
	{
		if(s[i] == '(') cntl++;
		else cntr++;
	}
	if(cntl > len || cntr > len) 
	{
		cout << 0;
		return 0;
	}
	
	return 0;
}
*/
const ld pi = ld(3.14159265358979323846);

/*
int GetCeilIndex(ll A[], ll T[], int l, int r, ll key) {
   int m;
 
   while( r - l > 1 ) {
      m = l + (r - l)/2;
      if( A[T[m]] >= key )
         r = m;
      else
         l = m;
   }
 
   return r;
}
 
ll LongestIncreasingSubsequence(ll A[], int size) {
   // Add boundary case, when array size is zero
   // Depend on smart pointers
 
   int *tailIndices = new int[size];
   int *prevIndices = new int[size];
   int len;
 
   memset(tailIndices, 0, sizeof(tailIndices[0])*size);
   memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);
 
   tailIndices[0] = 0;
   prevIndices[0] = -1;
   len = 1; // it will always point to empty location
   for( int i = 1; i < size; i++ ) {
      if( A[i] < A[tailIndices[0]] ) {
         // new smallest value
         tailIndices[0] = i;
      } else if( A[i] > A[tailIndices[len-1]] ) {
         // A[i] wants to extend largest subsequence
         prevIndices[i] = tailIndices[len-1];
         tailIndices[len++] = i;
      } else {
         // A[i] wants to be a potential condidate of future subsequence
         // It will replace ceil value in tailIndices
        int pos = GetCeilIndex(A, tailIndices, -1, len-1, A[i]);
 
        prevIndices[i] = tailIndices[pos-1];
        tailIndices[pos] = i;
      }
   }
  // cout << "LIS of given input" << endl;
  // for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
   //cout << A[i] << "   ";
  // cout << endl;
 ll ans = 0;
for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
{
	ans += A[i]
   delete[] tailIndices;
   delete[] prevIndices;
 
   return len;
}
*/

vector<pair<ll, ll> > x;
vector<llll> y;
ld a[100001];
ll tree[400001];
ll n;
void initialize(ll node, ll b, ll e, ll mode)
{
	if (b == e)
	{
		if(mode == 1)
		{
			tree[node] = b;
		}
		else
		{
			tree[node] = b;
		}
	}
	else
	{
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2, mode);
		initialize(2 * node + 1, (b + e) / 2 + 1, e, mode);
		if(mode == 1)
		{
			if (a[tree[2*node]] >= a[tree[2 * node + 1]])
			{
				tree[node] = tree[2 * node];
			}
			else
			{
				tree[node] = tree[2 * node + 1]; 
			}
		}
		
	}
} 

 void update(ll i, ld v, ll node, ll b, ll e) 
 {
	if (b == e) 
	{
		a[i] = v;
	} 
	else if(b > e)
	{
		return;
	}
	else 
	{
		ll mid = (b + e) / 2;
		if(i <= mid)
		{
			update(i, v, 2 * node, b, mid);
		}
		else
		{
			update(i, v, 2 * node + 1, mid + 1, e);
		}
		if (a[tree[2 * node]] >= a[tree[2 * node + 1]])
		{
			tree[node] = tree[2 * node];
		}
		else
		{
			tree[node] = tree[2 * node + 1];
		}
	}
}

ll query(ll node, ll b, ll e, ll i, ll j, ll mode)
{
	ll p1, p2;
   
	if (i > e || j < b)
	{
		return -1;
	}
   
	if (b >= i && e <= j)
	{
		if(mode == 1)
		{
			return tree[node];
		}
		else
		{
			return tree[node];
		}
	}
   
	p1 = query(2 * node, b, (b + e) / 2, i, j, mode);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j, mode);
   
	if (p1 == -1)
	{
		return p2;
	}
	if (p2 == -1)
	{
		return p1;
	}
	if(mode == 1)
	{
		if (a[p1] >= a[p2])
		{
			return p1;
		}
		return p2;
	}
	else
	{
		if (a[p1] >= a[p2])
		{
			return p1;
		}
		return p2;
	}
}

bool comp(llll a, llll b)
{
	if(a.fi != b.fi) return a.fi < b.fi;
	else return a.se < b.se;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	ll xy, xz;
	for(ll i = 0; i < n; i++) 
	{
		cin >> xy >> xz;
		xy *= xy;
		xy *= xz;
		//cout << xy << endl;
		x.pb(llll(xy, i));
		y.pb(llll(i, xy));
	}
	sort(x.begin(), x.end(), comp);
	
	memset(a, 0, sizeof(a));
	initialize(1, 0, n - 1, 1);
	ll rank, el;
	ll dum;
	for(ll i = 0; i < n; i++)
	{
		el = y[i].se;
		//el = x[i].fi;
		//cout << el << endl;
		rank = lower_bound(x.begin(), x.end(), llll(el, -1)) - x.begin();
		//cout << i << " " << el << " " << rank << " " << x[rank].fi << endl;
		a[rank] = el;
		dum = query(1, 0, n - 1, 0, rank - 1, 1);
		if(dum != -1) a[rank] += a[dum];
		update(rank, a[rank], 1, 0, n - 1);
		
	}
	ld ans = 0;
	for(ll i = 0; i < n; i++)
	{
		//cout << i << " " << a[i] << endl;
		ans = max(ans, a[i]);
	}
	//ans = query(1, 0, n - 1, 0, n - 1, 1);
	//cout << ans << endl;
	ans *= pi;
	cout << fixed << setprecision(20) << ans;
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