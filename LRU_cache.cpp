
//Question : Design a LRU cache.
// Link : https://leetcode.com/problems/lru-cache/
class LRUCache {
private:
    struct DLinkedNode{
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
    };
    
    //add the new node right after head
    void addNode(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    // Remove an existing node from the linked list.
    void removeNode(DLinkedNode* node){
        DLinkedNode* pre = node->prev;
        DLinkedNode* post = node->next;
        
        pre->next = post;
        post->prev = pre;
    }
    
    // Move any node in between to the head.
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addNode(node);
    }
    
    //delete the current tail node
    DLinkedNode* popTail(){
        DLinkedNode* tailNode = tail->prev;
        removeNode(tailNode);
        return tailNode;
    }
    
    unordered_map<int, DLinkedNode*>cache;
    int count;
    int capacity;
    DLinkedNode* head;
    DLinkedNode* tail;//dummy head and dummy tail to avoid checking of null value at the end       

public:
    LRUCache(int c) {
        count = 0;
        capacity = c;

        head = new DLinkedNode();
        head->prev = NULL;
        
        tail = new DLinkedNode();
        tail->next = NULL;
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        DLinkedNode* node = cache[key];
        //if the key is absent , return -1 or error message 
        if(!node)return -1;
        
        // else move the accessed node to the head;
        moveToHead(node);
        
        return node->value;  
    }
    
    void put(int key, int value) {
        DLinkedNode* node = cache[key];
        //first check if node is already present in the hashtable
        if(!node){
            DLinkedNode* newNode = new DLinkedNode();
            newNode->key = key;
            newNode->value = value;
            
            cache[key] = newNode;
            addNode(newNode);

            ++count;
            
            //if current size > capacity, first remove the least recently used 
            // item(which is going to be at the tail) , then put it at the front
            if(count>capacity){
                DLinkedNode* tailNode = popTail();
                cache.erase(tailNode->key);
                --count;
            }
        }
        
        // if the node is already present, move that node(by updating it's value) to the head;
        else{
            node->value = value;
            moveToHead(node);
        }
    }
};
