#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

template<typename stringArgOne,typename stringArgTwo>
class Dictionary
{
    private:
    std::vector<std::pair<stringArgOne,stringArgTwo>> stringInputValue;

    public:
    void add(const stringArgOne& argumentOne,const stringArgTwo& argumentTwo)
    {
        stringInputValue.push_back(std::make_pair(argumentOne,argumentTwo));
    }

    stringArgTwo getValue(const stringArgOne& key) 
    {
        for (const auto& item : stringInputValue)
        {
            if (item.first == key) 
            {
                return item.second; // Return the associated value
            }
        }
        throw std::runtime_error("Key not found"); // Handle key not found
    }
    template<typename T1, typename T2>
    friend std::ostream& operator<<(std::ostream& os, const Dictionary<T1,T2>& dictionaryObj);

};
template<typename stringArgOne, typename stringArgTwo>
std::ostream& operator<<(std::ostream& os, const Dictionary<stringArgOne,stringArgTwo>& dictionaryObj)
{
    for (const auto& item : dictionaryObj.stringInputValue) 
    {
        os<< item.first << " => " << item.second << std::endl;
    }
    return os;
}

//Implement Dictionary

int main(){
    Dictionary<string,string> mapObj;
    mapObj.add("blr","Bangaluru");
    mapObj.add("chn","Chennai");
    mapObj.add("hyd","Hyderabad");
    cout<<mapObj.getValue("blr")<<endl;
    cout<<mapObj; 

    return 0;
}
