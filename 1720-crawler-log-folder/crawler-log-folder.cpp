class Solution {
public:
    int minOperations(vector<string>& logs) {
     int result=0;
     for(const auto& curr_oper : logs){
        if(curr_oper=="../"){
            if(result>0) result--;
        }
        else if(curr_oper=="./") continue;
        else result++;
     }  
     if(result<0) return 0;
     return result; 
    }
};