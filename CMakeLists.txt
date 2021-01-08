cmake_minimum_required(VERSION 3.0.2)
project(mqtt_router)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

#target_link_libraries(mqtt_pub_node ${catkin_LIBRARIES} ${Mosquitto_libs})

#find_package(mosquitto REQUIRED)
set(MOSQUITTOPP_INCLUDE_DIR
  /usr/lib/include
)

add_service_files(
  FILES
  Switch.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES mqtt_router
  CATKIN_DEPENDS message_runtime std_msgs roscpp
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${MOSQUITTOPP_INCLUDE_DIR}
)


add_executable(${PROJECT_NAME}_sub src/subscriber_node.cpp
                                   src/subscriber.cpp)


add_executable(${PROJECT_NAME}_pub src/publisher_node.cpp
                                   src/publisher.cpp)


## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above

add_dependencies(${PROJECT_NAME}_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(${PROJECT_NAME}_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


## Specify libraries to link a library or executable target against
set(Mosquitto_libs
  /usr/lib/x86_64-linux-gnu/libmosquittopp.so
  /usr/lib/x86_64-linux-gnu/libmosquitto.so
  /usr/lib/x86_64-linux-gnu/libmosquitto.so.1
)


target_link_libraries(${PROJECT_NAME}_sub
  ${catkin_LIBRARIES}
  ${MOSQUITTOPP_LIBRARIES}
  ${Mosquitto_libs}
)

target_link_libraries(${PROJECT_NAME}_pub
  ${catkin_LIBRARIES}
  ${MOSQUITTOPP_LIBRARIES}
  ${Mosquitto_libs}
)



#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

install(TARGETS mqtt_router_pub RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS mqtt_router_sub RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_mqtt_test.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
