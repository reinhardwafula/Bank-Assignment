#include <iostream>

using namespace std;

class Bank{
    static const int interestRate = 0.03;
    private:
        int accNumber;
        int accBalance;
        int compound;
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
            cout << "\n";
        }
        void computeInterest(int years){
        compound = accBalance;
           for(int i = 0; i < years; i++){
                compound = compound + compound * 0.03;
                cout << "Account Balance for Year " << i+1 << " is: " << compound << endl;
           }
           cout << "\n";
        }
        void displayAccount(){
            cout << "Account Number: " << accNumber << endl;
            cout << "Initial Account Balance: " << accBalance << endl;
            cout << "Final Account Balance: " << compound << endl;
        }
};



int main()
{
    Bank user1;
    user1.enterAccountData();
    user1.computeInterest(5);
    user1.displayAccount();
    return 0;
}
