#include <iostream>
#include <string>
#include <stack>
using namespace std;

int bracket_count = 0;
int line_count = 0;

void checkmatching(string str) {
   /* Init */
   stack<char> s;

   bool error = false;     //flag 에러
   bool s_q = false;       //flag 작은따옴표
   bool b_q = false;       //flag 큰따옴표
   bool anno1 = false;     //flag 주석 //
   bool anno2 = false;     //flag 주식 /*

   /* Calculate */
   for (int i = 0; i < str.size(); i++) {
       /* 주석 진입 */
       if (str[i] == '\/' && str[i + 1] == '\/' && s_q == false && b_q == false)
           anno1 = true;
       if (str[i] == '\/' && str[i + 1] == '*')
           anno2 = true;
       /* 큰따옴표 */
       if (str[i] == '"') {
           if (b_q == false)
               b_q = true;
           else
               b_q = false;
       }
       /* 작은따옴표 */
       if (str[i] == '\'') {
           if (s_q == false)
               s_q = true;
           else
               s_q = false;
       }
       /* 괄호 */
       if (!s_q && !b_q && !anno1 && !anno2) {
           if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
               s.push(str[i]);
           }
           else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
               if (s.empty() ||
                   (str[i] == ')' && s.top() != '(') ||
                   (str[i] == '}' && s.top() != '{') ||
                   (str[i] == ']' && s.top() != '[')) {
                   error = true;
                   break;
               }
               else {
                   s.pop();
                   bracket_count++;
               }
           }
       }    
       /* 주석 해제 */
       if (str[i] == '\n')
           anno1 = false;
       if (str[i] == '*' && str[i + 1] == '\/')
           anno2 = false;
   }

   /* Output */
   if (!s.empty() || error || s_q || b_q)
       std::cout << "Error";
   else
       std::cout << "OK";

   std::cout << ", Line_count : " << line_count << ", bracket_count : " << bracket_count;

   /* Return */
   return;
}

int main(int argc, char* argv[]) {
   /* Faster */
   ios::sync_with_stdio(0);
   cin.tie(0); std::cout.tie(0);

   /* Init */
   string str;
   while (true) {
       string tmp; getline(cin, tmp);
       if (tmp == "EOF") break;

       str.append(tmp);
       str.append("\n");

       line_count++;
           
       cin.clear();
   }

   /* Output */
   checkmatching(str);

   /* End */
   return 0;
}

/*
'\'\'a'
'\'\'a
EOF

Error, Line_count : 2, quotes_count : 1
-----------------------
'\'\'a'
'\'\'a'
EOF

OK, Line_count : 2, quotes_count : 2
-----------------------
*/