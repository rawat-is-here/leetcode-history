class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Loop from right to left until both strings and the carry are exhausted
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            
            // Extract the digit using your exact logic: (char - '0')
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            // Your exact binary logic: remainder becomes the digit, quotient becomes the carry
            int r = sum % 2;
            carry = sum / 2;
            
            // Append the character to our result string
            str.push_back('0' + r);
        }
        
        // Since we added from right to left, the string is backwards. 
        // We just reverse it once at the end.
        reverse(str.begin(), str.end());
        
        return str;
    }
};