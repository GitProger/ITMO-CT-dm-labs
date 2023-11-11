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

// https://neerc.ifmo.ru/wiki/index.php?title=Теорема_Редеи-Камиона

void cut(veci &from, veci &to, int cnt, int pos_to) {
    to.insert(to.begin() + pos_to, from.begin(), from.begin() + cnt);
    from.erase(from.begin(), from.begin() + cnt);
}

inline void solve() {
    int n; cin >> n;
    vec<veci> g(n, veci(n));
    for (int i = 1; i < n; ++i) {
        str s; cin >> s;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '1')
                g[i][j] = 1;
            else
                g[j][i] = 1;
        }
    }
    
    veci path = {0};
    for (int i = 1; i < n; ++i) {
        int p = len(path);
        for (int j = 0; j < len(path); ++j) {
            if (!g[path[j]][i]) {
                p = j;
                break;
            }
        }
        path.insert(path.begin() + p, i);
    }
    
    int trueStart = 0;
    for (int i = len(path) - 1; i >= 2; --i)
        if (g[path[i]][path[0]]) {
            trueStart = i;
            break;
        }

    veci cycle;
    cut(path, cycle, trueStart + 1, 0);

    for (int i = 0; i < len(path);) {
        bool found = false;
        for (int j = 0; j < len(cycle); ++j) {
            if (!g[cycle[j]][path[i]]) {
                cut(path, cycle, i + 1, j);
                found = true;
                break;
            }
        }
        
        ++i;
        if (found) i = 0;
    }

    
    cout << inc_vec<int>(cycle) << $;
}
/*
*/ 
