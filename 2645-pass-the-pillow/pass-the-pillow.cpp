class Solution {
public:
    int passThePillow(int n, int time) {
    int currPillowPos=1;
    int currTime=0;
    int dirn=1;
    while(currTime < time){
        if(0<currPillowPos+dirn && currPillowPos+dirn <=n){
            currPillowPos+=dirn;
            currTime++;
        }
        else{
            dirn*=-1;
        }
    }
    return currPillowPos;
    }   
};