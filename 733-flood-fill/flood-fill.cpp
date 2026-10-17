struct pos {
	int i;
	int j;
	pos(int idx, int jj)
	{
		i = idx;
		j = jj;
	}
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       	int rows = image.size();
	    int cols = image[0].size();
	    queue<pos> abc;
        int img=image[sr][sc];
	    abc.push(pos(sr,sc));
        image[sr][sc]=color;
        if(img==color)
        {
            return image;
        }
	    pos directions[4] = {pos(1,0),pos(0,1),pos(-1,0),pos(0,-1)};
	    while(!abc.empty())
	    {
		pos current = abc.front();
		abc.pop();
		for (int a=0;a<4;a++)
		{
			int new_i=current.i+directions[a].i;
			int new_j=current.j+directions[a].j;
			if (new_i >=0 && new_i<rows && new_j>=0)
			{
                if(new_j<cols && image[new_i][new_j]==img)
                {
				image[new_i][new_j]=color;
				abc.push(pos(new_i,new_j));
                }
			}
		}
	}
    return image;
    }
};