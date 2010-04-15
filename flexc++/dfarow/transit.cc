#include "dfarow.ih"

void DFARow::transit(size_t stateIdx, DFARow &thisRow,
                                      size_t rangeChar,
                                      StateSet &nextSet)
{
    State const &state = (*(thisRow.d_states))[stateIdx];

    if (state.accept())
        thisRow.setAccept(state.accept(), stateIdx);

    switch (size_t type = state.type())
    {
        case State::FINAL:
            thisRow.setFinal(stateIdx);
        break;

        case State::CHARSET:
            if (state.contains(rangeChar))
            {
                nextSet.insert(state.next1());
                nextSet.insert(state.next2());
            }
        break;

        default:
            if (type == rangeChar)
            {
                nextSet.insert(state.next1());
                nextSet.insert(state.next2());
            }
        break;
    }
}