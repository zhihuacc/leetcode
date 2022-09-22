class TwoSum {
    
    unordered_map<int, int> map;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        
        map[number]++;
    }
    
    bool find(int value) {
        
        for (auto p: map) {
            
            // Check overflow
            int complement = int(long(value) - long(p.first));
            if (value < 0 && p.first > 0 && complement > 0) {
                return false;
            } else if (value > 0 && p.first < 0 && complement < 0) {
                return false;
            }
            
            if (map.find(complement) != map.end()) {
                
                if (complement != p.first) {
                    return true;
                } else if (p.second > 1) {
                    // if p.first == complement, need ensure p.first appears > 1 time.
                    // WARN: if p.second == 1, continue searching instead of return false.
                    return true;
                } 
            }
        }
        return false;
    }
};