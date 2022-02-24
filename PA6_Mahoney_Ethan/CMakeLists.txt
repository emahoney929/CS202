cmake_minimum_required(VERSION 2.8.9)

# Necessary to give our project a name of our choice
project(proj6)

# Add subfolder named [include] to the list directories to be 
# considered for #include statements throughout the entire project
include_directories(include)

# Create a variable with the list of source files for Vehicle
set(MY_VEHICLE_SOURCE src/Vehicle/Vehicle.cpp)
# Create a library by compiling these (uses the above created list of sources)
add_library(Vehicle ${MY_VEHICLE_SOURCE}) 

# Create a variable with the list of sources for Car
set(MY_CAR_SOURCE src/Car/Car.cpp)
# Create a library by compiling these (uses the above created list of sources)
add_library(Car ${MY_CAR_SOURCE})

# Rule for creating an executable (by compiling the project source main)
add_executable(proj6 src/proj6.cpp)
# Specify any necessary linking for the above rule, against other libraries 
# either created by this project or externally provided
target_link_libraries(proj6 Vehicle Car)

# Specify where to place build products if we also want to do a [make install]
install(TARGETS proj6 Vehicle Car
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
# Copy the headers (for people who want to use our libraries) to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
