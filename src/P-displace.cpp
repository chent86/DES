#include "P-displace.hpp"

int P_table[32] = {
    16, 7, 20, 21, 
    29, 12, 28, 17, 
    1, 15, 23, 26, 
    5, 18, 31, 10, 
    2, 8, 24, 14, 
    32, 27, 3, 9, 
    19, 13, 30, 6, 
    22, 11, 4, 25
};

string P_displace(string text) {
    string result(32, ' ');
    for(int i = 0; i < 32; i++)
        result[i] = text[P_table[i]-1];
    return result;
}