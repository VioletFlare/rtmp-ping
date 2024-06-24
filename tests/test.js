const RTMPPing = require('../src/rtmp-ping');

const RTMPUrl = 'rtmps://mil02.contribute.live-video.net/app';

RTMPPing.getPingMS(RTMPUrl).then(ping => console.log('Ping in ms: ', ping));

RTMPPing.getPingUS(RTMPUrl).then(ping => console.log('Ping in us: ', ping));