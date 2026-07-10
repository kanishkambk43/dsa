/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 */

class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            prev=NULL;
            next=NULL;
        }
        
    };
    void putatfirst(Node *node){
        Node *temp=head->next;
        head->next=node;
        temp->prev=node;
        node->next=temp;
        node->prev=head;
    }
    void deletenode(Node *node){
        Node *temp=node->prev;
        temp->next=node->next;
        node->next->prev=temp;
    }
    map<int,Node*>mp;
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        else{
            Node *node=mp[key];
            deletenode(node);
            putatfirst(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            deletenode(node);
            node->val=value;
            putatfirst(node);
            return;        }
        if(mp.size()==cap){
            Node* lr=tail->prev;
            deletenode(lr);
            mp.erase(lr->key);
        }
        Node * node=new Node(key,value);
        putatfirst(node);
        mp[key]=node
;            
        }
    };