#include<iostream>
#include<string>
using namespace std;

class Device
{
    protected:
    string assetID;
    string model;

    public:
    Device(string assetIDArg,string modelArg):assetID{assetIDArg},model{modelArg}
    {
        cout << "Device Instantiated "<<endl;   
    }
    ~Device(){ cout << "Device destructor. "<<endl; }
};
class Printer : virtual public Device
{
    public:
    Printer(string assetIDArg, string modelArg) : Device(assetIDArg, modelArg)
    {
        cout << "Printer Instantiated "<<endl;   
    }
    void print(string content){ cout << "Printer printed. "<<content<<endl;}
    ~Printer(){ cout << "Printer destructor. "<<endl; }
};
class Scanner : virtual public Device
{
    public:
    Scanner(string assetIDArg, string modelArg) : Device(assetIDArg, modelArg)
    {
        cout << "Scanner Instantiated "<<endl;   
    }
    void scan(string content){ cout << "Scanner reads. "<<content<<endl;}
    ~Scanner(){ cout << "Scanner destructor. "<<endl; }
};
class PrintScanner : public Printer, public Scanner // DON'T USE MULTIPLE INHERITANCE. IF NOT, YOU ARE GETTING INTO TRAP.
{
    public:
    PrintScanner(string assetIDArg, string modelArg):Device(assetIDArg, modelArg), Printer(assetIDArg, modelArg), Scanner(assetIDArg, modelArg)
    {
        cout << "PrintScanner Instantiated" << endl;
    }
    ~PrintScanner(){ cout<<" PrintScanner Destructor. "<<endl; }
};
int main()
{
    // Printer printerObj("Ajay","APPLE");
    // printerObj.print("FROM PRINTER");

    // Scanner scannerObj("Ajay","APPLE");
    // scannerObj.scan("FROM SCANNER");

    PrintScanner printScannerObj("Ajay","APPLE");
    //printScannerObj.print("From printScannerObj : Print");
    //printScannerObj.scan("From printScannerObj : scan");


    return 0;
}