#include <direct.h> // _getwcwd
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>


#include <FileReader.h>


bool displayParams = false;


int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	try
	{
		std::wstring inputFile;
		std::wstring outputFile;

		for (int i = 1; i < argc; i++) {

			std::wstring arg(argv[i]);

			if (arg == L"-h") {
				displayParams = true;
				break;
			}

			if (arg == L"-o" && i + 1 < argc) {
				outputFile = argv[i + 1];
				i++;
			}
			if (arg == L"-i" && i + 1 < argc) {
				inputFile = argv[i + 1];
				i++;
			}
		}

		if (displayParams) {
			std::cout << "Available parameters:" << std::endl;
			std::cout << "-o <output_file> : Set the output file path" << std::endl;
			std::cout << "-i <input_file>  : Set the input file path" << std::endl;
		}

		else
		{
			if (inputFile.empty()) {
				throw std::invalid_argument("input path not specified");
			}
			if (outputFile.empty()) {
				throw std::invalid_argument("output path not specified");
			}

			// Use inputString and outputString as needed


			return FileReader::ConvertJSON(inputFile, outputFile);
		}

		

	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}

	return 0;
}
