#ifndef TERM_H
#define TERM_H

namespace specScore
{

class Term
{
public:
    /* Constructors */

    // Default constructor
    Term(uint docTermFrequency, uint corpusTermFrequency, uint numDocsWithTerm)
    {
        this->docTermFrequency = docTermFrequency;
        this->corpusTermFrequency = corpusTermFrequency;
        this->numDocsWithTerm = numDocsWithTerm;
    }

    /* Public methods */

    // Get the document term frequency
    uint getFrequency() { return this->docTermFrequency; }

    // Get the total term frequency across all documents in the collection
    uint getCorpusFrequency() { return this->corpusTermFrequency; }

    // Get the number of documents containing the term
    uint getNumDocsWithTerm() { return this->numDocsWithTerm; }

private:
    uint docTermFrequency;  // Number of times the term occurs in the document
    uint corpusTermFrequency;  // Total frequency across all documents in the collection
    uint numDocsWithTerm;  // Number documents with the term
};

}

#endif
