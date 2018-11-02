#ifndef FEISTEL_HPP
#define FEISTEL_HPP

#include <string>
#include <bitset>
#include "E-expand.hpp"
#include "key.hpp"
#include "S-box.hpp"
#include "P-displace.hpp"
using namespace std;

// Feistel　轮函数
string Feistel(string R, int key_id);

#endif