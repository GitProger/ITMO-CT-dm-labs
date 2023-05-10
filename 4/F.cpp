#include <bits/stdc++.h>
using namespace std;
ifstream fin("isomorphism.in");
ofstream fout("isomorphism.out");
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

struct DFA {
    int n, m, k;
    veci term, is_term;
    vec<map<char, int>> tr;
    void read() {
        cin >> n >> m >> k;
        tr = vec<map<char, int>>(n + 1);
        is_term = veci(n + 1);
        term = veci(k); 
        for (int i = 0; i < k; ++i) {
            cin >> term[i];
            is_term[term[i]] = 1;
        }
        for (int i = 0; i < m; i++) {
            int v, u; char c; cin >> v >> u >> c;
            tr[v][c] = u;
        }
    }
};

DFA d1, d2; 
veci used;
veci mapping;

bool dfs(int u, int v) {
   used[u] = true;
   if (d1.is_term[u] != d2.is_term[v])
       return false;

   mapping[u] = v;
   bool result = true;
   for (auto p : d1.tr[u]) {
       char c = p.first;
       int t1 = d1.tr[u][c];
       int t2 = d2.tr[v][c];
       if ((t1 == 0 && t2 != 0) || (t1 != 0 && t2 == 0))
           return false;
       if (used[t1]) {
           result &= t2 == mapping[t1];
       } else {
           result &= dfs(t1, t2);
       }
   }
   return result;
}

inline void solve() {
    d1.read();
    d2.read();
    if (d1.n != d2.n || d1.k != d2.k) {
        cout << "NO\n";
        return;
    }
    used = veci(d1.n + 1);
    mapping = veci(d1.n + 1);
    cout << (dfs(1, 1) ? "YES" : "NO") << $;
}

// https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D1%82%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B5_%D0%BA%D0%BE%D0%BD%D0%B5%D1%87%D0%BD%D1%8B%D0%B5_%D0%B0%D0%B2%D1%82%D0%BE%D0%BC%D0%B0%D1%82%D1%8B
