class RandomizedSet {
    
    std::unordered_map<int, int> num_itsApp; // to store the number and its appearence
    std::vector<int> num{}; //vector to store the number
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        /*check whether the val is available in num_itsApp*/
        auto it = num_itsApp.find(val);
        /*if val is NOT present in the num_itsApp then add it*/
        if (it == num_itsApp.end()){
            //add it at the end of the num vector
            num.emplace_back(val);
            /*save it and its index in num_itsApp*/
            num_itsApp[val] = num.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int rem_val) {
       
        auto it  = num_itsApp.find(rem_val);
        /*if rem_val is present in num_itsApp */
        if ( it != num_itsApp.end()){
             /*get index of the rem_val*/
            int idx_rem_val = num_itsApp[rem_val];
             /*get last element in num vector */
            int last_elements = num.back();
            /*replace rem_val by the last element*/
            num[idx_rem_val] = last_elements;
            /*delete the last elements in num vector*/
            num.pop_back();
            /*update the index of last_elements by the index of rem_val lin  num_itsApp*/
            num_itsApp[last_elements] = idx_rem_val;
            /*final step, delete rem_val in num_itsApp*/
            num_itsApp.erase(rem_val);
            return true;
        }
        /*if rem_val is NOT present in num_itsApp */
        return false;
    }
    
    int getRandom() {
        
        int rand_idx = rand() % num.size();
        return num[rand_idx];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
