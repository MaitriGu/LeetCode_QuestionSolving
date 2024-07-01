class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
     int count = 0;
    
    for (int num : arr) {
        if (num % 2 != 0) {  // num is odd
            count++;
            if (count == 3) {
                return true;
            }
        } else {
            count = 0;  // reset count if num is even
        }
    }
    
    return false;
    }
};