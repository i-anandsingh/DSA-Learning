// Problem Link :- https://leetcode.com/problems/n-queens/
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

int ways = 0;

bool isSafe(int row, int col, vector<vector<bool>> &board){
	int n = sz(board);
	for(int i = row-1; i >= 0; i--){
		if(board[i][col])
			return false;
	}

	for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--){
		if(board[i][j])
			return false;
	}

	for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++){
		if(board[i][j])
			return false;
	}
	return true;
}

void nqueens(int n, int i, vector<vector<bool>> &board){
	if(i == n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][j])
					cout<<"Q";
				else
					cout<<".";
			}
			cout<<br;
		}
		cout<<"-----------\n";
		ways++;
		return;
	}
	for(int j = 0; j < n; j++){
		if(isSafe(i, j, board)){
			board[i][j] = true;
			nqueens(n, i+1, board);
			board[i][j] = false;
		}
	}
}

bitset<30> col, lt, rt;
void nqueens_op(int n, int i, vector<vector<bool>> &board){
	if(i == n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][j])
					cout<<"Q";
				else
					cout<<".";
			}
			cout<<br;
		}
		cout<<"-----------\n";
		ways++;
		return;
	}
	for(int j = 0; j < n; j++){
		if(!col[j] and !lt[i-j+n-1] and !rt[i+j]){
			col[j] = lt[i-j+n-1] = rt[i+j] = 1;
			board[i][j] = true;
			nqueens_op(n, i+1, board);
			board[i][j] = false;
			col[j] = lt[i-j+n-1] = rt[i+j] = 0;
		}
	}
}

signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n;
	cin>>n;
	vector<vector<bool>> board(n, vector<bool>(n, false));
	// nqueens(n, 0, board);
	col.reset();
	lt.reset();
	rt.reset();
	nqueens_op(n, 0, board);
	cout<<ways<<br;
	return 0;
}