cmake_minimum_required(VERSION 2.8.11)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif (DOXYGEN_FOUND)

# add a target to generate HTML files from commonmark files
find_program(PANDOC_EXECUTABLE pandoc)
if (PANDOC_EXECUTABLE)
    set(HTML_DIR ${CMAKE_CURRENT_LIST_DIR}/gh-pages/papers)
    foreach(PAPER p0381 p0381r1 p0381r0 p0037 p0037r3 p0037r2 p0037r1 p0037r0 p0554 p0675)
        set(HTML_FILE ${HTML_DIR}/${PAPER}.html)
        set(COMMONMARK_FILE ${CMAKE_CURRENT_LIST_DIR}/${PAPER}.md)
        add_custom_target(
                "commonmark_${PAPER}" ALL
                COMMAND mkdir -p ${HTML_DIR}
                COMMAND ${PANDOC_EXECUTABLE} ${COMMONMARK_FILE} > ${HTML_FILE}
                DEPENDS ${COMMONMARK_FILE}
        )
    endforeach(PAPER)
endif (PANDOC_EXECUTABLE)
