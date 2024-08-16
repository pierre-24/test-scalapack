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

Note: every argument is actually (!) a pointer in MKL :(

Note: <https://info.gwdg.de/wiki/doku.php?id=wiki:hpc:scalapack> and <https://andyspiros.wordpress.com/2011/07/08/an-example-of-blacs-with-c/>