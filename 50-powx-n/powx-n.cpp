class Solution {
public:
    double myPow(double x, int n) {
      double ans=1.0;
      long long temp=n;
      if(n<0) temp= -1 * temp;
      while(temp>0){
        if(temp%2==0){
            x=x*x;
            temp/=2;
        }
        else{
            ans*=x;
            temp-=1;
        }
      }
     if(n>0) return ans;
     else return 1/ans;
    }
};