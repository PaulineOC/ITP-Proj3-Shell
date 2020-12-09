
function serialSetup(serial){
    serial.on('connected', serverConnected); // callback for connecting to the server
    serial.on('open', portOpen);        // callback for the port opening
    serial.on('data', serialEvent);     // callback for when new data arrives
    serial.on('error', serialError);    // callback for errors
    serial.on('close', portClose);      // callback for the port closing
    serial.open(portName);              // open a serial port
}

function serialEvent() {
    var inString = serial.readStringUntil('\r\n');
    console.log('initial input from arduino:', inString);

    if (inString.length > 0 && Object.keys(songIdxToColors).includes(inString)) {
        console.log('here is ind:', songIdxToColors[inString]);
        console.log(allSounds[songIdxToColors[inString]]);

        currSound = allSounds[songIdxToColors[inString]];

        if(prevSound !== currSound){
            console.log('playing new sound');
            if(prevSound){
                prevSound.stop();
            }
            currSound.play();
        }
        prevSound = currSound;
    }
}

function serverConnected() {
    console.log('connected to server.');
}

function serialError(err) {
    console.log('Something went wrong with the serial port. ' + err);
}

function portOpen() {
    console.log('the serial port opened.')
}

function portClose() {
    console.log('The serial port closed.');
}
