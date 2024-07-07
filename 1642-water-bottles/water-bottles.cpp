class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    int sub =-1;
    int result=0;
    if(numBottles<numExchange) return numBottles;
    while(numBottles>= numExchange){
        numBottles-=numExchange;
        result+=numExchange;
        numBottles++;
    }  
    return result+numBottles;  
    }
};