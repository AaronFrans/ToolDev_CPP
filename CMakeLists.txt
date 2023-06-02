#root of project
cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AssignmentProject)

message("Include lib: JSONReader")
add_subdirectory(JSONReader)




message("Include exe: GUITool")
add_subdirectory(GUITool)

message("Setting up include dirs : GUITool")
target_include_directories(
    MyJUCEApp PUBLIC
    "${JSONReaderIncludeDir}"
)


message("Setting up linking : GUITool")
target_link_libraries(
    MyJUCEApp PUBLIC JSONReader
)



message("Include exe: ConsoleTool")
add_subdirectory(ConsoleTool)


message("Setting up include dirs : ConsoleTool")
target_include_directories(
    ConsoleTool PUBLIC
    "${JSONReaderIncludeDir}"
)


message("Setting up linking : ConsoleTool")
target_link_libraries(
    ConsoleTool PUBLIC JSONReader
)