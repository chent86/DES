#include "fill.hpp"

void fill(string& PlainText) {
    if(PlainText.length()%8 == 0) {
        int n = 8;
        while(n--)
            PlainText += 8;
    } else {
        int n = 8 - PlainText.length()%8;
        while(n--)
            PlainText += 8;   //　只说了填入相同字节
    }
}