int SearchArray(int t[], int n, int v) {
  int i = 0;
  while (i < n) {
    if (t[i] == v) break;
    else i++;
  }
  return i;
}
