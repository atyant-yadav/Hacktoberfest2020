class Solution {
public:
    bool isValid(string s) {
        
        
        //string s;
        
        stack<char> stack;
        char c;
        for(int i=0;i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]== '[' || s[i]== '{')
            {
                stack.push(s[i]);
                continue;
            }
            if(stack.empty())
                return 0;
            if(s[i]==')')
            {
                c=stack.top();
                if(c=='{' || c=='[')
                    return 0;
                stack.pop();
                
                
            }
            else if(s[i]==']')
            {
                c=stack.top();
                stack.pop();
                if(c=='{' || c=='(')
                    return 0;
            }
            else if(s[i]=='}')
            {
                c=stack.top();
                stack.pop();
                if(c=='(' || c=='[')
                    return 0;
            }
            
            
            
        }
        
        return stack.empty();
    
    }
};
