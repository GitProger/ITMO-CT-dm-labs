#include <bits/stdc++.h>
using namespace std;
#define int ll
ifstream fin("matching.in");
ofstream fout("matching.out");
//*
#define cin fin
#define cout fout
//*/
typedef __int128 int128;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> prii;
typedef pair<ll,ll> prll;
typedef vector<int> veci;
typedef vector<prii> vecp;
typedef vector<ll> vecl;
typedef vector<veci> graph;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef bitset<64> bits;
typedef string str;
#define vec vector
#define fir first
#define sec second
#define $  '\n' // '
#define MAX LONG_LONG_MAX
#define INF (LONG_LONG_MAX/2)
#define MIN LONG_LONG_MIN
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(o) ((int)o.size())
#define psh push_back
#define beg begin
#define mkp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define deb(a) #a<<": "<<a<<"; "
template<class T>istream&operator>>(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}
template<class T>ostream&operator<<(ostream&out,const vector<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const set<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const multiset<T>&v){for(const T&t:v)out<<t<<' ';return out;}
 
template <class T> void rmin(T &a, const T &b) { a = min(a, b); }
template <class T> void rmax(T &a, const T &b) { a = max(a, b); }
 
 
template<class T>istream&operator>>(istream&in,pair<T, T>&t){in>>t.fir>>t.sec;return in;}
 
ostream&operator<<(ostream&out,prii p){out<<"{"<<p.fir<<", "<<p.sec<<"}";return out;}//debug
 
mt19937 rnd(1337);
//const ll MOD = 1000000007;
const ll MOD = 998244353;
inline void solve();
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    while (t--) solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}

vec<veci> g;
veci used, match;

bool dfs(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (int u : g[v])
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            match[v] = u;
            return 1;
        }
    return 0;
}

inline void solve() {
    int n; cin >> n;
    used.resize(2 * n, 0);
    match.resize(2 * n, -1);
    g.resize(2 * n);

    veci ws(n); cin >> ws; 

    for (int i = 0; i < n; ++i) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int v; cin >> v; --v;
            g[i].push_back(v + n);
            g[v + n].push_back(i);
        }
    }

    veci indices(n); iota(all(indices), 0ll);
    sort(all(indices), [=] (int i, int j) {
        return ws[i] > ws[j];
    });
    for (int &v : indices) {
        used.assign(2 * n, false);
        dfs(v);
    }

    for (int i = 0; i < n; ++i) {
        cout << (match[i] >= 0 ? match[i] + 1 - n : 0) << ' ';
    }
    cout << $;
}
/*
*/
