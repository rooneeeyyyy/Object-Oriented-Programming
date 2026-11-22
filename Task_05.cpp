#include<iostream>
using namespace std;

class BankAccount{
protected:
    string accountNumber,accountHolderName;
    double balance;

public:
    BankAccount(string num,string name,double b){
        accountNumber=num;
        accountHolderName=name;
        balance=b;
    }

    void displayAccountInfo(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    void deposit(double amount){
        if(amount>0){
            balance=balance+amount;
            cout<<"Deposit Successful"<<endl;
        }
        else{
            cout<<"Invalid Deposit Amount"<<endl;
        }
    }

    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance=balance-amount;
            cout<<"Withdrawal Successful"<<endl;
        }
        else{
            cout<<"Insufficient Funds or Invalid Amount"<<endl;
        }
    }
};

class SavingsAccount:public BankAccount{
    double interestRate,minimumBalance;

public:
    SavingsAccount(string num,string name,double b,double rate,double min):BankAccount(num,name,b){
        interestRate=rate;
        minimumBalance=min;
    }

    void displaySavingsInfo(){
        displayAccountInfo();
        cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
        cout<<"Minimum Balance: "<<minimumBalance<<endl;
    }

    void addInterest(){
        if(balance>=minimumBalance){
            balance=balance+(balance*interestRate/100);
            cout<<"Interest Added Successfully"<<endl;
        }
        else{
            cout<<"Minimum Balance Not Maintained"<<endl;
        }
    }
};

class CurrentAccount:public BankAccount{
    double overdraftLimit,monthlyFee;

public:
    CurrentAccount(string num,string name,double b,double limit,double fee):BankAccount(num,name,b){
        overdraftLimit=limit;
        monthlyFee=fee;
    }

    void displayCurrentInfo(){
        displayAccountInfo();
        cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
        cout<<"Monthly Fee: "<<monthlyFee<<endl;
    }

    void applyMonthlyFee(){
        if(balance>=monthlyFee){
            balance=balance-monthlyFee;
            cout<<"Monthly Fee Applied"<<endl;
        }
        else{
            cout<<"Insufficient Balance for Monthly Fee"<<endl;
        }
    }
};

class FixedDepositAccount:public BankAccount{
    int tenureMonths;
    string maturityDate;
    double interestRate;

public:
    FixedDepositAccount(string num,string name,double b,int t,string date,double rate):BankAccount(num,name,b){
        tenureMonths=t;
        maturityDate=date;
        interestRate=rate;
    }

    void displayFixedDepositInfo(){
        displayAccountInfo();
        cout<<"Tenure: "<<tenureMonths<<" Months"<<endl;
        cout<<"Maturity Date: "<<maturityDate<<endl;
        cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
    }

    double calculateMaturityAmount(){
        return balance+(balance*interestRate*tenureMonths/1200);
    }
};

int main(){

    SavingsAccount s1("SA101","Ali",50000,5,10000);
    CurrentAccount c1("CA101","Ahmed",30000,10000,500);
    FixedDepositAccount f1("FD101","Sara",100000,12,"22-11-2027",8);

    cout<<"===== SAVINGS ACCOUNT ====="<<endl;
    s1.deposit(10000);
    s1.withdraw(5000);
    s1.addInterest();
    s1.displaySavingsInfo();

    cout<<"\n===== CURRENT ACCOUNT ====="<<endl;
    c1.deposit(5000);
    c1.withdraw(8000);
    c1.applyMonthlyFee();
    c1.displayCurrentInfo();

    cout<<"\n===== FIXED DEPOSIT ACCOUNT ====="<<endl;
    f1.deposit(20000);
    f1.withdraw(10000);
    f1.displayFixedDepositInfo();
    cout<<"Maturity Amount: "<<f1.calculateMaturityAmount()<<endl;

    return 0;
}