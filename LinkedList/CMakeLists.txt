project(LinkedList)

add_executable(${PROJECT_NAME}
        double_linked_list.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2})
