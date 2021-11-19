#include <iostream>

using namespace std;

int cnt = 0;
static const float interestRate = 0.03;
class BankAccount{
    private:
        int accNumber;
        float accBalance;
        float compound;
        float compoundDisplay;
        int inTime;
        int sizeOfObject;
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
                cout << "Enter a valid account balance(a positive a value): ";
                cin >> accBalance;
            }
            cout << "Enter a term between 1 and 40(inclusive): ";
            cin >> inTime;
            while(inTime < 0 || inTime > 40){
                cout << "Enter a valid term between 1 and 40! : ";
                cin >> inTime;
            }
            //cout << "\n";
        }
        void computeInterest(int years){
        compound = accBalance;
           for(int i = 0; i < years; i++){
                compound = compound + compound * interestRate;
           }
           cout << "\n";
        }
        void displayAccount(){
            compoundDisplay = accBalance;
            cout << "Account Number: " << accNumber << endl << "\n";
            for(int i = 0; i < inTime; i++){
                compoundDisplay = compoundDisplay + compoundDisplay * 0.03;
                cout << "Account Balance for Year " << i+1 << " is: " << compoundDisplay << endl;
                cout << "***** ***** ***** ***** ***** ******" << endl;
            }
            cout << "Initial Account Balance: " << accBalance << endl;
            cout << "Final Account Balance: " << compound << endl;
            cout << "***** ***** ***** ***** ***** ******" << endl << "\n" << "\n";
        }
        int getInTime(){
            return inTime;
        }
        void setSize(int a){
            sizeOfObject = a;
        }
};

 char response;
 void continuation(){
        cout << "Do you wish to continue(Y/N): ";
        cin >> response;
        cout << "\n";
    }
 int objectCount;
 void displayBankInfo(BankAccount customer[10]){
    cout << "No. of Bank Accounts: " << cnt << endl;
    cout << "\n";
    for(int i = 0; i < cnt; i++){
        customer[i].displayAccount();
    }
 }

int main()
{
    int i;
    BankAccount customer[10];
    continuation();
    if(response == 'Y' || response == 'y'){
        for(i = 0; i < 10; i++,cnt++){
            customer[i].enterAccountData();
            customer[i].computeInterest(customer[i].getInTime());
            //customer[i].displayAccount();
            continuation();
            if(response == 'Y' || response == 'y'){
                continue;
            } else if (response == 'N' || response == 'n'){
                i = 9;
            } else {
                while(response != 'Y' || response != 'y' || response != 'N' || response != 'n'){
                    cout << "Enter Valid Input(Y/N)!";
                }
            }
        }
    } else if (response == 'N' || response == 'n'){
            return 0;
    } else {
        cout << "Enter Valid Input(Y/N)!";
    }

    displayBankInfo(customer);
    cout << "Complete!";
}
