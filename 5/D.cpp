#include <bits/stdc++.h>
using namespace std;
ifstream fin("nfc.in");
ofstream fout("nfc.out");

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


map<char, vec<str>> aut;
map<char, vec<veci>> cache;
str w;

int get(char v, int l, int r) {
    if (cache[v][l][r] == -1) {
        int ans = 0;
        for (const str &cur : aut[v])
            if (len(cur) == 1) { // term
                if (l + 1 == r && w[l] == cur[0]) {
                    ans = (ans + 1) % MOD;
                }
            } else {
                for (int i = l + 1; i < r; ++i) {
                    ans += get(cur[0], l, i) * get(len(cur) > 1 ? cur[1] : 'a', i, r);
                    ans %= MOD;
                }
            }
        cache[v][l][r] = ans;        
    }
    return cache[v][l][r];
}


inline void solve() {
    int n; char S;
    cin >> n >> S;
    for (int i = 0; i < n; ++i) {
        char nt; str arr, s; cin >> nt >> arr >> s;
        aut[nt].psh(s);
    }
    cin >> w;
    for (auto e : aut)
        cache[e.fir] = vec<veci>(111, veci(111, -1));
    cout << get(S, 0, len(w)) << $;
}

/*
4 S
S -> AB
A -> a
B ->
B -> b

*/

