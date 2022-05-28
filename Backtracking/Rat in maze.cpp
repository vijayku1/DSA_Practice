/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

*/

class Solution{
    public:
   vector<string> v;
     bool visited[10][10];
    void pathst(string &st,vector<vector<int>> &m,int i,int j,int n)
    {
        if(i==n-1 && j==n-1)
        {
            v.push_back(st);
            return ;
        }
       // if(i>n-1 || j>n-1)return;
        visited[i][j]=true;
       
        if( i+1<n && m[i+1][j]==1 &&!visited[i+1][j])
        {
            st+='D';
             pathst(st,m,i+1,j,n);
             st.pop_back();
        }
        if( j+1<n && m[i][j+1]==1 && !visited[i][j+1])
        {
            st+='R';
               pathst(st,m,i,j+1,n);
               st.pop_back();
        }
        if(i-1>=0 && m[i-1][j]==1 &&  !visited[i-1][j])
        {
            st+='U';
               pathst(st,m,i-1,j,n);
               st.pop_back();
        }
       
        if(j-1>=0 && m[i][j-1]==1 && !visited[i][j-1])
        {
            st+='L';
               pathst(st,m,i,j-1,n);
               st.pop_back();
        }
        visited[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       memset(visited,0,sizeof(visited));
        string st="";
        if(m[0][0]==1){
        pathst(st,m,0,0,n);
        sort(v.begin(),v.end());
        }
        return v;
    }
};