# AVR_MIDI
Playing around with AVR GCC to communicate with MIDI

Made a class that handles the setting of the UART registers into 8N1 in compliance with MIDI, 
and a send function where you pass the NoteOn+Channel byte, Note Value byte, and Velocity Byte.

To-do list:
Change MIDI class so it checks setbaud results and sets up serial accordingly.
