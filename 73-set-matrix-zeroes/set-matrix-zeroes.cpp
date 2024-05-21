class Solution {
public:
    void setZero(vector<vector<int>>& m, int x, int y){
        for(int i = 0;i<m.size();i++)
            m[i][y] = 0;

        for(int j = 0;j<m[0].size();j++)
            m[x][j] = 0;
    }
    void setZeroes(vector<vector<int>>& m) {
        vector<pair<int,int>> cordi;

        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[0].size();j++)
                if(m[i][j]==0){
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    cordi.push_back(p);
                }

        for(auto i:cordi){
            setZero(m,i.first,i.second);
        }
        
    }
};