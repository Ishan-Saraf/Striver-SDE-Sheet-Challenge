int NthRoot(int n, int m) {
  /*
  // Approach 1: brute forceing our way:
  int ans = -1;

  for (int i=1; i<=m; i++) {
    long long temp = pow(i, n);
    if (temp == m) ans = i;
  }

  return ans;
  */

  // Approach 2: using binary searching technique:
  if (m == 1 || n == 1) {
    return m;
  }

  int ans = -1;

  int lo = 1;
  int hi = m;

  while (lo <= hi) {
    int mid = lo + (hi-lo)/2;

    if (pow(mid, n) == m) {
      ans = mid;
      break;
    }

    else if (pow(mid, n) > m) {
      hi = mid - 1;
    }

    else lo = mid + 1;
  }

  return ans;
}