cmake_minimum_required(VERSION 3.12)

project(MyJUCEApp VERSION 1.0.0)
# add the JUCE software as library in the project.
add_subdirectory("JUCE")
# common library add_subdirectory
# add the JuceGUI folder with your own code to the project.
add_subdirectory("JuceGUI")

