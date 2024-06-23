{
  'targets': [
    {
      'target_name': 'happy-eyeballs',
      'type': 'static_library',
      'dependencies': [
        '../util/util.gyp:util',
      ],
      'sources': [
        'happy-eyeballs.c'
      ],
      'include_dirs': [
        '../util'
      ]
    },
  ],
}