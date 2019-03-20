#ifndef BASEENTROPY_H
#define BASEENTROPY_H

#include <staticSpecRank/Term.h>


namespace specScore::base
{

/**
 * @brief Calcualte the probability that a term appears in the document.
 *
 * @param corpusFreq The term frequency across the entire collection.
 * @param docFreq The term frequency across the document.
 * @return double The probability that a paticular instance of a term
 *  occurs in the document.
 */
double calcProbDist(uint const & corpusFreq, uint const & docFreq)
{
    return (docFreq / corpusFreq);
}


/**
 * @brief Compute the entropy of a term across the collection.
 *  Of the set of all terms in a collection, each term has an entropy.
 *  Entropy measures the uncertainty associated with a random variable X.
 *
 * @param corpusFreq The term frequency across the entire collection.
 * @param docTermVector The terms found in the document.
 * @return double The entropy of a term across the collection.
 */
double calcTermEntropy(uint const & corpusFreq, std::vector<Term> const & docTermVector)
{
    double entropy = 0;

    for (auto t : docTermVector)
    {
        double pr = calcProbDist(corpusFreq, t.getFrequency());
        entropy += pr * std::log(pr);
    }

    return -entropy;
}


/**
 * @brief Calculate the entropy-based measure of document specificity.
 *  Lower values are better.
 *
 * @param docTermVector The terms found in the document.
 * @return double Entropy-based measure of document specificity.
 */
double calcEntropySpecificity(uint const & docSize, std::vector<Term> const & docTermVector)
{
    double score = 0;

    for (auto t : docTermVector)
    {
        double entropy = calcTermEntropy(t.getCorpusFrequency(), docTermVector);
        score += t.getFrequency() * entropy;
    }

    score *= (1 / docSize);
    return score;
}

}

#endif
