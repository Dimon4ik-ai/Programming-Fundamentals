#include <iostream> // ��� ������ � ���������/����������
#include <stack>    // ��� ������������ ������������ �����
#include <string>   // ��� ������ � �������
#include <cctype>   // ��� ������� isdigit(), ��� ��������, �� � ������ ������

using namespace std;

// ������� ��� ���������� ��������� ���������
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;//
    if (c == '*' || c == '/')
        return 2;// ����� ��������
    return 0;
}

// ������� ��� ��������, �� � ������ ����������
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// ������������ ���������� ������ � ����������� 
string infixToPostfix(const string& expression) {//& ������, �� �������� expression ���������� �� ����������
    stack<char> operators; // ���� ��� ���������
    string postfix;        // ����� ��� ���������� (������������ ������)

    for (int i = 0; i < expression.length(); i++) {//expression � �� ����� ��� ������ ����� � ������������ �������
        char current = expression[i];

        // ���� �� �����, ������ ���� �� ��������� �����
        if (current == ' ') {
            continue;
        }
        if (isdigit(current)) {//���� current � ������, ������� isdigit() ������� true.
            postfix += current;
        }
        // ���� �� ��������
        else if (isOperator(current)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current)) {
                postfix += operators.top();//������� ��� �������
                operators.pop();//�������� �� ������� (�������� �������) �������� � �����, ��� �������� ���� �������� � �������� ���������� current �� �������� ��� �������
            }
            operators.push(current);
        }
    }

    // ������ �������� � ����� ��������� �� ������������ ������
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// ��������� �������� �� ����� ����������
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else {
            cout << "Error: Division by zero." << endl;
            exit(1);
        }
    default:
        cout << "invalid expression";
        exit(1);

    }
}

// ���������� ������������ ������
int evaluatePostfix(const string& expression) {
    stack<int> operands;//���� ��� ��������� ��������

    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        // ���� �� �����
        if (isdigit(current)) {
            operands.push(current - '0');
        }
        // ���� �� ��������
        else if (isOperator(current)) {
            int operand2 = operands.top(); operands.pop();//�������� �������� ������� ������� � ����� �� ��������� ���� � �����.
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(current, operand1, operand2);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression (without parentheses): ";
    //cin >> infixExpression;
    getline(cin, infixExpression);//��� ���� ��������� ��������� 

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
