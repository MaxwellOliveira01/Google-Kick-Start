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

/*
(0,0) (0,1) (1,0) (1,1)
(2,3) (4,3) (2,6) (4,6)
(0,3) (5,3) (5,9) (0,9)
*/

    int k;
    cin >> k;
    
    vector<ll> x;
    vector<ll> y;

    for(int i = 0; i < k; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        /*
        (a,d)   (c,d)
        (a,b)   (c,b)
        */
        x.push_back(a);
        x.push_back(a);
        x.push_back(c);
        x.push_back(c);

        y.push_back(d);
        y.push_back(d);
        y.push_back(b);
        y.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[ k*2 -1 ] << " " << y[ k*2-1 ] << "\n"; 
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
