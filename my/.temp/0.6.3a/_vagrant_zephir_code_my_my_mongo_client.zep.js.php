<?php return array (
  0 => 
  array (
    'type' => 'namespace',
    'name' => 'My\\Mongo',
    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
    'line' => 3,
    'char' => 5,
  ),
  1 => 
  array (
    'type' => 'class',
    'name' => 'Client',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'init',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'servers',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 8,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                'line' => 8,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 8,
              'char' => 66,
            ),
          ),
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
                  'type' => 'variable',
                  'value' => 'servers',
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 9,
                  'char' => 20,
                ),
                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                'line' => 9,
                'char' => 20,
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
                          'value' => '请设定正确的服务器地址',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 10,
                          'char' => 60,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 10,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 10,
                    'char' => 61,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 11,
                  'char' => 3,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 13,
              'char' => 11,
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
                  'variable' => 'servers',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'shuffle',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'servers',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 13,
                          'char' => 38,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 13,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 13,
                    'char' => 39,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 13,
                  'char' => 39,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 14,
              'char' => 11,
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
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 14,
                    'char' => 25,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 14,
                  'char' => 25,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 15,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'dnsString',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 15,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 15,
                  'char' => 30,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 16,
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
                  'variable' => 'dnsString',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'join',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => ',',
                            'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                            'line' => 16,
                            'char' => 43,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 16,
                          'char' => 43,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'servers',
                            'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                            'line' => 16,
                            'char' => 52,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 16,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 16,
                      'char' => 53,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 16,
                    'char' => 53,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 16,
                  'char' => 53,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 18,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'connect',
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 18,
                  'char' => 20,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 19,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'class_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '\\MongoClient',
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 19,
                      'char' => 39,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 19,
                    'char' => 39,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                'line' => 19,
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
                      'variable' => 'connect',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => '\\MongoClient',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'mongodb://',
                                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                                'line' => 20,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'dnsString',
                                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                                'line' => 20,
                                'char' => 66,
                              ),
                              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                              'line' => 20,
                              'char' => 66,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                            'line' => 20,
                            'char' => 66,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                              'line' => 20,
                              'char' => 75,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                            'line' => 20,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 20,
                        'char' => 76,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 20,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 21,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'declare',
                  'data-type' => 'string',
                  'variables' => 
                  array (
                    0 => 
                    array (
                      'variable' => 'readPreference',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 21,
                        'char' => 39,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 21,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 22,
                  'char' => 15,
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
                      'variable' => 'readPreference',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '\\MongoClient',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 22,
                          'char' => 68,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'RP_PRIMARY_PREFERRED',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 22,
                          'char' => 68,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 22,
                        'char' => 68,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 22,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 23,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connect',
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 23,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => '\\MongoClient',
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 23,
                      'char' => 48,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 23,
                    'char' => 48,
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
                          'type' => 'variable',
                          'value' => 'connect',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 25,
                          'char' => 25,
                        ),
                        'name' => 'setReadPreference',
                        'call-type' => 3,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'readPreference',
                              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                              'line' => 25,
                              'char' => 62,
                            ),
                            'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                            'line' => 25,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 25,
                        'char' => 63,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                      'line' => 26,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 27,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                          'value' => '请安装PHP的Mongo1.4+版本的扩展',
                          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                          'line' => 28,
                          'char' => 75,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                        'line' => 28,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                    'line' => 28,
                    'char' => 76,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                  'line' => 29,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 31,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'connect',
                'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
                'line' => 31,
                'char' => 23,
              ),
              'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
              'line' => 32,
              'char' => 2,
            ),
          ),
          'docblock' => '**
	 * servers = array("127.0.0.1:57017","127.0.0.1:27017");
	 *',
          'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
          'line' => 8,
          'char' => 23,
        ),
      ),
      'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
      'line' => 3,
      'char' => 5,
    ),
    'file' => '/vagrant/zephir_code/my/my/mongo/client.zep',
    'line' => 3,
    'char' => 5,
  ),
);