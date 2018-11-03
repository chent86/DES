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

string IP(string text);
// IP置换函数
// 输入: 原始８字节字符串
// 输出: IP置换后的０１串


string invert_IP(string text);  
// IP逆置换函数
// 输入: 0 1 串
// 输出: IP置换后的０１串

#endif