#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define all(obj) obj.begin(),obj.end()
#define rall(obj) obj.begin(),obj.end()
#define len(obj) ((int)obj.size())
template <class T> istream &operator >> (istream &in, vector<T> &v) { 
    for (T &t : v) in >> t;
    return in;
}
template <class T> ostream &operator << (ostream &out, const vector<T> &v) {
    for (const T &t : v) out << t << ' ';
    return out;
}

ifstream fin("minimization.in");
ofstream fout("minimization.out");
//*
#define cin fin
#define cout fout
//*/


mt19937 rnd(1337);
const ll MOD = 1000000007;
inline void solve();
signed main() {
//    freopen("pratincole.in", "r", stdin);
//    freopen("pratincole.out", "w", stdout);
//    cin.tie(nullptr);
//    ios_base::sync_with_stdio(false);
    int t = 1;
  //  cin >> t;
    while (t--) solve();
    cout.flush();
    cerr << "\nTime: " << setprecision(2) <<
        int(1000 * (double)clock() / CLOCKS_PER_SEC) << " ms\n";
    return 0;
}


str alpha;
int n, k, q0;
vector<int> term;
vector<int> can_reach;
vector<map<char, int>> table;
vector<map<char, vector<int>>> rtable;
vector<vector<int>> diff;
/*
#define print(v) { \
    cerr << "check! LINE: " << __LINE__ << "; "; \
    cerr << "VAR: " << #v << " | "; \
    for (int i = 1; i <= n; i++) cerr << v[i] << ' '; \
    cerr << "\n"; \
}
#define HR cerr<<string(20, '-')<<"\n";
#define BHR cerr<<string(20, '=')<<"\n";
*/

void dfs(vector<map<char, int>> &g, vector<int> &used, int v) {
    used[v] = 1;
    for (auto next : g[v]) {
        int u = next.second;
        if (!used[u]) dfs(g, used, u);
    }
}

inline void solve() {
    for (char c = 'a'; c <= 'z'; c++) {
        alpha.push_back(c);
    }
    
    
    cin >> n;
    int m; cin >> m;
    term.resize(n + 1);
    table.resize(n + 1);
    rtable.resize(n + 1);
    can_reach.resize(n + 1);
    
    q0 = 1;
    cin >> k; 
    for (int i = 0; i < k; i++) {
        int e; cin >> e;
        term[e] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        int v, u; char c;
        cin >> v >> u >> c;
        table[v][c] = u;
        rtable[u][c].push_back(v);
    }
    
    dfs(table, can_reach, q0);

  //  print(can_reach);

    diff = vector<vector<int>>(n + 1, vector<int>(n + 1));    
    queue<pair<int, int>> pairs;
    for (int p = 1; p <= n; p++)
        for (int q = 1; q <= n; q++)
            if (!diff[p][q] && term[p] != term[q]) {
                diff[p][q] = diff[q][p] = 1;
                pairs.push({p, q});
//                cerr << "default pair: " << p << " " << q << "\n";
            }
   // HR
    
    while (!pairs.empty()) {
        auto top = pairs.front(); pairs.pop();
        int u = top.first, v = top.second;
    //    cerr << "\033[1;31mprocess pair:\033[0m " << u << " " << v << "\n";
        for (char c : alpha) {
            for (int r : rtable[u][c])
                for (int s : rtable[v][c])
                    if (!diff[r][s]) {
                        diff[r][s] = diff[s][r] = 1;
                        pairs.push({r, s});
    //                     cerr << "add new pair: " << r << " " << s << "\n";
                    }
        }
    }
  /*  
    HR
    cerr << "diff: \n";
    cerr << "   ";
    for (int i = 1; i <= n; i++) cerr << i << " ";
    cerr << "\n";
    for (int i = 1; i <= n; i++) {
        cerr << i << ": ";
        for (int j = 1; j <= n; j++) {
            cerr << diff[i][j] << " ";
        }
        cerr << "\n";
    }

    BHR    */
////////////////////////////////////////////////////////////////////////////////

    int comp_cnt = 1;
    vector<int> comp(n + 1);
    for (int i = 1; i <= n; i++) 
        if (!diff[q0][i] && can_reach[i])
            comp[i] = 1;
    
    for (int p = 1; p <= n; p++) {
        if (!can_reach[p]) continue;
        if (comp[p] != 0) continue;
        comp[p] = ++comp_cnt;
        for (int q = p + 1; q <= n; q++)
            if (!diff[p][q] && can_reach[q])
                comp[q] = comp_cnt;
    }
    
   // print(comp);

    vector<map<char, int>> new_dsm(comp_cnt + 1);

    for (int v = 1; v <= n; v++)
        for (char c : alpha)
            new_dsm[comp[v]][c] = comp[table[v][c]];

    int new_q0 = comp[q0];
    set<int> new_term;
    for (int v = 1; v <= n; v++)
        if (term[v] && comp[v] != 0)
            new_term.insert(comp[v]);


    int m_cnt = 0;
    for (int v = 1; v <= comp_cnt; v++) {
        for (char c : alpha) {
            int u = new_dsm[v][c];
            if (u != 0)
                m_cnt++;
        }
    }


    cout << comp_cnt << ' ' << m_cnt << ' ' << len(new_term) << '\n';
    for (int t : new_term) cout << t << ' ';
    cout << '\n';
    
    for (int v = 1; v <= comp_cnt; v++) {
        for (char c : alpha) {
            int u = new_dsm[v][c];
            if (u != 0)
                cout << v << ' ' << u << ' ' << c << '\n';
        }
    }
}
// doesn't work
// https://github.com/GitProger/lksh-winter/blob/main/2/E.cpp

