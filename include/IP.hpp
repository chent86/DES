#ifndef IP_HPP
#define IP_HPP

#include <string>
#include <bitset>
using namespace std;

/*
初始置换

给定64位明文块 M,通过一个固定的初始置换 IP 来重排 M 中的
二进制位,得到二进制串 M 0 = IP(M) = L 0 R 0 ,这里 L 0 和 R 0 分 别是
M 0 的前32位和后32位。下表给出 IP 置换后的下标编号序列。
*/

string IP(string text);  // 返回０１串

// 逆置换
string invert_IP(string text);  // 返回０１串

string handler(string text, int* current_table); // 辅助函数，使用输入的置换表进行置换

#endif