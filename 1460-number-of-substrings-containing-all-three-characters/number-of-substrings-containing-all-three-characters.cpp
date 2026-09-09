class Solution {
public:
    int numberOfSubstrings(string s) {
        int a =0,b=0, c=0;
        int l=0, r=0, n=s.size() ;
        int ans = 0 ;
        while(r<n) {
            char ch = s[r] ;
            if(ch=='a') a++;
            else if(ch=='b') b++ ;
            else c++ ;

            while(a>=1 and b>=1 and c>=1) {
                ans += n-r ;
                char ch1 = s[l] ;
                 if(ch1=='a') a--;
                 else if(ch1=='b') b-- ;
                 else c-- ;
                l++;

            }
            r++;
        }
        return ans;
    }
};