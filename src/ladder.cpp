#include "ladder.h"
#define my_assert(e) {cout<<#e<<((e)? " passed": " failed") << endl;}

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int len_1 = static_cast<int>(str1.length());
    int len_2 = static_cast<int>(str2.length());
    if ((max(len_1, len_2) - min(len_1, len_2)) > d) return false;
    if (len_1 == len_2) {
        return is_adjacent_equal_len(str1, str2);
    }
    else {
        string word1 = str1, word2 = str2;
        if (len_1 > len_2) swap(word1, word2);
        for (int index = 0; index<len_1; index++) {
            if (word1[index] != word2[index]) {
                string new_word = truncate(index, word2.length(), word2);
                return new_word == word1;
            }
        }
    }
    return true;
}
bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

string truncate(size_t index, const size_t length_word, const string& word){
    string ret_word;
    for (size_t i = 0; i< length_word; i++) {if (i != index) ret_word += word[i];}
    return ret_word;
}

bool is_adjacent_equal_len(const string& word1, const string& word2){
    if (word1==word2) return true;
    bool is_one_off = false;
    size_t len_1 = word1.length();
    for (size_t index = 0; index<len_1; index++) {
            if (!is_one_off && word1[index] != word2[index]) is_one_off = true;
            else if (is_one_off && word1[index] != word2[index]) return false;
        }
    return is_one_off;
}

void all_lower(const string& word1, string & replace){
    replace = "";
    size_t len_1 = word1.length();
    for (size_t index = 0; index<len_1; index++) {
        replace += tolower(word1[index]);
    }
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    vector<string> ladder;
    if (begin_word == end_word) return {};
    if (word_list.count(end_word) == 0) return {};
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    string last_word, replace;
    while (!ladder_queue.empty()) {
        ladder = ladder_queue.front();
        last_word = ladder.back();
        // all_lower(ladder.back(), last_word);
        for (string word: word_list){
            // all_lower(word, replace);
            if (is_adjacent(last_word, word)){
            // if (is_adjacent(last_word, replace)){
                if (visited.count(word) == 0) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {return new_ladder;}
                    ladder_queue.push(new_ladder);
                }
            }
        }
        ladder_queue.pop();
    }
    if (ladder.size() == 1) ladder.pop_back();
    return ladder;
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    // if (!in) cout << "NOO";
    for (string word; in >> word;) word_list.insert(word);
    in.close();
}
void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size()<=1) {cout<< "No word ladder found.\n";return;}
    else cout << "Word ladder found: ";
    for (auto word: ladder) cout << word << ' ';
    cout<< endl;
}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}