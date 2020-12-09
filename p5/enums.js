

const songIdxToColors = {
  'BLUE': 0,
  'ORANGE': 1,
  'BLACK': 2,
};

const allSounds = [];

const songNames = [
    'beach-12',
    'rainforest-10',
    '1911-NYC-5',
];

const locationDetails = {
    'INSTRUCTIONS':{
        bgColor: '#000',
        prompt: `Scan a seashell to hear where it's been`,
        prompt2: 'Come listen to a new place far away',
    },
    'BEACH': {
        bgColor: '#70C6FF',
        prompt: 'The Maldives',
    },
    'RAINFOREST': {
        bgColor: '#FFAC70',
        // bgColor: '#70ffc1',
        prompt: 'The Amazon',
    },
    'City': {
        bgColor: '#ABABC4',
        prompt: 'New York City, 1911',
    },
};
