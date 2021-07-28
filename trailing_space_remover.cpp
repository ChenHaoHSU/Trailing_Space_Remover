
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string filename = argv[1];

    // Read
    vector<string> vLines;
    ifstream fin(filename, ios::in);
    string buffer;
    size_t line_no = 0;
    cout << "Reading..." << endl;
    while (getline(fin, buffer)) {
        vLines.emplace_back(buffer);
        ++line_no;
    }
    fin.close();

    // Remove trailing spaces
    cout << "Removing..." << endl;
    size_t nSpaces = 0;
    for (size_t i = 0, n = vLines.size(); i < n; ++i) {
        string& str = vLines[i];
        size_t found = str.find_last_not_of(" ");
        if (found != string::npos) {
            nSpaces += (str.size() - found - 1);
            str.erase(found + 1);
        }
        else {
            nSpaces += str.size();
            str.clear();
        }
    }

    // Write
    cout << "Writing..." << endl;
    ofstream fout(filename, ios::out);
    for (size_t i = 0, n = vLines.size(); i < n; ++i) {
        if (i != 0) {
            fout << endl;
        }
        fout << vLines[i];
    }
    fout.close();

    // Print summary
    cout << "[Info] Filename : " << filename << "\n";
    cout << "[Info] Number of lines : " << line_no  << "\n";
    cout << "[Info] Remove " << nSpaces << " trailing spaces.\n";

    return 0;
}



