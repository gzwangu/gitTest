#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 1e5+5;
int n, dp[maxn][2], in[maxn];
vector<int> g[maxn];

//从根开始dfs，回溯的时候更新dp数组
void dfs(int x){
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		dfs(v);
		dp[x][0] += max(dp[v][0], dp[v][1]); // 不选该节点
		dp[x][1] += dp[v][0]; // 选该节点
	}
}

int main(){
	while (cin >> n && n) {
		memset(in, 0, sizeof(in));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> dp[i][1];
		}
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			g[v].push_back(u);
			in[u]++;
		}
		int root;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root);
		cout << max(dp[root][0], dp[root][1]) << endl;
	}
	return 0;
}
