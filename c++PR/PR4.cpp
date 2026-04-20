#include <iostream>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully.\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful.\n";
        } else {
            cout << "Insufficient Balance.\n";
        }
    }

    double getBalance() {
        return balance;
    }
    
    int getAccountNumber()
{
    return accountNumber;
}

protected:
    void setBalance(double bal) {
        balance = bal;
    }

public:
    virtual void calculateInterest() {
        cout << "No Interest for this account.\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nHolder Name    : " << accountHolderName;
        cout << "\nBalance        : " << balance << endl;
    }
};

// Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest = " << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Type            : Savings Account\n";
        cout << "Interest Rate   : " << interestRate << "%\n";
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal Successful.\n";
        } else {
            cout << "Overdraft Limit Exceeded.\n";
        }
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Type            : Checking Account\n";
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
private:
    int term;
    double rate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double r)
        : BankAccount(accNo, name, bal) {
        term = t;
        rate = r;
    }

    void calculateInterest() override {
        double interest = getBalance() * rate * term / (100 * 12);
        cout << "Fixed Deposit Interest = " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity.\n";
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Type            : Fixed Deposit Account\n";
        cout << "Term            : " << term << " Months\n";
        cout << "Interest Rate   : " << rate << "%\n";
    }
};

// Main Function
int main() {
    BankAccount* accounts[100];
    int count = 0;
    int choice;

    while(true) {
        cout << "\n===== BANK MENU =====";
        cout << "\n1. Create Savings Account";
        cout << "\n2. Create Checking Account";
        cout << "\n3. Create Fixed Deposit Account";
        cout << "\n4. Display All Accounts";
        cout << "\n5. Deposit";
        cout << "\n6. Withdraw";
        cout << "\n7. Calculate Interest";
        cout << "\n8. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        int accNo, index, term;
        string name;
        double bal, rate, limit, amount;

        switch (choice) {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[count] = new SavingsAccount(accNo, name, bal, rate);
            count++;
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            accounts[count] = new CheckingAccount(accNo, name, bal, limit);
            count++;
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Term (Months): ";
            cin >> term;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[count] = new FixedDepositAccount(accNo, name, bal, term, rate);
            count++;
            break;

        case 4:
            for (int i = 0; i < count; i++) {
                cout << "\nIndex: " << i << endl;
                accounts[i]->displayAccountInfo();
            }
            break;

    case 5:
{
    int searchAcc;
    cout << "Enter Account Number: ";
    cin >> searchAcc;

    cout << "Enter Amount: ";
    cin >> amount;

    int i;

    for(i = 0; i < count; i++)
    {
        if(accounts[i]->getAccountNumber() == searchAcc)
        {
            accounts[i]->deposit(amount);
            break;
        }
    }

    if(i == count)
    {
        cout << "Account Not Found\n";
    }

    break;
}

     case 6:
{
    int searchAcc;
    cout << "Enter Account Number: ";
    cin >> searchAcc;

    cout << "Enter Amount: ";
    cin >> amount;

    int i;

    for(i = 0; i < count; i++)
    {
        if(accounts[i]->getAccountNumber() == searchAcc)
        {
            accounts[i]->withdraw(amount);
            break;
        }
    }

    if(i == count)
        cout << "Account Not Found\n";

    break;
}
     
    case 7:
    cout << "Enter Account Index: ";
    cin >> index;

    if(index >= 0 && index < count)
    {
        accounts[index]->calculateInterest();
    }
    else
    {
        cout << "Invalid Index\n";
    }
    break;
        case 8:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    }

    for (int i = 0; i < count; i++) {
        delete accounts[i];
    }

    return 0;
}