class Solution {
public:
    int trap(vector<int>& height) {
        int st= height[0];
        int end=height[height.size()-1];
        int m1=st;
        int m2=end;
        int ct=0;
        int z=0;
        int n=height.size()-1;
        for (int i=0;i<height.size()-1;i++)
        {
            if(st<=end)
            {
                if(m1<st)
                {
                    m1=st;
                }
               
                //m=end;
                ct+=m1-st;
                z++;
                st=height[z];
            }
            else
            {
                if(m2<end)
                {
                    m2=end;
                }
               // m=m2;
                ct+=m2-end;
                n--;
                end=height[n];
            }
        }
        return ct;
    }
};