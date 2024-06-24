const RTMPPing = require('../src/rtmp-ping');

const RTMPUrl = 'rtmps://mil02.contribute.live-video.net/app';

console.log('Ping in ms: ', RTMPPing.getPingMS(RTMPUrl));
console.log('Ping in us: ', RTMPPing.getPingUS(RTMPUrl));