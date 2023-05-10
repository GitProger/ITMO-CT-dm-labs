#include <bits/stdc++.h>
using namespace std;
ifstream fin("problem4.in");
ofstream fout("problem4.out");
//*
#define cin fin
#define cout fout
//*/
#define int ll
typedef __int128 int128;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> prii;
typedef pair<ll,ll> prll;
typedef vector<int> veci;
typedef vector<prii>vecp;
typedef vector<ll> vecl;
typedef vector<veci> graph;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
typedef string str;
#define vec vector
#define fir first
#define sec second
#define $ '\n'
#define MAX LONG_LONG_MAX
#define INF (LONG_LONG_MAX/2)
#define MIN LONG_LONG_MIN
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(o) ((int)o.size())
#define psh push_back
#define beg begin
#define mkp make_pair
#define deb(a) #a<<": "<<a<<"; "
#define forn(i,n) for(int i=0;i<n;i++)
template<class T>istream&operator>>(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}
template<class T>ostream&operator<<(ostream&out,const vector<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const set<T>&v){for(const T&t:v)out<<t<<' ';return out;}
template<class T>ostream&operator<<(ostream&out,const multiset<T>&v){for(const T&t:v)out<<t<<' ';return out;}
  
template <class T> void rmin(T &a, const T &b) { a = min(a, b); }
template <class T> void rmax(T &a, const T &b) { a = max(a, b); }
 
 
template<class T>istream&operator>>(istream&in,pair<T, T>&t){in>>t.fir>>t.sec;return in;}
 
ostream&operator<<(ostream&out,prii p){out<<"{"<<p.fir<<", "<<p.sec<<"}";return out;}//debug
 
mt19937 rnd(1337);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
inline void solve();
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
   // cin >> t;
    while (t--) solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}

vec<veci> I(int n) {
    vec<veci> r(n, veci(n));
    for (int i = 0; i < n; ++i) r[i][i] = 1;
    return r;
}

vec<veci> transpose(const vec<veci> &M) {
    vec<veci> R(len(M[0]), veci(len(M)));
    for (int i = 0; i < len(M); ++i)
        for (int j = 0; j < len(M[0]); ++j)
            R[j][i] = M[i][j];
    return R;
}

int dot(const veci &a, const veci &b) {
    int r = 0;
    for (int i = 0; i < len(a); ++i) {
        r += a[i] * b[i];
        r %= MOD;
    }
    return r;
}

veci mulv(const vec<veci> &M, const veci &v) {
    veci r(len(v));
    for (int i = 0; i < len(M); ++i)
        r[i] = dot(M[i], v);
    return r;
}

vec<veci> mul(const vec<veci> &A, const vec<veci> &B) {
    vec<veci> R(len(A), veci(len(B[0])));
    vec<veci> BT = transpose(B);
    for (int i = 0; i < len(A); ++i) {
        for (int j = 0; j < len(B[0]); ++j) {
            R[i][j] = dot(A[i], BT[j]);
        }
    }
    return R;
}
      
vec<veci> pow(const vec<veci> &M, int p) {
    if (p == 0) {
        return I(len(M));
    }
    auto h = pow(M, p / 2);
    auto x = (p % 2 == 1) ? M : I(len(M));
    return mul(mul(h, h), x);
}



inline void solve() {
    int n, m, k, l; cin >> n >> m >> k >> l;
    veci term(k); cin >> term;
    veci is_term(n);
    for (int x : term) is_term[x - 1] = 1;    
     
    vec<veci> g(n, veci(n));
    for (int i = 0; i < m; ++i) {
        int v, u; char c;
        cin >> v >> u >> c;
        g[v - 1][u - 1]++;
    }

    cout << dot(pow(g, l)[0], is_term) << $;
}
/*
inline void solve() {
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    vvi g(n);
    vi terms(k);
    forn(i, k) {
        cin >> terms[i];
        terms[i]--;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(b);
    }
    vi kekw(n), tmp(n), clr(n);
    kekw[0] = 1;
    while (l--) {
        for (int u = 0; u < n; u++) {
            for (auto v : g[u]) {
                tmp[v] += kekw[u];
                tmp[v] %= p;
            }
        }
        kekw = tmp;
        tmp = clr;
    }
    ll ans = 0;
    for (auto i : terms) {
        ans += kekw[i];
        ans %= p;
    }
    cout << ans << endl;
}
*/
