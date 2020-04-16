REM Script to flash the i2c slave

avrdude -c arduino -P COM3 -p m328p -D -U fl:w:slave_receiver.hex:i
