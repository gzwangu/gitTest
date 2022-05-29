#include<bits/stdc++.h>

using namespace std;

// 判断每一列上是否有冲突，即一个客户对应一个专车，值为-1说明已有对应关系
bool isvalid(vector<vector<int>>& route, int &row, int &col, int &n){
    // 列
    for(int i=0;i<row;++i){
        if(route[i][col]==-1) //已安排专车
            return false;
    }
    return true;
}

// 回溯法
vector<vector<vector<int>>> res; // 存放所有可能的路线
void dfs(vector<vector<int>> route,int &n, int row){
    if(row==n){ //一种可能路线安排
        res.push_back(route);
        return ;
    }
    for(int col=0;col<n;++col){
        if(isvalid(route,row,col,n)){ // 验证合法就可以安排
            int tm = route[row][col]; // 暂存距离
            route[row][col] = -1; // 安排专车
            dfs(route,n,row+1);
            route[row][col] = tm; // 回溯，撤销安排
        }
    }  
}


int main(){
    int n;
    n = 7;
    int minds = INT_MAX;
    vector<vector<int>> route(n,vector<int>(n));
    dfs(route,n,0);
    cout<<res.size();

    // vector<vector<int>> ans;
    // vector<vector<int>> route={{1,3,2},{2,4,1},{5,3,2}};
    
    // dfs(route,n,0);

    // for(auto vec2:res){
    //     int sm = 0;
    //     for(int i=0;i<vec2.size();++i){
    //         for(int j=0;j<vec2[i].size();++j){
    //             if(vec2[i][j]==-1){
    //                 sm += route[i][j];
    //             }
    //         }
    //     }
    //     if(sm<minds){
    //         minds = sm;
    //         ans = vec2;
    //     }
    // }
    // for(auto v:ans){
    //     for(auto p:v)
    //         cout<<p<<" ";
    //     cout<<endl;
    // }
}