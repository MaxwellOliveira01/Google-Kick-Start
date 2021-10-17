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

// O(N^3)
void solve(){
    int n, ans = oo;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto &v : arr)
        cin >> v;
    
    auto brute = [&](int b, int e, ll target){
        //begin and end -> [begin, end)
        int sz = oo;
        for(int i = b; i < e; i++){
            ll sum = 0;
            for(int j = i; j < e; j++){
                sum += arr[j];
                if(sum == target){
                    sz = min(sz, j-i+1);
                } else if(sum > target){
                    break;
                }
            }
        }
        return sz;
    };

    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            //i...j
            sum += arr[j];
            if(sum > k){
                break;
            } else if(sum == k){
                ans = min(ans, j-i+1);
            }
            ans = min(ans, j-i+1 + brute(j+1,n,k-sum));
            ans = min(ans, j-i+1 + brute(0,i,k-sum));
        }
    }
    cout << (ans >= oo ? -1 : ans) << "\n";
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
