cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (TemperatureController
	VERSION 0.1
	DESCRIPTION "A Temperature Controller Project")
	
add_subdirectory(mainProject)
add_subdirectory(Tests)
add_subdirectory(googletest)