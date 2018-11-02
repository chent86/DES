#ifndef KEY_HPP
#define KEY_HPP

#include <string>
using namespace std;

class key {
private:
    string sub_key[16];  // 16个48位的子密钥 K1 -K16
public:
    key();
    void set_all_key();  // 计算所有的子秘钥
    string get_subkey(int i);  //　返回指定子秘钥
};

#endif