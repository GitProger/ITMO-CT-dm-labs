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
 
////////////////////////////////////////////////////////////////////////////////
 
template <class T> T rmin(T &a, const T &b) { return (a = min(a, b)); }
template <class T> T rmax(T &a, const T &b) { return (a = max(a, b)); }
template <class T> T reql(T &a, const T &b) { return (a = b); }
 
// https://neerc.ifmo.ru/wiki/index.php?title=Алгоритм_нахождения_Гамильтонова_цикла_в_условиях_теорем_Дирака_и_Оре
// https://neerc.ifmo.ru/wiki/index.php?title=Теорема_Хватала
inline void solve() {
    int n; cin >> n;
    vec<veci> g(n, veci(n));
    for (int i = 1; i < n; i++) {
        str s; cin >> s;
        for (int j = 0; j < len(s); j++) {
            g[i][j] = g[j][i] = s[j] == '1';
        }
    }
 
   
    deque<int> q;
     
    for (int i = 0; i < n; ++i) {
        q.push_back(i);
    }
     
    for (int k = 0; k <= n * (n - 1); ++k) {
        int q0 = q[0], q1 = q[1];
        if (!g[q0][q1]) {
            int i = 2;   
            while ((i < n - 1) && (!g[q0][q[i]] || !g[q1][q[i + 1]]))
                ++i;

            if (i >= n - 1) {
                i = 2;
                while (!g[q0][q[i]]) ++i;
            }

      
            for (int j = 0; 1 + j < i - j; ++j)
                swap(q[1 + j], q[i - j]);
        }
        q.push_back(q.front());
        q.pop_front();
    }
 
    for (int x : q) cout << x + 1 << ' ';
    cout << $;
 
}
/*
*/
