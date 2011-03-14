#include "generator.ih"

void Generator::ignoreBOLaction(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
            "    if (range == s_rangeOfBOL)\n" <<
            "        return ActionType__::IGNORE_BOL;\n";
    }
}