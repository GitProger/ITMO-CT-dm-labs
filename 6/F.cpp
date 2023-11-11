#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef long double ld;
typedef long long var;
typedef pair<int, int>prii;
typedef pair<ll, ll>prll;
typedef vector<int>veci;
typedef vector<ll>vecl;
typedef vector<veci> graph;
typedef map<int, int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
typedef string str;
#define vec vector
#define fir first
#define sec second
#define $ '\n' //'
#define $$ endl
#define MAX LONG_LONG_MAX
#define INF LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(o) ((int)o.size())
#define psh push_back
template <typename T> istream& operator >> (istream &in, vector<T> &v) { 
    for (T &t : v) in >> t;
    return in;
}
template <typename T> ostream& operator << (ostream &out, const vector<T> &v) {
    for (const T &t : v) out << t << ' ';
    return out;
}
template <typename T> ostream& operator << (ostream &out, const set<T> &v) {
    for (const T &t : v) out << t << ' ';
    return out;
}

const int MOD = 1'000'000'007;
inline void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  //  freopen("biconv.in", "r", stdin);
  //  freopen("biconv.out", "w", stdout);

    solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}

template <typename T, bool is_num> struct inc_vec_t {};
template <typename T> struct inc_vec_t<T, true> {
    inc_vec_t() = delete;
    inc_vec_t(const vector<T>& res): me(res) {}
    inc_vec_t(vector<T>&& res): me(std::move(res)) {}
    friend ostream& operator << (ostream &out, const inc_vec_t<T, true> &v) {
        for (const T &t : v.me) out << t + 1 << ' ';
        return out;
    }
private:
    vector<T> me;
};
template <typename T> using inc_vec = inc_vec_t<T, is_integral<T>::value>;

////////////////////////////////////////////////////////////////////////////////

template <class T> T rmin(T &a, const T &b) { return (a = min(a, b)); }
template <class T> T rmax(T &a, const T &b) { return (a = max(a, b)); }

inline void solve() {
    int n; cin >> n;
    veci p_(n - 2); cin >> p_;
    for (int &v : p_) v--;
    vec<prii> g; g.reserve(n);
 
    deque<int> p;
    p.insert(p.begin(), all(p_));

    veci deg(n);
    for (int e : p) deg[e]++;
 
    seti s;
    for (int i = 0; i < n; i++) s.insert(i);
    
     
    seti p_inv;
    for (int i = 0; i < n; i++) p_inv.insert(i);
    for (int v : p) p_inv.erase(v);

    seti used; 
    while (!p.empty()) {
        int p1 = p.front();
        int i1 = *p_inv.begin();

        g.psh({i1, p1});
        s.erase(i1);
        p.pop_front(); // rem p1

        --deg[p1];
        --deg[i1];
        
        p_inv.erase(i1);
        used.insert(i1);
        if (used.find(p1) == used.end() && deg[p1] == 0) {
            p_inv.insert(p1);
        }
    }

    g.psh({*s.begin(), *++s.begin()});
 
    for (const prii& e : g) {
        cout << e.fir + 1 << ' ' << e.sec + 1 << $;
    }

}
/*
  alternate: https://cp-algorithms.com/graph/pruefer_code.html
*/
