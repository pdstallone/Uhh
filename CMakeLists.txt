add_executable(UhhServer main.c cryptography.cpp FreeSpeech-cpp/crypto.cpp FreeSpeech-cpp/cppext/cppext.cpp FreeSpeech-cpp/GlobalGrid.cpp FreeSpeech-cpp/database.cpp FreeSpeech-cpp/sqlite3.c)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
target_link_libraries(UhhServer pthread dl rt crypto ssl)
