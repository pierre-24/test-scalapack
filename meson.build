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

# linear algebra backend
la_backend = get_option('la_backend')
if la_backend == 'netlib'
    scalapack_dep = dependency('scalapack', required: false)
    if scalapack_dep.found()
        project_dep += scalapack_dep
    else
        netlib_libraries = [
            'mpi',
            'blas',
            'lapack',
            'scalapack'
        ]

        foreach name: netlib_libraries
            project_dep += cc.find_library(name, required: true)
        endforeach
    endif

    build_args += '-DUSE_LA_NETLIB'
elif la_backend == 'mkl'
    mkl_libraries = [
        'm',
        'mkl_scalapack_ilp64',
        'mkl_intel_ilp64',
        'mkl_intel_thread',
        'mkl_core',
        'mkl_blacs_intelmpi_ilp64',
        'iomp5',
    ]

    foreach name: mkl_libraries
        project_dep += cc.find_library(name, required: true)
    endforeach

    build_args += '-DUSE_LA_MKL'
    build_args += '-DMKL_ILP64'
elif la_backend == 'custom'
    foreach lib: get_option('la_libraries')
        project_dep += cc.find_library(lib, required : true)
    endforeach
    build_args += '-DUSE_LA_CUSTOM'
endif

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
