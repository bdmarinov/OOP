#include <iostream>
#include <stack>

using namespace std;

int operation(char symbol, int & a, int & b)
{
	switch (symbol) {
	case '+': return a + b;
		break;
	case '-': return b - a;
		break;
	case '*': return a * b;
		break;
	case '/': return b / a;
		break;
	case '%': return b % a;
		break;
	}
}

int pow(int base, int exp) {
	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return base;
	}
	return base * pow(base, exp - 1);
}

int calculate(char str[101])
{
	stack<int> st;
	stack<int> helper;
	stack<char> char_helper;

	char a = '0';
	for (int i = 0; str[i] != '\0';i++) {
		if (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57)) {
			char_helper.push(str[i]);
		}

		if (str[i] >= 48 && str[i] <= 57) {
			helper.push(str[i] - a);
		}

		if (str[i] == ' ' && !helper.empty()) {
			int value = 0, j = 0;
			while (!helper.empty()) {
				value += helper.top()*pow(10, j);
				helper.pop();
				j++;
			}
			st.push(value);
		}
		if ((str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '%')||(str[i] =='-' && str[i-1]==' ' && (str[i+1] ==' '||str[i+1] == '\0'))) {
			int number1 = st.top();
			st.pop();
			if (!char_helper.empty()) {
				number1 = -number1;
				char_helper.pop();
			}
			int number2 = st.top();
			st.pop();
			if (!char_helper.empty()) {
				number2 = -number2;
			}
			st.push(operation(str[i], number1, number2));
		}
	}
	return st.top();
}

int main()
{
	cout << calculate("100 3 * 6 -5 *") << endl; //-30
	cout << calculate("100 3 * 6 -5 * - 33 /") << endl; //10
	cout << calculate("5 -10 -15 + - -10 * 2 /") << endl; //100
	cout << calculate("5 -5 +") << endl; //0
	cout << calculate("5 5 - 11 8 4 - - *") << endl; //0
	cout << calculate("5 5 - 11 8 4 - - -") << endl; //-7
	cout << calculate("5 2 3 - -") << endl; //6
	cout << calculate("5 1 2 + 4 * + 3 -") << endl; //14
	cout << calculate("5 1 2 + 4 * + 3 -") << endl; //14

	return 0;
}
