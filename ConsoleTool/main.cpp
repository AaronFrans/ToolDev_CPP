#include <direct.h> // _getwcwd
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>


#include <FileReader.h>

int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	try
	{
		std::wstring inputFile;
		std::wstring outputFile;

		for (int i = 1; i < argc; i++) {
			std::wstring arg(argv[i]);

			if (arg == L"-o" && i + 1 < argc) {
				outputFile = argv[i + 1];
				i++;
			}
			else if (arg == L"-i" && i + 1 < argc) {
				inputFile = argv[i + 1];
				i++;
			}
		}

		if (inputFile.empty()) {
			throw std::invalid_argument("input path not specified");
		}
		if (outputFile.empty()) {
			throw std::invalid_argument("output path not specified");
		}

		// Use inputString and outputString as needed
		

		return ConvertJSON(inputFile, outputFile);

	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}

	return 0;
}
