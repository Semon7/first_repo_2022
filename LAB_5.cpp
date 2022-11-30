#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
private:

    
    string Owner_name;
    string Replenish_balance;
    string Withdraw_cash;

public:

    int Balance;
    int ID;
    double amoumt;
    int amount;
    int Getid()
    {
        return ID;
    }

    string Getowner_name()
    {
        return Owner_name;
    }

    int Getbalance()
    {
        return Balance;
    }

    string GetReplenish_balance()
    {
        return Replenish_balance;
    }

    string GetWithdraw_cash()
    {
        return Withdraw_cash;
    }
   

    BankAccount() 
    {
    }

    BankAccount(int id, string ownername, int balance,  string  withdraw_cash)
    {
        ID = id;
        Owner_name = ownername;
        Balance = balance;
        Withdraw_cash = withdraw_cash;
    }
    
   

     void addbalance(int amount) 
    {
        Balance += amount;
    }

     void showAccount() 
    {
        cout << "_________Your Bank Account_________" << "\n\n    ID: " << ID << "\n    Owner Name: " << Owner_name << "\n    Balance: " << Balance << "\n    Withdraw cash " << endl << endl;

    }
};

class Bank
{
public:
    int number = 0;
    BankAccount ArrayBankAccount[99];
    BankAccount SortArray[1];

    void BankAccountAdd(BankAccount BankAccount_) 
    {
        ArrayBankAccount[number] = BankAccount_;
        number++;
    }

    void showallAccounts() 
    {
        for (int i = 0; i < number; i++)
        {
            ArrayBankAccount[i].showAccount();
        }

    }

    void AccountDel(int AccountID) 
    {
        for  (int t = 0; t < number; t++)
        {
            if (ArrayBankAccount[t].ID == AccountID) 
            {
                for (int  p = 0; p < number; p++)
                {
                    ArrayBankAccount[t] = ArrayBankAccount[t + 1];
                    t++;
                }
                number--;
                break;
            }
        }
    }

    void AddArray(BankAccount nombre) 
    {
        ArrayBankAccount[number] = nombre;
        number++;
    }
   
    void SortByBalance()
    {
        for (int i = 1; i < number; i++)
        {
            for (int j = 1; j < number; j++)
            {
                if (ArrayBankAccount[j].Balance > ArrayBankAccount[j - 1].Balance)
                {
                    SortArray[0] = ArrayBankAccount[j];
                    ArrayBankAccount[j] = ArrayBankAccount[j - 1];
                    ArrayBankAccount[j - 1] = SortArray[0];
                }
            }


        }

        for (int i = 0; i < number; i++) 
        {
            ArrayBankAccount[i].showAccount();
        }
    }

};

int main()
{
    BankAccount a(1598, "Semen", 1000, "Withdraw cash");
    BankAccount c(1527, "Oleh", 5300, "Withdraw cash");
    BankAccount d(1564, "Andrii", 4100, "Withdraw cash");
    BankAccount f(1530, "Max", 7500, "Withdraw cash");

    //a.showAccount();
    a.addbalance(10000);
    //a.showAccount();
    
    Bank b;
    b.BankAccountAdd(a);
    b.BankAccountAdd(c);
    b.BankAccountAdd(d);
    b.BankAccountAdd(f);
    //b.BankAccountAdd(a);
   
    //b.AccountDel(1598);
    //b.AccountDel(1564);
    b.SortByBalance();
    //b.showallAccounts();
   
   
}

