<?php return array (
  0 => 
  array (
    'type' => 'namespace',
    'name' => 'My\\Utils',
    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
    'line' => 3,
    'char' => 5,
  ),
  1 => 
  array (
    'type' => 'class',
    'name' => 'Registry',
    'abstract' => 0,
    'final' => 0,
    'extends' => '\\ArrayObject',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => '_registryClassName',
          'default' => 
          array (
            'type' => 'string',
            'value' => '\\My\\Utils\\Registry',
            'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
            'line' => 6,
            'char' => 61,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 8,
          'char' => 11,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => '_registry',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
            'line' => 8,
            'char' => 36,
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 11,
          'char' => 10,
        ),
      ),
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
          'name' => 'getInstance',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 13,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 13,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 13,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 13,
                  'char' => 37,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 13,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'scall',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'init',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 14,
                    'char' => 25,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 15,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 17,
              'char' => 14,
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
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 17,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => '_registry',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 17,
                  'char' => 31,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 17,
                'char' => 31,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 18,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 11,
          'char' => 26,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setInstance',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'registry',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Registry',
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 20,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 20,
              'char' => 59,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 22,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 22,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 22,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 22,
                  'char' => 37,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 22,
                'char' => 37,
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
                          'value' => 'Registry is already initialized',
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 23,
                          'char' => 67,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 23,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 23,
                    'char' => 68,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 24,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 26,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'setClassName',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'get_class',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'registry',
                            'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                            'line' => 26,
                            'char' => 46,
                          ),
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 26,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 26,
                      'char' => 47,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 26,
                    'char' => 47,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 26,
                'char' => 48,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 27,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => '_registry',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 27,
                    'char' => 39,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 27,
                  'char' => 39,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 20,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'init',
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
                  'variable' => 'className',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 32,
                  'char' => 19,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 33,
              'char' => 8,
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
                  'variable' => 'className',
                  'expr' => 
                  array (
                    'type' => 'static-property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 33,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => '_registryClassName',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 33,
                      'char' => 46,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 33,
                    'char' => 46,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 33,
                  'char' => 46,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 34,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'setInstance',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'new',
                      'class' => 'className',
                      'dynamic' => 1,
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 34,
                      'char' => 44,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 34,
                    'char' => 44,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 34,
                'char' => 45,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 35,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 30,
          'char' => 29,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'setClassName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'registryClassName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '\\My\\Utils\\Registry',
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 37,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 37,
              'char' => 89,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 39,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 39,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 39,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 39,
                  'char' => 37,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 39,
                'char' => 37,
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
                          'value' => 'Registry is already initialized',
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 40,
                          'char' => 67,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 40,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 40,
                    'char' => 68,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 41,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 43,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_string',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'registryClassName',
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 43,
                          'char' => 41,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 43,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 43,
                    'char' => 42,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 43,
                  'char' => 42,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 43,
                'char' => 44,
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
                          'value' => 'Argument is not a class name',
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 44,
                          'char' => 64,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 44,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 44,
                    'char' => 65,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 47,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => '_registryClassName',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'registryClassName',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 47,
                    'char' => 57,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 47,
                  'char' => 57,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 37,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '_unsetInstance',
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
                  'property' => '_registry',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 52,
                    'char' => 35,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 52,
                  'char' => 35,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 53,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 50,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 55,
              'char' => 45,
            ),
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
                  'variable' => 'instance',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 57,
                  'char' => 18,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 58,
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
                  'variable' => 'instance',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'getInstance',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 58,
                    'char' => 43,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 58,
                  'char' => 43,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 59,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'instance',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 59,
                    'char' => 22,
                  ),
                  'name' => 'offsetExists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 59,
                        'char' => 41,
                      ),
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 59,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 59,
                  'char' => 43,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 59,
                'char' => 43,
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
                          'value' => 'No entry is registered for key \'index\'',
                          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                          'line' => 60,
                          'char' => 74,
                        ),
                        'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                        'line' => 60,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 60,
                    'char' => 75,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 61,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 63,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'instance',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 63,
                  'char' => 25,
                ),
                'name' => 'offsetGet',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 63,
                      'char' => 41,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 63,
                    'char' => 41,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 63,
                'char' => 42,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 55,
          'char' => 26,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 66,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 66,
              'char' => 52,
            ),
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
                  'variable' => 'instance',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 68,
                  'char' => 18,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 69,
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
                  'variable' => 'instance',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'getInstance',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 69,
                    'char' => 43,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 69,
                  'char' => 43,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 70,
              'char' => 16,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'instance',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 70,
                  'char' => 18,
                ),
                'name' => 'offsetSet',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 70,
                      'char' => 34,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 70,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 70,
                      'char' => 41,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 70,
                    'char' => 41,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 70,
                'char' => 42,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 66,
          'char' => 26,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'isRegistered',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 73,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'static-property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 75,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 75,
                    'char' => 30,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 75,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 75,
                  'char' => 37,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 75,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 76,
                    'char' => 25,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 78,
              'char' => 14,
            ),
            1 => 
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
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 78,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => '_registry',
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 78,
                    'char' => 32,
                  ),
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 78,
                  'char' => 32,
                ),
                'name' => 'offsetExists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 78,
                      'char' => 51,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 78,
                    'char' => 51,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 78,
                'char' => 52,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 73,
          'char' => 26,
        ),
        8 => 
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
              'name' => 'arr',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 81,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 81,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'flags',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parent',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 81,
                  'char' => 80,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'ARRAY_AS_PROPS',
                  'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                  'line' => 81,
                  'char' => 80,
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 81,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 81,
              'char' => 80,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arr',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 83,
                      'char' => 32,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 83,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'flags',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 83,
                      'char' => 39,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 83,
                    'char' => 39,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 83,
                'char' => 40,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 81,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 86,
              'char' => 47,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_key_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 88,
                      'char' => 38,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 88,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                      'line' => 88,
                      'char' => 44,
                    ),
                    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                    'line' => 88,
                    'char' => 44,
                  ),
                ),
                'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
                'line' => 88,
                'char' => 45,
              ),
              'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
          'line' => 86,
          'char' => 19,
        ),
      ),
      'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
      'line' => 3,
      'char' => 5,
    ),
    'file' => '/vagrant/zephir_code/my/my/utils/registry.zep',
    'line' => 3,
    'char' => 5,
  ),
);