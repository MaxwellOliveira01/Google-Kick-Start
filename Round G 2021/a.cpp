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
    ll n, d, c, m;
    string s;
    cin >> n >> d >> c >> m >> s;
    int last_dog = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D')
            last_dog = i;
    }
    for(int i = 0; i <= last_dog; i++){
        if(s[i] == 'D'){
            if(d > 0){
                d--;
            } else {
                cout << "NO\n";
                return;
            }
            c += m;
        } else {
            if(c > 0){
                c--;
            } else {
                if(i < last_dog){
                    cout << "NO\n";
                    return;
                }
                break;
            }
        }
    }
    cout << "YES\n";
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
