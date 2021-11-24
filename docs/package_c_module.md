# How to package the c module in a python package

### Packaging installation
First create a setup.py that implements the stuff below
Extension is imported from distutils.core
  
```python
ext_modules=[Extension("fputs", ["fputsmodule.c"])]
```

Let's package
We can use the setup.py file to build the Python C extension module.
Install in a venv

The command below compiles and installs the Python C extension module in the current directory.
By default the Python interpreter uses `clang`. 
The second line shows you how to tell the python interpreter to use gcc.
It will fall back to gcc by default if clang is not available. 

(make sure you are in wsl)
```commandline
sudo CC=gcc python3 setup.py install
# then run the test python file
python3 run_module.py
```

sudo CC=gcc python3 setup.py install
python3 run_module.py
