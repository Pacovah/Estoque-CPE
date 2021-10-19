#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>

using namespace std;

namespace fs = filesystem;

namespace str_utils {
    inline string substr(string s, int start, int end);
    vector<string> split(string s, string del);
    string replace(string s, string old_value, string new_value);
    bool find(string s, string f);
}


namespace file {
    string read(const string path);
    bool fs_exists(const fs::path& p, fs::file_status s = fs::file_status{});
    void write(const fs::path& p, string content, bool append = false);
}


template <typename T>
void print_vector(vector<T> v);
#include "utils_t_impl.h"

#endif
