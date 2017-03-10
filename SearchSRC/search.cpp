#include "search.h"

void preprocess(string text, string pattern) {


}

void search(string text, string pattern) {
	// The end condition to signal the text is done
	int text_end = text.size() - 1;
	
	// Current string being considered in text
	// Position the text and pattern over each other
	int i_text = pattern.size() - 1;
	string found = "";
	for(int i = pattern.size()-1; i >= 0; i--) {
		if (text[i_text] == pattern[i]) {
			i_text--;
			if (!i) {
				found += to_string(i)+'#';
				i = pattern.size() - 1;
				// TODO: Need to add something to set i_text to the next appropriate value
			}
			continue;
		}


		// This should always go at the end of the loop
		if (i_text >= text_end) break;
	}
	cout << found;
}


int main(){
	string text = "Hey you over there, hey!";
    string pattern = "Hey";
	search(text, pattern);
	return 0;
}

