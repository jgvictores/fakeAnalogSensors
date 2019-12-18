# Copyright: (C) 2019 Universidad Carlos III de Madrid
# Author: Juan G. Victores

yarp_prepare_plugin(fakeAnalogSensors
                    CATEGORY device
                    TYPE roboticslab::FakeAnalogSensors
                    INCLUDE fakeAnalogSensors.hpp
                    DEFAULT ON
                    EXTRA_CONFIG WRAPPER=multipleanalogsensorsserver)

if(NOT SKIP_fakeAnalogSensors)

    set(CMAKE_INCLUDE_CURRENT_DIR TRUE) # yarp plugin builder needs this

    yarp_add_plugin(fakeAnalogSensors fakeAnalogSensors.hpp
                                      DeviceDriverImpl.cpp
                                      ISixAxisForceTorqueSensorsImpl.cpp)

    target_link_libraries(fakeAnalogSensors YARP::YARP_os
                                            YARP::YARP_dev)

    yarp_install(TARGETS fakeAnalogSensors
                 LIBRARY DESTINATION ${FAKE-ANALOG-SENSORS_DYNAMIC_PLUGINS_INSTALL_DIR}
                 ARCHIVE DESTINATION ${FAKE-ANALOG-SENSORS_STATIC_PLUGINS_INSTALL_DIR}
                 YARP_INI DESTINATION ${FAKE-ANALOG-SENSORS_PLUGIN_MANIFESTS_INSTALL_DIR})

endif()
