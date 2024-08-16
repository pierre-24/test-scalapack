# Just a test of `scalapack`

For the moment, it uses MKL.

```bash
source /opt/intel/oneapi/setvars.sh

export CC=mpicc
meson setup _build
meson compile _build

mpirun -np 4 _build/test-scalapack
```

Note: <https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-link-line-advisor.html>
