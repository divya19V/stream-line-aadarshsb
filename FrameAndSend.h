#ifndef FRAMEANDSEND_H
#define FRAMEANDSEND_H

#include "GenerateParameters.h"
#include <stdio.h>

void TransmitDataToConsole(void);

void ChangeTheGetParamType(void (*GetTypeFunction)());
float GetVoltageOfElement(const unsigned int ArrayElement);
float GetCurrentOfElement(const unsigned int ArrayElement);

#endif
