#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class TextEditor {
 public:
  TextEditor() {
    text.clear();
    cursor = 0;
  }

  void addText(string text_) {
    text.insert(text.begin() + cursor, text_.begin(), text_.end());
    cursor += text_.size();
  }

  int deleteText(int k) {
    if (cursor >= k) {
      text.erase(text.begin() + cursor - k, text.begin() + cursor);
      cursor -= k;
      return k;
    } else {
      int ret = cursor;
      text.erase(text.begin(), text.begin() + cursor);
      cursor = 0;
      return ret;
    }
  }

  string cursorLeft(int k) {
    if (cursor >= k) {
      cursor -= k;
    } else {
      cursor = 0;
    }
    int left = min(10, cursor);
    return string(text.begin() + cursor - left, text.begin() + cursor);
  }

  string cursorRight(int k) {
    if (cursor + k <= text.size()) {
      cursor += k;
    } else {
      cursor = text.size();
    }
    int left = min(10, cursor);
    return string(text.begin() + cursor - left, text.begin() + cursor);
  }

 private:
  string text;
  int cursor;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */