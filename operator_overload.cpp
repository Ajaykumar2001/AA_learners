#include <iostream>
using namespace std;
class Date{
	private:
		int day,month,year;
	public:
	
		//modern c++ 11
		Date(int dayArg,int monthArg,int yearArg):day{dayArg},month{monthArg},year{yearArg} {
				
		}
		void operator++(int delta)
		{
			cout<<delta<<endl;
		}
		void operator--()
		{
			
		}
		void printDate(){
		cout<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
		}
};

int main(){
		
		Date date1{24,9,2024};
		date1++;
		date1.printDate(); // 25-9-2024
		date1--;
		date1.printDate(); // 24-9-2024
		return 0;
		
}
