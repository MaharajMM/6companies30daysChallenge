class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long int operator1 = s.top();
                s.pop();
                long long int operator2 = s.top();
                s.pop();

                if (tokens[i] == "+")
                {
                    s.push(operator2 + operator1);
                }
                else if (tokens[i] == "-")
                {
                    s.push(operator2 - operator1);
                }
                else if (tokens[i] == "*")
                {
                    s.push(operator2 * operator1);
                }
                else if (tokens[i] == "/")
                {
                    s.push(operator2 / operator1);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};