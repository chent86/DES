#include <string>
#include <bitset>
#include <vector>
#include "Feistel.hpp"
using namespace std;

/*
16轮迭代T
*/

pair<string,string> T_iteration(string L, string R, vector<int>& key_order);
// 输入: L 为IP置换后的L0
//      R 为IP置换后的R0
//      key_order　为T迭代调用key的顺序
// 输出: result.first 为16轮迭代T后的L
//      result.second 为16轮迭代T后的R