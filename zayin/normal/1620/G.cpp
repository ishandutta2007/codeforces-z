#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i,begin,end) for (__typeof(begin) i=(begin),_end=(end),_step=1-2*((begin)>(end));i!=_end;i+=_step)

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    if (!v.size()) 
        os<<"]"; 
    else
        for (int i=0;i<v.size();++i)
            os<<v[i]<<",]"[i==v.size()-1];
    return os;
}
template<class T>
ostream& operator << (ostream& os, const set<T>& s)  {
    os<<"{";
    if (!s.size()) 
        os<<"}"; 
    else
        for (auto x:s)
            os<<x<<",}"[x==*s.rbegin()];
    return os;
}

void printr(ostream& os){os<<'\n';}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t; if (sizeof...(args)) os<<" ";
    printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}
template<class T>
void readarray(T* A,int n)  {
    rep(i,0,n) read(A[i]);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
    os<<t; if (sizeof...(args)) os<<", ";
    dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed


#define maxn 23
#define maxm 20050
#define maxc 26
#define maxs 10000050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a,LL b)    {
    uniform_int_distribution<int> u(a,b);
    static mt19937 e(time(0));
    return u(e);
}

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n;
char s[maxm];
LL cnt[maxn][maxc];
LL g[maxs],f[maxs],h[maxs],mn[maxs];

int lastbit[maxs];

LL sgn(int x)   {
    return (x&1)?modu-1:1;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin>>n;
    for (int i=0;i<n;++i)   {
        cin>>s;
        for (int j=0;s[j];++j)
            ++cnt[i][s[j]-'a'];
    }
    g[0]=1;
    for (int s=1;s<(1<<n);++s)  {
        g[s]=1;
        if (~s&1)
            lastbit[s]=lastbit[s>>1]+1;
    }
    for (int c=0;c<maxc;++c)    {
        mn[0]=1e9;
        for (int s=1;s<(1<<n);++s)  {
            int i=lastbit[s];
            mn[s]=min(mn[s^(1<<i)],cnt[i][c]);
            g[s]=g[s]*(mn[s]+1)%modu;
        }
    }
    
    // for (int s=0;s<(1<<n);++s)
    //     cout<<"g["<<s<<"]="<<g[s]<<endl;

    for (int s=1;s<(1<<n);++s)
        f[s]=g[s]*sgn(__builtin_popcount(s)+1)%modu;

    for (int i=0;i<n;++i)
        for (int s=0;s<(1<<n);++s)
            if (s>>i&1)
                f[s]=(f[s]+f[s^(1<<i)])%modu;
    
    int all=(1<<n)-1;

    // for (int s=0;s<(1<<n);++s)
    //     cout<<"f["<<s<<"]="<<f[s]<<endl;

    LL ans=0;
    for (int s=1;s<(1<<n);++s)  {
        LL is=0;
        for (int i=0;i<n;++i)
            if (s>>i&1)
                is+=i+1;
        LL t=is*__builtin_popcount(s)*f[s];
        ans^=t;
    }
    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/