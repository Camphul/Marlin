//
// Created by luca on 7/6/20.
//
#pragma once

//===========================================================================
//===============================- GENERAL -=================================
//===========================================================================

#define CUSTOM_CONFIG_H_VERSION 020039
#define C_MACHINE_NAME "Beep boop"
#define C_FILAMENT_DIA 1.75
#define C_NOZZLE_DIAMETER 0.4
#define C_BAUDRATE 115200

//===========================================================================
//============================- LINEAR ADVANCE -=============================
//===========================================================================

#define LIN_ADVANCE_K_POLYMAX_PC 0.43
#define LIN_ADVANCE_K_REAL_PLA 0.55
#define LIN_ADVANCE_K_SET_BY_GCODE 0.0
//Setting linear advance k to 0 allows us to set the k value via m500 in our slicer for specific materials.
#define C_LIN_ADVANCE_K LIN_ADVANCE_K_SET_BY_GCODE

//===========================================================================
//============================ TMC2209 STEPPERS =============================
//===========================================================================

#define CUSTOM_MINIMUM_STEPPER_POST_DIR_DELAY 120//20
#define CUSTOM_MINIMUM_STEPPER_PRE_DIR_DELAY CUSTOM_MINIMUM_STEPPER_PRE_DIR_DELAY
#define CUSTOM_MINIMUM_STEPPER_DIR_DELAY CUSTOM_MINIMUM_STEPPER_PRE_DIR_DELAY

//#define CUSTOM_MINIMUM_STEPPER_PULSE 0
//#define CUSTOM_MAXIMUM_STEPPER_RATE 5000000

//===========================================================================
//================================= BUFFERS =================================
//===========================================================================

#define CUSTOM_BUFFER_SIZE 64
#define CUSTOM_BLOCK_BUFFER_SIZE CUSTOM_BUFFER_SIZE
#define CUSTOM_MAX_CMD_SIZE 96
#define CUSTOM_FLOAT_PRECISION 4

//===========================================================================
//======================== TRINAMIC DRIVERS =================================
//===========================================================================
/**
 * To use TMC2130, TMC2160, TMC2660, TMC5130, TMC5160 stepper drivers in SPI mode
 * connect your SPI pins to the hardware SPI interface on your board and define
 * the required CS pins in your `pins_MYBOARD.h` file. (e.g., RAMPS 1.4 uses AUX3
 * pins `X_CS_PIN 53`, `Y_CS_PIN 49`, etc.).
 * You may also use software SPI if you wish to use general purpose IO pins.
 *
 * To use TMC2208 stepper UART-configurable stepper drivers connect #_SERIAL_TX_PIN
 * to the driver side PDN_UART pin with a 1K resistor.
 * To use the reading capabilities, also connect #_SERIAL_RX_PIN to PDN_UART without
 * a resistor.
 * The drivers can also be used with hardware serial.
 *
 * TMCStepper library is required to use TMC stepper drivers.
 * https://github.com/teemuatlut/TMCStepper
 */
#define C_TMC_XYZ_CURRENT 590//XYZ max rating 840ma
#define C_TMC_E_CURRENT 700//E max rating 1000ma
#define C_TMC_MICROSTEPS 16
#define C_TMC_INTERPOLATE true
#define C_TMC_HOLD_MULTIPLIER 0.5
#define C_TMC_RSENSE 0.11
#define C_TMC_CHAIN_POS -1
/**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 and TMC5160 only
   * The driver will switch to spreadCycle when stepper speed is over HYBRID_THRESHOLD.
   * This mode allows for faster movements at the expense of higher noise levels.
   * STEALTHCHOP_(XY|Z|E) must be enabled to use HYBRID_THRESHOLD.
   * M913 X/Y/Z/E to live tune the setting
   */
#define C_TMC_HYBRID_THRESHOLD_XY 1200
#define C_TMC_HYBRID_THRESHOLD_Z 600
#define C_TMC_HYBRID_THRESHOLD_E 1200

#define C_TMC_STALL_SENSITIVITY_X 60
#define C_TMC_STALL_SENSITIVITY_X2 C_TMC_STALL_SENSITIVITY_X
#define C_TMC_STALL_SENSITIVITY_Y 60
#define C_TMC_STALL_SENSITIVITY_Y2 C_TMC_STALL_SENSITIVITY_Y


//===========================================================================
//================================= MOVEMENT ================================
//===========================================================================

#define C_DEFAULT_AXIS_STEPS_PER_UNIT { 80, 80, 400, 104 }
#define C_DEFAULT_MAX_FEEDRATE          {1200, 1200, 400, 50 }
#define C_DEFAULT_MAX_ACCELERATION      {1200, 1200, 400, 50 }
#define C_MANUAL_FEEDRATE {1400, 1400, 60, 75 }
#define C_DEFAULT_ACCELERATION         540   // X, Y, Z and E acceleration for printing moves
#define C_DEFAULT_RETRACT_ACCELERATION  (C_DEFAULT_ACCELERATION-40)    // E acceleration for retracts
#define C_DEFAULT_TRAVEL_ACCELERATION   C_DEFAULT_ACCELERATION    // X, Y, Z acceleration for travel (non printing) moves
#define C_DEFAULT_EJERK 5.0  // May be used by Linear Advance

