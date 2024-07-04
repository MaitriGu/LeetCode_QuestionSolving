class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size && n > 0; ++i) {
            if (flowerbed[i] == 0) {
                bool left_empty = (i == 0) || (flowerbed[i - 1] == 0);
                bool right_empty = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                if (left_empty && right_empty) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        return n == 0;
    }
};
