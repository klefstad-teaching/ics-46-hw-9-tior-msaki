#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2){
    len_1 = word1.length();
    len_2 = word2.length();
    if ((max(len_1, len_2) - min(len_1, len_2)) > 1) return false;
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

string truncate(size_t index, const size_t length_word, const string& word);
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
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();