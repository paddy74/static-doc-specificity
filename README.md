[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Query-Independent Document Specificity Scoring

The project calculates a query-independent document specificity score for use with document ranking.

## Methods

This project provides the following models:

- Normalized inverse document frequency based specificity score
- Term entropy based specificity score

More details on the formulas used can be found in [FORMULAS.md](FORMULAS.md).

## Getting Started

### Adding to your project

The reccommended way to add this library to you project is by including the following to your CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.13)
project(myProject)

include_directories("path/to/static-doc-specificity/include")
add_subdirectory("path/to/static-doc-specificity")

add_executable(myProject myProject_SOURCES)
# or `add_library(myProject myProject_SOURCES)`

target_link_libraries(myProject staticspecrank)
```

### Usage

The library has can be included in your source files with the following:

```c++
#include <staticSpecRank/Term.h>
#include <staticSpecRank/calcSpecificityScore.h>
```

The score for a given document can be calculated by calling the `specScore::calcSpecificityScore(scoreBase, numDocsInCorpus, docSize, docTermVector)` where the `scoreBase` variable is either 0 for NIDF or 1 for term entropy.

The docTermVector must be of type `std::vector<Term>`. See the file [`include/staticSpecRank/Term.h`](include/staticSpecRank/Term.h) for details on constructing the term vector.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](tags).

## Authors

* **Patrick Cox** - [paddy74](https://github.com/paddy74)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgements

This project is based on the following paper:

* Zheng L., Cox I.J. (2009) Re-ranking Documents Based on Query-Independent Document Specificity. In: Andreasen T., Yager R.R., Bulskov H., Christiansen H., Larsen H.L. (eds) Flexible Query Answering Systems. FQAS 2009. Lecture Notes in Computer Science, vol 5822. Springer, Berlin, Heidelberg
