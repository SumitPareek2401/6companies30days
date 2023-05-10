class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int indx_a = -1, indx_b = -1, indx_c = -1;
        int temp = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') indx_a = i;

            else if(s[i] == 'b') indx_b = i;

            else if(s[i] == 'c') indx_c = i;

            if(i > 1){
                temp = min(indx_a, indx_b) ;
                count += min(indx_c, temp) + 1;
            }
        }
        return count;
    }
};
