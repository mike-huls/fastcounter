#include <string.h>
#include <Python.h>

int c_prime_counter(int frm, int til) {
   
   
  // int flag = 0;
  int primecount = 0;
  for (int num = frm; num <= til; num++) {
    int flag = 0;


    for (int candidate = 2; candidate < num; candidate++) {
      if ((num % candidate) == 0) {

        flag = 1;
        break;
      }
    }

    if (flag == 0) {
      primecount++;
    }

    // if (t % num == 0) {
    //   // flag = 1;
    //   // break;
    //   continue;
    // }

  }

  // printf("==> found %d primes \n", primecount);
  return primecount;
}

static PyObject *py_primecounter(PyObject *self, PyObject *args) {


  /**/
  // str is the string we want to write to the file stream
  // filename is the name of the file to write to
  int *n_frm, *n_til = NULL;


  // Parse arguments
  // args = type of PyObject
  // ss is the format specifier of the data type to the argumetns to parse (c-api arg on docs.python)
  // $str and $filename are pointers to local variables to which the parsed values will be assigned
  if (!PyArg_ParseTuple(args, "ii", &n_frm, &n_til)) {
    return NULL;
  }



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






  // Call function
  int found_primes = c_prime_counter(n_frm, n_til);


  return PyLong_FromLong(found_primes);
}

// Holds info about the methods in your pytho C extension module
// Makes sure you can call the methods defined in your module. 
// Each struct of 4 members represents a single method in your module
static PyMethodDef CountingMethods[] = {
  // SPECIFY THE FUNCTION NAME HERE
  {"primecounter", py_primecounter, METH_VARARGS, "Function for counting primes in a range in c"}, 
  {NULL, NULL, 0, NULL}
};


// Holds information about your c extension module itself.Single structure that defines your module
static struct PyModuleDef fastcountmodule = {
  PyModuleDef_HEAD_INIT,
  // SPECIFY THE MODULE NAME HERE
  "Fastcount",                              // name of the python c extension module
  "C library for counting fast",  // module docstring
  -1,                                   // amount of memory needed. 
                                        //    neg = no support for sub-interpreters, 
                                        //    non-negative = supports re-initialization of this module, 
  CountingMethods                          // referende to the methods table. The array of PyMethodDef structs as defined earlier
};


// this gets called when python imports your module
// 1. implicitly sets the return type of the function as PyObject*
// 2. Declares any special linkages
// 3. Declares the function as extern "C". In case your using C++ it tells the C++ compiler not to do name-mangling on the symbols
// Returns a new module object of type PyObject. As an argument pass the address of the method structure that you've already defined; fputsmodule

// PyInit_[THISPART] has to match your momdule name (case sensitive)
PyMODINIT_FUNC PyInit_Fastcount(void) {
  return PyModule_Create(&fastcountmodule);
};
