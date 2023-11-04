#pragma once

struct node {
	char ch;
	int freq;
	node* left = nullptr;
	node* right = nullptr;
	node() {}
	node(char ch, int freq) : ch(ch), freq(freq) {}
};