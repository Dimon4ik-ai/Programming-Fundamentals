#include <iostream> // Для роботи з введенням/виведенням
#include <stack>    // Для використання стандартного стека
#include <string>   // Для роботи з рядками
#include <cctype>   // Для функції isdigit(), яка перевіряє, чи є символ числом

using namespace std;

// Функція для визначення пріоритету операторів
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;//
    if (c == '*' || c == '/')
        return 2;// вищий пріоритет
    return 0;
}

// Функція для перевірки, чи є символ оператором
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Перетворення інфіксного виразу у постфіксний 
string infixToPostfix(const string& expression) {//& означає, що параметр expression передається за посиланням
    stack<char> operators; // Стек для операторів
    string postfix;        // Рядок для результату (постфіксного виразу)

    for (int i = 0; i < expression.length(); i++) {//expression – це змінна яка містить рядок з арифметичним виразом
        char current = expression[i];

        // Якщо це число, додаємо його до вихідного рядка
        if (current == ' ') {
            continue;
        }
        if (isdigit(current)) {//Якщо current є цифрою, функція isdigit() повертає true.
            postfix += current;
        }
        // Якщо це оператор
        else if (isOperator(current)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current)) {
                postfix += operators.top();//повертає цей елемент
                operators.pop();//дивиться на верхній (останній доданий) оператор у стеку, щоб порівняти його пріоритет з поточним оператором current та витягуємо цей елемент
            }
            operators.push(current);
        }
    }

    // Додаємо залишені у стеці оператори до постфіксного виразу
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Виконання операції між двома операндами
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

// Обчислення постфіксного виразу
int evaluatePostfix(const string& expression) {
    stack<int> operands;//Стек для зберігання операндів

    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        // Якщо це число
        if (isdigit(current)) {
            operands.push(current - '0');
        }
        // Якщо це оператор
        else if (isOperator(current)) {
            int operand2 = operands.top(); operands.pop();//Витягуємо останній доданий операнд зі стеку та видаляємо його зі стеку.
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
    getline(cin, infixExpression);//щоб воно зчитувало зпробілами 

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
