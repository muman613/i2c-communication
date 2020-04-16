REM Script to flash the i2c master

avrdude -c wiring -P COM11 -p m2560 -D -U fl:w:master_writer.hex:i
