class Solution {
public:
    bool isPalindrome(int x) {
     if(x<0) return false;
     long long orig_num=x;
     long long new_num=0;
     while(x>0){
        int r=x%10;
        new_num=new_num*10+r;
        x/=10;
     } 
     if(orig_num==new_num)return true;
     else return false;
    }
};