/*************************************************************
    Dual Digital Pot(100K)
     <https://www.dfrobot.com/wiki/index.php/Dual_Digital_Pot_(100K)_SKU:_DFR0520>
 *************************************************************
   This example generates two triangular waves to demonstrate
   the basic usage of dual digital pot.

   Created 2017-8-31
   By Henry Zhao <Henry.zhao@dfrobot.com>

   GNU Lesser Genral Public License.
   See <http://ww.gnu.org/licenses/> for details.
   All above must be included in any redistribution.
 ************************************************************/

/***********************Circuit Connections*******************
      Digital Pot  |   Arduino UNO R3    |   Oscilloscope
          CS       |     D10 (SS)        |
          SI       |     D11 (MOSI)      |
          CLK      |     D13 (SCK)       |
      VCC,PA0,PA1  |       VCC           |
      GND,PB0,PB1  |       GND           |     CH1- CH2-
          W0       |                     |       CH1+
          W1       |                     |       CH2+
 ************************************************************/

/***********************Notice********************************
   1.Resistor terminals A, B and W have no restrictions on
     polarity with respect to each other.
   2.Current through terminals A, B and W should not excceed ±1mA.
   3.Voltages on terminals A, B and W should be within 0 - VCC.
************************************************************/

#include <SPI.h>

/***********************PIN Definitions*************************/
// set pin 4 as the slave select (SS) for the digital pot:
// for using the SD SPI interface of Gravity IO Expansion Shield for Arduino V7.1
//const int CS_PIN = 4;

// set pin 10 as the slave select (SS) for the digital pot
// for using Arduino UNO
const int CS_PIN = 10;

/***********************MCP42XXX Commands************************/
//potentiometer select byte
const int POT0_SEL = 0x11;
const int POT1_SEL = 0x12;
const int BOTH_POT_SEL = 0x13;

//shutdown the device to put it into power-saving mode.
//In this mode, terminal A is open-circuited and the B and W terminals are shorted together.
//send new command and value to exit shutdowm mode.
const int POT0_SHUTDOWN = 0x21;
const int POT1_SHUTDOWN = 0x22;
const int BOTH_POT_SHUTDOWN = 0x23;

/***********************Customized Varialbes**********************/
//resistance value byte (0 - 255)
//The wiper is reset to the mid-scale position upon power-up, i.e. POT0_Dn = POT1_Dn = 128
int POT0_Dn = 128;
int POT1_Dn = 128;
int BOTH_POT_Dn = 128;

//Function Declaration
void DigitalPotTransfer(int cmd, int value);     //send the command and the wiper value through SPI

void setup()
{
  Serial.begin(115200);
  pinMode(CS_PIN, OUTPUT);   // set the CS_PIN as an output:
  SPI.begin();     // initialize SPI:
}

void loop()
{
      // change the resistance on the POT0 from min to max:
    for (int POT_Dn = 0; POT_Dn < 256; POT_Dn++) {
      DigitalPotWrite(POT0_SEL, POT_Dn);
      delay(20);
    }

    // change the resistance on the POT0 from max to min:
    for (int POT_Dn = 0; POT_Dn < 256; POT_Dn++) {
      DigitalPotWrite(POT0_SEL , 255 - POT_Dn);
      delay(20);
    }
}

void DigitalPotWrite(int cmd, int val)
{
  // constrain input value within 0 - 255
  val = constrain(val, 0, 255);
  // set the CS pin to low to select the chip:
  digitalWrite(CS_PIN, LOW);
  // send the command and value via SPI:
  SPI.transfer(cmd);
  SPI.transfer(val);
  // Set the CS pin high to execute the command:
  digitalWrite(CS_PIN, HIGH);
}
