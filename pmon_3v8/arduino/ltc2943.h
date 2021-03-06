// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LTC2943_H
#define LTC2943_H

#include "avr_util.h"

// Linear Technology LTC2942 Fuel Gauge IC driver.
namespace ltc2943 {

// Called once from main setup(). Also setup I2C.
extern void setup();

// Called once after setup and possibly more after an error. Reinitialize the device
// as needed. Returns true if ok.
extern bool init();

// Returns true if ok. Takes about 200us with 400Khz I2C clock.
extern boolean readAccumCharge(uint16* value);

// Returns true if ok. Requires non null raw_register_value and voltage_mv.
// This reads the voltage at the (-) side of the shunt resistor. The LTC2943 is 
// initialized to perform continuous a/d conversion and this function just returns
// the current reading in the voltage register.
extern boolean readVoltage(uint16* raw_register_value, uint16* voltage_mv);

}  // namespace ltc2943

#endif  


