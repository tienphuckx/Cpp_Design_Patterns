#include <iostream>
#include <csignal>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <memory>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
using namespace std;

int main() {
    /*
        Not use design pattern
    */
    string origin_s{"TieN   pHUc     kX"}; // tienphuckx
    string low_s = boost::to_lower_copy(origin_s);

    vector<string> parts;
    boost::split(parts, low_s, 
        boost::is_any_of(" "), 
        boost::token_compress_on);
    
    for(const auto &part : parts)
        cout << part << " -> " << part.length() << endl;

    return 0;
}


