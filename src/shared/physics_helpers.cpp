#include "physics_helpers.h"

double physics_helpers::current_speed(double dx, double dy)
{
    return std::sqrt(dx * dx + dy * dy);
}
