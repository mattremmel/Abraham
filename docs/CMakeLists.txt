################################################################
# Doxygen
###############

option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)

if (DOXYGEN_FOUND)

    set(DOXYFILE_IN Doxyfile.in)
    set(DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYFILE_IN} ${DOXYFILE} @ONLY)
    message("Doxygen build started")

    add_custom_target(${DOCS_TARGET} ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

else (DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)