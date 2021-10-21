#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void show(string & s)
        {
            for (auto & i : s)
                {
                    cout<<i<<" ";
                }
                cout<<endl;
        };
    void show(vector<string> & l)
        {
            for (auto & i : l)
                {
                    show(i);
                }
                cout<<endl;
        };
    char cut_front(string & str)
        {
            char bit = str.at(0);
            str.erase(str.begin());
            cout<<"cut_front()\n";
            return bit;
        };

    string convert(string s, int numRows) 
    {
        cout<<"convert get ";
        show(s);
        vector<string> lines(numRows);
        bool up = 0;
        int i = -1;
        numRows--;
        while(s.size())
            {
                if(up) i--;
                    else i++; 
                
                lines.at(i) += cut_front(s);
                
                if(i == numRows) up = 1;
                    else if (i == 0 && up) up = 0;
            };
        cout<<"convert push \n";
        show(lines);
        return " ";
    }
};

int main()
{
    Solution s;
    string teststr = "hellomrsboobs";
    s.convert(teststr, 3);
    



    return 0;
};