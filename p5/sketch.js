let serial;
let portName = '/dev/cu.usbmodem14201';  // fill in your serial port name here

let canvas;

let currSound = null;
let prevSound = null;

let beachSound;
let rainforestSound;
let historicalNYCSound;

let mainFont;

function preload() {
    beachSound = loadSound('assets/sounds/beach-12.mp3');
    rainforestSound = loadSound('assets/sounds/rainforest-10.mp3');
    historicalNYCSound = loadSound('assets/sounds/1911-NYC-5.mp3');
    mainFont = loadFont('assets/font/Montserrat-Regular.ttf');
    //mainFont = loadFont('assets/font/museo-550.otf');
}

function setup(){
    allSounds[0] = beachSound;
    allSounds[1] = rainforestSound;
    allSounds[2] = historicalNYCSound;

    canvas = createCanvas(windowWidth, windowHeight);
    serial = new p5.SerialPort();
    serialSetup(serial);
}

function draw() {
    textFont(mainFont);
    textSize(54);
    fill(0);

    let bgColor;
    let prompt;

    switch(currSound){
        case beachSound:
            bgColor = locationDetails.BEACH.bgColor;
            prompt = locationDetails.BEACH.prompt;
            break;
        case rainforestSound:
            bgColor = locationDetails.RAINFOREST.bgColor;
            prompt = locationDetails.RAINFOREST.prompt;
            break;
        case historicalNYCSound:
            bgColor = locationDetails.City.bgColor;
            prompt = locationDetails.City.prompt;
            break;
        case null:
            bgColor = locationDetails.INSTRUCTIONS.bgColor;
            prompt = locationDetails.INSTRUCTIONS.prompt;
            // prompt1 = locationDetails.INSTRUCTIONS.prompt2;
            fill(255);
            break;
    }
    background(bgColor);
    const promptWidth = textWidth(prompt);
    text(prompt, (width/2)-(promptWidth/2), height/2);
}


function keyPressed(){
    if(keyCode === 27 ){
        location.reload();
        return false;
    }
    //UP
    if(keyCode === 38){
        if(currSound) currSound.stop();
        currSound =  allSounds[songIdxToColors['BLUE']];
        currSound.play();
    }
    //DOWN
    if(keyCode === 40){
        if(currSound) currSound.stop();
        currSound =  allSounds[songIdxToColors['ORANGE']];
        currSound.play();
    }
    //LEFT
    if(keyCode === 37){
        if(currSound) currSound.stop();
        currSound =  allSounds[songIdxToColors['BLACK']];
        currSound.play();
    }
}
