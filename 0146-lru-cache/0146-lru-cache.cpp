//  struct ListNode {
//      int key;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class LRUCache {
private:
    int cap, size;
    map <int,int> mp;
    ListNode *head;
    ListNode *tail;

    void bringToTail(int _key){
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* dummy = prev;
        while(prev->next->val != _key){
            prev = prev->next;
        }
        tail->next = prev->next;
        tail=tail->next;
        prev->next = prev->next->next;
        tail->next = nullptr;
        head = dummy->next;
    }

    void print(){
        ListNode* temp = head;
        cout<<"[";
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"]"<<endl;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        // cout<<"get ("<<key<<"): \n";
        if(mp.count(key)>0){
            bringToTail(key);
            // print();
            return mp[key];
        }
        // print();
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"put ("<<key<<","<<value<<"): \n";
        if(mp.count(key)==0){
            size++;
            // add to list
            if(head == nullptr){
                // cout<<"// initialising list with: "<<key<<endl;;
                head = new ListNode(key);
                tail = head;
            }
            else{
                // cout<<"// adding: "<<key<<endl;;
                tail->next = new ListNode(key);
                tail=tail->next;
            }
            // add to map
            mp[key] = value;
            if(size>cap){
                // delete list's head from mapping
                mp.erase(head->val);
                // pop list's head
                // cout<<"// poping: "<<head->val<<endl;
                head=head->next;
                size--;
            }
        }
        else{
            mp[key] = value;
            bringToTail(key);
        }
        // print();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */