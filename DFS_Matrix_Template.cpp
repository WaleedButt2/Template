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
class Maze{
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
    bool Traverse_DFS(){
        bool Flag=false; 
        Traverse_DFS(start[0],start[1],Flag);
        fill(Visited.begin(), Visited.end(), vector<bool>(Visited.size(),false));
        return Flag;
    }
    int Traverse_DFS(int x){
        int shorte=99999999;
        Traverse_DFS(start[0],start[1],x,shorte);
        fill(Visited.begin(), Visited.end(), vector<bool>(Visited.size(),false));
        //fill(Visited.begin(),Visited.end(),false);
        return shorte;
    }
    void Traverse_DFS(int i, int j,int x,int &shortest){
       // cout<<i<<' '<<j<<endl;
        if(Matrix[i][j]==2) {shortest=min(x,shortest);return;}
        Visited[i][j]=true;
        x++;
        //go up
        if(Is_Safe(i-1,j))   Traverse_DFS(i-1,j,x,shortest);
        //go down
        if(Is_Safe(i+1,j))  Traverse_DFS(i+1,j,x,shortest);
        //go left
        if(Is_Safe(i,j-1))  Traverse_DFS(i,j-1,x,shortest);
        //go right
        if(Is_Safe(i,j+1))  Traverse_DFS(i,j+1,x,shortest);
        //shortest=-1;
        Visited[i][j]=false;
        return;
    }
    void Traverse_DFS(int i, int j,bool &Flag){
       // cout<<i<<' '<<j<<endl;
        if(Matrix[i][j]==2) { Flag= true;return;}
        Visited[i][j]=true;
        //Print(this->Matrix);
        //go up
        if(Is_Safe(i-1,j))   Traverse_DFS(i-1,j,Flag);
        //go down
       // cout<<"d"<<endl;
        if(Is_Safe(i+1,j))  Traverse_DFS(i+1,j,Flag);
        //go left
        if(Is_Safe(i,j-1))  Traverse_DFS(i,j-1,Flag);
        //go right
        if(Is_Safe(i,j+1))  Traverse_DFS(i,j+1,Flag);
        Visited[i][j]=false;
        return;
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
    Success=Jojo.Traverse_DFS();
    paths=Jojo.Traverse_DFS(paths);
    if(paths!=99999999)cout<<"Shortest Distance is "<<paths<<endl;
    else cout<<"Paths does not exist\n";
    if(Success) cout<<"Path Found"<<endl;
    else cout<<"Path Not Found"<<endl;
}

