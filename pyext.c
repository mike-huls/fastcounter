#include <string.h>
#include <Python.h>


static PyObject *method_fputs(PyObject *self, PyObject *args) {
  /**/
  // str is the string we want to write to the file stream
  // filename is the name of the file to write to
  int *n_frm, *n_til = NULL;
  int bytes_copied = -1;

  // Parse arguments
  // args = type of PyObject
  // ss is the format specifier of the data type to the argumetns to parse (c-api arg on docs.python)
  // $str and $filename are pointers to local variables to which the parsed values will be assigned
  if (!PyArg_ParseTuple(args, "ii", &n_frm, &n_til)) {
    return NULL;
  }

  // Raise a custom python exception from C to python
  // char s[]="error";
  // if (strcmp(str,s) == 0) {
  //   PyErr_SetString(PyExc_ValueError, "This exception is thrown in the C file");
  //   return NULL;
  // }

  // Check inputs
  if (n_frm <= 1) {
    PyErr_SetString(PyExc_ValueError, "Please provide input n_frm larger than 1");
    return NULL;
  }
  if (n_til <= 1) {
    PyErr_SetString(PyExc_ValueError, "Please provide input n_til larger than 1");
    return NULL;
  }
  if (n_frm >= n_til) {
    PyErr_SetString(PyExc_ValueError, "f_rm cannot be equal to or larger than n_til");
    return NULL;
  }


  // int flag = 0;
  int primecount = 0;
  int frm = n_frm;
  int til = n_til;

  for (int num = frm; num <= til; num++) {
    int flag = 0;


    for (int candidate = frm; candidate <= til / 2; candidate++) {
      if ((num % candidate) == 0) {
        flag = 1;
        break;
      }
    }

    if (flag == 0) {
      primecount++;
      // printf("\tthis canditate is a prime: %d.\n", num);
    }

    // if (t % num == 0) {
    //   // flag = 1;
    //   // break;
    //   continue;
    // }

  }

  printf("==> found %d primes \n", primecount);




  // if (*str == 'error') {
  //   PyErr_SetString(PyExc_ValueError, "Dit is een exception");
  //   return NULL;
  // }

  // // Write the file, store the number of bytes copied (default negatieve)
  // FILE *fp = fopen(filename, "w");
  // bytes_copied = fputs(str, fp);
  // fclose(fp);

  // PyLong_FromLong() retuens a PyLongObject => int object in python.
  return PyLong_FromLong(primecount);
}

// Holds info about the methods in your pytho C extension module
// Makes sure you can call the methods defined in your module. 
// Each struct of 4 members represents a single method in your module
static PyMethodDef FputsMethods[] = {
  // fputs - name user would write to invoke this function
  // method_fputs - name of the C function to invoke
  // METH_VARARGS - flag that tells the interpreter that the func will accept two arguments of type PyObject*:
  //    - self is the modlue object
  //    - args is a tuple containging the actual arguments to your function, get unpacked py PyArg_ParseTuple()
  // DOCSTRING
  {"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C lib func"},
  {NULL, NULL, 0, NULL}
};


// Holds information about your c extension module itself.Single structure that defines your module
static struct PyModuleDef fputsmodule = {
  PyModuleDef_HEAD_INIT,
  "fputs",                              // name of the python c extension module
  "Py interface for fputs C lib func",  // module docstring
  -1,                                   // amount of memory needed. 
                                        //    neg = no support for sub-interpreters, 
                                        //    non-negative = supports re-initialization of this module, 
  FputsMethods                          // referende to the methods table. The array of PyMethodDef structs as defined earlier
};


// this gets called when python imports your module
// 1. implicitly sets the return type of the function as PyObject*
// 2. Declares any special linkages
// 3. Declares the function as extern "C". In case your using C++ it tells the C++ compiler not to do name-mangling on the symbols
// Returns a new module object of type PyObject. As an argument pass the address of the method structure that you've already defined; fputsmodule
PyMODINIT_FUNC PyInit_fputs(void) {
  return PyModule_Create(&fputsmodule);
};

int main() {
  return 1;
}


// python calls PyInit_fputs
// -> calls PyModule_Create
// -> Lists FputsMethods
// -> links "fputs" to the C function