// Tap-hold config
#define HOLD_ON_OTHER_KEY_PRESS

// Split config
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex
#define SERIAL_USART_TX_PIN D2     // The original half-duplex pin going to aux connector on the splinktegrated
#define SERIAL_USART_RX_PIN D3     // Originally used for RGB on splinktegrated, but I repurposed it for full duplex (jumper to aux)

// Unicode input modes: Linux and MacOS
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_MACOS
