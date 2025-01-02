class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
      vector<vector<int>>result(img.size(),vector<int>(img[0].size(),0));
      for(int i=0;i<img.size();i++){
        for(int j=0;j<img[0].size();j++){
             result[i][j]=avg(i,j,img);
        }
      } 
      return result;
    } 
    int avg(int a, int b , vector<vector<int>>&img){
        int sum=0;
        int count=0;
        for(int dx= max(0,a-1); dx<= min((int)img.size()-1,a+1);dx++){
            for(int dy= max(0,b-1);dy<= min((int)img[0].size()-1,b+1);dy++){
                sum+=img[dx][dy];
                count++;
            }
        }
        return sum/count;
    }
};