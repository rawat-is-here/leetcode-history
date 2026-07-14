class Solution {
public:
    vector<char> to_binary(long long n) {
        vector<char> bin;
        long long r;
        if(n==0)
        return {0};
        for (int i = 0; i < 32; i++) {
            bin.insert(bin.begin(),(char)(n % 2));
            n = n / 2;
        }
        
        return bin;
    }
    long long to_number(vector<char> bits) {
        long long n = 0;
        for (size_t i = 0; i < bits.size(); i++) {
            n = (n * 2) + bits[i];
        }
        return n;
    }
    long long reverseBits(long long n) {
        vector<char> bits;
        bits = to_binary(n);
        reverse(bits.begin(), bits.end());
        long long output = to_number(bits);
        return output;
    }
};