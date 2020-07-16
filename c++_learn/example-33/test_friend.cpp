#include "test_friend.h"
using namespace std;

Sales_data& Sales_data::combine(const Sales_data& rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is,Sales_data & item){
	double price = 0;
	std::cout<<"begin"<<std::endl;
	is>>item.bookNo>>item.units_sold>>price;
	item.revenue = price*item.units_sold;
	std::cout<<"done.next..."<<std::endl;
	return is;
}

ostream& print(ostream& os,const Sales_data& item){
	os<<item.isbn()<< " "<<item.units_sold
				   <<" "<<item.revenue
				   <<" "<<item.avg_price()
				   <<std::endl;
	return os;
}

Sales_data add(const Sales_data& lhs,const Sales_data& rhs){
	Sales_data sum=lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(std::istream& is){
	read(is,*this);
}


int main(){
	Sales_data caller(std::cin);
	print(std::cout,caller);
}
