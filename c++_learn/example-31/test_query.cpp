#include<sstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class QueryResult;

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery()=default;
	TextQuery(std::ifstream& );
	QueryResult query(const std::string& )const ;

	shared_ptr< vector<string> > get_file(){
		return file;
	}
private:
	shared_ptr< vector<string> > file;
	map<string,shared_ptr< set<line_no> > > wm;
};

TextQuery::TextQuery(std::ifstream& is):
	file(new vector<string>)
{
	string text;
	while(getline(is,text)){
		//std::cout<<text<<std::endl;
		file->push_back(text);
		int n = file->size()  - 1;
		istringstream line(text);
		string word;
		while(line>>word){
			//std::cout<<word<<std::endl;	
			auto & lines = wm[word];
			if(!lines){
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

class QueryResult{
friend std::ostream& print(std::ostream& ,const QueryResult&);
public:
	using line_no = TextQuery::line_no;
	QueryResult(const string s,
			shared_ptr<set<line_no> >p,
			shared_ptr<vector<string>> f):
	sought(s),lines(p),file(f)
	{

	}
	
	shared_ptr<vector<string> > get_file()const{
		return file;
	}
	
	set<line_no>::iterator end(){
		return lines->end();
	}
	
	set<line_no>::iterator begin(){
		return lines->begin();
	}
private:
	std::string sought;//查询单词
	std::shared_ptr<set<line_no> > lines;//出现的行号
	std::shared_ptr<vector<string>> file;//输入文件
};


QueryResult TextQuery::query(const string& sought) const{
	
	static shared_ptr<set<line_no> >nodata(new set<line_no>);

	auto loc =wm.find(sought);
	
	if(loc != wm.end()){
		return QueryResult(sought,loc->second,file);
	}else{
		return QueryResult(sought,nodata,file);
	}
}

string make_plural(size_t ctr,const string& word,const string& ending){
	return (ctr>1)?word+ending:word;
}

ostream& print(ostream& os,const QueryResult& qr){
	os<<qr.sought<<" Occurs " <<qr.lines->size()<<" "
		<<make_plural(qr.lines->size(),"time","s")<<endl;
	for(auto num:*qr.lines){
		os <<"\t (line "<<num+1<<")"
			<<*(qr.file->begin() + num)<<endl;
	}
	return os;
}



class Query_base{
public:
	Query_base()=default;
protected:
	using line_no = TextQuery::line_no;
	
	virtual ~Query_base()=default;
public:
	virtual QueryResult eval(const TextQuery& ) const=0;
	virtual std::string rep() const =0;
};


class Query{

public:
	Query()=default;

	Query(const std::string& s);

	Query(std::shared_ptr<Query_base> query):q(query){
	
	}	
	
	QueryResult eval(const TextQuery& t)const{
		return q->eval(t);
	}
	
	string rep()const{
		return q->rep();
	}
private:

	std::shared_ptr<Query_base> q;

};




class WordQuery: public Query_base{
public:
	WordQuery(const string& s):query_word(s){
	
	}
	
	QueryResult eval(const TextQuery & t) const{
		std::cout <<"Executing WordQuery eval()  "<<query_word <<std::endl;
		QueryResult rt = t.query(query_word);
		print(std::cout,rt);
		return  rt;		//return QueryResult(" ",nodata,nofile);
	}

	std::string rep()const{
		return query_word;
	}

private:
	std::string query_word;
};

Query::Query(const std::string& s):q(new WordQuery(s)){

}


class NotQuery:public Query_base{
	friend Query operator~(const Query&);	
public:
	NotQuery(const Query& q):query(q){
	
	}
	
	QueryResult eval(const TextQuery& )const;

	std::string rep() const {
		return "~(" + query.rep() + ")";
	}
private:
	Query query;
};

inline Query operator~(const Query& operand){
	std::cout <<"Executing ~"<<std::endl;
	return Query(std::shared_ptr<Query_base>(new NotQuery(operand)));

}

QueryResult NotQuery::eval(const TextQuery& t)const{
	std::cout <<"Executing NotQuery eval()"<<std::endl;
	auto result = query.eval(t);
	auto ret_lines=make_shared<set<line_no>>();
	auto beg = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size();
	for(size_t n = 0;n != sz;++n){
		if(beg ==end || *beg !=n){
			ret_lines->insert(n);
		}else if(beg != end){
			++beg;	
		}
	}
	std::cout <<"Executing ending NotQuery eval()"<<std::endl;
	return QueryResult(rep(),ret_lines,result.get_file());
}

class BinayQuery:public Query_base{
public:
	BinayQuery(const Query& l,const Query& r,std::string s):
	lhs(l),rhs(r),opSym(s){
	
	}
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + rhs.rep() +  " )";
	}
protected:
	Query lhs,rhs;
	std::string opSym;
};

class AndQuery:public BinayQuery{
friend Query operator&(const Query& l,const Query& r);
public:
	AndQuery(const Query& l,const Query& r):
		BinayQuery(l,r,"&"){
	}
	
	QueryResult eval(const TextQuery& )const;
};

Query operator&(const Query& l,const Query& r){
	std::cout <<"Executing l&r"<<std::endl;
	return Query(std::shared_ptr<Query_base>(new AndQuery(l,r)));
}

QueryResult AndQuery::eval(const TextQuery& t)const{
	std::cout <<"Executing AddQuery eval()"<<std::endl;

	auto left = lhs.eval(t);
	auto right = rhs.eval(t);
	auto ret_lines = make_shared<set<line_no>>();

	set_intersection(left.begin(),left.end(),
					right.begin(),right.end(),
					inserter(*ret_lines,ret_lines->begin()));

	std::cout <<"Executing ending AddQuery eval()"<<std::endl;	
	return QueryResult(rep(),ret_lines,left.get_file());

}

class OrQuery:public BinayQuery{
friend Query operator|(const Query& l,const Query& r);
public:
	OrQuery(const Query& l,const Query& r):
		BinayQuery(l,r,"|"){
	}
	QueryResult eval(const TextQuery& )const;

};

QueryResult OrQuery::eval(const TextQuery& t) const{
	std::cout <<"Executing OrQuery eval()"<<std::endl;	
	auto left = lhs.eval(t);
	auto right = rhs.eval(t);
	auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
	ret_lines->insert(right.begin(),right.end());
	std::cout <<"Executing ending OrQuery eval()"<<std::endl;	
	return QueryResult(rep(),ret_lines,left.get_file());
}

Query operator|(const Query& l,const Query& r){
	std::cout <<"Executing l|r"<<std::endl;
	return Query(std::shared_ptr<Query_base>(new OrQuery(l,r)));
}


int main(int argc,char* argv[]){
	Query r = Query("Conditional") & Query("fields") | Query("as");
	string text_file = argv[1];
	std::cout<<text_file<<std::endl;
	ifstream is(text_file);
	TextQuery t(is);
	QueryResult rt = t.query("is");
	print(std::cout,rt);
	auto final_result = r.eval(t);
	print(std::cout,final_result);
}
