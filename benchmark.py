import time
import Fastcount


def prime_count_vanilla(range_from:int, range_til:int):
    """ Returs the number of found prime numbers within a range. from and till are greedy """
    prime_count = 0
    for num in range(range_from, range_til + 1):
      if (num > 1):
        for candidate_prime in range(2, num):

          if ((num % candidate_prime) == 0):
            break
        else:
          prime_count += 1
    return prime_count




if __name__ == "__main__":
  startNumber = 0
  endNumber = 100000
  n_potential_numbers = endNumber - (startNumber - 1)

  start_time_vanilla = time.perf_counter()
  n_vanilla = prime_count_vanilla(range_from=startNumber, range_til=endNumber)
  end_time_vanilla = time.perf_counter()
  passed_time_vanilla = end_time_vanilla - start_time_vanilla
  print(f"[Vanilla] \t examined {n_potential_numbers} candidates and found {n_vanilla} primes in {passed_time_vanilla} seconds")

  start_time_fastcount = time.perf_counter()
  n_fastcount = Fastcount.primecounter(startNumber, endNumber)
  end_time_fastcount = time.perf_counter()
  passed_time_fastcount = end_time_fastcount - start_time_fastcount
  print(f"[Fastcount] \t examined {n_potential_numbers} candidates and found {n_fastcount} primes in {passed_time_fastcount} seconds")


  print(f"Fastcount is {passed_time_vanilla / passed_time_fastcount} times quicker than vanilla python")

  """
  # sudo python3 setup.py install && python3 benchmark.py

  Vanilla examined 9997 candidates and found 1228 primes in 0.30823640000016894 seconds
  Fastcount examined 9997 candidates and found 1228 primes in 0.015933700000459794 seconds
  Fastcount is 19.344935576248723 times quicker than vanilla python
  """