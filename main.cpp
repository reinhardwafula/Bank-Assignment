#include <iostream>

using namespace std;

class Bank{
    static const int interestRate = 0.03;
    private:
        int accNumber;
        int accBalance;
    public:
        void enterAccountData(){
            cout << "Enter account number: ";
            cin >> accNumber;
            while(accNumber < 1000){
                cout << "Enter a valid account number(value greater than 1000): ";
                cin >> accNumber;
            }
            cout << "Enter account balance: ";
            cin >> accBalance;
            while(accBalance < 0){
                cout << "Enter a valid account balance(a positve a value): ";
                cin >> accBalance;
            }
        }
};

int main()
{
    Bank user1;
    user1.enterAccountData();
    return 0;
}
