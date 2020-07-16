#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
	void push(const Screen& s){
		screens.push_back(s);
	}
private:
    std::vector<Screen> screens;
};


class Screen{
public:
		friend void Window_mgr::clear(ScreenIndex i);
		Screen()=default;
		Screen(int w,int h,char c):width_(w),height_(h){
			contents_ = std::string(h*w,c);
		}
		~Screen(){
		}
private:
		int width_;
		int height_;
		std::string contents_;
};




void Window_mgr::clear(ScreenIndex i){
	Screen & s = screens[i];
    s.contents_ = std::string(s.height_*s.width_,' ');
}

int main(){

	Window_mgr mgrer;
	mgrer.push(Screen(24,80,'*'));
	mgrer.clear(0);

}
