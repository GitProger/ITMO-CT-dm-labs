#include <bits/stdc++.h>
using namespace std;
ifstream fin("useless.in");
ofstream fout("useless.out");

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
#define pr pair
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
#define pp pop_back
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
    int n; char S;
    cin >> n >> S;
    vec<pr<char, str>> rules;
    set<char> all_nts = {S};

    for (int i = 0; i < n; ++i) {
        char nt; str arr; cin >> nt >> arr;
        str s;
        getline(cin, s);
        s.erase(remove_if(all(s), ::isspace), s.end());

        rules.psh(mkp(nt, s));

        all_nts.insert(nt);
        for (char c : s) 
            if (::isupper(c))
                all_nts.insert(c);

    }
    
    set<char> gen;
    for (const auto &x : rules) {
        if (all_of(all(x.sec), ::islower)) {
            gen.insert(x.fir);
        }
    }
    

    int gen_size = len(gen);
    for (;;) {
        for (const auto &x : rules) {
            if (all_of(all(x.sec), [=] (char c) { return ::islower(c) || gen.find(c) != gen.end(); })) {
                gen.insert(x.fir);
            }
        }
        
        if (gen_size == len(gen)) break;
        gen_size = len(gen);
    }
    
    vec<pr<char, str>> new_rules;
    for (const auto &x : rules) {
        if (gen.find(x.fir) == gen.end()) continue;
        if (!all_of(all(x.sec), [=] (char c) { 
            return ::islower(c) || gen.find(c) != gen.end(); 
        })) continue;
        new_rules.psh(x);
    }
    
    rules = new_rules;
    new_rules.clear();

    set<char> reach = {S};
    int reach_size = 1;
    for (;;) {
        for (const auto &x : rules) {
            if (reach.find(x.fir) != reach.end()) {
                for (char c : x.sec) {
                    if (::isupper(c)) {
                        reach.insert(c);
                    }
                }
            }
        }
        
        if (reach_size == len(reach)) break;
        reach_size = len(reach);
    }

    
    vec<char> ans;
    set_difference(all(all_nts), all(reach), inserter(ans, ans.beg()));


    for (const auto &x : rules) {
        if (reach.find(x.fir) == reach.end()) continue;
        if (!all_of(all(x.sec), [=] (char c) { 
            return ::islower(c) || reach.find(c) != reach.end(); 
        })) continue;
        new_rules.psh(x);
    }
    
    if (len(reach) == 1) { // {S}
        bool ok = false;
        for (const auto &x : new_rules) {
            if (all_of(all(x.sec), ::islower)) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            ans.psh(S);
            sort(all(ans));
        }
    }
    
    cout << ans << $;

}

/*
https://neerc.ifmo.ru/wiki/index.php?title=%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B1%D0%B5%D1%81%D0%BF%D0%BE%D0%BB%D0%B5%D0%B7%D0%BD%D1%8B%D1%85_%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%BE%D0%B2_%D0%B8%D0%B7_%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%D1%82%D0%B8%D0%BA%D0%B8

5 S
S -> AB
S -> C
A -> a
B -> b
T -> c

>C T

1 S
S -> a
ответ: пусто
2 S
S -> S
S -> aS
ответ: S

* 
*/


