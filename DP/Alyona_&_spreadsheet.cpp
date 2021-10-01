// Problem Link :- https://codeforces.com/problemset/problem/777/C
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

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

void precompute(int n, int m, vector<vector<int>> &v, vector<vector<int>> &dp, vector<int> &arr){
	loop(i, 1, m){
		dp[1][i] = 1;
	}

	loop(i, 2, n){
		loop(j, 1, m){
			if(v[i-1][j] <= v[i][j]){
				dp[i][j] = dp[i-1][j];
			} else{
				dp[i][j] = i;
			}
		}
	}

	loop(i, 1, n){
		arr[i] = *min_element(dp[i].begin(), dp[i].end());
	}
}

signed main(int32_t argc, char const *argv[]){
	// getFast;
	file_i_o();
	//Write your code here...
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n+1, vector<int> (m+1, 0));
	loop(i, 1, n){
		loop(j, 1, m){
			cin>>v[i][j];
		}
	}

	vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX));
	vector<int> arr(n+1, INT_MAX);
	precompute(n, m, v, dp, arr);
	int t;
	cin>>t;
	while(t--){
		int l, r;
		cin>>l>>r;
		if(l == r){
			cout<<"Yes"<<br;
			continue;
		}
		if(arr[r] <= l)	cout<<"Yes"<<br;
		else	cout<<"No"<<br;
	}
	return 0;
}