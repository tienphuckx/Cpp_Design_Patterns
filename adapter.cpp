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

// ADAPTER DESIGN PATTERN
class String_Adapter
{
    private:
        std::string s;
    public:
        String_Adapter(const std::string &other_s): s(other_s){}
        string to_lower_copy(const std::string &s);
        string to_lower_copy() const;
        string get_val() { return s;}
        int get_len() {return s.length();}
        vector<String_Adapter> split_to_parts(const string deli);
        void print(const vector<string>& parts) const;
};

vector<String_Adapter> String_Adapter::split_to_parts(const string deli) {
    vector<string> parts;
    boost::split(parts, s, boost::is_any_of(deli), boost::token_compress_on);
    return vector<String_Adapter>(parts.begin(), parts.end());
}

void String_Adapter::print( const vector<string>& parts) const {
    for(auto& part:parts)
        std::cout << part << " -> " << part.length() << std::endl; 
}

string String_Adapter::to_lower_copy() const {
    return (boost::to_lower_copy(this->s));
}

string String_Adapter::to_lower_copy(const std::string &s) {
    return (boost::to_lower_copy(s));
}

int main(int argv, char* argc[])
{

    String_Adapter sa1("NguYen TiEN    PhuC");
    cout << sa1.to_lower_copy() << endl;

    String_Adapter sa2("NguYen TiEN    PhuC 2");
    vector<String_Adapter> sas = sa2.split_to_parts(" ");
    
    for(auto& s: sas)
        std::cout << s.get_len() << endl;

    return 0;
}