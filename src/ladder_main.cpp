#include "ladder.h"

void test_edit_distance_within(){
    string word1 = "bob";
    string word2 = "bobs";
    cout << edit_distance_within(word1, word2, 1) << endl;
    word1 = "catch";
    word2 = "tatch";
    cout << edit_distance_within(word1, word2, 1) << endl;
    word1 = "cat";
    word2 = "tatch";
    cout << edit_distance_within(word1, word2, 1) << endl;
    word1 = "catch";
    word2 = "tatcz";
    cout << edit_distance_within(word1, word2, 1) << endl;
    word1 = "wee";
    word2 = "tatch";
    cout << edit_distance_within(word1, word2, 1) << endl;
}

void test_is_adjacent_equal_len(){
    string word1 = "bob";
    string word2 = "bob";
    cout << is_adjacent_equal_len(word1, word2) << endl;
    word1 = "cat";
    word2 = "caa";
    cout << is_adjacent_equal_len(word1, word2) << endl;
    word1 = "bbb";
    word2 = "caa";
    cout << is_adjacent_equal_len(word1, word2) << endl;
}

void test_truncate(){
    cout << truncate(1, 3, "cat") << endl;
    cout << truncate(0, 3, "cat") << endl;
    cout << truncate(2, 3, "cat") << endl;
}

void test_is_adjacent(){
    string word1 = "bob";
    string word2 = "bob";
    cout << is_adjacent(word1, word2) << endl;
    word1 = "cat";
    word2 = "caa";
    cout << is_adjacent(word1, word2) << endl;
    word1 = "bbb";
    word2 = "caa";
    cout << is_adjacent(word1, word2) << endl;
    word1 = "aaaa";
    word2 = "caa";
    cout << is_adjacent(word1, word2) << endl;
    word1 = "caaa";
    word2 = "caa";
    cout << is_adjacent(word1, word2) << endl;
    word1 = "bbb";
    word2 = "weeee";
    cout << is_adjacent(word1, word2) << endl;
}

void test_all_lower(){
    string word1, replace;
    word1 = "AAA";
    all_lower(word1, replace);
    cout<< replace << endl;
    word1 = "Bob";
    all_lower(word1, replace);
    cout<< replace << endl;
}

void test_verify(){
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    // cout<<"DONE";
    print_word_ladder(generate_word_ladder("sleep", "awake", word_list));
    // verify_word_ladder();
}

int main() {
    // test_edit_distance_within();
    // test_is_adjacent_equal_len();
    // test_truncate();
    // test_is_adjacent();
    // test_all_lower();
    test_verify();
}
