#include <iostream>
#include "fill.hpp"
#include "IP.hpp"
#include "Feistel.hpp"
using namespace std;

string Encryption(string PlainText) {
    int num = PlainText.length()/8;
    string L, R, next_L, next_R, result;
    for(int i = 0; i < num; i++) {
        string seg = PlainText.substr(i*8, 8);  //　当前要加密的段,长度为８个字节
        string L0R0 = IP(seg);
        L = L0R0.substr(0,32);
        R = L0R0.substr(32);
        for(int i = 0; i < 16; i++) {
            bitset<32> x(L);
            string tmp = Feistel(R, i);
            bitset<32> y(tmp);
            next_L = R;
            next_R = (x^y).to_string();
            L = next_L;
            R = next_R;
        }
        result += R+L;
    }
    string EncryptedText = "";
    for(int i = 0; i < num*8; i++) {
        bitset<8> t(result.substr(i*8,8));  // 将二进制字符串恢复为实际字符串
        EncryptedText += t.to_ulong();
    }
    return EncryptedText;
}


int main() {
    string PlainText;
    cin >> PlainText;
    fill(PlainText);
    cout << Encryption(PlainText) << endl;
}