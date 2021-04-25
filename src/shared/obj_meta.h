#ifndef OBJ_META_H
#define OBJ_META_H

struct obj_meta
{
    // You can do physics and gfx calculations on 'active' object only
    // if game object is not active - it's removed from game objects vector
    bool is_active {true};
};

#endif // OBJ_META_H
