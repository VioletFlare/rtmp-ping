var ping = require('bindings')('ping.node')

class RTMPPing {

    getPingUS(url) {
        return new Promise(resolve => resolve(Number(ping.ping(url))));
    }

    getPingMS(url) {
        return new Promise(resolve => resolve((Number(ping.ping(url)) / 1000)))
    }

}

module.exports = new RTMPPing();