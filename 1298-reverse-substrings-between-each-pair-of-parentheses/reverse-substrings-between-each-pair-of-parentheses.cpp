class Solution {
public:
    string reverseParentheses(string s) {
       int n =s.size();
       string output="";
       stack<int>t;
       for(int i=0;i<n;i++){
        if(s[i]=='(')
        t.push(i);
        else if(s[i]==')'){
            reverse(s.begin()+t.top()+1,s.begin()+i);
            t.pop();
        }
       }
    for(int i=0;i<n;i++){
        if(s[i]!='('&&s[i]!=')'){
            output+=s[i];
        }
    }
    return output;
}
};