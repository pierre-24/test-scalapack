project('test-scalapack', 'c',
  version : '0.0.1',
  default_options : ['warning_level=3'],
)

cc = meson.get_compiler('c')

# configure dependencies
project_dep = []

build_args = [
  '-DPROJECT_NAME="' + meson.project_name() + '"',
  '-DPROJECT_VERSION="' + meson.project_version() + '"',
]

# mkl

project_dep += cc.find_library('mkl_core')
project_dep += cc.find_library('mkl_intel_ilp64')
project_dep += cc.find_library('mkl_sequential')

build_args += '-DMKL_ILP64'

# sources
srcs = files(
    'main.c'
)

includes = include_directories('.')

# executable
stdlite_exe = executable(
    meson.project_name(),
    sources: srcs,
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)
