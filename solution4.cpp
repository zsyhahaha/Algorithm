
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.size() < 1)
            return false;
        int i = 0;
        // 越过头部空格
        while (s[i] == ' ') ++i;
        // 扫描数字，带符号或不带符号都行
        bool numeric = scanInteger(s, i);

        // 如果出现'.'，则接下来是数字的小数部分
        if (s[i] == '.') {
            ++i;
            // 1.小数可以没有整数部分，如.123
            // 2.小数点后面可以没有数字，如233.
            // 3.小数点前后可以都有数字
            numeric = scanUnsignedInteger(s, i) || numeric;
        }

        // 如果出现'e'或者'E'，则接下来是数字的指数部分
        if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            // 用&&的原因：
            // 1.当e或E前面没有数字时，整个字符串不能表示数字，如.e1、e1;
            // 2.当e或E后面没有整数时，整个字符串不能表示数字，如12e，12e+5.4
            numeric = numeric && scanInteger(s, i);
        }
        // 扫描尾后空格
        while (s[i] == ' ') ++i;

        return numeric && i == s.size();
    }

private:
    bool scanUnsignedInteger(const string &s, int &i) {
        int pos = i;
        while (s[i] != s.size() && s[i] >= '0' && s[i] <= '9') ++i;
        // 当s中存在若干0~9数字时，返回true
        return i > pos;
    }

    bool scanInteger(const string& s, int &i) {
        if (s[i] == '+' || s[i] == '-')
            ++i;
        return scanUnsignedInteger(s, i);
    }
};
