#include "common/mavlink.h"
#include <Arduino.h>

#define SERIAL_BAUD 115200       // MAVLink communication baud rate
#define SYSTEM_ID 1              // MAVLink system ID (unique identifier for the ESP32)
#define COMPONENT_ID 1           // MAVLink component ID
#define MAV_TYPE MAV_TYPE_ROCKET // MAVType

mavlink_message_t msg;

void setup()
{
  // Initialize serial communication
  Serial.begin(SERIAL_BAUD); // MAVLink communication
}

void loop()
{
  // Define a heartbeat message
  mavlink_message_t msg;
  uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

  // Pack the heartbeat message
  mavlink_msg_heartbeat_pack(
      SYSTEM_ID,             // System ID
      COMPONENT_ID,          // Component ID
      &msg,                  // MAVLink message
      MAV_TYPE,              // Type of MAV
      MAV_AUTOPILOT_GENERIC, // Autopilot type
      MAV_MODE_PREFLIGHT,    // MAVLink mode (set to preflight)
      0,                     // Custom mode (not used here)
      MAV_STATE_STANDBY      // MAVLink state
  );

  // Serialize the MAVLink message to the buffer
  uint16_t len = mavlink_msg_to_send_buffer(buffer, &msg);

  // Send the serialized message over serial
  Serial.write(buffer, len);

  // Send heartbeat every second
  delay(1000);
}