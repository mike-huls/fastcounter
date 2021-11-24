from distutils.core import setup, Extension


def main():
  setup(
    name="Fastcount",
    version="1.0.0",
    description="Fastcount module in python",
    author="Mike",
    author_email="mikehuls42@github.com",
    ext_modules=[Extension("Fastcount", ["pyext.c"])]
  )

if (__name__ == "__main__"):
  main()

  """ 
    commandline:
    sudo CC=gcc python3 setup.py install
  """