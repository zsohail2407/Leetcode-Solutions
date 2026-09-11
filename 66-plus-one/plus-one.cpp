class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {

            digits[i]=digits[i]+1;
            if(digits[i]==10)
            {            
                digits[i]=0;    
                if(i==0)
                {
                  digits.push_back(1);
                  shift_right(digits.begin(),digits.end(), 1);
                  i++;
                }
                
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};