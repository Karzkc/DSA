#include <iostream>

int main()
{

    char op;
    char exit;
    double val1;
    double val2;
    double result;

    while (true)
    {   
        system("cls");
        std::cout << "\t******Simple Calculator******\n" << std::endl;

        std::cout << "Enter any One Operator (+,-,*,/):- " << std::endl;
        std::cin >> op;

        std::cout << "Enter First Value:- " << std::endl;
        std::cin >> val1;

        std::cout << "Enter Second Value:- " << std::endl;
        std::cin >> val2;

        switch (op)
        {
        case '+':
            result = val1 + val2;
            break;
        case '-':
            result = val1 - val2;
            break;
        case '*':
            result = val1 * val2;
            break;
        case '/':
            result = val1 / val2;
            break;

        default:
            std::cout << "Enter Valid Input!!" << std::endl;
            break;
        }
        std::cout << val1 << op << val2 << "=" << result << std::endl;

        std::cout << "Enter 'y' to continue or any other key to exit:- " << std::endl;
        std::cin >> exit;

        if (exit == 'y')
        {
            continue;
        }
        else
        {
            break;
        }

        std::cout << "\t*****************************\t" << std::endl;
    }

    return 0;
}