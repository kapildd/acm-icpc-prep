#include<iostream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

string convert(string input) {
	stack<char> stackOperator;
	queue<char> queueOutput;
	string operators = "+-*/^";
	string res;
	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i])) {
			queueOutput.push(input[i]);	
		} else if (operators.find(input[i]) != string::npos) {
			stackOperator.push(input[i]);
		} else if (input[i] == '(') {
			stackOperator.push('(');
		} else if (input[i] == ')') {
			while (!stackOperator.empty()) {
				if (stackOperator.top() == '(') {
					stackOperator.pop();
			 		break;
				}		
				queueOutput.push(stackOperator.top());
				stackOperator.pop();
			}
		}
	}

	while (!stackOperator.empty()) {
		queueOutput.push(stackOperator.top());
		stackOperator.pop();
	}

	while (!queueOutput.empty()) {
		res += queueOutput.front();
		queueOutput.pop();
	}

	return res;	
}
int main()
{
	int t;
	string c;
	cin>>t;
	while(t--)
	{
		cin>>c;
		cout<<convert(c)<<endl;
	}
}
