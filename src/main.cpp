#include <iostream>
#include "fill.hpp"
#include "IP.hpp"
#include "Feistel.hpp"
using namespace std;

string Encryption(string PlainText) {

    int num = PlainText.length()/8;
    string L, R, next_L, next_R, result, EncryptedText;
    for(int i = 0; i < num; i++) {
        string seg = PlainText.substr(i*8, 8);  //　当前要加密的段,长度为８个字节
        string L0R0 = IP(seg);
        L = L0R0.substr(0,32);
        R = L0R0.substr(32);
        for(int j = 0; j < 16; j++) {
            bitset<32> x(L);
            string tmp = Feistel(R, j);
            bitset<32> y(tmp);
            next_L = R;
            next_R = (x^y).to_string();
            L = next_L;
            R = next_R;
        }
        result += invert_IP(R+L);
    }

    for(int i = 0; i < num*8; i++) {
        bitset<8> t(result.substr(i*8,8));  // 将二进制字符串恢复为实际字符串
        EncryptedText += t.to_ulong();
    }
    return EncryptedText;
}

string Decryption(string EncryptedText) {
    int num = EncryptedText.length()/8;
    string L, R, next_L, next_R, result, PlainText;
    for(int i = 0; i < num; i++) {
        string seg = EncryptedText.substr(i*8, 8);  //　当前要加密的段,长度为８个字节
        string L0R0 = IP(seg);
        L = L0R0.substr(0,32);
        R = L0R0.substr(32);
        for(int j = 15; j >= 0; j--) {
            bitset<32> x(L);
            string tmp = Feistel(R, j);
            bitset<32> y(tmp);
            next_L = R;
            next_R = (x^y).to_string();
            L = next_L;
            R = next_R;
        }
        result += invert_IP(R+L);
    }

    for(int i = 0; i < num*8; i++) {
        bitset<8> t(result.substr(i*8,8));  // 将二进制字符串恢复为实际字符串
        PlainText += t.to_ulong();
    }
    return PlainText;
}




int main() {
    string PlainText;
    cin >> PlainText;
    fill(PlainText);
    string EncryptedText = Encryption(PlainText);
    cout << EncryptedText << endl;
    string DecryptedText = Decryption(EncryptedText);
    cout <<  DecryptedText << endl;
}