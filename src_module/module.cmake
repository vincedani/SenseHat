set(MODULE_NAME "src_module")
set(SENSE_HAT_DIR_BUILD "/home/pi/energy-measurement/SenseHat/build")
set(SENSE_HAT_DIR_SRC "/home/pi/energy-measurement/SenseHat/src")

add_subdirectory(${MODULE_DIR}/src/ ${MODULE_BINARY_DIR}/${MODULE_NAME})
link_directories(${MODULE_DIR} ${SENSE_HAT_DIR_BUILD} ${SENSE_HAT_DIR_SRC})
list(APPEND MODULE_LIBS src_binding sense stdc++)