//===========================================================================
//================ MOVEMENT/JUNCTION DEVIATION ==============================
//===========================================================================
//wanted jerk
#define C_JD_JERK 8
// JD acceleration to the power of two
#define C_JD_JERK_SQUARED (C_JD_JERK * C_JD_JERK)
#define C_JD_FORMULA (C_NOZZLE_DIAMETER * C_JD_JERK * C_JD_JERK / C_DEFAULT_ACCELERATION)
//Final junction deviation value
#define C_JUNCTION_DEVIATION_MM C_JD_FORMULA

//===========================================================================
//================================= THERMALS ================================
//===========================================================================

#define C_HEATER_MAXTEMP 305
#define C_BED_MAXTEMP 130


//PID settings

//PID settings for 260C
#define C_PID_SETTINGS_260

#ifdef C_PID_SETTINGS_260
    #define C_DEFAULT_Kp 27.7354
    #define C_DEFAULT_Ki 3.1170
    #define C_DEFAULT_Kd 61.6973
#else
    #define C_DEFAULT_Kp 22.69
    #define C_DEFAULT_Ki 2.01
    #define C_DEFAULT_Kd 64.13
#endif

#define C_PIDTEMPBED_SETTINGS_260

#ifdef C_PIDTEMPBED_SETTINGS_260
    #define C_DEFAULT_bedKp 126.63
    #define C_DEFAULT_bedKi 23.57
    #define C_DEFAULT_bedKd 453.64
#else
    #define C_DEFAULT_bedKp 126.63
    #define C_DEFAULT_bedKi 23.57
    #define C_DEFAULT_bedKd 453.64
#endif

// If the temperature difference between the target temperature and the actual temperature
#define C_PID_FUNCTIONAL_RANGE 20

//===========================================================================
//========================== PROBING/HOMING =================================
//===========================================================================


#define C_HOMING_FEEDRATE_XY (60*60)
#define C_HOMING_FEEDRATE_Z (4*60)
//old was -2.355
#define C_NOZZLE_TO_PROBE_OFFSET_X -43
#define C_NOZZLE_TO_PROBE_OFFSET_Y -6
//old was -1.63
//wass -1.455
#define C_PAPER_THICKNESS 0.12
#define C_NOZZLE_TO_PROBE_OFFSET_Z (-1.325+C_PAPER_THICKNESS)//-1.57
#define C_NOZZLE_TO_PROBE_OFFSET {C_NOZZLE_TO_PROBE_OFFSET_X,C_NOZZLE_TO_PROBE_OFFSET_Y,C_NOZZLE_TO_PROBE_OFFSET_Z }
#define C_PROBING_MARGIN 10
#define C_XY_PROBE_SPEED C_HOMING_FEEDRATE_XY
#define C_Z_PROBE_SPEED_FAST C_HOMING_FEEDRATE_Z
#define C_Z_PROBE_SPEED_SLOW_DIVISOR 2

//===========================================================================
//================================= BED SIZE ================================
//===========================================================================

#define C_X_BED_SIZE 235
#define C_Y_BED_SIZE C_X_BED_SIZE
#define C_BED_SIZE_XY C_Y_BED_SIZE
#define C_XY_CENTER (C_BED_SIZE_XY / 2)

//===========================================================================
//======================== UNIFIED BED LEVEL ================================
//===========================================================================

#define C_GRID_POINTS_XY 4
#define C_MESH_INSET (abs(C_NOZZLE_TO_PROBE_OFFSET_X)+1)

//===========================================================================
//======================== G26 MESH LEVELING ================================
//===========================================================================

//#define C_MESH_TEST_POLYMAX_PC 1
//#define C_MESH_TEST_PETG 1
#define C_MESH_TEST_PLA 1

#define C_MESH_TEST_NOZZLE_SIZE    C_NOZZLE_DIAMETER
//nozzle diameter divided by 2
#define C_MESH_TEST_LAYER_HEIGHT   (C_MESH_TEST_NOZZLE_SIZE/2)
#define C_G26_XY_FEEDRATE         20
#define C_G26_RETRACT_MULTIPLIER   1.0
#define C_DEFAULT_MESH_TEST_HOTEND_TEMP  205
#define C_DEFAULT_MESH_TEST_BED_TEMP      45

#if C_MESH_TEST_POLYMAX_PC
    #define C_MESH_TEST_HOTEND_TEMP  265
    #define C_MESH_TEST_BED_TEMP     100
#elif C_MESH_TEST_PETG
    #define C_MESH_TEST_HOTEND_TEMP  240
    #define C_MESH_TEST_BED_TEMP      70
#elif C_MESH_TEST_PLA
    #define C_MESH_TEST_HOTEND_TEMP  205
    #define C_MESH_TEST_BED_TEMP      60
#endif

//if still not defined
#ifndef C_MESH_TEST_HOTEND_TEMP
    #define C_MESH_TEST_HOTEND_TEMP C_DEFAULT_MESH_TEST_HOTEND_TEMP
#endif

//if still not defined
#ifndef C_MESH_TEST_BED_TEMP
    #define C_MESH_TEST_BED_TEMP C_DEFAULT_MESH_TEST_BED_TEMP
#endif


