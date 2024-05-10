class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> order;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x = arr[i]/(arr[j]*1.0);
                if(order.size() == k){
                    if(x < order.top().first){
                        order.pop();
                        order.push({x,{arr[i],arr[j]}});
                    }
                }
                else{
                    order.push({x,{arr[i],arr[j]}});
                }
            }
        }

        return {order.top().second.first,order.top().second.second};
    }
};