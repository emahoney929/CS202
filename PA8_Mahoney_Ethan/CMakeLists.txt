cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD=11)
# Necessary to give our project a name of our choice
project(proj8)

# Add subfolder named [include] to the list directories to be 
# considered for #include statements throughout the entire project
include_directories(include)

# Create a variable with the list of source files for DataType
set(MY_DATATYPE_SOURCE src/DataType/DataType.cpp)

# Create a variable with the list of source files for NodeList
set(MY_NODELIST_SOURCE src/NodeList/NodeList.cpp)

# Create a variable with the list of source files for ArrayList
set(MY_ARRAYLIST_SOURCE src/ArrayList/ArrayList.cpp)

# Create a library by compiling these (uses the above created list of sources)
add_library(DataType ${MY_DATATYPE_SOURCE}) 
add_library(NodeList ${MY_NODELIST_SOURCE})
add_library(ArrayList ${MY_ARRAYLIST_SOURCE})

# Rule for creating an executable (by compiling the project source main)
add_executable(proj8 src/proj8.cpp)
# Specify any necessary linking for the above rule, against other libraries 
# either created by this project or externally provided
target_link_libraries(proj8 DataType NodeList ArrayList)

# Specify where to place build products if we also want to do a [make install]
install(TARGETS proj8 DataType NodeList ArrayList
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
# Copy the headers (for people who want to use our libraries) to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
