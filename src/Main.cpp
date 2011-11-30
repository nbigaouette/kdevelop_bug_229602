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
    std::cout << "Hello world!" << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
    std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;
    std::cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl;
    std::cout << "sizeof(unsigned long int) = " << sizeof(unsigned long int) << std::endl;
    std::cout << "sizeof(unsigned long long int) = " << sizeof(unsigned long long int) << std::endl;
    std::cout << "sizeof(uint64_t) = " << sizeof(uint64_t) << std::endl;
    std::cout << "sizeof(uint32_t) = " << sizeof(uint32_t) << std::endl;
    std::cout << "sizeof(int64_t) = " << sizeof(int64_t) << std::endl;
    std::cout << "sizeof(int32_t) = " << sizeof(int32_t) << std::endl;
    std::cout << "sizeof(std::vector<uint64_t>::size_type) = " << sizeof(std::vector<uint64_t>::size_type) << std::endl;
    std::cout << "sizeof(std::vector<double>::size_type) = " << sizeof(std::vector<double>::size_type) << std::endl;
    std::cout << "sizeof(std::vector<float>::size_type) = " << sizeof(std::vector<float>::size_type) << std::endl;

    Log_Git_Info(std::string("output/"));


    // Allocate some data
    double *ptr = new double[100];

    // Save it in the output folder
    std::ofstream fp_out;
    std::string filename;
    for (int i = 0 ; i < 10000 ; i++)
    {
        filename = std::string("output/data_") + IntToStr<int>(i, 6, 0) + ".bin";
        fp_out.open(filename.c_str(), std::ios::out | std::ios::binary);
        assert(fp_out.is_open());
        fp_out.write(reinterpret_cast<char*>(ptr), 100*sizeof(double));
        fp_out.close();
    }

    delete[] ptr;

    return EXIT_SUCCESS;
}

