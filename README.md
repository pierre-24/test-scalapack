# Just a test of `scalapack`


```bash
source /opt/intel/oneapi/setvars.sh

export CC=mpicc
meson setup _build
meson compile _build

mpirun -np 4 _build/test-scalapack
```

## Notes

+ Header from <https://github.com/pierre-24/cblacs-header>.
+ If not Meson, see [oneMKL line advisor](https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-link-line-advisor.html) for MKL.
+ The header for scalapack use the Fotran API: every argument is passed via a pointer.
+ Examples: <https://info.gwdg.de/wiki/doku.php?id=wiki:hpc:scalapack> and <https://andyspiros.wordpress.com/2011/07/08/an-example-of-blacs-with-c/>.