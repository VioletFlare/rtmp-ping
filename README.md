# Usage

```
const RTMPPing = require('../src/rtmp-ping');
```

```
// Get ping in milliseconds where RTMPUrl is the rtmp:// url to the resource.

RTMPPing.getPingMS(RTMPUrl)

// Get ping in microseconds.

RTMPPing.getPingUS(RTMPUrl)
```

# Building (Debian)

```
$ sudo apt install build-essentials libssl-dev
$ npm i 
```

# Dev

To debug the code in vscodium or vscode, install

https://github.com/vadimcn/codelldb

and then run

"Launch Test" 

from Run And Debug menu.