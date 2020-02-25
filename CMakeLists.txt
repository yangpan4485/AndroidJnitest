add_library(verify
        ./verify_callback.cpp
        ./verify_test.cpp
        ./verify_class.cpp
        )

# INSTALL(FILES ${HEADERS} DESTINATION ${os_name}/include)

INSTALL(TARGETS verify DESTINATION ${os_name}/lib/${LOCAL_PLATFROM})
INSTALL(FILES ${CMAKE_SOURCE_DIR}/src/verify_callback.h DESTINATION ${os_name}/include/verify)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/src/verify_test.h DESTINATION ${os_name}/include/verify)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/src/verify_class.h DESTINATION ${os_name}/include/verify)
if(MSVC)
    INSTALL(FILES ${PROJECT_BINARY_DIR}/src/Debug/verify.pdb
        DESTINATION ${os_name}/lib/${LOCAL_PLATFROM}
        CONFIGURATIONS Debug)
endif()

