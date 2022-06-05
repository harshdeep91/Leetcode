class TextEditor {
    deque<char> left;
    deque<char> right;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        left.insert(left.end(),text.begin(),text.end());
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(!left.empty() and k--){
            left.pop_back();
            cnt++;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() and k--){
            right.push_back(left.back());
            left.pop_back();
        }
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
        while(!right.empty() and k--){
            left.push_back(right.back());
            right.pop_back();
        }
        return cursorShiftString();
    }
    
    string cursorShiftString(){
        return string(max(left.end()-10,left.begin()),left.end());
    }
};