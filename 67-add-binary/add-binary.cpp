class Solution {
public:
    
    string addBinary(string a, string b) {
        int n = a.size() - 1, m = b.size() - 1;
        string s = "";
        
        int carry = 0;

        while(n >= 0 || m >= 0 || carry) {
            int sum = carry;
            if(n >= 0) sum += a[n--] - '0';
            if(m >= 0) sum += b[m--] - '0';

            s += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};