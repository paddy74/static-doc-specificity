#ifndef STATICSPECRANK_H
#define STATICSPECRANK_H

#include <string>
#include <vector>

#include "Term.h"

#define NIDF_BASE 0
#define ENTROPY_BASE 1


namespace specScore
{

/**
 * @brief Calculates the document specificity score for a single document with either an NIDF base (0) or a term entropy base (1).
 *
 * @param scoreBase Either NIDF (0) or term entropy (1).
 * @param numDocsInCorpus The number of documents in the collection.
 * @param docSize The size/length of the document.
 * @param docTermVector
 * @return double The document specificity score for the given document.
 */
double calcSpecificityScore(int const & scoreBase, uint const & numDocsInCorpus, uint const & docSize, std::vector<Term> const & docTermVector);

}

#endif
