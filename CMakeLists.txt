cmake_minimum_required(VERSION 2.6)
project (CppSceptor)

set(CppSceptor_VERSION_MAJOR 1)
set(CppSceptor_VERSION_MINOR 1)

# Check if the system provides log and exp functions
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

# Optional library
option( USE_MYMATH "Use my shitty approximation for square root" ON)


# actually place the version numbers into a header file.
configure_file(
  "${PROJECT_SOURCE_DIR}/CppSceptorConfig.h.in"
  "${PROJECT_BINARY_DIR}/CppSceptorConfig.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

# add the library
if(USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory(MathFunctions)
	# NOOTE here we add MathFunctions to the EXTRA_LIBS list in order to help organize target_link_libraries
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif()

# create the executable by linking some libraries.
add_executable(CppSceptor CppSceptor.cpp)
target_link_libraries (CppSceptor ${EXTRA_LIBS})


install (TARGETS CppSceptor DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/CppSceptorConfig.h" DESTINATION include)

include(CTest)

# does the application run?
add_test (CppSceptorRuns CppSceptor 25)


##### Packaging with CPack step 6

include(InstallRequiredSystemLibraries)

set (CPACK_RESOURCE_FILE LICENSE
	"${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${CppSceptor_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CppSceptor_VERSION_MINOR}")
include (CPack)