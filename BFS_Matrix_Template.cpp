#include <bits/stdc++.h>
using namespace std;
#define max 5
void Print(vector<vector<int>> Matrix){
    for(int i=0;i<Matrix.size();i++){ 
    for(int j=0;j<Matrix[i].size();j++)
    cout<<Matrix[i][j]<<' ';
    cout<<endl;
    }
    cout<<endl;
}
void Print(vector<int> Matrix){
    for(int i=0;i<Matrix.size();i++) cout<<Matrix[i]<<' ';
    cout<<endl;
}
class point{
    public:
    int i=-1;
    int j=-1;
    int dist=0;
point(int i,int j,int dist){
    this->i;this->j=j;this->dist=dist;
}
};
class Maze{
    queue <point> q;
    vector<vector<int>> Matrix;
    vector<vector<bool>> Visited;
    int start[2];
public:
    Maze(vector<vector<int>> Maze,vector<vector<bool>> Visited){
        Matrix=Maze;
        for(int i=0;i<max;i++)
        for(int j=0;j<max;j++)
        if(Matrix[i][j]==1) {
            start[0]=i;
            start[1]=j;
        }
        this->Visited=Visited;
        //exit(0);
    }
    bool Is_Safe(int i,int j){
        return (i>=0&&j>=0&&j<Matrix[i].size()&&i<Matrix.size()&&!Visited[i][j]&&Matrix[i][j]!=3);
    }  
    int Traverse_BFS(){
        int shorte=Traverse_BFS(start[0],start[1]);
        fill(Visited.begin(), Visited.end(), vector<bool>(Visited.size(),false));
        //fill(Visited.begin(),Visited.end(),false);
        return shorte;
    }
    int Traverse_BFS(int i, int j){
       // cout<<i<<' '<<j<<endl;
        point p(i,j,0);
        q.push(p);
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(Matrix[p.i][p.j]==2) return p.dist;
            //go up
            if(Is_Safe(p.i+1,p.j))  { 
                q.push(point(p.i+1,p.j,p.dist+1));
                Visited[p.i+1][p.j]=true;
            }
            //go down
            if(Is_Safe(p.i-1,p.j))  { 
                q.push(point(p.i-1,p.j,p.dist+1));
                Visited[p.i-1][p.j]=true;
            }
            //go left
            if(Is_Safe(p.i,p.j-1))  { 
                q.push(point(p.i,p.j-1,p.dist+1));
                Visited[p.i][p.j-1]=true;
            }
            //go right
            if(Is_Safe(p.i,p.j+1))  { 
                q.push(point(p.i,p.j+1,p.dist+1));
                Visited[p.i][p.j+1]=true;
            }
        } 
        return -1;
    }
   
};
int main(){
   // vector<vector<int>> Maze(max,vector<int>(max,0));
    bool Success;
    vector<vector<int>> Matrix
    {
    {0,0,0,0,0},
    {0,1,0,0,0},
    {0,0,3,0,3},
    {0,0,3,2,0},
    {0,0,3,0,0}
    };
    vector<vector<bool>> Visited(max,vector<bool>(max,false));
    Maze Jojo(Matrix,Visited);
    int paths=0;
    paths=Jojo.Traverse_BFS();
    if(paths!=-1)cout<<"Shortest Distance is "<<paths<<endl;
    else cout<<"Paths does not exist\n";
}