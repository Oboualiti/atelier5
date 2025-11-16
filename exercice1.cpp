#include<iostream>
#include<cmath>
#include<set>
using namespace std ;


bool findInSet(const set<int>& s, int value) {
    return s.find(value) != s.end();
}
bool findInIteratorRange(std::set<int>::const_iterator begin,
                         std::set<int>::const_iterator end,
                         int value)
{
    for (auto it = begin; it != end; ++it) {
        if (*it == value) return true;
    }
    return false;
}
template <typename Iterator, typename T>
bool findGeneric(Iterator begin, Iterator end, const T& value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) return true;
    }
    return false;
}

int main(){
	 
	 set<int> s ;
	 for (int i =1 ; i <101 ; i++){
	 
      s.insert(i);

	 }
	 



}



 
