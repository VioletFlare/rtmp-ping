{
  'targets': [
    {
      'target_name': 'librtmp',
      'type': 'static_library',
      'dependencies': [
        '../happy-eyeballs/happy-eyeballs.gyp:happy-eyeballs',
      ],
      'sources': [
        'amf.c',
        'cencode.c',
        'hashswf.c',
        'log.c',
        'md5.c',
        'parseurl.c',
        'rtmp.c'
      ],
      'include_dirs': [
        '../happy-eyeballs'
      ]
    },
  ],
}