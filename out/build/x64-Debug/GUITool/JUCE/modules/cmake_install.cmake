# Install script for directory: D:/TD/Project-CPP/GUITool/JUCE/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/TD/Project-CPP/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_analytics")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_basics")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_devices")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_formats")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_plugin_client")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_processors")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_audio_utils")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_box2d")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_core")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_cryptography")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_data_structures")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_dsp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_events")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_graphics")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_gui_basics")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_gui_extra")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_opengl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_osc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_product_unlocking")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/JUCE-7.0.2/modules" TYPE DIRECTORY FILES "D:/TD/Project-CPP/GUITool/JUCE/modules/juce_video")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/TD/Project-CPP/out/build/x64-Debug/GUITool/JUCE/modules/juce_audio_plugin_client/cmake_install.cmake")
endif()

