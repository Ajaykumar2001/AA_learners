#include<iostream>
#include<string>
using namespace std;

class Device
{
    protected:
    string assetID;
    string model;

    public:
    //Device(string assetIDArg,string modelArg):assetID{assetIDArg},model{modelArg}
    Device(string assetArg,string modelArg)
    {
        this->assetID=assetArg;
        this->model=modelArg;
        cout << "Device Instantiated "<<endl;   
    }
    ~Device(){ cout << "Device destructor. "<<endl; }
};
class Printer : public Device
{
    public:
    Printer(string assetIDArg, string modelArg) : Device::Device(assetIDArg, modelArg)
    {
        cout << "Printer Instantiated "<<endl;   
    }
    void print(){ cout << "AssetID:  "<<assetID<<endl<<"Model: "<<model<<endl;}
    ~Printer(){ cout << "Printer destructor. "<<endl; }
};
class Scanner : public Device
{
    public:
    Scanner(string assetIDArg, string modelArg) : Device::Device(assetIDArg, modelArg)
    {
        cout << "Scanner Instantiated "<<endl;   
    }
    void scan(){cout << "AssetID:  "<<assetID<<endl<<"Model: "<<model<<endl;}
    ~Scanner(){ 
        cout<<"-----------------------------"<<endl;
        cout << "Scanner destructor. "<<endl; }
};
class PrintScanner : public Device
{
    private:
    Printer printerObj;
    Scanner scannerObj;
    public:
    PrintScanner(string assetIDArg, string modelArg) : Device::Device(assetIDArg,modelArg)
    {
        cout << "PrintScanner Instantiated" << endl;
    }
    void print()
    {
        printerObj.print();
    }
    void scan()
    {
        scannerObj.scan();
    }
    ~PrintScanner(){ cout<<" PrintScanner Destructor. "<<endl; }
};
int main()
{


    PrintScanner printScannerObj("AssetNumberID","BrandingName");
    printScannerObj.print();
    printScannerObj.scan();

    return 0;
}