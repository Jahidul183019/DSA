#include<iostream>
#include<stack>

using namespace std;

int precedence(char op){
    if(op=='^') return 3;
    if(op=='*' || op== '/') return 2;
    if(op=='+' || op== '-') return 1;

    return 0;
}

bool isNumber (char num){
    return (num >= '0' && num <= '9');
}

string infixToPostfix(string infix){
    stack<char>s;
    string postfix="";

    for(char c : infix) {
        if(isNumber(c)){//operand
            postfix+=c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if(c==')'){
            while(s.size()>0 && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            if(s.size()>0){
                s.pop();
            }
        }else{
            while(s.size()>0 && precedence(s.top()) >= precedence(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }   
    }
    while(s.size()>0){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
