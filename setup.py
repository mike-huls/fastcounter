from distutils.core import setup, Extension


def main():
  setup(
    name="fputs",
    version="1.0.0",
    description="Python interface for the fputs C lib func",
    author="Mike",
    author_email="mikehuls42@github.com",
    ext_modules=[Extension("fputs", ["pyext.c"])]
  )

if (__name__ == "__main__"):
  main()

  """ 
    commandline:
    sudo CC=gcc python3 setup.py install
  """