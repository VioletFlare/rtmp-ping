{
  "targets": [
    {
      'dependencies': [
        'lib/librtmp/librtmp.gyp:librtmp',
      ],
      "target_name": "ping",
      "sources": [ 
        "src/ping.c" 
      ],
      'include_dirs': [
        "<!(node -e \"require('node-api-headers')\")/include",
        'lib/librtmp'
      ]
    }
  ],
}