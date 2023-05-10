#include <bits/stdc++.h>
using namespace std;
ifstream fin("problem5.in");
ofstream fout("problem5.out");
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

struct DFA {
    int n, m, k, l;
    veci term, is_term;
    vec<map<char, int>> tr;
    void read() {
        cin >> n >> m >> k >> l;
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

struct NFA {
    int n, m, k, l;
    veci term, is_term;
    vec<map<char, veci>> tr;
    void read() {
        cin >> n >> m >> k >> l;
        tr = vec<map<char, veci>>(n + 1);
        is_term = veci(n + 1);
        term = veci(k); 
        for (int i = 0; i < k; ++i) {
            cin >> term[i];
            is_term[term[i]] = 1;
        }
        for (int i = 0; i < m; i++) {
            int v, u; char c; cin >> v >> u >> c;
            tr[v][c].push_back(u);
        }
    }
};


bool cmp(seti const &lhs, seti const &rhs){
    return lhs.size() == rhs.size() 
        && equal(lhs.begin(), lhs.end(), rhs.begin());
}

DFA thompson(NFA nf) {
    vector<seti> clusters; clusters.push_back({1});
    int idx = 0;
    while (idx < len(clusters)) {
        auto cluster = clusters[idx];
        set<char> chars;
        for (auto x : cluster) {
            for (auto p : nf.tr[x]) {
                chars.insert(p.first);
            }
        }
        
        for (char c : chars) {
            seti newCluster;
            for (auto x : cluster)
                for (auto p : nf.tr[x][c])
                    newCluster.insert(p);
            
            bool has = false;
            for (seti x : clusters) 
                if (cmp(x, newCluster)) {
                    has = true;
                    break;
                }            
            if (!has) 
                clusters.push_back(newCluster);
        }
        idx++;
    }

    DFA dfa;
    dfa.n = len(clusters);
    dfa.l = nf.l;
    dfa.tr = vec<map<char, int>>(dfa.n + 1);

    for (int idx = 1; idx <= len(clusters); ++idx) {
        auto cluster = clusters[idx - 1];
        
        set<char> chars;
        for (auto x : cluster) {
            for (auto p : nf.tr[x]) {
                chars.insert(p.first);
            }
        }

        for (char c : chars) {
            seti newCluster;
            for (auto x : cluster)
                for (auto p : nf.tr[x][c])
                    newCluster.insert(p);
                    
            int index = 0;
            for (int i = 0; i < len(clusters); ++i) {
                if (cmp(clusters[i], newCluster)) {
                    index = i + 1;
                    break;
                }
            }
                    
            dfa.tr[idx][c] = index;
        }
        
        bool has = false;
        for (int x : cluster)
            if (nf.is_term[x]) {
                has = true;
                break; 
            }

        if (has) 
            dfa.term.push_back(idx);
    }
    
    return dfa;
}


int get_ans(const DFA &d) {
    veci is_term(d.n);
    for (int x : d.term) is_term[x - 1] = 1;    
    vec<veci> g(d.n, veci(d.n));
    for (int i = 1; i <= d.n; ++i)
        for (auto p : d.tr[i]) {
            if (p.sec > 0)
                g[i - 1][p.sec - 1]++;
        }
    return dot(pow(g, d.l)[0], is_term);
}

inline void solve() {
    NFA nf; nf.read();
    DFA x = thompson(nf);
    /*
    cerr << x.term << $;
    for (int i = 1; i <= x.n; i++) {
        for (auto p : x.tr[i]) {
            cerr << i << ' ' << p.sec << ' ' << p.fir << $;
        }
    }
    cerr << $;*/
   // DFA x; x.read();
    
    cout << get_ans(x) << $;
}
/*
0 2 1  0 0 3  0 0 0  


*/

