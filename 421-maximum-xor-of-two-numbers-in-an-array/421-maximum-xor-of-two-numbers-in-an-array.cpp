class Node{
  
    public:
      Node *link[2];
    Node(){
        link[0]=link[1]={0};
    }
    // bool contains(int bit)
    // {
    //     return head->link[bit];
    // }
    // Node* next(int bit)
    // {
    //     return head->link[bit];
    // }
};
class Trie{
    Node *first;
    public:
    Trie()
    {
        first=new Node();
    }
    //insert the node in 32 bit size why? because it guarantees that we are not getting extra bit while doing search (comparing with equal bits)
    void insert(int key)
    {
        int bit;
        Node *head=first;
        for(int i=31;i>=0;i--)
        {
           bit=(key>>i)&1;
            if(!head->link[bit])
                head->link[bit]=new Node();
            head=head->link[bit];
        }
    }
    //getmax
    int getmax(int key)
    {
        int bit,val=0;
        Node *head=first;
        for(int i=31;i>=0;i--)
        {
           bit=(key>>i)&1;
            if(head->link[!bit])
                bit=!bit;
                val=val<<1|bit;
                head=head->link[bit];
        }
		// cout << val << " " << key <<" "<<(val^key)<< endl;
		return val^key;
    }
};
class Solution {
    
public:
    int findMaximumXOR(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		Trie trie;
        for(auto x:nums)
            trie.insert(x);
        int mx=0;
        for(auto x:nums)
        {
            mx=max(mx,trie.getmax(x));
        }
        return mx;
    }
};