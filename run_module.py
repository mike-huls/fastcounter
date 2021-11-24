import Fastcount
from Fastcount import primecounter

print(Fastcount) 

print(Fastcount.__name__) 






try:
  Fastcount.primecounter(1, 12)
except Exception as e:
    print(f'1 failed as expected: {e}')

try:
  Fastcount.primecounter(0, 1)
except Exception as e:
    print(f'2 failed as expected: {e}')

try:
  Fastcount.primecounter(3, 1)
except Exception as e:
    print(f'3 failed as expected: {e}')


try:
  res = Fastcount.primecounter(3, 12)
  print('successs?', res)
except Exception as e:
    print(f'4 failed unexpected: {e}')

quit()


print("reading..")
with open("testbestand.txt", "r") as f:
  print(f.read())
print("read!")


print("now the exception:")
try:
  fputs.fputs("error", "testbestand.txt")
except Exception as e:
  print("caught the exception. Check it out below:")
  print(f"\tC-exception: {e}")


print("reading..")
with open("testbestand.txt", "r") as f:
  print(f.read())
print("read!")
