struct trie{
    trie *child[26]={0};
    int wordcount=0;
};
class WordDictionary {
    trie *head;
public:
    WordDictionary() {
        head=new trie;
    }
    
    void addWord(string word) {
        trie *root=head;
        for(int i=0;i<word.size();i++)
        {
            if(!root->child[word[i]-'a'])
                root->child[word[i]-'a']=new trie;
                
            // if(!root->child[26])
            // root->child[26]=new trie;
            root=root->child[word[i]-'a'];
        }
        root->wordcount++;
    }
    bool search2(string word,trie *root)
    {
        // cout<<word<<endl;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                // if(root->child[26])//if present
                // {
                    // cout<<'e';
                    for(int j=0;j<26;j++)
                    {
                        if(root->child[j]&&search2(word.substr(i+1,word.size()-i-1),root->child[j]))
                            return true;
                    }
                // }
                return false;
            }
            else if(!root->child[word[i]-'a'])
                return false;
            root=root->child[word[i]-'a'];
    }
        return root->wordcount;
    }
    bool search(string word) {
        return search2(word,head);
    }
        
        
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */