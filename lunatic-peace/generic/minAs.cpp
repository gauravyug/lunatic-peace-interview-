#include <iostream>
using namespace std;
long int answer[31];

int main()
{
  answer[1] = 1;
  answer[2] = 2;
  answer[3] = 3;
  answer[4] = 4;
  answer[5] = 5;
  answer[6] = 6;
  answer[7] = 7;
  answer[8] = 12;
  answer[9] = 16;
  for(int i=10; i<=30; i++)
  {
     answer[i] = max(answer[i], 2 * answer[i - 4]);
     answer[i] = max(answer[i], 3 * answer[i - 5]);
     answer[i] = max(answer[i], 4 * answer[i - 6]);
     answer[i] = max(answer[i], 5 * answer[i - 7]);
     answer[i] = max(answer[i], 6 * answer[i - 8]);
     answer[i] = max(answer[i], 7 * answer[i - 9]);
     cout << "Input: " << i << " Output: " << answer[i] << endl;
  }
  return 0;
}
