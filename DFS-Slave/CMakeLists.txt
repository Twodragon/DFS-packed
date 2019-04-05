cmake_minimum_required(VERSION 3.6)
project(DFS_slave)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(Boost_USE_STATIC_LIBS        OFF) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost 1.65.1 COMPONENTS thread filesystem system date_time REQUIRED)
if(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    #include_directories(${Boost_INCLUDE_DIRS})


    #target_link_libraries(DFS ${Boost_FILESYSTEM_LIBRARY} ${Boost_LIBRARIES})
endif(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

add_executable(DFS_slave slave_fs/superblock.h slave_fs/FileSystem.h slave_fs/FileSystem.c slave_fs/superblock.c slave_fs/block.h slave_fs/block.c Slave_Server/main_slave_server.cpp Slave_Server/Slave_Server.cpp Slave_Server/Slave_Server.h Slave_Server/main_slave_server.cpp utils/Server_Message.h utils/Server_Message.cpp Base_Classes/Server.h Base_Classes/Server_Group.cpp Base_Classes/Server_Group.h Slave_Server/Slave_FS_Handler.cpp Slave_Server/Slave_FS_Handler.h)

TARGET_LINK_LIBRARIES(DFS_slave ${USED_LIBS} -lpthread -lm)




