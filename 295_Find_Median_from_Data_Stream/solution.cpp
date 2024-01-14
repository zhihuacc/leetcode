class MedianFinder {
public:
    MedianFinder():low(sorted.end()), high(sorted.end()) {
        
    }
    
    void addNum(int num) {
        int count = sorted.size();
        sorted.insert(num);
        if (count == 0) {
            low = high = sorted.begin();
            return;
        }

        if (count & 1) {
            // odd before insert, then low == high
            if (num < *low) {
                // num is placed before low
                low--;  
            } else {
                // if num == *low == *high or num > *high
                // then num is placed after high
                high++;
            }
            // low+1 = high
        } else {
            // even before insert, then low+1 = high
            if (num < *low) {
                // num is placed before low
                high--;
            } else if (num >= *high) {
                // num is placed after high
                low++;
            } else {
                // if num >= *low && num < *high
                // then num is placed after low and before high
                low = --high;
            }
            // *low = *high = num
        }
    }
    
    double findMedian() {
        return (*low + *high) / 2.;
    }

private:
    std::multiset<int> sorted;
    std::multiset<int>::const_iterator low;
    std::multiset<int>::const_iterator high;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */