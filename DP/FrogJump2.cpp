// Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_b
/* By- Anand Singh */    
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define getFast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define br "\n"
#define inf 1e18
#define pi 3.1415926535897
#define mp make_pair
#define int long long int
#define ld long double
#define mid(l,r)  (l+(r-l)/2)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define ub(x, k)    upper_bound((x).begin(), (x).end(), k);
#define lb(x, k)    lower_bound((x).begin(), (x).end(), k);
#define loop(i, a, x)    for(int i = (a); i <= (x); i++)
#define bpc(n)    __builtin_popcount(x)
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
typedef vector<bool>    vb;
typedef vector<int>    vi;
typedef pair<int, int>    pii;
typedef vector<pii>    vp;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
// int frogjumpBu(vector<int> &v, int n, int k){
//  // bottom up
//  vector<int> dp(100005, inf);
//  dp[0] = 0;
//  for(int i = 1; i < n; i++){
//      for(int j = 1; j <= k; j++){
//          if(i-j < 0) break;
//          dp[i] = min(dp[i], dp[i-j] + abs(v[i] - v[i-j]));
//      }
//  }
//  return dp[n-1];
// }
 
vector<int> dp(1e5+5, inf);
int frogjumpTD(vector<int> &v, int n, int k){
    // base case
    if(n == 0){
        return 0;
    }
 
    // check if dp[n] is already calculated then return 
    if(dp[n] != inf)
        return dp[n];
 
    // get the minimum from every n-j
    for(int j = 1; j <= k; j++){
        if(n-j < 0) break;
        dp[n] = min(dp[n], (frogjumpTD(v, n-j, k) + abs(v[n]-v[n-j])));
    }
    return dp[n];
}
 
signed main(int32_t argc, char const *argv[]){
    getFast;
    //Write your code here...
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i : v)
        cin>>i;
    // cout<<frogjumpBU(v, n, k);
    // memset(dp, inf, sizeof dp);
    cout<<frogjumpTD(v, n-1, k);
    return 0;
}