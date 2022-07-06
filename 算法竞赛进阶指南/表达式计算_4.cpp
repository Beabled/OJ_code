#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    char op;
    bool flag;
};
string str;
map<char, int> op;
stack<node> s;
queue<node> q;

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    op['^'] = 3;
    getline(cin, str);
    
    for (auto it = str.end() - 1; it != str.begin(); it--)
        if (*it == ' ') str.erase(it);
    
    node temp;
    int s1 = 0;
    for (int i = 0; i < str.size();)
    {
        if (str[i] >= '0' && str[i] <= '9' )
        {
            temp.flag = true;
            temp.data = str[i++] - '0';
            while (i < str.size() && str[i] >= '0' && str[i] <= '9') temp.data = temp.data * 10 + str[i++] - '0';
            q.push(temp);
        }
        else if (i - 1 >= 0 && str[i - 1] == '(' && str[i + 1] == '(' && str[i] == '-') {
            q.push({-1, '*', true});
            while (!s.empty() && op['*'] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            s.push({1, '*', false});
            i++;
        }
        else if (!i && str[i] == '-') {
            q.push({-1, '*', true});
            while (!s.empty() && op['*'] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            s.push({1, '*', false});
            i++;
        }
        else if ((!i || str[i - 1] == '(' || (str[i - 1] > '9' && str[i - 1] < '0')) && str[i] == '-' && i + 1 < str.size() && str[i + 1] >= '0' && str[i + 1] <= '9') {
            i++;
            temp.flag = true;
            temp.data = str[i++] - '0';
            while (i < str.size() && str[i] >= '0' && str[i] <= '9') temp.data = temp.data * 10 + str[i++] - '0';
            temp.data = -temp.data;
            q.push(temp);
        }
        else 
        {
            temp.flag = false;
            if (str[i] == '(') 
            {
                temp.op = str[i++];
                s.push(temp);
                s1++;
            }
            else if (str[i] == ')')
            {
                if (s1) s1--;
                else {
                    i++;
                    continue;
                }
                while (s.top().op != '(')
                {
                    q.push(s.top());
                    s.pop();
                }
                s.pop();
                i++;
            }
            else 
            {
                while (!s.empty() && op[str[i]] <= op[s.top().op])
                {
                    q.push(s.top());
                    s.pop();
                }
                temp.op = str[i++];
                s.push(temp);
            }
        }
    }
    
    while (!s.empty() && s.top().op != '(')
    {
        q.push(s.top());
        s.pop();
    }
    
    int temp1, temp2;
    node cur, now;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.flag == true) s.push(cur);
        else 
        {
            temp2 = s.top().data;
            s.pop();
            temp1 = s.top().data;
            s.pop();
            if (cur.op == '+') now.data = temp1 + temp2;
            else if (cur.op == '-') now.data = temp1 - temp2;
            else if (cur.op == '*') now.data = temp1 * temp2;
            else if (cur.op == '/') now.data = temp1 / temp2;
            else now.data = pow(temp1, temp2);
            s.push(now);
            // cout << temp1 << " " << temp2 << "\n";
        }
    }
    
    cout << s.top().data;
    return 0;
}