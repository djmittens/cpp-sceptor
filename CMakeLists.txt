cmake_minimum_required(VERSION 2.6)
project (CppSceptor)

set(CppSceptor_VERSION_MAJOR 1)
set(CppSceptor_VERSION_MINOR 1)


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