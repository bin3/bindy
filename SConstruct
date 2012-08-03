#CacheDir('/usr/local/build_cache')

import os
from os.path import join, dirname, abspath

root_dir = dirname(File('SConstruct').rfile().abspath)
src_dir = join(root_dir, 'src')
third_dir = join(root_dir, '../third_party')
build_dir = join(root_dir, 'build')

env = DefaultEnvironment()
env['root_dir'] = root_dir
env['src_dir'] = src_dir
env['third_dir'] = third_dir
env['build_dir'] = build_dir

cpp_path = [
  '$build_dir',
  '$src_dir',
  '$third_dir/include'
]

lib_path = [
  '$third_dir/lib',
]

static_libs = [
  'glog',
  'gflags',
  'gtest',
]


env.Append(CPPFLAGS='-g')
#env.Append(CPPFLAGS='-O2')
env.Append(CPPPATH=cpp_path)
env.Append(LIBPATH=lib_path)
env.Append(LIBS=static_libs)

def Test(test_env, name):
  local_env = test_env.Clone()
  local_env.Append(LIBS = ['gtest'])
  local_env.Program(name + '_test.cc')
  
import __builtin__
__builtin__.Test = Test

Export('env')

SConscript('%s/SConscript' % src_dir)
