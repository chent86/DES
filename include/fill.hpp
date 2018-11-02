#ifndef FILL_HPP
#define FILL_HPP

#include <string>
using namespace std;

void fill(string& PlainText);
/* 
字节填充
原始明文消息最后的分组不够8个字节 (64位) 时,在末尾以
字节填满,填入的字节取值相同,都是填充的字节数目;
原始明文消息刚好分组完全时,在末尾填充8个字节 (即增
加一个完整分组),字节取值都是08。
*/

#endif