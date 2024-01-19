#include <iostream>
#include <string>
#include <stack>
using namespace std;

void checkmatching(string str, int line_count) {
   /* Init */
   stack<char> s;
   bool isno = false; //flag º¯¼ö
   int bracket_count = 0;

   /* Calculate */
   for (int i = 0; i < str.size(); i++) {
       if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
           s.push(str[i]);
       }
       else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
           if (s.empty() ||
               (str[i] == ')' && s.top() != '(') ||
               (str[i] == '}' && s.top() != '{') ||
               (str[i] == ']' && s.top() != '[')) {
               isno = true;
               break;
           }
           else {
               s.pop();
               bracket_count++;
           }
       }
   }

   /* Output */
   if (!s.empty() || isno == true)
       cout << "Error";
   else
       cout << "OK";

   cout << ", Line_count : " << line_count << ", bracket_count : " << bracket_count;

   /* Return */
   return;
}

int main(int argc, char* argv[]) {
   /* Faster */
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   /* Init */
   string str; int line_count = 0;
   while (true) {
       string tmp; getline(cin, tmp);
       if (tmp == "EOF") break;

       str.append(tmp);
       line_count++;

       cin.clear();
   }

   /* Output */
   checkmatching(str, line_count);

   /* End */
   return 0;
}
