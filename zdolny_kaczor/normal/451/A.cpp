# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (min(n, m) % 2)
    printf("Akshat\n");
  else
    printf("Malvika\n");
}