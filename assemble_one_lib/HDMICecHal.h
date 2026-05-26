#ifndef HDMI_CEC_HAL_H
#define HDMI_CEC_HAL_H

class HDMICecHal {
public:
    virtual ~HDMICecHal() = default;
    bool HdmiCecOpen();
};

#endif // HDMI_CEC_HAL_H
