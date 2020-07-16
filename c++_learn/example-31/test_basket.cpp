#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>
using namespace std;

class Quote{
public:
    Quote()=default;
    Quote(const std::string& book,double sales_price):
         bookNo(book),price(sales_price){
        
    }
    
	virtual Quote* clone() const & {
		return new Quote(*this);
	}
    virtual Quote* clone() && {
		return new Quote(std::move(*this));
	}
	
	std::string isbn()const { return bookNo;}
    //返回给定数量的书籍的销售总额
    //派生类负责改写并使用不同的折扣计算方法
    virtual double net_price(std::size_t n) const {
        return n*price;
	}
	virtual ~Quote()=default;
private:
    std::string bookNo;
protected:
    //因为派生类需要自定义其net_price,故需要将price定义为protected，允许派生类直接访问
    double price = 0.0;
};


class Bulk_quote:public Quote{
public:
    Bulk_quote() =default;
    Bulk_quote(const std::string& book,double p ,
			std::size_t qty ,double disc):
		Quote(book,p),min_qty(qty),discount(disc){
	}
	
	virtual	Bulk_quote* clone() const & override{
		return new Bulk_quote(*this);
	}
	
	virtual Bulk_quote* clone() && override{
		return new Bulk_quote(std::move(*this));
	}

//	virtual	Bulk_quote* clone() const & {
//		return new Bulk_quote(*this);
//	}
//	
//	virtual Bulk_quote* clone() &&{
//		return new Bulk_quote(std::move(*this));
//	}
//
	//覆盖基类的版本
    double net_price(std::size_t n) const override;
private:
    std::size_t min_qty=0; //适用折扣价的最低购买量
    double discount = 0.0;  //折扣
};



double Bulk_quote::net_price(size_t cnt) const{
    if(cnt >= min_qty){
        return cnt*(1-discount)*price;
    }else{
        return cnt*price;
    }
}


double print_total(ostream& os,const Quote& item,size_t n){
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()
	  <<" # sold: "<<n<<" total due:"<<ret<<endl;
	return ret;
}

class Basket{
public:
	void add_item(const std::shared_ptr<Quote>& sale){
		items.insert(sale);

	}
	
	void add_item(const Quote& sale){
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	
	void add_item(Quote&& sale){
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}

	double total_receipt(std::ostream& )const;
private:
	static bool compare(const std::shared_ptr<Quote>& lhs,
						const std::shared_ptr<Quote>& rhs){
		return lhs->isbn()< rhs->isbn();
	}
	//建立一个利用isbn进行排序的mutliset
	//decltype(compare)*> 函数指针
	std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};

};

double Basket::total_receipt(std::ostream& os) const{
	double sum = 0.0;
	for(auto iter = items.cbegin();
			iter != items.cend();
			iter = items.upper_bound(*iter)){
		sum += print_total(os,**iter,items.count(*iter));
	}
	os<<" Total Sale: "<<sum <<endl;
	return sum;
}


int main(){
	Basket basket;
	basket.add_item(make_shared<Quote>("0-201-82470-1",50));
	basket.add_item(make_shared<Bulk_quote>("0-201-54848-8",50,10,0.25));
	
	basket.add_item(Quote("0-201-82470-1",50));
	basket.add_item(Bulk_quote("0-201-54848-8",50,10,0.25));
	basket.total_receipt(std::cout);
}
