#pragma warning(disable:4996);
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getoprank(char op) {
	switch (op) {
	case '*' : case '/' :
		return 2;
	case '+' : case '-' :
		return 1;
	case '(' :
		return 0;
	}
	return -1;
}

string infix_to_postfix(string infix) {
	/* Init */
	stack<char> op;
	string postfix;

	/* Calculation */
	for (int i = 0; i < infix.size(); i++) {
		/* Alphabet */
		if ('A' <= infix[i] && infix[i] <= 'Z') {
			postfix.push_back(infix[i]);
		}
		/* Operator */
		else {
			/* '(' */
			if (infix[i] == '(') {
				op.push(infix[i]);
			}
			/* ')' */
			else if (infix[i] == ')') {
				while (op.top() != '(') {
					postfix.push_back(op.top());
					op.pop();
				}
				op.pop();
			}
			/* '*', '/', '+', '-' */
			else {
				while (!op.empty() && (getoprank(op.top()) >= getoprank(infix[i]))) {
					postfix.push_back(op.top());
					op.pop();
				}
				op.push(infix[i]);
			}
		}
	}

	while (!op.empty()) {
		postfix.push_back(op.top());
		op.pop();
	}

	/* Return */
	return postfix;
}

int main(int argc, char* argv[]) {
	/* Init */
	string str;
	double alphabet[26] = {};

	/* Input */
	double d_tmp; char c_tmp; int idx = 0;
	while ((c_tmp = getc(stdin)) != '\n') {
		/* Double */
		if ('0' <= c_tmp && c_tmp <= '9') {
			ungetc(c_tmp, stdin);
			scanf("%lf", &d_tmp);
			alphabet[idx++] = d_tmp;
			str.push_back('A' + idx - 1);
		}
		/* Operator */
		else if (c_tmp != ' ') {
			str.push_back(c_tmp);
		}
	}

	/* Debug */
	//std::cout << str << '\n';
	//for (int i = 0; i < idx; i++)
	//	std::cout << alphabet[i] << ' ';
	//std::cout << '\n';
	//std::cout << infix_to_postfix(str) << '\n';

	/* postfix to value */
	stack<double> val;
	string postfix = infix_to_postfix(str);
	
	/* Calculation */
	for (int i = 0; i < postfix.size(); i++) {
		/* Alphatbet */
		if ('A' <= postfix[i] && postfix[i] <= 'Z') {
			val.push(alphabet[postfix[i] - 'A']);
		}
		/* Operator */
		else {
			double val1 = val.top(); val.pop();
			double val2 = val.top(); val.pop();

			if (postfix[i] == '*') {
				val.push(val2 * val1);
			}
			else if (postfix[i] == '/') {
				if (val1 == 0) {
					std::cout << "Error : zero division error";
					return 0;
				}
				val.push(val2 / val1);
			}
			else if (postfix[i] == '+') {
				val.push(val2 + val1);
			}
			else if (postfix[i] == '-') {
				val.push(val2 - val1);
			}
		}
	}

	/* Output */
	std::cout << fixed; std::cout.precision(2);
	std::cout << val.top();

	/* Return */
	return 0;
}