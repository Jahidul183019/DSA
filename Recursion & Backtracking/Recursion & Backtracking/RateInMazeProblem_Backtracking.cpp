// #include <iostream>
// #include <vector>

// using namespace std;

// void helper(vector<vector<int>>&mat,int row,int col,string path,vector<string>&ans,vector<vector<bool>>&vis){
//     int n=mat.size();

//     if(row<0 || col<0 || row>=n || col>=n || mat[row][col]==0 ||vis[row][col]==true){
//         return;
//     }
//     if(row==n-1 && col==n-1){
//         ans.push_back(path);
//         return;
//     }

//     vis[row][col]=true;

//     helper(mat,row+1,col,path+"D",ans,vis);//dowm
//     helper(mat,row-1,col,path+"U",ans,vis);//up
//     helper(mat,row,col-1,path+"L",ans,vis);//left
//     helper(mat,row,col+1,path+"R",ans,vis);//right

//     vis[row][col]=false;
// }
// vector<string>findPath(vector<vector<int>>&mat){
//     int n=mat.size();
//     vector<string>ans;
//     string path="";
//     vector<vector<bool>>vis(n,vector<bool>(n,false));

//     helper(mat,0,0,path,ans,vis);

//     return ans;
// }
// int main(){
//     vector<vector<int>>mat={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
//     vector<string>ans=findPath(mat);

//     for(string path : ans){
//         cout<<path<<endl;
//     }
//     return 0;
// }
                                   

                                            //Optimization (Time Complexity : O(4^n*n))


#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>>&mat,int row,int col,string path,vector<string>&ans){
    int n=mat.size();

    if(row<0 || col<0 || row>=n || col>=n || mat[row][col]==0 ||mat[row][col]==-1){
        return;
    }
    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }

    mat[row][col]=-1;

    helper(mat,row+1,col,path+"D",ans);//dowm
    helper(mat,row-1,col,path+"U",ans);//up
    helper(mat,row,col-1,path+"L",ans);//left
    helper(mat,row,col+1,path+"R",ans);//right

    mat[row][col]=1;
}
vector<string>findPath(vector<vector<int>>&mat){
    int n=mat.size();
    vector<string>ans;
    string path="";

    helper(mat,0,0,path,ans);

    return ans;
}
int main(){
    vector<vector<int>>mat={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>ans=findPath(mat);

    for(string path : ans){
        cout<<path<<endl;
    }
    return 0;
}