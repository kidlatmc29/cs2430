template <typename Comparable>
void insertionSort(Comparable a[], int N)
{
  Comparable temp;
  int i;
  for(int p = 1; p < N; ++p) {
    temp = a[p];
    for(i = p; i > 0 && temp < a[i-1]; --i) {
      a[i] = a[i-1];
    }
    a[i] = temp;
  }
}


  