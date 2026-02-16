// Tap-hold config
#define HOLD_ON_OTHER_KEY_PRESS

// Split config
#define SERIAL_USART_FULL_DUPLEX // Enable full duplex
#define SERIAL_USART_TX_PIN GP0  // RGB pin repurposed for full duplex serial
#define SERIAL_USART_RX_PIN GP1  // Serial pin on audio jack repurposed for full duplex
#define SPLIT_USB_DETECT       // Master is whichever half has USB connected
#define SPLIT_HAND_PIN GP20    // LOW/GND = left half, HIGH/floating = right half
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

// Unicode input modes: Linux and MacOS
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_MACOS
