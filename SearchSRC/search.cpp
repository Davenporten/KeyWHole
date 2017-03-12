#include "search.h"

void preprocess(string text, string pattern) {


}

string search(string text, string pattern) {
	transform(text.begin(), text.end(), text.begin(),(int (*)(int))tolower);
	transform(pattern.begin(), pattern.end(), pattern.begin(),(int (*)(int))tolower);

	// The end condition to signal the text is done
	int text_end = text.size() - 1;
	
	// Current string being considered in text
	// Position the text and pattern over each other
	int i_text = pattern.size() - 1;
	string found = "";
	for(int i = pattern.size()-1; i >= 0; i--) {
		if (text[i_text] == pattern[i]) {
			// We've found a match and are adding the index of where the match is
			if (!i) {
				found += to_string(i)+'#';
				i = pattern.size() - 1;
				i_text += (pattern.size() * 2) - 1;
				// thisisitthisisit
				// thisisit
			}
			else {
				i_text--;
			}
		}
		else {
			// Chars don't match, doing with bad match or good suffix
			// Bad match
			int bad_match_i = pattern.substr(0, i).find_last_of(text[i_text]);
			

			// Good suffix
		}


		// This should always go at the end of the loop
		// Indicates the end of the text; search is done
		if (i_text >= text_end) break;
	}
	return found;
}


int main(){
	string text = "Hello you over there, hey!";
    string pattern = "Leylo";
	search(text, pattern);
	return 0;
}

