#ifndef BASETFIDF_H
#define BASETFIDF_H

#include <cmath>
#include <vector>


namespace specScore::base
{

/**
 * @brief Calculate the normalized inverse document frequency (NIDF).
 *
 * @param numDocsInCollection
 * @param numDocsWithTerm
 * @return double
 */
double calcNidf(uint numDocsInCollection, uint numDocsWithTerm)
{
    uint numDocsWithoutTerm = numDocsInCollection - numDocsWithTerm;

    // 0.5 helps to moderate extreme values
    double nidf = std::log( (numDocsWithoutTerm + 0.5) / (numDocsWithTerm + 0.5) );
    return nidf;
}


/**
 * @brief Calculate the NIDF based document specificity score.
 *  Higher values are better.
 *
 * @param numDocsInCollection
 * @param docSize
 * @param docTermVector
 * @return double
 */
double calcNidfSpecificity(uint const & numDocsInCollection, uint const & docSize, std::vector<Term> const & docTermVector)
{
    double score = 0;

    for (auto t : docTermVector)
        score += t.getFrequency() * calcNidf(numDocsInCollection, t.getNumDocsWithTerm());

    score *= (1 / docSize);
    return score;
}

}

#endif
