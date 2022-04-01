#include <iostream>

using namespace std;

int Calculator(int no1, char op ,int no2);

int main() {

    int number1;
    char operator1;
    int number2;

    cout <<"Console Calculator Application\n";
    cout <<"Enter your operation of choice. (Format: a+b | a-b | a*b | a/b\n";
    cin >> number1 >> operator1 >> number2;
    cout << "Your answer is: " << Calculator(number1, operator1, number2) << "\n";
    cin.get();
    return 0;
}

int Calculator(int no1, char op ,int no2) {

    switch (op)
    {
    case '+':
        return no1 + no2;
        
    
    case '-':
        /* code */
        return no1 - no2;
    
    case '*':
        /* code */
        return no1 * no2;
    
    case '/':
        /* code */
        return no1 / no2;
    
    default:
        return 0;

    }

}