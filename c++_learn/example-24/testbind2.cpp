#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace std::placeholders;

class Person{
	private:
		string name;
	public:
		Person(const string& n):name(n){
		}
		void print()const{
			cout<<name<<endl;
		}
		void print2(const string& prefix)const{
			cout<<prefix<<" "<<name <<endl;
		}

};

int main(){
	vector<Person> coll={Person("Tick"),Person("Trick"),Person("Track")};
	for_each(coll.begin(),coll.end(),bind(&Person::print,_1));
	for_each(coll.begin(),coll.end(),bind(&Person::print2,_1,"The Person: "));
}
	
