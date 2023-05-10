#include<stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s1; 
        for(int i = 0; i < tokens.size(); i++)
        {
            string s = tokens[i];
            if(s == "+"){
                int n1 = s1.top();
                s1.pop();
                int n2 = s1.top();
                s1.pop();
                s1.push(n2+n1); 
            }
            else if(s == "-"){
                int n1 = s1.top();
                s1.pop();
                int n2 = s1.top();
                s1.pop();
                s1.push(n2-n1); 
            
            }
            else if(s == "*"){
                int n1 = s1.top();
                s1.pop();
                int n2 = s1.top();
                s1.pop();
                s1.push(n2*n1);
            }
            else if(s == "/"){
                int n1 = s1.top();
                s1.pop();
                int n2 = s1.top();
                s1.pop();
                s1.push(n2/n1);
            }
            // when number comes s1(stack) is of integer type and s is string
            // to convert string to integer we use 'stoi'
            else {
                s1.push(stoi(s)); 
            }
        }        
        return s1.top();
    }

};
