//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "FileCacheManager.h"

using namespace std;


class ls
{
    static bool wild_match(const string &str, const string &pattern)
    {
        string::const_iterator str_it = str.begin();

        for (auto pat_it = pattern.begin(); pat_it != pattern.end(); ++pat_it) {
            switch (*pat_it) {
                case '*': {
                    if (pat_it + 1 == pattern.end()) {
                        return true;
                    }

                    const size_t max = strlen(&*str_it);

                    for (size_t i = 0; i < max; ++i) {
                        if (wild_match(&*(pat_it + 1), &*(str_it + i))) {
                            return true;
                        }
                    }

                    return false;
                }
                default:
                    if (*str_it != *pat_it) {
                        return false;
                    }

                    ++str_it;
            }
        }

        return str_it == str.end();
    }

public:
    class CouldNotOpenDirectory : exception {};

    /** שמות הקבצים בתיקייה כשלהי שמתאימים לתבנית כלשהי */
    static vector<string> get_filenames(const char *dir_name, const string &pattern)
    {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(dir_name)) == NULL) throw CouldNotOpenDirectory();

        vector<string> results;

        while ((ent = readdir(dir)) != NULL) // iterate over all files in directory
        {
            if (wild_match(ent->d_name, pattern)) {
                results.emplace_back(ent->d_name);
            }
        }
        closedir(dir);

        return results;
    }
};

/** type_name<int>() returns "int" */
template<typename T>
constexpr auto type_name()
{
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

/** מחזיר סטרינג קצר שמייצג האש של הסטרינג הנתון */
string str_hash(string &str)
{
    size_t h = std::hash<string>{}(str);

    return to_string(h);
}

namespace cache_manager
{
    template<typename Problem, typename Solution>
    void store(Problem &problem, Solution &solution)
    {
        throw "not implemented";
    }

    template<typename Problem, typename Solution>
    Solution retrieve(Problem &problem)
    {
        vector<string> optionalFilesOfHaseProblem = ls::get_filenames(getTyped(problem) + "#" + getHase(problem) + "#*", "*.cpp");
        vector<string>::iterator it = optionalFilesOfHaseProblem.begin();
        for(it; it != optionalFilesOfHaseProblem.end(); it++){
//            ofstream file;
//            file.open(cacheFileName(problem), ios::binary);
//            if (!file) { throw CouldNotWriteFile(); }
//
//            size_t problem_length = sizeof(*problem);
//            file.write((char *) problem_length, sizeof(problem_length));
//
//            file.write((char *) problem, sizeof(*problem));
//
//            file.write((char *) solution, sizeof(*solution)); // overrides if exists
//            file.close();
            fstream fileOfProblem;
            fileOfProblem.open(*it, ios::binary);
            if (!fileOfProblem){throw cache_manager::FileCacheManager::notSeeccsedOpenTheFile();}
            char *bufferSize = nullptr,  *bufferProblem = nullptr;
            string ()
            while (problem)
            fileOfProblem.read(bufferSize, 8);
            fileOfProblem.read(bufferProblem, atoi(bufferSize));
            string bufferString(bufferProblem);

        }
    }

    template<typename Problem, typename Solution>
    bool is_cached(Problem &problem)
    {
        throw "not implemented";
    }

}
