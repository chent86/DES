#include "T-iteration.hpp"

pair<string,string> T_iteration(string L, string R, vector<int>& key_order) {
    string next_L, next_R;
    for(int j = 0; j < 16; j++) {
        bitset<32> x(L);
        string tmp = Feistel(R, key_order[j]);
        bitset<32> y(tmp);
        next_L = R;
        next_R = (x^y).to_string();
        L = next_L;
        R = next_R;
    }
    return make_pair(L, R);
}