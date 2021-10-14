#include <iostream>
#include <regex>
#include <sstream>
#include <list>
#include <array>

using namespace std;

struct IpAddress {
    std::array<int, 4> ip_value;
    friend ostream& operator<<(ostream& os, const IpAddress& ip) {
        return os << ip.ip_value[0] << "." << ip.ip_value[1] << "." 
                  << ip.ip_value[2] << "." << ip.ip_value[3];
    }
    friend bool operator<(const IpAddress& a, const IpAddress& b) {
        for (size_t i = 0; i < a.ip_value.size(); i++) {
            if (a.ip_value[i] < b.ip_value[i]) {
                return true;
            } else if (a.ip_value[i] > b.ip_value[i]) {
                return false;
            }
        }
        return false;
    } 
};

int main() {
    static const auto ip_regex = std::regex(R"((\d*)\.(\d*)\.(\d*)\.(\d*))");     
    list<IpAddress> ip_address_list;

    for(std::string line; std::getline(std::cin, line);) {
        smatch m;
        regex_search(line, m, ip_regex);
        IpAddress t;
        for (size_t i = 0; i < 4; i++) {
            istringstream(m[i + 1]) >> t.ip_value[i];
        }
        ip_address_list.emplace_back(t);
    }
    
    ip_address_list.sort([](auto a, auto b) { return b < a; } );
    for (const auto& ip : ip_address_list) {
        cout << ip << endl;
    }

    for (const auto& ip : ip_address_list) {
        if (ip.ip_value[0] == 1) {
            cout << ip << endl;
        }
    }

    for (const auto& ip : ip_address_list) {
        if (ip.ip_value[0] == 46 && ip.ip_value[1] == 70) {
            cout << ip << endl;
        }
    }

    for (const auto& ip : ip_address_list) {
        if (ip.ip_value[0] == 46 || ip.ip_value[1] == 46 || ip.ip_value[2] == 46 || ip.ip_value[3] == 46) {
            cout << ip << endl;
        }
    }
    
    return 0;
}