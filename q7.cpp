#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

class Bank{
    private:
        string depName;
        string type;
        float balance;
        string accName;
    public:
        Bank(string name, string t,float b){
            type = t;
            accName = name;
            balance = b;
        }

        void deposit(){
            float amount;
            cout << "Enter the name of the Depositor:" << endl;
            cin >> depName;
            cout << "Enter the amount to deposit:" << endl;
            cin >> amount;
            if(amount>0)
                balance+=amount;
        }

        void withdraw(){
            float amount;
            cout << "Enter the amount to withdraw:" << endl;
            cin >> amount;
            if(amount <= balance)
                balance-=amount;
            else
                cout << "Invalid Amount!" << endl;
        }
        void display(){
            cout << "Account Holder Name: " << accName << endl;
            cout << "Type of Account:     " << type << endl;
            cout << "Remaining Balance:   " << balance << endl;
        } 
};
int main(){
    cout << "Enter the name of the account holder, account type and balance: " << endl;
    string t,n;
    float b;
    cin >> n >> t >> b;
    Bank ba(n,t,b);
    
    ba.withdraw();
    ba.deposit();
    ba.display();
    return 0;
}
