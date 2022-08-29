#include "new.h"
#include "player.h"

int main(void)
{
    Object  *player = new(Player);

    delete(player);
    return (0);
}
