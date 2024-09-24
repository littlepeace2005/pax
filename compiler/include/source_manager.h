#ifndef SOURCE_MANAGER_H
#define SOURCE_MANAGER_H

#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>

namespace pax
{
    using const_path_ptr = const std::filesystem::path *;

    struct sm
    {
        std::ifstream src;
        std::vector<std::streampos> lns;
        static std::map<std::filesystem::path, sm> sources;

        static const_path_ptr fpath(const char *);
        static std::string fread(const char *);
    };

    struct location
    { unsigned ln = 1, col = 1; };

} // namespace pax

#endif // SOURCE_MANAGER_H