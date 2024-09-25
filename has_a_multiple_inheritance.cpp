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
class Printer : public Device
{
    public:
    Printer(string assetIDArg, string modelArg) : Device(assetIDArg, modelArg)
    {
        cout << "Printer Instantiated "<<endl;   
    }
    void print(string content){ cout << "Printer printed. "<<content<<endl;}
    ~Printer(){ cout << "Printer destructor. "<<endl; }
};
class Scanner : public Device
{
    public:
    Scanner(string assetIDArg, string modelArg) : Device(assetIDArg, modelArg)
    {
        cout << "Scanner Instantiated "<<endl;   
    }
    void scan(string content){ cout << "Scanner reads. "<<content<<endl;}
    ~Scanner(){ 
        cout<<"-----------------------------"<<endl;
        cout << "Scanner destructor. "<<endl; }
};
class PrintScanner
{
    private:
    Printer* printerObj;
    Scanner* scannerObj;
    public:
    PrintScanner(string assetIDArg, string modelArg)
    {
        cout << "PrintScanner Instantiated" << endl;
    }
    PrintScanner(Printer* printerAddress, Scanner* scannerAddress)
    {
        cout << "PrintScanner Instantiated by constructor injection" << endl;
        this->printerObj=printerAddress;
        this->scannerObj=scannerAddress;
    }
    void setPrinter(Printer* printerAddress)
    {
        cout<<"Setting Printer"<<endl;
        this->printerObj=printerAddress;
    }
    void setScanner(Scanner* scannerAddress)
    {
        cout<<"Setting Scanner"<<endl;
        this->scannerObj=scannerAddress;
    }
    ~PrintScanner(){ cout<<" PrintScanner Destructor. "<<endl; }
};
int main()
{
    cout<<"---------------------------------"<<endl;
    Printer printerObj("Ajay","MAC");
    printerObj.print("FROM PRINTER");
    cout<<"---------------------------------"<<endl;

    Scanner scannerObj("Ajay","MAC");
    scannerObj.scan("FROM SCANNER");
    cout<<"---------------------------------"<<endl;

    PrintScanner printScannerObj("Ajay","MAC");
    printScannerObj.setPrinter(&printerObj);
    printScannerObj.setScanner(&scannerObj);
    cout<<"---------------------------------"<<endl;
    PrintScanner printScannerObjFromConstructorInjection(&printerObj, &scannerObj);
    cout<<"---------------------------------"<<endl;
    return 0;
}