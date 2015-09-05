#include <list>
#include <iostream>
void find_factor(int sum, int n, std::list<int> & result)
{
  if (n <= 0 || sum <= 0)
    return;
  if (sum == n)
  {
    std::cout << "sum: " <<sum << std::endl;
    for (auto iter_ = result.begin(); iter_ != result.end(); iter_++)
    {
      std::cout << *iter_ << "+";
    }
    std::cout << n << std::endl;
  }
  result.push_front(n);
  find_factor(sum - n, n - 1, result);
  result.pop_front();
  find_factor(sum, n - 1, result);
}

int main(int argc, char ** argv)
{
  int sum,n;
  std::list<int> result;
  std::cin >> sum >> n;
  find_factor(sum, n, result);
}
