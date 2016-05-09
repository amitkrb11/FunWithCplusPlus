#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main(){
	string str;
	stack<char> st;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++){
		st.push(str[i]);
	}
	for (int i = 0; i < str.length(); i++){
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}