#include <set>
#include <vector>
#include <iostream>
using namespace std;
class Message;

class Folder{
public:
	Folder()=default;
	
	void addMsg(Message* msg){
		messages.insert(msg);	
	}

	void remMsg(Message* msg){
		messages.erase(msg);
	}

private:
	//本目录下放的所有消息
	set<Message*> messages;

};


class Message{
	friend class Folder;
	friend void swap(Message& lhs,Message& rhs);
public:	
	explicit Message(const string & str=""):
		contents(str){
	}
	Message(const Message& m):contents(m.contents),folders(m.folders){
		add_to_folders(m);
	}

	Message& operator=(const Message& rhs){
		remove_from_folders();
		contents=rhs.contents;
		folders=rhs.folders;
		add_to_folders(rhs);
		return *this;
	}

	~Message(){
		remove_from_folders();
	}

	//从给定的Folder集合中添加和删除本Message
	void save(Folder& f){
		folders.insert(&f);
		f.addMsg(this);
	}
	
	void remove(Folder& f){
		folders.erase(&f);
		f.remMsg(this);
	}
private:
	string contents; //实际消息文本
	set<Folder*> folders ;//包含此消息的所有folder

	//当我们拷贝一个message是，得到的副本应该与原Message出现在相同的folder中。因此需要遍历右侧参数的Folder，将左侧的Message添加到右侧的Folder中
	//将本Message添加到m指向参数的folders中
	void add_to_folders(const Message& m){
		for(auto f:m.folders){
			f->addMsg(this);
		}
	}
	//从folders中的每个folder中删除本Message
	void remove_from_folders()
	{
		for(auto f:folders){
			f->remMsg(this);
		}
	}

};



void swap(Message& lhs,Message& rhs){
	using std::swap;
	for(auto f:lhs.folders){
		f->remMsg(&lhs);
	}
	for(auto f:rhs.folders){
		f->remMsg(&rhs);
	}
	swap(lhs.folders,rhs.folders);
	swap(lhs.contents,rhs.contents);

	for(auto f:lhs.folders){
		f->addMsg(&lhs);
	}
	for(auto f:rhs.folders){
		f->addMsg(&rhs);
	}
}



int main(){
	Message messager;
	Folder folder;

}
