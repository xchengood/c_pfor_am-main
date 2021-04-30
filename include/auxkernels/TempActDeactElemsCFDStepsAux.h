// Nicolò Grilli
// 3 Gennaio 2021
// National University of Singapore

#pragma once

#include "AuxKernel.h"
#include "LaserTempReadFile.h"

// Read temperature due to laser scan during SLM from CFD simulation
// Temperature is changed only every CFD time step for phase transformation
// Therefore, no linear interpolation in time

// Forward declarations

class TempActDeactElemsCFDStepsAux : public AuxKernel
{
public:
  static InputParameters validParams();

  TempActDeactElemsCFDStepsAux(const InputParameters & parameters);
  virtual ~TempActDeactElemsCFDStepsAux() {}

protected:

  /// Base name of the material system used to calculate the temperature
  const std::string _base_name;
  
  /// The LaserTempReadFile GeneralUserObject to read element specific temperature values from file
  const LaserTempReadFile * const _temperature_read_user_object;
  
  /// Time interval between two temperature data field
  const Real _temperature_time_step;

  const Real _melting_temperature_high;
  const Real _melting_temperature_low;
  const Real _gas_temperature_high;
  const Real _gas_temperature_low;
  
  bool _deact_temp_next;

  virtual Real computeValue();

};
