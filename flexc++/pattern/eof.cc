#include "pattern.ih"

Pattern Pattern::eof(States &states)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(EOF__, pair.second, 0);

    Pattern ret(pair);
    return ret;
}
