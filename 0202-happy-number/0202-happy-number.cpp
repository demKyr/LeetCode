class Solution {
public:
    int happify(int n){
        cout<<n;
        int ans = (n % 10) * (n % 10);
        n /= 10;
        while(n>=1){
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        cout<<"->"<<ans<<endl;
        return ans;
    }

    bool isHappy(int n) {
        int maxLoops = 10;
        while(maxLoops > 0){
            n = happify(n);
            if (n==1)
                return true;
            maxLoops-- ;
        }
        return false;
    }
};