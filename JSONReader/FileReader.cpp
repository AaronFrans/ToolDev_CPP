#include "FileReader.h"

#include <windows.h>
#include <direct.h> // _getwcwd
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/IStreamWrapper.h"

namespace FileReader
{

	void WriteCube(float x, float y, float z, FILE* pOFile, int cubeNr)
	{

		constexpr int MaxVertices = 8;
		const int startIndex = MaxVertices * cubeNr;

		fwprintf_s(pOFile, L"gCube %d\n", cubeNr);

		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x, y, z);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x, y, z + 1.0f);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x, y + 1.0, z);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x, y + 1.0, z + 1.0f);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x + 1.0, y, z);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x + 1.0, y, z + 1.0f);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x + 1.0, y + 1.0, z);
		fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", x + 1.0, y + 1.0, z + 1.0f);


		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 2, startIndex + 7, 2, startIndex + 5, 2);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 2, startIndex + 3, 2, startIndex + 7, 2);

		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 6, startIndex + 4, 6, startIndex + 3, 6);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 6, startIndex + 2, 6, startIndex + 4, 6);

		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 3, 3, startIndex + 8, 3, startIndex + 7, 3);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 3, 3, startIndex + 4, 3, startIndex + 8, 3);

		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 5, 5, startIndex + 7, 5, startIndex + 8, 5);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 5, 5, startIndex + 8, 5, startIndex + 6, 5);

		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 4, startIndex + 5, 4, startIndex + 6, 4);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 1, 4, startIndex + 6, 4, startIndex + 2, 4);

		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 2, 1, startIndex + 6, 1, startIndex + 8, 1);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", startIndex + 2, 1, startIndex + 8, 1, startIndex + 4, 1);

		fwprintf_s(pOFile, L"gCube %d\n", cubeNr);
	}

	void WriteVertexNormals(FILE* pOFile)
	{

		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, 1.0f);
		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, -1.0f);
		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 1.0f, 0.0f);
		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, -1.0f, 0.0f);
		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 1.0f, 0.0f, 0.0f);
		fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", -1.0f, 0.0f, 0.0f);
	}

	void WriteMaterial(FILE* pOFile, Cube::CubeType type)
	{
		switch (type)
		{
		case Cube::CubeType::Dirt:
			fwprintf_s(pOFile, L"usemtl Dirt\n");
			break;
		case Cube::CubeType::Stone:
			fwprintf_s(pOFile, L"usemtl Stone\n");
			break;
		case Cube::CubeType::Wood:
			fwprintf_s(pOFile, L"usemtl Wood\n");
			break;
		case Cube::CubeType::Glass:
			fwprintf_s(pOFile, L"usemtl Glass\n");
			break;
		default:
			break;
		}
	}

	void WriteMTLFile(FILE* pOBJFile, const std::wstring& outputPath)
	{
		fwprintf_s(pOBJFile, L"mtllib minecraftMats.mtl\n");
		std::wstring mtlOutput = outputPath + L"/minecraftMats.mtl";
		FILE* pMTLFile = nullptr;
		_wfopen_s(&pMTLFile, mtlOutput.c_str(), L"w+,ccs=UTF-8");

		if (pMTLFile != nullptr)
		{
			fwprintf_s(pMTLFile, L"# 1 dirt material\n");
			fwprintf_s(pMTLFile, L"newmtl Dirt\n");
			fwprintf_s(pMTLFile, L"Kd 0.647 0.165 0.165\n");
			fwprintf_s(pMTLFile, L"Ks 0 0 0\n");

			fwprintf_s(pMTLFile, L"# 2 stone material\n");
			fwprintf_s(pMTLFile, L"newmtl Stone\n");
			fwprintf_s(pMTLFile, L"Kd 0.5 0.5 0.5\n");
			fwprintf_s(pMTLFile, L"Ks 0 0 0\n");

			fwprintf_s(pMTLFile, L"# 3 wood material\n");
			fwprintf_s(pMTLFile, L"newmtl Wood\n");
			fwprintf_s(pMTLFile, L"Kd 0.8 0.4 0.2\n");
			fwprintf_s(pMTLFile, L"Ks 0 0 0\n");

			fwprintf_s(pMTLFile, L"# 4 glass material\n");
			fwprintf_s(pMTLFile, L"newmtl Glass\n");
			fwprintf_s(pMTLFile, L"Kd 1 1 1\n");
			fwprintf_s(pMTLFile, L"Ks 0 0 0\n");
			fwprintf_s(pMTLFile, L"d 0.1\n");
			fwprintf_s(pMTLFile, L"Ni 1.52\n");
		}

		fclose(pMTLFile);
	}

	Cube::CubeType LayerToEnum(const std::string& layer)
	{

		if (layer == "dirt")
		{
			return Cube::CubeType::Dirt;
		}
		if (layer == "wood")
		{
			return Cube::CubeType::Wood;
		}
		if (layer == "stone")
		{
			return Cube::CubeType::Stone;
		}
		if (layer == "glass")
		{
			return Cube::CubeType::Glass;
		}

		return Cube::CubeType::Dirt;
	}

	//Will return the vertices in a vector >> order goes [0]x, [1]y, [2]z, [3]x,...
	std::vector<std::vector<float>> GetJsonVertices(const std::wstring& input)
	{

		std::vector<std::vector<float>> output{};

		if (std::ifstream is{ input })
		{
			using namespace rapidjson;
			IStreamWrapper isw{ is };

			Document scenedoc;
			scenedoc.ParseStream(isw);


			if (scenedoc.IsArray())
			{
				for (Value::ConstValueIterator itr = scenedoc.Begin();
					itr != scenedoc.End(); ++itr)
				{
					const Value& cubeVal = *itr;

					const Value& layerPositions = cubeVal["positions"];

					if (layerPositions.IsArray())
					{
						for (Value::ConstValueIterator layerItr = layerPositions.Begin();
							layerItr != layerPositions.End(); ++layerItr)
						{
							const Value& posVal = *layerItr;
							if (posVal.IsArray())
							{

								output.push_back({ posVal[0].GetFloat() , posVal[2].GetFloat(), posVal[1].GetFloat() });
							}
						}
					}
				}
			}

		}

		return output;
	}

	int ConvertJSON(const std::wstring& input, const std::wstring& output)
	{


		if (std::ifstream is{ input })
		{
			using namespace rapidjson;
			IStreamWrapper isw{ is };

			Document scenedoc;
			scenedoc.ParseStream(isw);

			if (scenedoc.IsArray())
			{
				if (!std::filesystem::exists(output)) {
					std::filesystem::create_directory(output);
				}

				auto actualOututPath = output + L"/scene.obj";
				FILE* pOFile = nullptr;
				_wfopen_s(&pOFile, actualOututPath.c_str(), L"w+,ccs=UTF-8");

				if (pOFile != nullptr)
				{

					int cubeIdx{ 0 };
					// it was possible to create the file for writing.
					const wchar_t* text = L"#∂ is the symbol for partial derivative.\n";
					fwrite(text, wcslen(text) * sizeof(wchar_t), 1, pOFile);
					WriteMTLFile(pOFile, output);
					WriteVertexNormals(pOFile);

					for (Value::ConstValueIterator itr = scenedoc.Begin();
						itr != scenedoc.End(); ++itr)
					{
						Cube cube{};
						const Value& cubeVal = *itr;
						const Value& cubeType = cubeVal["layer"];
						const Value& cubeOpaqueness = cubeVal["opaque"];

						std::string labelString = cubeType.GetString();
						cube.type = LayerToEnum(labelString);

						cube.isOpaque = cubeOpaqueness.GetBool();

						WriteMaterial(pOFile, cube.type);

						const Value& layerPositions = cubeVal["positions"];

						if (layerPositions.IsArray())
						{
							for (Value::ConstValueIterator layerItr = layerPositions.Begin();
								layerItr != layerPositions.End(); ++layerItr)
							{
								const Value& posVal = *layerItr;
								if (posVal.IsArray())
								{
									cube.position[0] = posVal[0].GetFloat();
									cube.position[1] = posVal[2].GetFloat();
									cube.position[2] = posVal[1].GetFloat();
									WriteCube(cube.position[0], cube.position[1], cube.position[2], pOFile, cubeIdx);
								}

								++cubeIdx;
							}
						}
					}

					fclose(pOFile);
					return 0;
				}
				else
				{
					return -1;
				}
			}
			else
			{
				return -1;
			}

		}
		else
		{
			return -1;
		}
	}


}