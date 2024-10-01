class Solution {
public:
    int reverse(int x) {
        int new_num = 0;
        while (x != 0) {
            int r = x % 10;
            if (new_num > INT_MAX / 10 || (new_num == INT_MAX / 10 && r > 7)) {
                return 0;  
            }
            if (new_num < INT_MIN / 10 || (new_num == INT_MIN / 10 && r < -8)) {
                return 0;  
            }
            new_num = new_num * 10 + r;
            x /= 10;
        }
        return new_num;
    }
};
