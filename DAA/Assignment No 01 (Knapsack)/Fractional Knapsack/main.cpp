#include <iostream>
#define MAX 10
using namespace std;
struct product
{
  int profit;
  int weight;
  float ratio;
  float take_quantity;
};
int main()
{
  product P[MAX], temp;
  int i, j, n, w;
  float value = 0;
  cout << "ENTER NUMBER OF ITEMS : ";
  cin >> n;
  cout << "ENTER CAPACITY OF SACK : ";
  cin >> w;
  cout << "\n";
  for (i = 0; i < n; ++i)
  {
    cout << "ENTER PROFIT AND WEIGHT OF PRODUCT " << i + 1 << " : ";
    cin >> P[i].profit >> P[i].weight;
    P[i].ratio = (float)P[i].profit / P[i].weight;
    P[i].take_quantity = 0;
  }

  for (i = 0; i < n; ++i)
  {
    for (j = i + 1; j < n; ++j)
    {
      if (P[i].ratio < P[j].ratio)
      {
        temp = P[i];
        P[i] = P[j];
        P[j] = temp;
      }
    }
  }
  for (i = 0; i < n; ++i)
  {
    if (w == 0)
      break;
    else if (P[i].weight < w)
    {
      P[i].take_quantity = 1;
      w -= P[i].weight;
    }
    else if (P[i].weight > w)
    {
      P[i].take_quantity = (float)w / P[i].weight;
      w = 0;
    }
  }
  for (i = 0; i < n; ++i)
  {
    value += P[i].profit * P[i].take_quantity;
  }
  cout << "\nTHE KNAPSACK VALUE IS : " << value;
  return 0;
}

/* eg.
3 items

value | weight
60       10
100      20
120      30

W=50
ans = 240 = (60+100+(2/3)120)
*/