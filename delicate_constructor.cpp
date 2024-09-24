// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
class BankCustomer{
    private:
        string name;
        string adharNumber;
        string panNumber;
        string emailId;
        const char* phoneNumber;
    
    public:
    //Compile Time Polymorphism , constructor Overloading
    BankCustomer()
    {
        this->name="";
        this->adharNumber="";
        this->panNumber="";
        this->emailId="";
        this->phoneNumber=nullptr;
    }
    BankCustomer(string nameArg,string adharNumberArg,string panNumberArg):BankCustomer()
    {
        this->name=nameArg;
        this->adharNumber=adharNumberArg;
        this->panNumber=panNumberArg;
    }
     BankCustomer(string nameArg,string adharNumberArg,string panNumberArg,const char* phoneArg,string emailArg): BankCustomer(nameArg,adharNumberArg,panNumberArg)
     {
        this->phoneNumber=phoneArg;
        this->emailId=emailArg;
    }
    
    void printCustomerInfo()
    {
        //cout<<
        cout<<this->name<<endl;
        cout<<this->adharNumber<<endl;
        cout<<this->panNumber<<endl;
        cout<<this->emailId<<endl;
        if (phoneNumber != nullptr) 
        {
            cout << "Phone: " << phoneNumber << endl;
        }
        else
        {
            cout << "Phone: Not provided" << endl;
        }
    }
    
};

int main() {
    // Write C++ code here
    cout<<"------customerOne-----------"<<endl;
    BankCustomer customerOne("Name: Ajay","AdhaarNumber : 789456123789","PanNumber : AJY789798");
    customerOne.printCustomerInfo();
    cout<<"------customerTwo-----------"<<endl;
    BankCustomer customerTwo("Name: Ajay","AdhaarNumber : 789456123789","PanNumber : AJY789798","7897897897","Email : aja@7899.com");
    customerTwo.printCustomerInfo();

    return 0;
}
