#include <bits/stdc++.h>
#define debug(x) cout << "[" << #x << " = " << x << "] "
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

using tii = tuple<int,int,int>;
// auto [a,b,c] = ...
// .insert({a,b,c})

const int oo = (int)1e9; //INF to INT
const ll OO = 0x3f3f3f3f3f3f3f3fLL; //INF to LL

/*wa? coloca long long que passa;
testar casos, n = 0? n = 1? todos os numeros iguais?
Uma resposta ótima pode ter tamanho 2?
RELER O ENUNCIADO!*/

map<char,int> mp;

void solve(){
    int n, ans = 0;
    string s;
    cin >> n >> s;
    ans = __builtin_popcount(mp[s[0]]);
    for(int i = 1; i < n; i++){
        int need = mp[s[i]];
        int add = (need & (~mp[s[i-1]]));
        //debug(add); cout << endl;
        ans += __builtin_popcount(add);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp['U'] = 0;
    mp['R'] = 1;
    mp['Y'] = 2;
    mp['B'] = 4;

    mp['O'] = 3;
    mp['P'] = 5;
    mp['G'] = 6;
    mp['A'] = 1+2+4;

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

}
