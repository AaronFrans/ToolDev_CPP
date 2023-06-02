#include <string>
#include <vector>



namespace FileReader 
{

struct Cube
{

	enum class CubeType
	{
		Dirt,
		Stone,
		Wood,
		Glass,
	};

	CubeType type{};
	float position[3]{};
	bool isOpaque{ true };
};


void WriteCube(float x, float y, float z, FILE* pOFile, int cubeNr = 0);

void WriteVertexNormals(FILE* pOFile);


void WriteMaterial(FILE* pOFile, Cube::CubeType type);

void WriteMTLFile(FILE* pOBJFile, const std::wstring& outputPath);

Cube::CubeType LayerToEnum(const std::string& layer);

int ConvertJSON(const std::wstring& input, const std::wstring& output);

std::vector<std::vector<float>> GetJsonVertices(const std::wstring& input);

}