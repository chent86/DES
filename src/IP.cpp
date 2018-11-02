#include "IP.hpp"

//　从１开始计
int IP_table[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int invert_IP_table[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41,  9, 49, 17, 57, 25
};

string IP(string text) {
    return handler(text, IP_table);
}

string invert_IP(string text) {
    return handler(text, invert_IP_table);
}

string handler(string text, int* current_table) {
    string origin = "";
    string result(64, ' ');
    for(int i = 0; i < 8; i++) {
        bitset<8> byte = text[i];
        origin += byte.to_string();    //十进制转二进制字符串
    }

    for(int i = 0; i < 64; i++) {
        result[i] = origin[current_table[i]-1];  //　根据置换表置换０,1
    }

    // string tmp = "";
    // for(int i = 0; i < 8; i++) {
    //     bitset<8> t(result.substr(i*8,8));  // 将二进制字符串恢复为实际字符串
    //     tmp += t.to_ulong();
    // }
    // text = tmp;

    return result;
}