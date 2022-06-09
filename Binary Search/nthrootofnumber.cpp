double findNthRootOfM(int n, long long m) {
// Write your code here.
    long double num = double(m);
   
    if(n==1){
        return num;
    }
    long double l = 0.0;
    long double r = sqrt(num+10.0);
   
    long double err = 0.0000001;
   
    while(abs(r-l)>=err){
        long double mid = l+((r-l)/2.0);
        bool ovr = false;
        long double val = 1.0;
        for(int i=1;i<(n+1);i++){
            val*=mid;
            if(val>=num){
                ovr = true;
                break;
            }
        }
       
        if(ovr){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}
