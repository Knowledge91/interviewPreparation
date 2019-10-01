# CPP
## Iterate through array
```cpp
#include <vector>
#include <iostream>

std::vector<int> v = {1, 2, 3};
for(std::vector<int>::iterator v = v.begin(); v != v.end(); ++v) {
  std::cout << *v << std::endl;
}
```

