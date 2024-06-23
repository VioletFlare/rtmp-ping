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
        'lib/librtmp'
      ]
    }
  ],
}