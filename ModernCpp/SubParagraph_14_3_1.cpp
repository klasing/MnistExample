#include "pch.h"

inline void subParagraph_14_3_1() {
	cout << "ECMAScript Syntax" << endl;
	cout << "-----------------" << endl;

	cout << "   Special Charaters:" << endl;
	cout << "   ^ $ \\ . * + ? ( ) [ ] { } |" << endl;
	cout << "a) Anchors" << endl;
	cout << "   Beginning of the string: ^" << endl;
	cout << "   End of the string: $" << endl;
	cout << "b) Wildcards" << endl;
	cout << "   Any character, except the newline character: ." << endl;
	cout << "c) Repetition" << endl;
	cout << "   Zero or more times: *" << endl;
	cout << "   One or more times: +" << endl;
	cout << "   Zero or one times: ?" << endl;
	cout << "   bounded repeat {...}" << endl;
	cout << "d) Alternation" << endl;
	cout << "   \"or\" relationship: |" << endl;
	cout << "e) Grouping" << endl;
	cout << "   Capture groups: ()" << endl;
	cout << "f) Precedence" << endl;
	cout << "g) Character Set Matches" << endl;
	cout << "   Character set: [...]" << endl;
	cout << "   Range specification: e.g. [a-zA-Z\\-]*" << endl;
	cout << "   Character classes: [:name:]" << endl;
	cout << "h) Word Boundaries" << endl;
	cout << "   The beginning of a source string" << endl;
	cout << "   The end of a source string" << endl;
	cout << "   The first character of a word" << endl;
	cout << "   The end of a word" << endl;
	cout << "   Match a word boundary: \\b" << endl;
	cout << "   Match anything except a word boundary: \\B" << endl;
	cout << "i) Back References" << endl;
	cout << "   E.g. match: 123-abc-123 or 1234-abcd-1234," << endl;
	cout << "   ^(\d+)-.*-\\1$" << endl;
	cout << "j) Regular Expression and Raw String Literals" << endl;
}