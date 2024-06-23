var ping = require('bindings')('ping.node')

module.exports = {
    ping: ping.ping
}