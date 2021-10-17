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

//O(N^2 * logN)
void solve(){
    int n, ans = oo;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);

    vector< vector<pii> > st(k+1);

    for(auto &v : arr)
        cin >> v;
    
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum > k){
                break;
            } else {
                //                          i, size
                st[sum].push_back(make_pair(i,j-i+1));
            }
        }
    }

    for(int i = 0; i <= k; i++){
        sort(st[i].begin(), st[i].end());
    }

    vector< vi > minSuf(k+1);

    for(int i = 0; i <= k; i++){
        minSuf[i].push_back(oo);
        for(int j = st[i].size() - 1; j >= 0; j--){
            minSuf[i].push_back(min(st[i][j].ss,minSuf[i].back()));
        }
        reverse(minSuf[i].begin(), minSuf[i].end());
    }

    auto comp = [&](int posi, ll target){
        pii x = {posi, 0};
        auto pq = lower_bound(st[target].begin(), st[target].end(), x);
        if(pq == st[target].end()) return oo;
        auto ax = pq - st[target].begin();
        return minSuf[target][ax];
    };

    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            //i...j
            sum += arr[j];
            if(sum > k || arr[j] == 0){
                break;
            } else if(sum == k){
                ans = min(ans, j-i+1);
            } else {
                ans = min(ans, j-i+1 + comp(j+1,k-sum));
            }
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
