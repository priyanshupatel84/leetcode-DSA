class Solution {
public:
    void solve(int n, string &temp, vector<string> &ans, int open, int close){
        if(close == n && open == n){
            ans.push_back(temp);
            return;
        }
        if(temp.length() == 2*n){
            return;
        }

        if(open < n){
            temp.push_back('(');
            solve(n, temp, ans, open+1, close);
            temp.pop_back();
        }

        if(temp.length() > 0 && close < open){
            temp.push_back(')');
            solve(n, temp, ans, open, close+1);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, temp, ans, 0, 0);
        return ans;
    }
};