// Problem Link :- https://www.codechef.com/problems/BPHC03
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

int cnt = 0;

bool isSafe(int i, int j, vector<vector<int>> &board, vector<vector<bool>> &vis){
	int n = board.size();
	return i >= 0 and i < n and j >= 0 and j < n and (board[i][j] != 1) and (vis[i][j] == false);
}

void unique_path(int cr, int cc, vector<vector<int>> &board, vector<vector<bool>> &vis, int n){
	if( cr == n-1 and cc == n-1){
		cnt++;
		return;
	}

	vis[cr][cc] = true;
	if(isSafe(cr+1, cc, board, vis))
		unique_path(cr+1, cc, board, vis, n);

	if(isSafe(cr-1, cc, board, vis))
		unique_path(cr-1, cc, board, vis, n);

	if(isSafe(cr, cc+1, board, vis))
		unique_path(cr, cc+1, board, vis, n);

	if(isSafe(cr, cc-1, board, vis))
		unique_path(cr, cc-1, board, vis, n);

	vis[cr][cc] = false;
}

signed main(int32_t argc, char const *argv[]){
	// getFast;
	file_i_o();
	//Write your code here...
	int n;
	cin>>n;
	vector<vector<int>> board(n, vector<int> (n));
	vector<vector<bool>> vis(n, vector<bool> (n, false));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>board[i][j];
		}
	}
	unique_path(0, 0, board, vis, n);
	cout<<cnt<<br;
	return 0;
}