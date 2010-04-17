#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <iosfwd>
#include <vector>
#include <string>
#include <set>

class Rules;
class States;

#include "../dfarow/dfarow.h"

class DFA
{
    friend std::ostream &operator<<(std::ostream & out, DFA const &dfa);

    Ranges *d_ranges;

    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA();
        DFA(Ranges &ranges);

        void build(std::vector<size_t> const &active, Rules const &rules, 
                   States const &states);

        std::vector<DFARow>::const_iterator begin() const;
        std::vector<DFARow>::const_iterator end() const;
        size_t size() const;

    private:
        static void fillStartSet(size_t idx, Rules const &rules, 
                                             StateSet &start);
};

inline DFA::DFA()
:
    d_ranges(0)    
{}

#endif
