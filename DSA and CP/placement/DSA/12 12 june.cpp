// https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
// different type of question

class RandomizedSet {
    unordered_set<int> st ;
    unordered_set<int>::iterator it ;
public:
    RandomizedSet() {
        //  nothing to do
        it = st.begin() ;
    }
    
    bool insert(int val) {
        it = st.begin() ;
        if(st.find(val)!=st.end())return false ;
        else {
            st.insert(val) ;
            return true ;
        }
    }
    
    bool remove(int val) {

        if(st.find(val)!=st.end()){
            st.erase(val) ;
        it = st.begin() ;

            return true ;
        }
        else return false ;
    }
    
    int getRandom() {
        return *next(st.begin(),rand()%st.size());
    }
};

/**
,"getRandom","insert","remove"
,[],[0],[0]
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */