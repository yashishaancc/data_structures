#include<iostream>
#include<string>
using namespace std;
class Car{
public:
	string brandName;
	int mileage;
	int price;
	void printBrandName(){
		cout << "Car's brand is: " << brandName << endl;
	}
	void printMileage(){
		cout << "Car's mileage is: " << mileage << endl;
	}
};
int main(){
	Car car1;
	car1.brandName = "Alto";
	car1.mileage = 100;
	car1.price = 100000;
	car1.printBrandName();
	car1.printMileage();
	return 0;
}