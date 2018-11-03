#include "key.hpp"

string m_key = "0110000101100010011000110110010001100101011001100110011101101000";
// 64位的秘钥 8 16 ... 64 为奇偶校验位

int PC_1[56] = {
    57, 49, 41, 33, 25, 17, 9, 
    1, 58, 50, 42, 34, 26, 18, 
    10, 2, 59, 51, 43, 35, 27, 
    19, 11, 3, 60, 52, 44, 36, 
    63, 55, 47, 39, 31, 23, 15, 
    7, 62, 54, 46, 38, 30, 22, 
    14, 6, 61, 53, 45, 37, 29, 
    21, 13, 5, 28, 20, 12, 4
};

int PC_2[48] = {
    14, 17, 11, 24, 1, 5, 
    3, 28, 15, 6, 21, 10, 
    23, 19, 12, 4, 26, 8, 
    16, 7, 27, 20, 13, 2, 
    41, 52, 31, 37, 47, 55, 
    30, 40, 51, 45, 33, 48, 
    44, 49, 39, 56, 34, 53, 
    46, 42, 50, 36, 29, 32 
};

std::shared_ptr<key> key::m_instance = nullptr;

key::key() {
    set_all_key();
}

shared_ptr<key> key::getInstance() {
    if(m_instance == nullptr) {
        std::shared_ptr<key>  instance(new key);
        m_instance = instance;
    } 
    return m_instance;
}

void key::set_all_key() {
    string CD0(56, ' ');
    for(int i = 0; i < 56; i++)
        CD0[i] = m_key[PC_1[i]-1];            //原秘钥经过PC-1置换得到C0D0
    string C = CD0.substr(0,28);
    string D = CD0.substr(28);
    string K(48, ' ');
    for(int i = 1; i <= 16; i++) {
        if(i == 1 || i == 2 || i == 9 || i == 16) {
            C = C.substr(1)+C.substr(0,1);    // C D 循环左移一个位置
            D = D.substr(1)+D.substr(0,1);
        } else {
            C = C.substr(2)+C.substr(0,2);    // C D 循环左移两个位置
            D = D.substr(2)+D.substr(0,2);            
        }
        string tmp = C+D;
        for(int j = 0; j < 48; j++) {
            K[j] = tmp[PC_2[j]-1];            // 对CD实行PC-2压缩置换
        }
        sub_key[i-1] = K;
    }
}

string key::get_subkey(int i) {
    return sub_key[i];
}