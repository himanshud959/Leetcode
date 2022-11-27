class Solution {
public:
    int appendCharacters(string s, string t) {
        long long t1=0,t2=0;
        long long n1=size(s),n2=size(t);
        while(t1<n1)
        {
            if(s[t1]==t[t2])
            {
                t1++,t2++;
            }
            else if(s[t1]!=t[t2])
            {
                t1++;
            }
        }
        return (n2-t2);
    }
};