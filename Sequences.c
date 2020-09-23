#include <stdio.h>

//fibonacci secuencial
long long int Sequences_sfibo(long long int n){
  int actual, ant1 = 1, ant2 = 1,i;
  if ((n == 0) || (n == 1)) {
  actual = 1;
  }
  else{
    for (i=2; i<=n; i++) {
      actual = ant1 + ant2;
      ant2 = ant1;
      ant1 = actual;
    }
  }
  return actual;
}

long long int Sequences_rfibo(long long int n){
  if (n < 2)
    return n;
return Sequences_rfibo(n - 1) + Sequences_rfibo(n - 2);
}
