#include <bits/stdc++.h>
using namespace std;
#define int ll
ifstream fin("destroy.in");
ofstream fout("destroy.out");
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

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1)
        { for (int i = 0; i < n; i++) p[i] = i; }
    int comp(int v)
        { return v == p[v] ? v : (p[v] = comp(p[v])); }
    bool conn(int v, int u) 
        { return comp(v) == comp(u); }
    void unite(int v, int u) {
        v = comp(v); u = comp(u);
        if (v == u) return;
        if (sz[v] > sz[u]) {
            p[u] = v;
            sz[v] += sz[u];
        } else {
            p[v] = u;
            sz[u] += sz[v];
        }
    }
};

struct edge {
    int u, v, w, i;
    edge(int u, int v, int w, int i): u(u), v(v), w(w), i(i) {}
    bool operator < (const edge& a) const { return w > a.w; }
};

inline void solve() {
    int n, m, s; cin >> n >> m >> s;
    DSU d(n);
    vec<edge> es; es.reserve(m);
    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        es.psh(edge(u - 1, v - 1, w, i + 1));
    }
    sort(all(es));
    
    seti mst;
    for (int i = 0; i < m; ++i) {
        if (!d.conn(es[i].u, es[i].v)) {
            mst.insert(es[i].i);
            d.unite(es[i].u, es[i].v);
        }
    }

    vec<prii> del;
    for (edge& e : es) {
        if (mst.find(e.i) == mst.end()) {
            del.psh(make_pair(e.w, e.i));
        }
    }
    sort(all(del));

    veci ans;
    for (prii& e : del) {
        if (e.fir <= s) {
            ans.psh(e.sec);
            s -= e.fir;
        }
    }

    sort(all(ans));
    cout << len(ans) << $ << ans << $;;
}
/*
*/
