#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visit,int x,int y,int n,int m){
             visit[x][y]=1;
            

            int dx[4]={0,1,0,-1};
            int dy[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visit[nx][ny]&& grid[nx][ny]==1) dfs(grid,visit,nx,ny,n,m);
            }
    }
    int solve(vector<vector<int>>&grid,vector<vector<int>>&visit){
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            if(grid[0][i]) dfs(grid,visit,0,i,n,m);
            
            if(grid[n-1][i]) dfs(grid,visit,n-1,i,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]) dfs(grid,visit,i,0,n,m);
            if(grid[i][m-1]) dfs(grid,visit,i,m-1,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&visit[i][j]==0) count++;
            }
        }
        return count;
    }
};



int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    vector<vector<int>>visit(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            grid[i][j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    solution obj;
    cout<<obj.solve(grid,visit);
        cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<visit[i][j]<<" ";
        }
        cout<<endl;
    }
}