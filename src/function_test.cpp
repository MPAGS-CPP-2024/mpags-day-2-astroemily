#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool processCommandLine(const std::vector,std::string>& args, bool& helpRequested, bool& versionRequested, \
    std::string& inputFileName, std::string& outputFileName)
    {
        // Handle version, if requested
        // Like help, requires no further action,
        // so return from main with zero to indicate success
        if (versionRequested) {
            std::cout << "0.1.0" << std::endl;
            return 0;
        }
        // Handle help, if requested
        if (helpRequested) 
         {
            std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
        }
        
        
    return 0;
    }

int main()
{
    bool helpRequested=true;
    bool versionRequested=true;
    std::string inputFileName {"input.txt"};
    std::string outputFileName {"output.txt"};
    std::cout << processCommandLine(helpRequested, versionRequested, inputFileName, outputFileName) << std::endl;
}