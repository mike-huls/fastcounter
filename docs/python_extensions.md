### Python extensions

Below is required for the python.h c package
```commandline
sudo apt-get install python3-dev  # for python3.x installs
```

Below wil compile and build your c extension so that you can run some code. It will create the program.
```commandline
clear && gcc pyext.c -I /usr/include/python3.8 -o dist/pyext && ./dist/pyext
```


clear && gcc primecounter.c -I /usr/include/python3.8 -o dist/primecounter && ./dist/primecounter
