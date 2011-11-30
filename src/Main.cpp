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


    // Allocate some data
    const int len_ptr = 100;
    double *ptr = new double[len_ptr];

    // Save it in the output folder
    std::ofstream fp_out;
    std::string filename;
    for (int i = 0 ; i < 10000 ; i++)
    {
        filename = std::string("output/data_") + IntToStr<int>(i, 6, 0) + ".bin";
        fp_out.open(filename.c_str(), std::ios::out | std::ios::binary);
        assert(fp_out.is_open());
        fp_out.write(reinterpret_cast<char*>(ptr), len_ptr*sizeof(double));
        fp_out.close();
    }

    delete[] ptr;

    return EXIT_SUCCESS;
}

