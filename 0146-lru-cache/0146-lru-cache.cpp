// //  struct ListNode {
// //      int key;
// //      ListNode *next;
// //      ListNode() : val(0), next(nullptr) {}
// //      ListNode(int x) : val(x), next(nullptr) {}
// //      ListNode(int x, ListNode *next) : val(x), next(next) {}
// //  };

// class LRUCache {
// private:
//     int cap, size;
//     map <int,int> mp;
//     ListNode *head;
//     ListNode *tail;

//     void bringToTail(int _key){
//         ListNode* prev = new ListNode();
//         prev->next = head;
//         ListNode* dummy = prev;
//         while(prev->next->val != _key){
//             prev = prev->next;
//         }
//         tail->next = prev->next;
//         tail=tail->next;
//         prev->next = prev->next->next;
//         tail->next = nullptr;
//         head = dummy->next;
//     }

//     void print(){
//         ListNode* temp = head;
//         cout<<"[";
//         while(temp!=nullptr){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<"]"<<endl;
//     }

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         size = 0;
//         head = nullptr;
//         tail = nullptr;
//     }
    
//     int get(int key) {
//         // cout<<"get ("<<key<<"): \n";
//         if(mp.count(key)>0){
//             bringToTail(key);
//             // print();
//             return mp[key];
//         }
//         // print();
//         return -1;
//     }
    
//     void put(int key, int value) {
//         // cout<<"put ("<<key<<","<<value<<"): \n";
//         if(mp.count(key)==0){
//             size++;
//             // add to list
//             if(head == nullptr){
//                 // cout<<"// initialising list with: "<<key<<endl;;
//                 head = new ListNode(key);
//                 tail = head;
//             }
//             else{
//                 // cout<<"// adding: "<<key<<endl;;
//                 tail->next = new ListNode(key);
//                 tail=tail->next;
//             }
//             // add to map
//             mp[key] = value;
//             if(size>cap){
//                 // delete list's head from mapping
//                 mp.erase(head->val);
//                 // pop list's head
//                 // cout<<"// poping: "<<head->val<<endl;
//                 head=head->next;
//                 size--;
//             }
//         }
//         else{
//             mp[key] = value;
//             bringToTail(key);
//         }
//         // print();
//         return;
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */


struct ListNode2 {
    int key;
    ListNode2* next;
    ListNode2* prev; // *** new line *** Add a `prev` pointer for doubly linked list

    ListNode2() : key(0), next(nullptr), prev(nullptr) {} // *** new line ***
    ListNode2(int x) : key(x), next(nullptr), prev(nullptr) {} // *** new line ***
    ListNode2(int x, ListNode2* next, ListNode2* prev) : key(x), next(next), prev(prev) {} // *** new line ***
};

class LRUCache {
private:
    int cap, size;
    unordered_map<int, pair<int, ListNode2*>> mp; // *** new line *** Map stores {value, pointer to node}
    ListNode2* head;
    ListNode2* tail;

    void bringToTail(ListNode2* node) {
        if (node == tail) return; // Already at the tail

        // Remove node from current position
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == head) head = node->next; // Update head if necessary

        // Append node to the tail
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node; // Update tail
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mp.count(key) == 0) return -1; // Key not found

        ListNode2* node = mp[key].second; // Get the node
        bringToTail(node); // Move to tail as it’s most recently used
        return mp[key].first; // Return the value
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            // Update value and move to tail
            mp[key].first = value;
            bringToTail(mp[key].second);
        } else {
            // Add new key-value pair
            ListNode2* newNode = new ListNode2(key);

            if (size == cap) {
                // Cache is full: remove LRU item (head)
                mp.erase(head->key);
                if (head->next) head->next->prev = nullptr;
                ListNode2* oldHead = head;
                head = head->next;
                delete oldHead;
                size--;
            }

            // Add new node to the tail
            if (!head) {
                head = newNode; // First node
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            mp[key] = {value, newNode}; // Add to map
            size++;
        }
    }
};
