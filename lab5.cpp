

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>

typedef std::unordered_multimap<int, std::string>::iterator umit;

int main()
{
    //ZADA4A 1
    std::unordered_multimap<int, std::string> umm0({ {-1, "er"}, {-2, "free"}, {5, "tractor"}, {10, "iter"}, {9, "lastring"}, {-1, "hi"} });
    
    auto printU = [](const std::pair<int, std::string> n) { 
        std::cout << "<" << n.first << ", " << n.second << ">  ";
    };

    std::for_each(umm0.cbegin(), umm0.cend(), printU);
    std::cout << std::endl;
    umm0.insert({ {4, "alpha"}, {4, "idk"}, {4, "help_me_please"} });
    std::for_each(umm0.cbegin(), umm0.cend(), printU);
    std::cout << std::endl;
    umm0.erase(-1);
    std::for_each(umm0.cbegin(), umm0.cend(), printU);
    std::cout << std::endl;
    std::map <int, std::string> m0;

    umit i = umm0.begin();
    for (; i != umm0.end(); i++) m0.insert(std::pair<int, std::string>(i->first, i->second));
    
    std::for_each(m0.cbegin(), m0.cend(), printU);
    std::cout << std::endl;

    //ZADA4A 2
    auto cnt8 = [](const std::pair<int, std::string> n) {return n.first > 8; };
    int cnt = 0;
    cnt = std::count_if(m0.cbegin(), m0.cend(), cnt8);
    std::cout << cnt << std::endl;

    std::vector<int> v0;
    auto make_vctr = [](const std::pair<int, std::string> n) {return n.first; };
    std::transform(m0.cbegin(), m0.cend(), std::back_inserter(v0), make_vctr);
    auto printV = [](int n) { std::cout << n << " "; };
    std::for_each(v0.cbegin(), v0.cend(), printV);
    std::cout << std::endl;

    //ZADA4A 3
    auto fnd4 = std::find(v0.cbegin(), v0.cend(), 4);
    if (fnd4 != v0.cend()) std::cout << "Takoy element est\' \n";
    else std::cout << "Takogo elementa net \n";
    std::replace_if(v0.begin(), v0.end(), std::bind(std::less<int>(), std::placeholders::_1, 0), 3);
    std::for_each(v0.cbegin(), v0.cend(), printV);
    std::cout << std::endl;
    
    std::sort(v0.begin(), v0.end(), [](int a, int b) {return a > b; });
    std::for_each(v0.cbegin(), v0.cend(), printV);
    std::cout << std::endl;
    //Первый способ создать set
    std::set<int, std::greater<int>> st0(v0.begin(), v0.end());

    std::for_each(st0.cbegin(), st0.cend(), printV);
    std::cout << std::endl;

    //Второй способ создать set
    std::set <int> st1;
    std::copy(v0.begin(), v0.end(), std::inserter(st1, st1.end()));
    std::for_each(st1.cbegin(), st1.cend(), printV);
    std::cout << std::endl;
    return 0;
}


