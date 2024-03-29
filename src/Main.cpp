/***************************************************************
 *
 *
 ***************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdint.h> // uint64_t
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstring>

#include "Version.hpp"
#include "Git_Diff.hpp"

template <class Integer>
inline std::string IntToStr(const Integer integer, const int width = 0, const char fill = ' ')
{
    std::ostringstream MyStream;
    if (width != 0)
    {
        MyStream << std::setw(width);
        MyStream << std::setfill(fill);
    }
    MyStream << integer << std::flush;
    return (MyStream.str());
}

// **************************************************************
int main(int argc, char *argv[])
{
    Log_Git_Info(std::string("output/"));

    const int len_ptr  = 10000;
    const int nb_saves = 1000000;

    // Allocate some data
    double *ptr = new double[len_ptr];
    for (int i = 0 ; i < len_ptr ; i++)
    {
        ptr[i] = double(i);
    }

    // Create the folder
    system("mkdir -p output/simulation_name");

    // Save it in the output folder
    char filename[1024];
    memset(filename, 0, 1024*sizeof(char));
    for (int i = 0 ; i < nb_saves ; i++)
    {
        sprintf(filename, "output/simulation_name/data_%010d.bin", i);
        std::ofstream fp_out(filename, std::ios::out | std::ios::binary);
        assert(fp_out.is_open());
        fp_out.write(reinterpret_cast<char*>(ptr), len_ptr*sizeof(double));
        fp_out.close();
    }

    delete[] ptr;

    return EXIT_SUCCESS;
}

