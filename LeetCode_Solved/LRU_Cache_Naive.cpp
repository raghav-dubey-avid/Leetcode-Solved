class LRUCache {
  
private:
    
    unordered_map <int, int> value; //will keep only existing elements
    queue<int> accessed;
    int capacity;
    unordered_map <int, int> cnt_in_queue;
    void add_to_queue(int key){
        accessed.push(key);
        cnt_in_queue[key]++;
    }
    
public:
    LRUCache(int given_capacity) {
        
        capacity = given_capacity;
    }
    
    int get(int key) {
        
        auto it = value.find(key);
        if(it == value.end()){
            return -1;
        }
        
        //find in value and append to queue
        add_to_queue(key);
        return it->second;
        //or you can use return value[key];
    }
    
    void put(int key, int v) {
        
        if(value.size() < capacity){
            value[key] = v;
            add_to_queue(key);
            return;
        }
        
        auto it = value.find(key);
        if(it != value.end()){
            it->second = v;
            add_to_queue(key);
            return;
        }
        
        //Find some old thing to replace
        while(true){
            
            int candidate = accessed.front();
            accessed.pop();
            if(--cnt_in_queue[candidate] == 0){
                
                value.erase(candidate);
                break;
            }
        }
        
        value[key] = v;
        add_to_queue(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */