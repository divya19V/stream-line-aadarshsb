#include "GenerateParameters.h"
#include <stdio.h>
#include <stdlib.h>

const unsigned int BufferSizePerSession = 50U;
const unsigned int UpperBoundaryVoltage = 43U, LowerBoundaryVoltage = 29U;
const unsigned int UpperBoundaryCurrent = 100U;

static tyBatteryParams_t BattParamBuffer[BufferSizePerSession] = {0};
tyBatteryParams_t const * BattParamPointer = BattParamBuffer;

void GenerateRandParams(void)
{
  for(unsigned char ArrIndex = 0U; ArrIndex < BufferSizePerSession; ++ArrIndex)
  {
    BattParamPointer[ArrIndex] -> BattVoltage = \
      (float)((rand() % (UpperBoundaryVoltage - LowerBoundaryVoltage + 1)) + LowerBoundaryVoltage)/10.0f;
    
    BattParamPointer[ArrIndex] -> BattVoltage = (float)(rand() % UpperBoundaryVoltage)/10.0f;
  }
}

void GetSensorParamsFromFile(void)
{
  FILE* fp = fopen("SensorDataFile.txt","r");
  if(fp != NULL)
  {
    char TempBuffer[20];
    for(unsigned char Index = 0U; ((Index < BufferSizePerSession) || (!feof(fp))) ; ++Index)
    {
      fgets(TempBuffer,20,fp);
      BattParamPointer[Index] -> BattVoltage = (float)atof(TempBuffer);
      fgets(TempBuffer,20,fp);
      BattParamPointer[Index] -> BattCurrent = (float)atof(TempBuffer);
      fgets(TempBuffer,20,fp);
    }
  }
  else
  {
    printf("Unable to Open the file,check if the file exist \n");
  }
}

tyBatteryParams_t* GetSensorArrayParameters(void)
{
  return BattParamPointer;
}
