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

mkl_libraries = [
    'm',
    'pthread',
    'mkl_scalapack_ilp64',
    'mkl_intel_ilp64',
    'mkl_sequential',
    'mkl_core',
    'mkl_blacs_intelmpi_ilp64'
]

foreach name: mkl_libraries
    project_dep += cc.find_library(name)
endforeach

build_args += '-DUSE_MKL'
build_args += '-DMKL_ILP64'
build_args += '-m64'

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
