#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, vector<string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[(unsigned char)root->ch] = code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

void writeEncodedFile(const string& text, vector<string>& codes) {
    ofstream out("output.txt");
    if (!out) {
        cerr << "Error opening output file!\n";
        return;
    }

    for (char c : text) {
        if (!isalnum(c) && c != ' ' && c != '\n') continue;
        out << codes[(unsigned char)c];
    }

    out.close();
}

string readFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error: input.txt not found!\n";
        exit(1);
    }

    string text;
    char c;
    while (in.get(c)) {
        text += c;
    }
    in.close();
    return text;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string text = readFile("input.txt");

    vector<int> freq(256, 0);
    for (char c : text) {
        if (isalnum(c) || c == ' ' || c == '\n')
            freq[(unsigned char)c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            pq.push(new Node(i, freq[i]));
    }

    if (pq.empty()) {
        cerr << "No valid characters to encode!\n";
        return 1;
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    vector<string> codes(256);
    generateCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (i == ' ') cout << "' ' : " << codes[i] << "\n";
            else if (i == '\n') cout << "\\n : " << codes[i] << "\n";
            else cout << (char)i << " : " << codes[i] << "\n";
        }
    }

    writeEncodedFile(text, codes);
    cout << "\nEncoded file saved as output.txt\n";

    deleteTree(root);

    return 0;
}
