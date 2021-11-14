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

void solve(){
    int ans = 0;
    string s, t;
    cin >> s >> t;
    // aumentar/diminuir as letras de s até estarem em T
    vector<int> tmp(26, 0);
    for(auto &x: t){
        tmp[x-'a']++;
    }
    for(int i = 0; i < (int)s.size(); i++){
        int add = oo;
        for(int j = 0; j < 26; j++){
            if(tmp[j]){
                int dif = abs(char(s[i]-'a') - j);
                //debug(dif);
                add = min(add, dif);
                add = min(add, 26-dif);
            }
        }
        ans += add;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

}
