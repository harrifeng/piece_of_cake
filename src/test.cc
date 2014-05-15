#include <iostream>
#include <ext/hash_map>


int main(int argc, char *argv[])
{
    using namespace __gnu_cxx;
    hash_map<int, int> hs;
    hs[1] = 3;
    hs[2] = 6;

    hash_map<int, int>::iterator iter;

    for (iter = hs.begin(); iter != hs.end(); iter++) {
        std::cout << (*iter).first << std::endl;
        std::cout << (*iter).second << std::endl;
    }
    return 0;
}
