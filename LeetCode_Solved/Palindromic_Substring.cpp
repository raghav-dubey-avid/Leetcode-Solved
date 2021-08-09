//Eg: s = "aaa"
//Output : "a", "a", "a", "aa", "aa", "aaa" : 6


class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            result += findP(s, i, i, n);
            result += findP(s, i, i+1, n);
        }
        
        return result;
    }
    
    int findP(string s, int l, int r, int n){
        
        int temp = 0;
        
        while(l >= 0 && r < n){
            
            if(s.at(l) == s.at(r)){
                l--;
                r++;
                temp++;
            }
            else{
                break;
            }
        }
        return temp;
    }
};