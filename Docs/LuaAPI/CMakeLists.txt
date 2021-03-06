
# ---------------------------------------------------------
include(FindDoxygen)
include(FindHHC)

file(GLOB_RECURSE SRC Source/*.inl Source/*.h)

set(OGREKIT_DOC_IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Images)
set(OGREKIT_DOC_IMAGES_DEST ${CMAKE_CURRENT_BINARY_DIR}/html)

set(OGREKIT_DOXYFILE_CPP_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.txt.in)
set(OGREKIT_DOXYFILE_CPP ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.txt)

if (DOXYGEN_FOUND)	
	find_hhc_location()
	
	configure_file(${OGREKIT_DOXYFILE_CPP_IN} ${OGREKIT_DOXYFILE_CPP})
	
	add_custom_target(DocLuaApiManual
		COMMAND ${DOXYGEN_EXECUTABLE} ${OGREKIT_DOXYFILE_CPP}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BUILD_DIR} 
		COMMENT "Building OgreKit Lua Documentation" 
		SOURCES ${SRC}
		)

	add_custom_command(
		TARGET DocLuaApiManual 
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different ${OGREKIT_DOC_IMAGES_DIR}/bg_t.gif		${OGREKIT_DOC_IMAGES_DEST}/bg_t.gif
		COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different ${OGREKIT_DOC_IMAGES_DIR}/top_bg.gif		${OGREKIT_DOC_IMAGES_DEST}/top_bg.gif
		COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different ${OGREKIT_DOC_IMAGES_DIR}/top__sm.gif	${OGREKIT_DOC_IMAGES_DEST}/top__sm.gif
		)
else()
	message("doxygen not found")
endif()
