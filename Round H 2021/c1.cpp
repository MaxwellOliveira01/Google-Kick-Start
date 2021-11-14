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

int apply(string& s, string pat, string change){
    string t = "";
    int cont = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(i+1 < (int)s.size() && s[i] == pat[0] && s[i+1] == pat[1]){
            t += change;
            cont++;
            i++;
        } else {
            t += s[i];
        }
    }
    s = t;
    return cont;
}

// Maybe 10 points of set 1? ;--;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    while(1){
        int c = 0;
        c += apply(s, "01","2");
        c += apply(s, "12","3");
        c += apply(s, "23","4");
        c += apply(s, "34","5");
        c += apply(s, "45","6");
        c += apply(s, "56","7");
        c += apply(s, "67","8");
        c += apply(s, "78","9");
        c += apply(s, "89","0");
        c += apply(s, "90","1");
        if(c == 0){
            break;
        }
    }
    cout << s << endl;
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
