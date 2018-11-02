#include "Feistel.hpp"

string Feistel(string R, int key_id) {
    string E = E_expand(R);
    key sub_key;
    bitset<48> x(E);
    bitset<48> y(sub_key.get_subkey(key_id));
    string XOR = (x^y).to_string();
    string result;
    for(int i = 0; i < 8; i++) {
        result += S_box(XOR.substr(i*6,6), i);
    }
    return P_displace(result);
}