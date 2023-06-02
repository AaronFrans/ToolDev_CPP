# common code subdir
# lib-> no exe
# header only lib 

add_library(JSONReader "FileReader.h" "FileReader.cpp")

set(JSONReaderIncludeDir 
    "${CMAKE_CURRENT_SOURCE_DIR}" 
    PARENT_SCOPE)