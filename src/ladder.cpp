#include "ladder.h"
#define my_assert(e) {cout<<#e<<((e)? " passed": " failed") << endl;}

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    len_1 = str1.length();
    len_2 = str2.length();
    if ((max(len_1, len_2) - min(len_1, len_2)) > d) return false;
}
bool is_adjacent(const string& word1, const string& word2){
    len_1 = word1.length();
    len_2 = word2.length();
    if (!edit_distance_within(word1, word2, 1)) return false;
    bool is_one_off = false;
    if (len_1 == len_2) {
        for (size_t index = 0; index<len_1; index++) {
            if (!is_one_off && word1[index] != word2[index]) is_one_off = true;
            else if (is_one_off && word1[index] != word2[index]) return false;
        }
    }
    else if (len_1 < len_2) {
        for (size_t index = 0; index<len_1; index++) {
            if (word1[index] != word2[index]) {
                string new_word = truncate(index, len_2, word2);
                return new_word == word1;
            }
        }
    }
    else {
        for (size_t index = 0; index<len_2; index++) {
            if (word1[index] != word2[index]) {
                string new_word = truncate(index, len_1, word1);
                return new_word == word1;
            }
        }
    }
    return true;
}

string truncate(size_t index, const size_t length_word, const string& word){
    string ret_word;
    for (size_t i = 0; i< length_word; i++) {if (i != index) ret_word += word[i];}
    return ret_word;
}

bool is_adjacent_equal_len(const string& word1, const string& word2){
    len_1 = word1.length();
    for (size_t index = 0; index<len_1; index++) {
            if (!is_one_off && word1[index] != word2[index]) is_one_off = true;
            else if (is_one_off && word1[index] != word2[index]) return false;
        }
}

void all_lower(string& word1){
    len_1 = word1.length();
    for (size_t index = 0; index<len_1; index++) {
        word1[index] = to_lower(word1[index]);
    }
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    all_lower(begin_word);
    all_lower(end_word);
    if (begin_word == end_word) error(begin_word, end_word, "ERROR: same word.")
    queue<vector<string>> ladder_queue;
    ladder_queue.push([begin_word]);
    set<string> visited;
    visited.insert(begin_word);
    vector<string> ladder;
    string last_word;
    while (!ladder_queue.empty()) {
        ladder = ladder_queue.front();
        last_word = ladder.back();
        for (auto word: word_list){
            if (is_adjacent(last_word, word)){
                if (visited.find(word) != visited.end() ) {
                    visited.insert(word);
                    vector<string> new_ladder = copy(ladder);
                    new_ladder.push_back(word);
                    if (word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }

    }
    return ladder;
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(filename);
    for (string word: in >> word;)
        word_list.insert(word);
    in.close();
}
void print_word_ladder(const vector<string>& ladder) {
    for (auto word: ladder) cout << word << ' ';
}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}