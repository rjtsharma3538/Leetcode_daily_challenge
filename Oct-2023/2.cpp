// this is leetcode daily challenge of 2 Oct 2023
// problem link : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/?envType=daily-question&envId=2023-10-02

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0,cnt=1;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
                cnt++;
            else 
            {
                if(colors[i]=='B')
                {
                    if(cnt>2)
                        alice+=(cnt-2);
                }
                else 
                {
                    if(cnt>2)
                        bob+=(cnt-2);
                }
                cnt=1;
            }
        }


        if(colors[colors.size()-1]=='A')
        {
            if(cnt>2)
                alice+=(cnt-2);
        }
        else 
        {
            if(cnt>2)
                bob+=(cnt-2);
        }

        if(alice>bob)
            return true;
            
        return false;
    }
};
