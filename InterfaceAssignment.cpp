#include<iostream>
using namespace std;

class IPrinter {
public:
    virtual void print(string path) = 0;  
};

class IScanner {
public:
    virtual void scan(string path) = 0;  
};

class Printer : public IPrinter{

    public:
     void print(string path) override {
        cout<<"Printing_from printer ....."<<path<<endl;;
    }
};

class Scanner : public IScanner{

    public:
     void scan(string path) override {
        cout<<"Scanning from scanner ....."<<path<<endl;;
    }
};
class PrintScanner : public IPrinter, public IScanner {
    private:
    Printer printerObj;
    Scanner scannerObj;
public:
    void print(string path)
    {
        printerObj.print(path);
    }
    void scan(string path)
    {
        scannerObj.scan(path);
    }
};
class TaskManager{
    public:
     static void execuctePrintTask(IPrinter *printer,string documentPath){
        printer->print(documentPath);
    }
     static void execucteScanTask(IScanner *scanner,string documentPath){
            scanner->scan(documentPath);
    }
};


    int main(){
        Printer printerObj;
        Scanner scannerObj;
        PrintScanner printScannerObj;

        TaskManager::execuctePrintTask(&printerObj,"Test.doc");
        TaskManager::execucteScanTask(&scannerObj,"MyImage.png");
        TaskManager::execuctePrintTask(&printScannerObj,"NewDoc.doc");
        TaskManager::execucteScanTask(&printScannerObj,"YourImage.png");
    }
