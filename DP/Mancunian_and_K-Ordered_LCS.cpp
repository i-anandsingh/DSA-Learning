// Problem Link :- https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
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
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
typedef vector<bool>    vb;
typedef vector<int>    vi;
typedef pair<int, int>    pii;
typedef vector<pii>    vp;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

int dp[2005][2005][8];

int korderedlcs(vector<int> &a, vector<int> &b, int i, int j, int k){
	if(i == sz(a) or j == sz(b)){
		return 0;
	}
	if(dp[i][j][k] != -1)
		return dp[i][j][k];

	int ans = 0;
	if(a[i] == b[j])
		ans = (1 + korderedlcs(a, b, i+1, j+1, k));
	else{
		if(k > 0)
			ans = (1 + korderedlcs(a, b, i+1, j+1, k-1));
		ans = max({ans, korderedlcs(a, b, i+1, j, k), korderedlcs(a, b, i, j+1, k)});
	}

	return dp[i][j][k] = ans;
}

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> a(n), b(m);
	for(auto &i : a)	cin>>i;
	for(auto &i : b)	cin>>i;
	memset(dp, -1, sizeof dp);
	cout<<korderedlcs(a, b, 0, 0, k)<<br;
	return 0;
}