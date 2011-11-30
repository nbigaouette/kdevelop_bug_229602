/***************************************************************
 *
 *
 ***************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdint.h> // uint64_t

#include "Version.hpp"
#include "Git_Diff.hpp"

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

    return EXIT_SUCCESS;
}

