#include "utils.h"

namespace str_utils {

    inline string substr(string s, int start, int end) {
        return s.substr(start, end - start);
    } 


    vector<string> split(string s, string del)
    {
        int start = 0;
        int end = s.find(del);
        vector<string> result;
        
        while (end != -1)
        {
            result.push_back(substr(s, start, end));
            start = end + del.size();
            end = s.find(del, start);
        }

        result.push_back(substr(s, start, end));

        return result;
    }


    string replace(string s, string old_value, string new_value) {
        return s.replace(s.find(old_value), sizeof(old_value) - 1, new_value);
    }


    bool find(string s, string f) {
        return (s.find(f) != std::string::npos);
    }
}



namespace file {
    string read(const string path)
    {
        string filename(path);
        auto ss = ostringstream{};
        ifstream input_file(path);
        if (!input_file.is_open())
        {
            cerr << "Could not open the file - '" << path << "'" << endl;
            exit(EXIT_FAILURE);
        }
        ss << input_file.rdbuf();
        return ss.str();
    }


    bool fs_exists(const fs::path& p, fs::file_status s)
    {
        if(fs::status_known(s) ? fs::exists(s) : fs::exists(p))
            return true;
        return false;
    }


    void write(const fs::path& p, string content, bool append)
    {
        auto write_mode = append ? ios_base::app : ios_base::out;
        ofstream ofs(p, write_mode);
        ofs << content; 
        ofs.close();
    }
}
