#include <bits/stdc++.h>
using namespace std;
ifstream fin("problem2.in");
ofstream fout("problem2.out");
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

inline void solve() {
    str s; cin >> s;
    int n, m, k; cin >> n >> m >> k;
    veci term(k); cin >> term;
    veci term_map(n + 1);
    for (int x : term) term_map[x] = 1;
     
    vec<map<char, veci>> dfa(n + 1);
    for (int i = 0; i < m; ++i) {
        int v, u; char c;
        cin >> v >> u >> c;
        dfa[v][c].push_back(u);
    }
    
    seti r = {1};
    for (int i = 0; i < len(s); ++i) {
        char c = s[i];
        seti cur;
        for (int v : r)
            for (int u : dfa[v][c])
                cur.insert(u);
        r = cur;
    }
    
    for (int x : r) {
        if (term_map[x]) {
            cout << "Accepts\n";
            return;
        }
    }
    
    cout << "Rejects\n"; 
}
