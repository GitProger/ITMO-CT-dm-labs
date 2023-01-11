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
//#define $ '\n'
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

void pop_front(veci &a) {
    for (int i = 0; i + 1 < len(a); i++)
        a[i] = a[i + 1];
    a.pop_back();
}
void push_front(veci &a, int x) {
    a.push_back(0);
    for (int i = 1; i < len(a); i++)
        a[i] = a[i - 1];
    a[0] = x;
}


void out(const veci &a, int nl = 1) {
    for (int e : a) cout << e;
    if (nl) cout << '\n';
}

int ctrl(const veci &a) {
    int x = 0;
    for (int e : a) x ^= e;
    return x;
}

int sm(const veci &s, int k, int bit) {
    int ans = 0;
    for (int i = 0; i < len(s); i++) {
        if (((i >> k) & 1) == bit) {
            ans += s[i];
        }
    }
    return ans % 2;
}

veci getcode(const veci &s) {
    veci c;
    for (int k = 0; k < ceil(log2(len(s))); k++) {
        c.push_back(sm(s, k, 1));
    }
    c.push_back(ctrl(c));
    return c;
}

const int MAXL = 100'017;

inline void solve() {
    int t; cin >> t;
    str in; cin >> in;
    veci s(len(in));
    for (int i = 0; i < len(in); i++) s[i] = in[i] - '0';
    


    if (t == 1) {
        veci c = getcode(s);
     //   if (len(s) + len(c) > MAXL) c.pop_back();
        out(s, 0);
        out(c);
        exit(0);
    }
//    if (len(s) == MAXL) s.push_back(1);

    int n = 0;
    for (int k = 0; k < len(s); k++) { // 2 ^ k + k = n
        n = len(s) - k - 1;
        if (ceil(log2(n)) == k)
            break;
    }

    veci x(n), y(len(s) - n);
    for (int i = 0; i < len(s); ++i) {
        if (i < n) x[i] = s[i];
        else y[i - n] = s[i];
    }

    veci yy = y;
    yy.pop_back();
    {
        veci gc = getcode(x);
        gc.pop_back();
        if (yy == gc) { //no error or error in ctrl bit
            out(x);
            exit(0);
        }
    }
    {
        if (ctrl(yy) != y.back()) {//error in code
            out(x);
            exit(0);
        }
    }

//    out(x,0);cout<<'|';out(y);

    int p = 0;
    for (int k = len(yy) - 1; k >= 0; --k) {
        p *= 2;
        if (yy[k] != sm(x, k, 1)) {
            p += 1;
        }
    }

    x[p] ^= 1;
    out(x);
    cout << '\n';
}

/*

*/

 
