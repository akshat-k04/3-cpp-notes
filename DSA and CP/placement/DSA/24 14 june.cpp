// https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150
// best = my  = linea linear

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> ans ;
        vector<string> temper ;
        for(int e=0 ;e<words.size() ;){
            int width =0 ;
            ans.push_back(temper) ;
            while(e<words.size()  && width+words[e].size()<=maxWidth){
                ans[ans.size()-1].push_back(words[e]) ;
                width+= words[e].size() ;
                if(width<maxWidth)width++ ;
                e++ ;
            }
        }

        vector<string> real_ans ;
        string temp="" ;
        for(auto &v: ans){
            if(v.size()==1){
                real_ans.push_back(temp) ;
                real_ans[real_ans.size()-1] = v[0] ;
                int space = maxWidth - v[0].size() ;
                while(space)real_ans[real_ans.size()-1]+=" " , space-- ;
            }
            else {   
                int count =0 ;
                for(auto &p: v)count+= p.size() ;
                int space = maxWidth- count ;
                int space_per = space /(v.size()-1) ;
                int extra_space = space%(v.size()-1) ;

                real_ans.push_back(temp) ;

                for(auto &p:v){
                    real_ans[real_ans.size()-1]+=p ;
                    for(int e=0 ;e<space_per;e++)real_ans[real_ans.size()-1]+=" ";
                    if(extra_space)real_ans[real_ans.size()-1]+=" " ,extra_space-- ;
                }
                while(real_ans[real_ans.size()-1].size()>maxWidth)real_ans[real_ans.size()-1].pop_back() ;
            }
        }
        vector<string> last = ans[ans.size()-1] ;
        real_ans.pop_back() ;

        string tmep ="" ;
        for(auto & v:last){tmep+=v ; tmep+=" ";};
        if(tmep.size()>maxWidth)tmep.pop_back() ;
        else if(tmep.size()<maxWidth){
            while(tmep.size()<maxWidth)tmep+=" ";
        }
        real_ans.push_back(tmep) ;
        return real_ans ;
    }
};