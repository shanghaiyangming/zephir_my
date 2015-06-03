<?php return array (
  0 => 
  array (
    'type' => 'namespace',
    'name' => 'My\\Utils',
    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
    'line' => 3,
    'char' => 5,
  ),
  1 => 
  array (
    'type' => 'class',
    'name' => 'Lock',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'static',
          ),
          'type' => 'property',
          'name' => '_cache',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 5,
            'char' => 22,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 7,
          'char' => 11,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => '_key',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 7,
            'char' => 22,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 9,
          'char' => 11,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => '_expire',
          'default' => 
          array (
            'type' => 'int',
            'value' => '30',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 9,
            'char' => 25,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 11,
          'char' => 11,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => '_isInstance',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 11,
            'char' => 32,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 13,
          'char' => 11,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => '_isLocked',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 13,
            'char' => 30,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 15,
          'char' => 11,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => '_autoUnLock',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 15,
            'char' => 31,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 17,
          'char' => 7,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 17,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => '_cache',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'connect',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 19,
                    'char' => 37,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 19,
                  'char' => 37,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 20,
              'char' => 5,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_key',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 20,
                    'char' => 23,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 20,
                  'char' => 23,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 21,
              'char' => 5,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_expire',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ini_get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'max_execution_time',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 21,
                          'char' => 51,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 21,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 21,
                    'char' => 52,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 21,
                  'char' => 52,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 22,
              'char' => 2,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => NULL,
            'void' => 1,
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 18,
            'char' => 2,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 17,
          'char' => 16,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'connect',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 26,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_cache',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 26,
                    'char' => 25,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 26,
                  'char' => 25,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 26,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'variable',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'servers',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 27,
                      'char' => 15,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 28,
                  'char' => 6,
                ),
                1 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'variable',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'config',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 28,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 29,
                  'char' => 6,
                ),
                2 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'variable',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'objMemcached',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 29,
                      'char' => 20,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 30,
                  'char' => 8,
                ),
                3 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'array',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'memcachedConfig',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 30,
                        'char' => 30,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 30,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 32,
                  'char' => 6,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'objMemcached',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => '\\Memcached',
                        'dynamic' => 0,
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 32,
                        'char' => 39,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 32,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 33,
                  'char' => 5,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 33,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'MEMCACHED_SERVER',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 33,
                        'char' => 39,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 33,
                      'char' => 41,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 33,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'config',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => '_SERVER',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 34,
                              'char' => 25,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'MEMCACHED_SERVER',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 34,
                              'char' => 44,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 34,
                            'char' => 45,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 34,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 35,
                      'char' => 4,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'config',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'tcp://127.0.0.1:11211/?weight=20',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 36,
                            'char' => 52,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 36,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 37,
                      'char' => 4,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 40,
                  'char' => 6,
                ),
                6 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'servers',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'explode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => ';',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 40,
                              'char' => 29,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 40,
                            'char' => 29,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'config',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 40,
                              'char' => 36,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 40,
                            'char' => 36,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 40,
                        'char' => 37,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 40,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 41,
                  'char' => 6,
                ),
                7 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'variable',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'server',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 41,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 42,
                  'char' => 6,
                ),
                8 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'servers',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 42,
                    'char' => 26,
                  ),
                  'value' => 'server',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'declare',
                      'data-type' => 'variable',
                      'variables' => 
                      array (
                        0 => 
                        array (
                          'variable' => 'arr',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 43,
                          'char' => 12,
                        ),
                        1 => 
                        array (
                          'variable' => 'host',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 43,
                          'char' => 17,
                        ),
                        2 => 
                        array (
                          'variable' => 'port',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 43,
                          'char' => 22,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 44,
                      'char' => 7,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'arr',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'parse_url',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'server',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 44,
                                  'char' => 31,
                                ),
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 44,
                                'char' => 31,
                              ),
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 44,
                            'char' => 32,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 44,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 45,
                      'char' => 7,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'host',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'arr',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 45,
                              'char' => 19,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'host',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 45,
                              'char' => 26,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 45,
                            'char' => 27,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 45,
                          'char' => 27,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 46,
                      'char' => 7,
                    ),
                    3 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'port',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'arr',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 46,
                              'char' => 19,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'port',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 46,
                              'char' => 26,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 46,
                            'char' => 27,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 46,
                          'char' => 27,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 47,
                      'char' => 7,
                    ),
                    4 => 
                    array (
                      'type' => 'declare',
                      'data-type' => 'int',
                      'variables' => 
                      array (
                        0 => 
                        array (
                          'variable' => 'weight',
                          'expr' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 47,
                            'char' => 19,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 47,
                          'char' => 19,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 48,
                      'char' => 9,
                    ),
                    5 => 
                    array (
                      'type' => 'declare',
                      'data-type' => 'array',
                      'variables' => 
                      array (
                        0 => 
                        array (
                          'variable' => 'params',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 48,
                            'char' => 22,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 48,
                          'char' => 22,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 49,
                      'char' => 13,
                    ),
                    6 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'parse_str',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'arr',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 49,
                                'char' => 18,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'query',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 49,
                                'char' => 26,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 49,
                              'char' => 27,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 49,
                            'char' => 27,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 49,
                              'char' => 34,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 49,
                            'char' => 34,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 49,
                        'char' => 35,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 50,
                      'char' => 7,
                    ),
                    7 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'weight',
                          'expr' => 
                          array (
                            'type' => 'ternary',
                            'left' => 
                            array (
                              'type' => 'empty',
                              'left' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'params',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 50,
                                  'char' => 30,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'weight',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 50,
                                  'char' => 39,
                                ),
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 50,
                                'char' => 41,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 50,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 50,
                              'char' => 45,
                            ),
                            'extra' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'intval',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'params',
                                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                      'line' => 50,
                                      'char' => 60,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'weight',
                                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                      'line' => 50,
                                      'char' => 69,
                                    ),
                                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                    'line' => 50,
                                    'char' => 70,
                                  ),
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 50,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 50,
                              'char' => 71,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 50,
                            'char' => 71,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 50,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 51,
                      'char' => 7,
                    ),
                    8 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'memcachedConfig',
                          'expr' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'host',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 52,
                                  'char' => 12,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'host',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 52,
                                  'char' => 17,
                                ),
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 52,
                                'char' => 17,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'port',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 53,
                                  'char' => 12,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'port',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 53,
                                  'char' => 17,
                                ),
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 53,
                                'char' => 17,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'weight',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 54,
                                  'char' => 14,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'weight',
                                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                  'line' => 55,
                                  'char' => 5,
                                ),
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 55,
                                'char' => 5,
                              ),
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 55,
                            'char' => 6,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 55,
                          'char' => 6,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 56,
                      'char' => 4,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 57,
                  'char' => 15,
                ),
                9 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'objMemcached',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 57,
                      'char' => 17,
                    ),
                    'name' => 'addServers',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'memcachedConfig',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 57,
                          'char' => 44,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 57,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 57,
                    'char' => 45,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 58,
                  'char' => 6,
                ),
                10 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'static-property',
                      'operator' => 'assign',
                      'variable' => 'self',
                      'property' => '_cache',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'objMemcached',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 58,
                        'char' => 35,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 58,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 59,
                  'char' => 9,
                ),
                11 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'objMemcached',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 59,
                    'char' => 23,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 60,
                  'char' => 3,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 62,
              'char' => 8,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'static-property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 62,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => '_cache',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 62,
                  'char' => 22,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 62,
                'char' => 22,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 63,
              'char' => 2,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => '\\Memcached',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 25,
                  'char' => 2,
                ),
                'collection' => 0,
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 25,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 25,
            'char' => 2,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 24,
          'char' => 23,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setExpire',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sec',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'int',
                'value' => '5',
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 70,
                'char' => 43,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 70,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_autoUnLock',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 72,
                    'char' => 38,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 72,
                  'char' => 38,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 73,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_expire',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sec',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 73,
                    'char' => 32,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 73,
                  'char' => 32,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 74,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * 设定缓存的强制锁定时间,必须锁定足够时间才能解锁
     *
     * @param number sec            
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => NULL,
            'void' => 1,
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 70,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'lock',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 85,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => '_isInstance',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 85,
                  'char' => 30,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 85,
                'char' => 30,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => '\\Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '每个Lock实例只能lock一次，当一个请求中需要多次锁定时，请分别实例化Lock类',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 86,
                          'char' => 138,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 86,
                        'char' => 138,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 86,
                    'char' => 139,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 87,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 89,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_isInstance',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 89,
                    'char' => 37,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 89,
                  'char' => 37,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 90,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'casToken',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 90,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 90,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'expireTime',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 90,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'now',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 90,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'n',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 90,
                  'char' => 44,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 91,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'casToken',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'microtime',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 91,
                          'char' => 38,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 91,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 91,
                    'char' => 39,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 91,
                  'char' => 39,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 92,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'n',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 92,
                    'char' => 18,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 92,
                  'char' => 18,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 93,
              'char' => 13,
            ),
            5 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'n',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 93,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 93,
                    'char' => 21,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 93,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 93,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => '_cache',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 93,
                        'char' => 36,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 93,
                      'char' => 36,
                    ),
                    'name' => 'getResultCode',
                    'call-type' => 1,
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 93,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Memcached',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 93,
                      'char' => 80,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RES_SUCCESS',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 93,
                      'char' => 80,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 93,
                    'char' => 80,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 93,
                  'char' => 80,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 93,
                'char' => 80,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 94,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '_cache',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 94,
                            'char' => 35,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 94,
                          'char' => 35,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 94,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => '_key',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 94,
                                'char' => 50,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 94,
                              'char' => 50,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 94,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'null',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 94,
                              'char' => 56,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 94,
                            'char' => 56,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'casToken',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 94,
                              'char' => 66,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 94,
                            'char' => 66,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 94,
                        'char' => 67,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 94,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 95,
                  'char' => 11,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 95,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '_cache',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 95,
                            'char' => 27,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 95,
                          'char' => 27,
                        ),
                        'name' => 'getResultCode',
                        'call-type' => 1,
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 95,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '\\Memcached',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 95,
                          'char' => 71,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'RES_NOTFOUND',
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 95,
                          'char' => 71,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 95,
                        'char' => 71,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 95,
                      'char' => 71,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 95,
                    'char' => 73,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'now',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'time',
                            'call-type' => 1,
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 96,
                            'char' => 27,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 96,
                          'char' => 27,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 97,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'expireTime',
                          'expr' => 
                          array (
                            'type' => 'add',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'now',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 97,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 97,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => '_expire',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 97,
                                'char' => 53,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 97,
                              'char' => 53,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 97,
                            'char' => 53,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 97,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 98,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 98,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '_cache',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 98,
                            'char' => 30,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 98,
                          'char' => 30,
                        ),
                        'name' => 'add',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 98,
                                'char' => 40,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => '_key',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 98,
                                'char' => 45,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 98,
                              'char' => 45,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 98,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'expireTime',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 98,
                              'char' => 57,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 98,
                            'char' => 57,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'expireTime',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 98,
                              'char' => 69,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 98,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 98,
                        'char' => 70,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 99,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => '_isLocked',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 99,
                            'char' => 44,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 99,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 100,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'static-property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '_cache',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 30,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 101,
                          'char' => 30,
                        ),
                        'name' => 'cas',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'casToken',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 101,
                              'char' => 43,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 101,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => '_key',
                                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                                'line' => 101,
                                'char' => 55,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 101,
                              'char' => 55,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 55,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 101,
                              'char' => 62,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 62,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                              'line' => 101,
                              'char' => 69,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 101,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 101,
                        'char' => 70,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 102,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => '_isLocked',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 102,
                            'char' => 43,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 102,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 104,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'n',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 104,
                      'char' => 20,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 106,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 106,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => '_isLocked',
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 106,
                  'char' => 31,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 106,
                'char' => 31,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * 采用CAS乐观锁
     *
     * @throws Exception
     * @return boolean
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 84,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 84,
            'char' => 5,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 83,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'release',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 112,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_cache',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 112,
                    'char' => 29,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 112,
                  'char' => 29,
                ),
                'name' => 'delete',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 112,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => '_key',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 112,
                        'char' => 47,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 112,
                      'char' => 47,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 112,
                    'char' => 47,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 112,
                'char' => 48,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 113,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 110,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__destruct',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 117,
                      'char' => 18,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => '_isLocked',
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 117,
                      'char' => 30,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 117,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 117,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 117,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_autoUnLock',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 117,
                    'char' => 50,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 117,
                  'char' => 50,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                'line' => 117,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'static-property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 118,
                        'char' => 23,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => '_cache',
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 118,
                        'char' => 23,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                      'line' => 118,
                      'char' => 23,
                    ),
                    'name' => 'delete',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 118,
                            'char' => 36,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => '_key',
                            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                            'line' => 118,
                            'char' => 41,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                          'line' => 118,
                          'char' => 41,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                        'line' => 118,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 118,
                    'char' => 42,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 119,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 121,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => '_isInstance',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                    'line' => 121,
                    'char' => 38,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
                  'line' => 121,
                  'char' => 38,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
              'line' => 122,
              'char' => 5,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => NULL,
            'void' => 1,
            'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
            'line' => 116,
            'char' => 5,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
          'line' => 115,
          'char' => 19,
        ),
      ),
      'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
      'line' => 3,
      'char' => 5,
    ),
    'file' => '/vagrant/zephir_code/my/my/utils/lock.zep',
    'line' => 3,
    'char' => 5,
  ),
);