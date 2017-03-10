#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>

using namespace std;

// Used for indexing into the tables related to specific strings
enum alphabeta {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};


void preprocess(string text, string pattern);
void search(string text, string pattern);

#endif
