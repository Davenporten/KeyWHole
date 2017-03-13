#include "search.h"

void preprocess(string text, string pattern) {


}

string search(string text, string pattern) {
	transform(text.begin(), text.end(), text.begin(),(int (*)(int))tolower);
	transform(pattern.begin(), pattern.end(), pattern.begin(),(int (*)(int))tolower);

	int offset = 0;

	// The end condition to signal the text is done
	int text_end = text.size() - 1;
	
	// Current string being considered in text
	// Position the text and pattern over each other
	int i_text = pattern.size() - 1;
	string found = "";
	int i = pattern.size()-1;
	while (true) {
		cout << text[i_text] << " " << pattern[i] << endl;
		cout << i_text << " " << i << endl;
		if (text[i_text] == pattern[i]) {
			// We've found a match and are adding the index of where the match is
			offset++;
			if (!i && (offset == pattern.size())) {
				found += to_string(i_text)+'#';
				i = pattern.size() - 1;
				i_text += (pattern.size() * 2) - 1;
				offset = 0;
				if (i_text == text_end) {
					break;
				}
				continue;
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
			cout << "Bad Match: " << bad_match_i << endl;
			if (bad_match_i != string::npos) {
				cout << "Found" << endl;
				i_text += offset + (i - bad_match_i);
			}
			else {
				cout << "Not Found" << endl;
				i_text += pattern.size();
			}

			// Good suffix
			
			// Reset where we are in pattern
			i = pattern.size() - 1;
			continue;
		}


		// This should always go at the end of the loop
		// Indicates the end of the text; search is done
		if (i_text >= text_end) break;
		i--;
	}
	cout << found << endl;
	return found;
}


int main(){
	string text = "Hey hey over there, hey!";
    string pattern = "Hey";
	cout << text << endl;
	cout << pattern << endl;
	search(text, pattern);
	return 0;
}

