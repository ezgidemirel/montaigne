#include <iostream>
#include <vector>
#include <algorithm>



class AddressBook{
private:
	std::vector<std::string> addressBook;

public:



	template<typename T>
	auto findMatchingAddresses(T func){
		std::vector<std::string> result;
		for(auto it=result.begin(); it != result.end(); ++it)
			if(func(*it))
				result.push_back(*it);
		return result;
	}

};


int main(){
	auto result = []{ return 4; }();

	result = [](int input){ return input * 2;}(10);

	result = [](int m, int n){return m*n;}([](int x){return x*2;}(2), [](int x){return x*3;}(4));

	std::cout << result << std::endl;
	
	std::vector<int> vec(10);
	std::generate(vec.begin(), vec.end(), [](){return rand() % 100;});
	
	auto foo = [](const std::vector<int> &vec){
		for(auto it= vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
	};
	
	foo(vec);

	sort(vec.begin(), vec.end(), [](int i, int j){return i > j;});
	
	std::cout << std::endl;
	
	foo(vec);

	return 0;
}
