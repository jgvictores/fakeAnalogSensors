// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "fakeAnalogSensors.hpp"

#include <yarp/os/LogStream.h>

namespace roboticslab
{

const int FakeAnalogSensors::DEFAULT_NUM_FT_SENSORS = 4;

// ------------------- DeviceDriver Related ------------------------------------

bool FakeAnalogSensors::open(yarp::os::Searchable& config)
{
    yInfo() << "config:" << config.toString() << "\n";

    numFtSensors = DEFAULT_NUM_FT_SENSORS;
    if(config.check("numFtSensors", "number of FT sensors"))
    {
        numFtSensors = config.find("numFtSensors").asInt();
    }

    startTime = yarp::os::Time::now();

    return true;
}

// -----------------------------------------------------------------------------

bool FakeAnalogSensors::close()
{
    yInfo() << "close:\n";
    return true;
}

// -----------------------------------------------------------------------------

}  // namespace roboticslab
