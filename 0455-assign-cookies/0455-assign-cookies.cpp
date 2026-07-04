class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int cookieptr = 0;
        int childptr = 0;
        while(cookieptr < s.size() && childptr<g.size())
        {
            if(s[cookieptr] >=  g[childptr])
            childptr++;
            

            cookieptr++;
        }
        return childptr;
    }
};