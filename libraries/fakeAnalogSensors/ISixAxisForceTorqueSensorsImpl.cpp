// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "fakeAnalogSensors.hpp"

namespace roboticslab
{

// ------------------ ISixAxisForceTorqueSensors Related ----------------------------------------

size_t FakeAnalogSensors::getNrOfSixAxisForceTorqueSensors() const
{
    return numFtSensors;
}

// ----------------------------------------------------------------------------

yarp::dev::MAS_status FakeAnalogSensors::getSixAxisForceTorqueSensorStatus(size_t sens_index) const
{
    return yarp::dev::MAS_OK;
}

// ----------------------------------------------------------------------------

bool FakeAnalogSensors::getSixAxisForceTorqueSensorName(size_t sens_index, std::string &name) const
{
    name = "ft_sensor_" + std::to_string(sens_index);;
    return true;
}

// ----------------------------------------------------------------------------

bool FakeAnalogSensors::getSixAxisForceTorqueSensorFrameName(size_t sens_index, std::string &frameName) const
{
    frameName = "ft_sensor_frame_" + std::to_string(sens_index);;
    return true;
}

// ----------------------------------------------------------------------------

bool FakeAnalogSensors::getSixAxisForceTorqueSensorMeasure(size_t sens_index, yarp::sig::Vector& out, double& timestamp) const
{
    double diff = yarp::os::Time::now() - startTime;
    double mult = sens_index + 1;

    out[0] = diff * mult;
    out[1] = diff * mult;
    out[2] = diff * mult;
    out[3] = diff * mult;
    out[4] = diff * mult;
    out[5] = diff * mult;
    return true;
}

// ----------------------------------------------------------------------------

}
