#include <vector>
#include <string>
#include <iostream>
#include "Sorts.h"

int main()
{
    std::vector<std::string> stringTest {"earthlings","greetings","leader","me","take","to","yall","your"};
    std::vector<std::string> stringTest2 {"greetings", "yall", "earthlings", "take", "me", "to", "your", "leader"};
    //std::vector<std::string> stringTest2 {"xyz", "abc", "aaa", "aa", "bbb", "efg", "zzz", "ccc", "mmm"};
    std::vector<std::string> a = quickSort(stringTest2);
    
    for (size_t i=0; i<a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}