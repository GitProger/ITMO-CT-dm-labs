#include <bits/stdc++.h>
using namespace std;
#define int ll
//typedef __int128 int128;
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

using node = pair<int, str>;
map<str, str> huffman(map<str, int> m) {
	set<node> a;
	for (auto e : m) a.insert(node{e.second, e.first});
	map<node, vector<node>> tree;	

    while (len(a) > 1) {
        node x = *a.begin(); a.erase(a.begin());
        node y = *a.begin(); a.erase(a.begin());
        node z = node{x.first + y.first, x.second + y.second};
  
        a.insert(z);        
        tree[z] = vector<node>{x, y};
    }
    
    map<str, str> ans;
    function<void(node, str)> dfs = [&] (node v, str st) {
		int n = len(tree[v]);
		if (n == 0) {
			ans[v.second] = st;
		}
		for (int i = 0; i < len(tree[v]); i++) {
			dfs(tree[v][i], st + str(1, '0' + i));
		}
	};
	dfs(*a.begin(), "");
	return ans;
}

int getsum(map<str, int> cnt, map<str, str> code) {
	int ans = 0;
    for (auto e : cnt) ans += e.second * len(code[e.first]);
	return ans;
}

inline void solve() {
    int n; cin >> n;
    veci p(n); cin >> p;
    map<str, int> cnt;
    for (int i = 0; i < n; i++) cnt[to_string(i)] = p[i];
	map<str, str> res = huffman(cnt);
	cout << getsum(cnt, res) << $;	
}

/*
 
*/

 
