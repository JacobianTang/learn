#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad{
	private:
		char* str;
		int len;
		static int num_strings;
	public:
		static const int CINLIM = 80;
		StringBad(const char* s);
		StringBad();
		StringBad(const StringBad &st);
		~StringBad();
		int length() const{
			//HowMany();
			return len;
		};
		void printHello(){
			std::cout<<"hello\n";
		}
		///////overload operator methods
		StringBad& operator=(const char *);
		StringBad& operator=(const StringBad& st);
		
		char& operator[](int i);
		const char& operator[](int i) const;


		////overload operator fiends
		friend bool operator <(const StringBad &st,const StringBad& st2);
		friend bool operator>(const StringBad& st1,const StringBad& st2);
		friend bool operator==(const StringBad& st,const StringBad& st2);

	
		friend std::istream& operator>>(std::istream& is,StringBad& st);
		friend std::ostream& operator<<(std::ostream& os,const StringBad & st);
		
		///static function
		static int HowMany();
};

#endif
