#ifndef HDMI_CEC_HAL_H
#define HDMI_CEC_HAL_H

class HDMICecHal {
public:
    virtual ~HDMICecHal() = default;
    virtual bool HdmiCecOpen() = 0;
};

#endif // HDMI_CEC_HAL_H
