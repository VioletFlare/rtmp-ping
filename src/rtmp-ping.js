var ping = require('bindings')('ping.node')

class RTMPPing {

    getPingUS(url) {
        return Number(ping.ping(url));
    }

    getPingMS(url) {
        return (Number(ping.ping(url)) / 1000)
    }

}

module.exports = new RTMPPing();