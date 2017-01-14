#include "generic.h"

#ifdef __cplusplus
  extern "C"{
#endif

void AIR_GENERIC_Init()
{

}

void AIR_GENERIC_UDelay(unsigned int microSeconds)
{
	delayMicroseconds(microSeconds);
}

#ifdef __cplusplus
  }
#endif

