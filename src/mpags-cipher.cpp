#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool processCommandLine(std::vector<std::string>& args)
    {
        bool helpRequested{false};
        bool versionRequested{false};
        std::string inputFile{""};
        std::string outputFile{""};

        const std::size_t nargs{args.size()};

        for (std::size_t i{1}; i < nargs; ++i) 
        {
            if (args[i] == "-h" || args[i] == "--help") 
            {
                helpRequested = true;
            }    
            else if (args[i] == "--version") 
            {
                versionRequested = true;
            }
            else if (args[i] == "-i") 
            {
                // Handle input file option
                // Next element is filename unless "-i" is the last argument
                if (i == nargs - 1) 
                {
                    std::cerr << "[error] -i requires a filename argument" << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                } 
                else 
                {
                    // Got filename, so assign value and advance past it
                    inputFile = args[i + 1];
                    ++i;
                }
            }
            else if (args[i] == "-o") 
            {
                // Handle output file option
                // Next element is filename unless "-o" is the last argument
                if (i == nargs - 1) 
                {
                    std::cerr << "[error] -o requires a filename argument" << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                } 
                else 
                {
                    // Got filename, so assign value and advance past it
                    outputFile = args[i + 1];
                    ++i;
                }
            } 
            else 
            {
                // Have an unknown flag to output error message and return non-zero
                // exit status to indicate failure
                std::cerr << "[error] unknown argument '" << args[i] << "'\n";
                return 1;
            }
        }
        // Handle help, if requested
        if (helpRequested) 
        {
            // Line splitting for readability
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

        // Handle version, if requested
        // Like help, requires no further action,
        // so return from main with zero to indicate success
        if (versionRequested) 
        {
            std::cout << "0.1.0" << std::endl;
            return 0;
        }
    return 0;
    }
    
    


std::string transformChar( const char in_char)
{
    /* will take a character in a list and return the transliterated string of that character
    in_char: character to transliterate

    return: string of the character in in_char

    */

   //initialise the string
   std::string changed_char;
   // Uppercase alphabetic characters
        if (std::isalpha(in_char)) {
            changed_char += std::toupper(in_char);
            
        }

        // Transliterate digits to English words
        switch (in_char) {
            case '0':
                changed_char += "ZERO";
                break;
            case '1':
                changed_char += "ONE";
                break;
            case '2':
                changed_char += "TWO";
                break;
            case '3':
                changed_char += "THREE";
                break;
            case '4':
                changed_char += "FOUR";
                break;
            case '5':
                changed_char += "FIVE";
                break;
            case '6':
                changed_char += "SIX";
                break;
            case '7':
                changed_char += "SEVEN";
                break;
            case '8':
                changed_char += "EIGHT";
                break;
            case '9':
                changed_char += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    return changed_char ;
}

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    std::vector<std::string> vect{cmdLineArgs};

    

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    processCommandLine(vect);

    
        
    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }

    // loop over each character from user input
    while (std::cin >> inputChar) {
        inputText +=transformChar(inputChar);
    }

    // Print out the transliterated text

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}