#include <bits/stdc++.h>
using namespace std;
bool balancedBracket(string &s)
{
   stack<int> st;
   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
      {
         st.push(s[i]);
      }
      else
      {
         // it means check if after inserting string got over and stack is empty that means no value got inserted
         if (st.empty())
            return false;
         auto topChar = st.top();
         st.pop();
         if ((s[i] == ')' && topChar == '(') || (s[i] == '}' && topChar == '{') || (s[i] == ']' && topChar == '['))
            continue;
         else
            return false;
      }
   }
   // if stack is empty at the end it means it has balanced parenthesis and if it is not empty() that means it is not balanced
   return st.empty();
}
int main()
{
   // code here
   int n;
   cin >> n;
   while (n--)
   {
      string s;
      cin >> s;
      bool isTrue = balancedBracket(s);
      if (isTrue)
         cout << "Yes" << endl;
      else
         cout << "No" << endl;
   }

   return 0;
}