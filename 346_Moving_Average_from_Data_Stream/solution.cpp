class MovingAverage {
public:
    MovingAverage(int size) {
        // the extra element is to differentiate full and empty.
        // when head = tail, it's empty; when head + 1 = tail, it's full
        queue.resize(size+1, 0);
        cur_size = 0;
        head = 0;
        tail = 0;
        wind_sum = 0;
    }
    
    double next(int val) {
        
        int next_head = (head + 1) % queue.size();
        if (next_head == tail) {
            // queue is full
            head = tail;
            tail = (tail + 1) % queue.size();
            wind_sum -= queue[tail];
            wind_sum += val;
            queue[head] = val;
        } else {
            cur_size++;
            head = next_head;
            queue[head] = val;
            wind_sum += val;
        }

        return wind_sum * 1. / cur_size;
    }
private:
    std::vector<int> queue;
    int cur_size;
    int head;
    int tail;
    int wind_sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */