cmake_minimum_required(VERSION 3.6)
project(DFS)


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

add_executable(DFS main.cpp master_fs/superblock.h master_fs/inode.h master_fs/FileSystem.h master_fs/FileSystem.c master_fs/superblock.c master_fs/inode.c master_fs/block.h master_fs/block.c
        utils/Network_utils.h utils/Network_utils.c Master_Server/Master_Server.cpp Master_Server/Master_Server.h utils/Server_Message.cpp utils/Server_Message.h Base_Classes/Inter_Server_Session.cpp Base_Classes/Inter_Server_Session.h Master_Server/Slaves_Group.cpp Master_Server/Slaves_Group.h Base_Classes/Server.h Base_Classes/Server_Group.cpp Base_Classes/Server_Group.h Master_Server/Initializing_ISS.h Master_Server/Clients_Group.cpp Master_Server/Clients_Group.h Master_Server/FS_Handler.cpp Master_Server/FS_Handler.h Master_Server/Initializing_ISS.cpp)

TARGET_LINK_LIBRARIES(DFS ${USED_LIBS})




