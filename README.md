Simple code to take an arduino (code is meant for a pro mini hooked up to a PN532 shield from adafruit) and make it so when a NFC tag is scanned, it will send the UID of the tag over serial in the following formats: FF:FF:FF:FF or 00:00:00:00:00:00:00, depending on UID length.

Written by David Sikes

Compiled on 1.5.2

Library available from adafruit