class Solution {
public:
    void f(int i,int j,int col_to_change,int color,vector<vector<int>>& image, vector<vector<int>>& vis){
if(i>=image.size() || i<0 ||j<0 ||j>=image[0].size()|| image[i][j]!=col_to_change || vis[i][j]!=-1) return;
        vis[i][j]=1;
        image[i][j]=color;
        f(i+1,j,col_to_change,color,image,vis);
        f(i-1,j,col_to_change,color,image,vis);
        f(i,j+1,col_to_change,color,image,vis);
        f(i,j-1,col_to_change,color,image,vis);
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col_to_change=image[sr][sc];
        vector<vector<int>> vis(image.size(),vector<int> (image[0].size(),-1));
        f(sr,sc,col_to_change,color,image,vis);
        return image;
    }
};