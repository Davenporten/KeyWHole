#include "search.h"

void preprocess(char* text, char* pattern) {


}

void search(char* text, char* pattern) {
	// The end condition to signal the text is done
	int text_end = strlen(text) - 1;
	
	// Current char being considered in text
	// Position the text and pattern over each other
	int i_text = strlen(pattern) - 1;
	char* found = "";
	for(int i = strlen(pattern)-1; i >= 0; i--) {
		if (text[i_text] == pattern[i]) {
			i_text--;
			found += to_string(i) + '#'; 
			continue;
		}
	}
	cout << found;
}


int main(){
	char* text = "Hey you over there, hey!";
    char* pattern = "Hey";
	search(text, pattern);
	return 0;
}

