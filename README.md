## About

The idea behind the package was to measure connection speed between a client and a RTMP server, where the server doesn't respond to traditional IP ping.
This package wraps librtmp, a C library in a convenient way, making it possible to see how much time it takes for a rtmp connection to be made.

Since it uses librtmp you can use all the protocols supported by librtmp.

That is:

  "RTMP",
  "RTMPT",
  "RTMPE",
  "RTMPTE",
  "RTMPS",
  "RTMPTS",
  "RTMFP"

# Usage

```
const RTMPPing = require('rtmp-ping');

// Get ping in milliseconds where RTMPUrl is the rtmp:// url to the resource.

RTMPPing.getPingMS(RTMPUrl)

// Get ping in microseconds.

RTMPPing.getPingUS(RTMPUrl)
```

Example:

```
RTMPPing.getPingMS(RTMPUrl).then(pingms => {
    console.log('Ping in millis: ', pingms)
})
```

## More in depth stuff

Since it uses C under the hood, you might miss some dependencies in order to build it.
Here are some tips to build it on different linux distros:

# Building 

(Debian)

```
$ sudo apt install build-essentials libssl-dev python3
```

(Alpine)

```
$ apk add  build-base openssl-dev python3
```

# Dev

To debug the code in vscodium or vscode, install

https://github.com/vadimcn/codelldb

and then run

"Launch Test" 

from Run And Debug menu.