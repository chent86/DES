#include <iostream>
#include <vector>
#include "fill.hpp"
#include "IP.hpp"
#include "T-iteration.hpp"

using namespace std;

string DES(string text, string type) {
    
    int num = text.length()/8;
    string L, R, result, outcome;

    vector<int> key_order;                       
    if(type == "Encryption") {
        for(int i = 0; i < 16; i++)
            key_order.push_back(i);             // T迭代调用key的顺序
    } else if(type == "Decryption") {
        for(int i = 15; i >= 0; i--)
            key_order.push_back(i);        
    }

    for(int i = 0; i < num; i++) {
        string seg = text.substr(i*8, 8);       //　当前要加密或解密的段,长度为８个字节
        string L0R0 = IP(seg);
        L = L0R0.substr(0,32);                  // 初始IP置换
        R = L0R0.substr(32);
        pair<string, string> LR = T_iteration(L, R, key_order);  // 16轮迭代T
        L = LR.first;
        R = LR.second;
        result += invert_IP(R+L);               // 交换置换W　和　逆置换IP-1
    }

    for(int i = 0; i < num*8; i++) {
        bitset<8> t(result.substr(i*8,8));      // 将二进制字符串恢复为实际字符串
        outcome += t.to_ulong();
    }
    return outcome;
}

int main() {
    string PlainText;
    cout << "请输入要加密的字段:" << endl;
    cin >> PlainText;
    fill(PlainText);                            // 字节填充
    string EncryptedText = DES(PlainText, "Encryption");
    cout << "密文为: " << EncryptedText << endl;
    string DecryptedText = DES(EncryptedText, "Decryption");
    cout << "解密结果为: " << DecryptedText << endl;
}