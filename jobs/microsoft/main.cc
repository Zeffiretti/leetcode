#include <iostream>
#include <vector>

#include "jobs/microsoft/alignedset.h"
#include "jobs/microsoft/consubstr.h"
#include "jobs/microsoft/fractionsum.h"
#include "jobs/microsoft/mergearray.h"
#include "jobs/microsoft/practice.h"
#include "jobs/microsoft/reducepollution.h"
#include "jobs/microsoft/rehabitalition.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);

  {  // s: "aaaaaa...a" for 100000 times
    std::string s =
        "sadhjsfhjasjkfhkjsafiuowetykjsdvnmksnvclewroiwetyusdnvmxznfqwkrpjdsfklajhflqwewqeqqweeqrewrasldqouwrflkdflk";
    std::cout << "consubstr::solution(s) = " << consubstr::solution(s) << std::endl;
  }

  {  // vector A: [1000000000] for 100000 times
    std::vector<int> A(100000, -1000000000);
    std::cout << "alignedset::solution(A, 3) = " << alignedset::solution(A, 100000) << std::endl;
  }

  {  // vector A: [1-100000]
    // vector B: [100000-1]
    std::vector<int> A, B;
    for (int i = 0; i < 100000; ++i) {
      A.push_back(i + 1);
      B.push_back(100000 - i);
    }
    std::cout << "mergearray: " << mergearray::solution(A, B) << std::endl;
  }
  return 0;
}