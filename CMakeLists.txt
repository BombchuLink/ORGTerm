cmake_minimum_required(VERSION 3.12)

option(SUBDIRECTORY "Use clownaudio as a subdirectory, instead of an external package" OFF)

project(orgplayer LANGUAGES C CXX)

add_executable(orgplayer
	"Audio.h"
	"File.cpp"
	"File.h"
	"main.cpp"
	"miniaudio.cpp"
	"miniaudio.h"
	"Organya.cpp"
	"Organya.h"
	"PixTone.cpp"
	"PixTone.h"
	"Random.cpp"
	"Random.h"
	"Sound.cpp"
	"Sound.h"
	"WindowsWrapper.h"
)

set_target_properties(orgplayer PROPERTIES
	C_STANDARD 90
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
	CXX_STANDARD 98
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

include(CheckLibraryExists)

check_library_exists(m pow "" LIBM)
if(LIBM)
	target_link_libraries(orgplayer PRIVATE m tinfo PRIVATE m)
	list(APPEND STATIC_LIBS m)
endif()

check_library_exists(pthread pthread_create "" LIBPTHREAD)
if(LIBPTHREAD)
	target_link_libraries(orgplayer PRIVATE pthread)
	list(APPEND STATIC_LIBS pthread)
endif()

target_link_libraries(orgplayer PRIVATE ${CMAKE_DL_LIBS})

if(MSVC)
	target_compile_definitions(orgplayer PRIVATE _CRT_SECURE_NO_WARNINGS)	# Shut up those stupid warnings
endif()
