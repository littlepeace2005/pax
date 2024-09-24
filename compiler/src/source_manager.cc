#include "source_manager.h"

#include <fstream>

namespace pax
{

std::map<std::filesystem::path, sm> sm::sources;

const_path_ptr sm::fpath(const char *path)
{
    auto cpath = std::filesystem::canonical(path);
    auto it = sources.find(cpath);
    return &it->first;
}

std::string sm::fread(const char *path)
{
    auto cpath = std::filesystem::canonical(path);
    sources[cpath].src = std::ifstream(cpath);
    std::istream &src = sources[cpath].src;
    auto &lns = sources[cpath].lns;
    
    src.seekg(std::ios::end);
    std::string str;
    str.reserve((std::streamsize)src.tellg());
    src.seekg(std::ios::beg);
    sources[cpath].lns.push_back(src.tellg());

    for(;;) {
        switch (src.peek()) {
        case EOF: return str;
        case '\r':
            src.get();
            if (src.peek() == '\n') // fall through
        case '\n':
                src.get();
            lns.push_back(src.tellg());
            str.push_back('\n');
            break;
        default:
            str.push_back(src.get());
            break;
        }
    }
    return str;
}
    
} // namespace pax