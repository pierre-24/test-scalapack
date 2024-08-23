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

# includes
includes = include_directories('.')

# executables
exe_hello = executable(
    'hello',
    sources: files('hello.c'),
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)

exe_pdgemm = executable(
    'pdgemm',
    sources: files('pdgemm.c'),
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)

exe_layout = executable(
    'layout',
    sources: files('layout.c'),
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)
exe_hello = executable(
    'multigrid',
    sources: files('multigrid.c'),
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)

exe_layout = executable(
    'pdsyev',
    sources: files('pdsyev.c'),
    dependencies: project_dep,
    install: true,
    c_args : build_args,
)

tests_to_run = [
    'hello',
    'pdgemm',
    'pdsyev'
]

mpiexec = find_program('mpiexec', required : true)

foreach f: tests_to_run
    src_file = files(f +  '.c')

    test_exe = executable(
        'test_' + f,
        sources: src_file,
        dependencies: project_dep,
        install: false,
        build_by_default: false,
        c_args : build_args,
    )

    test(
        'test_' + f,
        test_exe,
        suite: 'test',
        is_parallel : false
    )
endforeach