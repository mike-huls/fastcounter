import time


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
  startNumber = 3
  endNumber = 14

  start_time_vanilla = time.perf_counter()
  n_vanilla = prime_count_vanilla(range_from=startNumber, range_til=endNumber)
  end_time_vanilla = time.perf_counter()
  print(f"Vanilla examined {n_potential_numbers} candidates and found {n_vanilla} primes in {end_time_vanilla - start_time_vanilla} seconds")
