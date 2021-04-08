#ifndef __TILEMAP_COLLISION_HPP
#define __TILEMAP_COLLISION_HPP

#include <characters/IGameCharacter.hpp>
#include <constants.hpp>
#include <collision/aabb.hpp>
#include <collision/common.hpp>
#include <collision/enums.hpp>

#include <array>

auto constexpr collision_tiles = std::array<int, 10>{1, 3, 12, 14, 15, 25, 27, 37, 38, 39};

void compute_tilemap_collisions(Tilemap const& tilemap, IGameCharacter* c);

#endif
