cmake_minimum_required(VERSION 3.12)

option(SUBDIRECTORY "Use clownaudio as a subdirectory, instead of an external package" OFF)

project(orgterm LANGUAGES C CXX)

add_executable(orgterm
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

set_target_properties(orgterm PROPERTIES
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
	target_link_libraries(orgterm PRIVATE m tinfo PRIVATE m)
endif()

check_library_exists(m pow "" LIBNCURSES)
if(LIBNCURSES)
	target_link_libraries(orgterm PRIVATE ncurses tinfo PRIVATE ncurses)
endif()

check_library_exists(pthread pthread_create "" LIBPTHREAD)
if(LIBPTHREAD)
	target_link_libraries(orgterm PRIVATE pthread)
endif()

target_link_libraries(orgterm PRIVATE ${CMAKE_DL_LIBS})

if(MSVC)
	target_compile_definitions(orgterm PRIVATE _CRT_SECURE_NO_WARNINGS)	# Shut up those stupid warnings
endif()


include(GNUInstallDirs)

# Install directories
install(TARGETS orgterm
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)
