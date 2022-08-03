
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.size() < 1)
            return false;
        int i = 0;
        // Խ��ͷ���ո�
        while (s[i] == ' ') ++i;
        // ɨ�����֣������Ż򲻴����Ŷ���
        bool numeric = scanInteger(s, i);

        // �������'.'��������������ֵ�С������
        if (s[i] == '.') {
            ++i;
            // 1.С������û���������֣���.123
            // 2.С����������û�����֣���233.
            // 3.С����ǰ����Զ�������
            numeric = scanUnsignedInteger(s, i) || numeric;
        }

        // �������'e'����'E'��������������ֵ�ָ������
        if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            // ��&&��ԭ��
            // 1.��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣���.e1��e1;
            // 2.��e��E����û������ʱ�������ַ������ܱ�ʾ���֣���12e��12e+5.4
            numeric = numeric && scanInteger(s, i);
        }
        // ɨ��β��ո�
        while (s[i] == ' ') ++i;

        return numeric && i == s.size();
    }

private:
    bool scanUnsignedInteger(const string &s, int &i) {
        int pos = i;
        while (s[i] != s.size() && s[i] >= '0' && s[i] <= '9') ++i;
        // ��s�д�������0~9����ʱ������true
        return i > pos;
    }

    bool scanInteger(const string& s, int &i) {
        if (s[i] == '+' || s[i] == '-')
            ++i;
        return scanUnsignedInteger(s, i);
    }
};
