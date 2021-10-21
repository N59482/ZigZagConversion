#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void show(string & s) // для вывода строки.
        {
            for (auto & i : s)
                {
                    cout<<i<<" ";
                }
                cout<<endl;
        };
    void show(vector<string> & l) // для вывода вектора строк.
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
        int it = -1;
        string res;

        if(numRows == 1) return s;
        
        numRows--;
        while(s.size())
            {
                if(up) it--;
                    else it++; 
                
                lines.at(it) += cut_front(s);
                
                if(it == numRows) up = 1;
                    else if (it == 0 && up) up = 0;
            };
        numRows++;

        cout<<"convert push \n";
        show(lines);

        for(auto & i : lines)
            {
                res += i;
            }

        cout<<"after merge\n";

        show(res);

        return " ";
    }
};

int main()
{
    Solution s;
    string teststr2 = "coldcoldcoldcold";
    string teststr3 = "atatatat";
    string teststr5 = "a";
    
    s.convert(teststr2, 3);
    s.convert(teststr3, 2);
    s.convert(teststr5, 1);
    return 0;
};