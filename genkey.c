#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <Blum.h>

int main(int argc, char *argv[]){
  if (argc != 4) {
    fprintf(stderr, "Usage : %s <filename of the public key> <filename of the private key> <size of the key>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  mp_bitcnt_t size;
  mpz_t p, q, n;

  size = (mp_bitcnt_t) strtoul(argv[4], NULL, 10);
  gmp_randstate_t state;

  mpz_inits(p, q, n, NULL);
  gmp_randinit_default(state);

  Genpremier(1000, size, state, &p);
  Genpremier(1000, size, state, &q);
  mpz_mul(n, p, q);

  write_key(argv[2], p, q);
  write_pub_key(argv[3], n);

  mpz_clears(p, q, n, NULL);
  exit(EXIT_SUCCESS);
}
