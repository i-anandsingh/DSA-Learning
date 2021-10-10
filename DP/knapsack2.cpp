// Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_e
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



signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n, w;
	cin>>n>>w;
	vector<int> wt(n, 0), val(n, 0);
	for(int i = 0; i < n; i++){
		cin>>wt[i]>>val[i];
	}
	// when all n items are of 1000 profit then max profit is n*1000
	vector<int> dp1(n*1000+1, inf);
	vector<int> dp2(n*1000+1, inf);
	dp1[0] = 0;
	dp1[val[0]] = wt[0];

	for(int i = 1; i < n; i++){
		for(int j = 0; j <= n*1000; j++){
			dp2[j] = dp1[j];
			if(val[i] <= j){
				dp2[j] = min(dp2[j], wt[i] + dp1[j-val[i]]);
			}
		}
		dp2.swap(dp1);
		dp2.clear();
	}

	int res = 0;
	for(int j = 0; j <= n*1000; j++){
		if(dp1[j] <= w)	res = j;
	}
	cout<<res<<br;
	return 0;
}