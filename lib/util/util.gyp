{
  'targets': [
    {
      'target_name': 'util',
      'type': 'static_library',
      'sources': [
        'base,c',
        'bmem.c',
        'dstr.c',
        'platform.c',
        'threading-posix.c',
        'utf8.c',
      ],
    },
  ],
}