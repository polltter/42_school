#include "string_utils.h++"

int open_files(std::ifstream *in, std::ofstream *out, const char *av) {
    std::string     out_name(av);

    in->open(av);
    if (!in->is_open())
    {
        std::cout << "Infile doesn't exist!\n";
        return 0;
    }
    out_name.append(".replace");
    out->open(out_name.c_str(), std::ios::trunc);
    if (!out->is_open())
    {
        std::cout << "Error opening outfile!\n";
        return 0;
    }
    return 1;
}

int main(int ac, char **av) {
    std::ifstream   in_file;
    std::ofstream   out_file;
    std::string     str;
    std::string     replaced;

    if (ac == 4)
    {
        if (!open_files(&in_file, &out_file, av[1]))
            return 0;
        str = getTextFile(in_file);
        replaced = searchReplace(str, av[2], av[3]);
        out_file << replaced;
    }
    else
        std::cout << "Wrong number of arguments\n";
    return 0;
}
